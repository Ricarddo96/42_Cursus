#!/bin/bash

set -e

echo "🚀 Instalando Vim, Zsh y dependencias..."
sudo apt update && sudo apt install -y vim zsh curl git unzip fontconfig

echo "🔁 Cambiando shell por defecto a Zsh..."
chsh -s "$(which zsh)"

echo "🎩 Instalando Oh My Zsh..."
export RUNZSH=no
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

ZSH_CUSTOM=${ZSH_CUSTOM:-~/.oh-my-zsh/custom}

echo "🔌 Instalando plugins populares..."
git clone https://github.com/zsh-users/zsh-autosuggestions "$ZSH_CUSTOM/plugins/zsh-autosuggestions"
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git "$ZSH_CUSTOM/plugins/zsh-syntax-highlighting"

echo "🎨 ¿Deseas instalar el tema Powerlevel10k? (y/n)"
read -r install_p10k
if [[ "$install_p10k" == "y" ]]; then
    git clone --depth=1 https://github.com/romkatv/powerlevel10k.git "$ZSH_CUSTOM/themes/powerlevel10k"
    sed -i 's/^ZSH_THEME=".*"/ZSH_THEME="powerlevel10k\/powerlevel10k"/' ~/.zshrc
else
    sed -i 's/^ZSH_THEME=".*"/ZSH_THEME="agnoster"/' ~/.zshrc
fi

echo "🛠️  Configurando plugins en .zshrc..."
sed -i 's/plugins=(.*)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/' ~/.zshrc

echo "🔤 Instalando fuente Nerd Font recomendada (MesloLGS NF)..."
FONT_DIR="$HOME/.local/share/fonts"
mkdir -p "$FONT_DIR"

cd /tmp
MESLO_URL="https://github.com/ryanoasis/nerd-fonts/releases/latest/download/Meslo.zip"
curl -fLo Meslo.zip "$MESLO_URL"
unzip -o Meslo.zip -d "$FONT_DIR"
fc-cache -fv

echo "📜 Fuente instalada. Asegúrate de cambiar la fuente de tu terminal a 'MesloLGS NF'."

echo "✅ ¡Todo listo! Reinicia tu terminal para disfrutar de tu nuevo entorno Zsh con estilo 🎉"

