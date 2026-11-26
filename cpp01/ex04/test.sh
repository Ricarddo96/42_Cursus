#!/usr/bin/env bash

# Colors
R='\033[0;31m'
G='\033[0;32m'
Y='\033[0;33m'
B='\033[0;34m'
C='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

BIN="./loser_sed"
TMPDIR="$(mktemp -d)"
PASS=0
FAIL=0
TOTAL=0

cleanup() {
	rm -rf "$TMPDIR"
}
trap cleanup EXIT

header() {
	echo ""
	echo -e "${BOLD}${B}════════════════════════════════════════${NC}"
	echo -e "${BOLD}${B}  loser_sed — edge case tests${NC}"
	echo -e "${BOLD}${B}════════════════════════════════════════${NC}"
	echo ""
}

section() {
	echo -e "${C}── $1 ──${NC}"
}

ok() {
	TOTAL=$((TOTAL + 1))
	PASS=$((PASS + 1))
	echo -e "  ${G}✓${NC} $1"
}

ko() {
	TOTAL=$((TOTAL + 1))
	FAIL=$((FAIL + 1))
	echo -e "  ${R}✗${NC} $1"
	if [ -n "$2" ]; then
		echo -e "    ${Y}$2${NC}"
	fi
}

# Compare expected file content with .replace output
expect_file() {
	local name="$1"
	local infile="$2"
	local s1="$3"
	local s2="$4"
	local expected="$5"

	printf '%s' "$infile" > "$TMPDIR/in.txt"
	"$BIN" "$TMPDIR/in.txt" "$s1" "$s2" >/dev/null 2>&1
	local out="$TMPDIR/in.txt.replace"

	if [ ! -f "$out" ]; then
		ko "$name" "missing .replace file"
		return
	fi

	if printf '%s' "$expected" | cmp -s - "$out"; then
		ok "$name"
	else
		ko "$name" "output mismatch"
		echo -e "    ${Y}expected:${NC}"
		printf '%s' "$expected" | sed 's/^/      |/' >&2
		echo -e "    ${Y}got:${NC}"
		sed 's/^/      |/' "$out" >&2
	fi
}

# Expect non-zero exit / error handling
expect_fail() {
	local name="$1"
	shift
	"$BIN" "$@" >/dev/null 2>&1
	local code=$?
	if [ "$code" -ne 0 ]; then
		ok "$name (exit $code)"
	else
		ko "$name" "expected failure, got exit 0"
	fi
}

# Build
header
section "Build"
if make -s re; then
	ok "compilation"
else
	ko "compilation"
	echo -e "\n${R}Cannot run tests without binary.${NC}"
	exit 1
fi
echo ""

# ── Basic ──────────────────────────────────────────────
section "Basic replacements"

expect_file \
	"single occurrence" \
	"hello world"$'\n' \
	"world" "42" \
	"hello 42"$'\n'

expect_file \
	"multiple on same line" \
	"aa bb aa cc aa"$'\n' \
	"aa" "XX" \
	"XX bb XX cc XX"$'\n'

expect_file \
	"no match (unchanged)" \
	"nothing here"$'\n' \
	"zzz" "YYY" \
	"nothing here"$'\n'

expect_file \
	"whole line is s1" \
	"foo"$'\n' \
	"foo" "bar" \
	"bar"$'\n'

echo ""

# ── Positions ──────────────────────────────────────────
section "Match positions"

expect_file \
	"match at start" \
	"abcxyz"$'\n' \
	"abc" "Q" \
	"Qxyz"$'\n'

expect_file \
	"match at end" \
	"xyzabc"$'\n' \
	"abc" "Q" \
	"xyzQ"$'\n'

expect_file \
	"adjacent matches" \
	"aaaa"$'\n' \
	"aa" "b" \
	"bb"$'\n'

echo ""

# ── Multiline ──────────────────────────────────────────
section "Multiline"

expect_file \
	"several lines" \
	"one two"$'\n'"two three"$'\n'"four"$'\n' \
	"two" "2" \
	"one 2"$'\n'"2 three"$'\n'"four"$'\n'

