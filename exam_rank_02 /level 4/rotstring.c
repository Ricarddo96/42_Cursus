/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$> */

#include <stdlib.h>
#include <unistd.h>

/* 
void rotstring(char *s)
{
    int i = 0;
    int end = 0;
    int start = 0;
    int j = 0;
    int boolean = 0;
    char *first_word = NULL;

    while (s[i] == ' ' || s[i] == '\t')
        i++;
    start = i;
    while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
        i++;
    end = i;
    first_word = malloc((end - start + 1) * sizeof(char));
    if (!first_word)
        return;

    while (start < end)
        first_word[j++] = s[start++];
    first_word[j] = '\0';

    j = 0;    
    while (s[i] == ' ' || s[i] == '\t')
        i++;

    while (s[i])
    {
        if (s[i] != ' ' && s[i] != '\t')
        {
            if (boolean)
                write(1, " ", 1);
            while (s[i] != ' ' && s[i] != '\t')
            {
                write(1, &s[i++], 1);
            }
            boolean = 1;
        }
        else
            i++;    
    }
    write(1, " ", 1);
    while (first_word[j])
        write(1, &first_word[j++], 1);
    free(first_word);
} */

void rotstring(char *s)
{
    int i = 0;
    int end_first_word = 0; 
    int start_first_word = 0;
    int j = 0;
    char *first_word = NULL; 


    while (s[i] == ' ' || s[i] == '\t')
        i++;
    
    start_first_word = i;
    while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
        i++;
    end_first_word = i;

    if (start_first_word == end_first_word && s[i] == '\0') 
        return;

    first_word = malloc((end_first_word - start_first_word + 1) * sizeof(char));
    if (!first_word)
        return;

    j = 0;
    while (start_first_word < end_first_word)
        first_word[j++] = s[start_first_word++];
    first_word[j] = '\0';


    while (s[i] == ' ' || s[i] == '\t')
        i++;

    // 4. Imprimir las palabras restantes
    // Necesitamos saber cuándo es la última palabra para no imprimir un espacio después.
    int current_word_start;
    int has_more_words_to_print;

    while (s[i] != '\0')
    {
        current_word_start = i;

        // Saltar cualquier espacio/tabulación para encontrar el inicio de la siguiente palabra
        while (s[current_word_start] == ' ' || s[current_word_start] == '\t')
            current_word_start++;

        // Si ya llegamos al final de la cadena después de saltar espacios, salimos.
        if (s[current_word_start] == '\0')
            break;

        // Imprimir la palabra actual
        while (s[current_word_start] != ' ' && s[current_word_start] != '\t' && s[current_word_start] != '\0')
        {
            write(1, &s[current_word_start], 1);
            current_word_start++;
        }
        
        // Determinar si hay más palabras después de la actual (excluyendo la primera palabra que va al final)
        has_more_words_to_print = 0;
        int temp_i = current_word_start;
        while (s[temp_i] != '\0')
        {
            if (s[temp_i] != ' ' && s[temp_i] != '\t')
            {
                has_more_words_to_print = 1;
                break;
            }
            temp_i++;
        }

        // Si hay más palabras por imprimir (además de la primera palabra), o si la primera palabra es la única
        // y no se ha impreso nada, entonces imprimimos un espacio.
        // Esto evita un espacio extra si 'first_word' es la única palabra.
        // También asegura que haya un espacio entre las palabras restantes y la 'first_word'.
        if (has_more_words_to_print || (s[i] != '\0' && s[current_word_start] == '\0')) {
             write(1, " ", 1);
        }

        i = current_word_start; // Actualizar 'i' para el siguiente ciclo
        while (s[i] == ' ' || s[i] == '\t') // Saltar espacios entre palabras
            i++;
    }

    // 5. Imprimir la primera palabra al final
    // Solo si first_word_found (implícito por el malloc y no return temprano)
    // Y si había más palabras o si first_word no era la única palabra.
    // Simplificando: siempre imprime la first_word, y el espacio anterior ya fue manejado.
    j = 0;
    while (first_word[j])
        write(1, &first_word[j++], 1);
    
    free(first_word);
}

int main(int c, char **v)
{
    if (c >= 2)
        rotstring(v[1]);
    write(1, "\n", 1);
    return (0);
}