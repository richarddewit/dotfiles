#! /usr/bin/env bash

folder="$(dirname $(readlink -f $0))"

bash $folder/Emacs/install.sh
bash $folder/Vim/install.sh
bash $folder/VSCode/install.sh
bash $folder/VSCode/install_extensions.sh
