run_bg() {
  nohup "$@" &>/dev/null & disown %%
}

# ZSH
alias "$"=""
alias sr="exec $SHELL"

alias vim=nvim

mkcd() {
  command mkdir -p "$1" && cd "$1"
}
alias open=xdg-open
[ -f "$HOME/go/bin/g" ] && unalias g
unalias gg
gg() {
  xdg-open "https://google.com/search?q=$*"
}

# Node
alias npmg="npm i -g"
alias npms="npm i -S"
alias npmd="npm i -D"
alias nvmrc="nvm current > .nvmrc"

# Vagrant
alias vsus="vagrant suspend"
alias vssh="vagrant ssh"
alias vup="vagrant up"

# Editors/IDEs
function gmacs {
  if [ -z "$@" ]; then
    args="."
  else
    args="$@"
  fi
  run_bg emacs "$args"
}

# Listing with directory first
alias l="ls -lah --group-directories-first"
alias la="ls -lAh --group-directories-first"
alias ll="ls -alh --color=auto --group-directories-first"
alias ls="ls -lh --color=auto --group-directories-first"
alias lsa="ls -lah --group-directories-first"

# Python/Django
alias py="python"
alias m="python manage.py"
alias pi="pipenv install"

# Emacs
emc() {
  dir="${1:-.}"
  if [ -n "$(ps -ax | grep "[e]macs --daemon")" ]; then
    emacsclient -a "" -n "$dir"
  else
    emacsclient -a "" -c -n "$dir"
  fi
}

# Docker
source $DOTFILES/zsh/docker-aliases.zsh

mine() {
  if [ -z "$@" ]; then
    args="."
  else
    args="$@"
  fi
  sudo chown -R $(id -nu):$(id -ng) "$args"
}
