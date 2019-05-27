#! /usr/bin/env bash

folder="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

bash $folder/Emacs/install.sh
bash $folder/Vim/install.sh
bash $folder/VSCode/install.sh
bash $folder/VSCode/install_extensions.sh
