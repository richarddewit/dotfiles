#!/usr/bin/env bash

folder="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
vscode_folder="$HOME/.config/Code/User"

rm -r $vscode_folder/settings.json
rm -r $vscode_folder/keybindings.json
rm -r $vscode_folder/snippets
mkdir -p $vscode_folder
ln -sf $folder/settings.json $vscode_folder/settings.json
ln -sf $folder/keybindings.json $vscode_folder/keybindings.json
ln -sf $folder/snippets $vscode_folder/snippets
echo
echo "Run install_extensions.sh to.. install extensions :)"
