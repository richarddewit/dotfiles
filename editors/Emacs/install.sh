#!/usr/bin/env bash

rm -r ~/.spacemacs
folder="$(dirname $(readlink -f $0))"
echo "Linking from $folder"
ln -sf $folder/spacemacs ~/.spacemacs
ln -sf $folder/spacemacs.desktop ~/.local/share/applications

force_overwrite=$([ "$1" == "-y" ] && echo "true" || echo "false")
emacs_folder="$HOME/.emacs.d"
install_spacemacs() {
  rm -rf $emacs_folder
  git clone --single-branch --branch develop https://github.com/syl20bnr/spacemacs $emacs_folder
}

ask_overwrite() {
  read -n 1 -p "Folder $emacs_folder already exists. Overwrite current Emacs configuration (y/n)? " answer
  echo
  case ${answer:0:1} in
    y|Y )
      echo "Overwriting ..."
      install_spacemacs
      ;;
  esac
}

if [ -d $emacs_folder ]; then
  if $force_overwrite; then
    echo "Overwriting ..."
    install_spacemacs
  else
    ask_overwrite
  fi
else
  install_spacemacs
fi
