#!/bin/bash

# Nombre de la carpeta de backup
BACKUP_DIR="zsh_config_backup_$(date +%Y%m%d%H%M%S)"
# Nombre del archivo comprimido
ARCHIVE_NAME="${BACKUP_DIR}.tar.gz"

echo "Creando carpeta de backup: ${BACKUP_DIR}"
mkdir -p "$BACKUP_DIR"

# 1. Copiar el archivo .zshrc
echo "Copiando ~/.zshrc..."
cp ~/.zshrc "$BACKUP_DIR/" || { echo "Advertencia: ~/.zshrc no encontrado o no se pudo copiar."; }

# 2. Copiar el historial de Zsh
echo "Copiando ~/.zsh_history..."
cp ~/.zsh_history "$BACKUP_DIR/" || { echo "Advertencia: ~/.zsh_history no encontrado o no se pudo copiar."; }

# 3. Copiar el directorio custom de Oh My Zsh
# Asegúrate de que ~/.oh-my-zsh/custom existe antes de intentar copiar
if [ -d ~/.oh-my-zsh/custom ]; then
    echo "Copiando ~/.oh-my-zsh/custom/..."
    cp -r ~/.oh-my-zsh/custom/ "$BACKUP_DIR/" || { echo "Error: No se pudo copiar ~/.oh-my-zsh/custom/."; exit 1; }
else
    echo "Advertencia: ~/.oh-my-zsh/custom/ no encontrado. Omitiendo copia."
fi

# 4. (Opcional) Otros dotfiles importantes
# Descomenta y ajusta las siguientes líneas si quieres incluir otros archivos.
# Por ejemplo, .gitconfig, .tmux.conf, .vimrc, etc.
# echo "Copiando ~/.gitconfig..."
# cp ~/.gitconfig "$BACKUP_DIR/" || { echo "Advertencia: ~/.gitconfig no encontrado o no se pudo copiar."; }

# echo "Copiando ~/.tmux.conf..."
# cp ~/.tmux.conf "$BACKUP_DIR/" || { echo "Advertencia: ~/.tmux.conf no encontrado o no se pudo copiar."; }

# Crea el archivo comprimido
echo "Creando el archivo comprimido ${ARCHIVE_NAME}..."
tar -czvf "$ARCHIVE_NAME" "$BACKUP_DIR"

# Eliminar la carpeta temporal (opcional)
# echo "Eliminando la carpeta temporal ${BACKUP_DIR}..."
# rm -rf "$BACKUP_DIR"

echo "¡Backup completado! El archivo '${ARCHIVE_NAME}' ha sido creado en tu directorio actual."
echo "Ahora puedes subir este archivo a tu repositorio de GitHub."
echo "Para restaurarlo en otro sistema, descarga el archivo y descomprímelo con 'tar -xzvf ${ARCHIVE_NAME}'."
