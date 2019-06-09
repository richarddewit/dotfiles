#!/usr/bin/env bash

folder="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

[ -d $HOME/.vim ] || mkdir -p $HOME/.vim
[ -d $HOME/.nvim ] || mkdir -p $HOME/.nvim
[ -d $HOME/.config/nvim ] || mkdir -p $HOME/.config/nvim
ln -sf $folder/vimrc $HOME/.vimrc
ln -sf $folder/nvim_init.vim $HOME/.config/nvim/init.vim

# Install vim-plug
curl -fLo $HOME/.vim/autoload/plug.vim         --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
curl -fLo $HOME/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

# vim-startify
mkdir -p $HOME/.vim/files/info
mkdir -p $HOME/.nvim/{backup,swap,undo,files/info}

vim +PlugInstall +qall
nvim +PlugInstall +qall