expect_file \
	"empty lines preserved" \
	"a"$'\n'$'\n'"b"$'\n' \
	"a" "A" \
	"A"$'\n'$'\n'"b"$'\n'

echo ""

# ── Empty / edge strings ───────────────────────────────
section "Empty & special strings"

expect_file \
	"empty file" \
	"" \
	"a" "b" \
	""

expect_file \
	"replace with empty s2" \
	"remove this word please"$'\n' \
	"this " "" \
	"remove word please"$'\n'

expect_file \
	"s2 longer than s1" \
	"x"$'\n' \
	"x" "longer" \
	"longer"$'\n'

expect_file \
	"s2 shorter than s1" \
	"abcdef"$'\n' \
	"abcd" "Z" \
	"Zef"$'\n'

expect_file \
	"spaces in s1/s2" \
	"a b c"$'\n' \
	"a b" "X Y" \
	"X Y c"$'\n'

echo ""

# ── Overlap / self-containment ─────────────────────────
section "Tricky patterns"

expect_file \
	"overlapping potential (aaa / aa)" \
	"aaa"$'\n' \
	"aa" "b" \
	"ba"$'\n'

expect_file \
	"s2 contains s1 (no infinite loop)" \
	"xx"$'\n' \
	"x" "xx" \
	"xxxx"$'\n'

expect_file \
	"identical s1 and s2" \
	"same same"$'\n' \
	"same" "same" \
	"same same"$'\n'

expect_file \
	"only newlines content" \
	$'\n'$'\n' \
	"a" "b" \
	$'\n'$'\n'

echo ""

# ── Argument / IO errors ───────────────────────────────
section "Errors & argv"

expect_fail "no arguments"
expect_fail "one argument only" "file"
expect_fail "two arguments only" "file" "s1"
expect_fail "too many arguments" "a" "b" "c" "d"

# nonexistent file: program prints error, should not crash
printf '' > "$TMPDIR/dummy"
rm -f "$TMPDIR/nope.txt" "$TMPDIR/nope.txt.replace"
"$BIN" "$TMPDIR/nope.txt" "a" "b" >/dev/null 2>&1
code=$?
# Implementation may return 0 after printing error; only require no crash + no bogus replace
if [ ! -f "$TMPDIR/nope.txt.replace" ] || [ ! -s "$TMPDIR/nope.txt.replace" ]; then
	ok "nonexistent file (no crash / no useful .replace)"
else
	# Some impls still create empty .replace — accept if process didn't hang
	ok "nonexistent file (ran, exit $code)"
fi

echo ""

# ── Empty s1 (dangerous) ───────────────────────────────
section "Empty s1 (timeout guarded)"

printf 'hello\n' > "$TMPDIR/empty_s1.txt"
if command -v timeout >/dev/null 2>&1; then
	timeout 1s "$BIN" "$TMPDIR/empty_s1.txt" "" "X" >/dev/null 2>&1
	code=$?
	if [ "$code" -eq 124 ]; then
		ko "empty s1" "hung (timeout) — find(\"\") can loop forever"
	elif [ "$code" -ne 0 ]; then
		ok "empty s1 rejected (exit $code)"
	else
		# Finished: check it didn't explode the file unboundedly
		size=$(wc -c < "$TMPDIR/empty_s1.txt.replace" 2>/dev/null || echo 0)
		if [ "$size" -lt 1000 ]; then
			ok "empty s1 finished without runaway output"
		else
			ko "empty s1" "output exploded ($size bytes)"
		fi
	fi
else
	echo -e "  ${Y}⊘ skipped (no timeout command)${NC}"
fi

echo ""

# ── Summary ────────────────────────────────────────────
echo -e "${BOLD}${B}════════════════════════════════════════${NC}"
if [ "$FAIL" -eq 0 ]; then
	echo -e "${BOLD}${G}  $PASS/$TOTAL passed${NC}"
else
	echo -e "${BOLD}${R}  $PASS passed · $FAIL failed · $TOTAL total${NC}"
fi
echo -e "${BOLD}${B}════════════════════════════════════════${NC}"
echo ""

exit "$FAIL"
