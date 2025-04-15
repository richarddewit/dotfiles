run_bg() {
  nohup "$@" &>/dev/null & disown %%
}

# ZSH
alias "$"=""
alias sr="exec $SHELL"

[ -f "$(which nvim)" ] && alias vim=nvim

mkcd() {
  command mkdir -p "$1" && cd "$1"
}
if [ "$PLATFORM" != "macos" ]; then
  alias open=xdg-open
fi
[ -f "$HOME/go/bin/g" ] && unalias g
unalias gg
gg() {
  xdg-open "https://google.com/search?q=$*"
}

# Git (extra)
alias glr="git pull --rebase --autostash"
alias gla="git pull --autostash"

# Node
if [ -f "$(which corepack)" ]; then
  alias yarn="corepack yarn"
  alias yarnpkg="corepack yarnpkg"
  alias pnpm="corepack pnpm"
  alias pnpx="corepack pnpx"
  alias npm="corepack npm"
  alias npx="corepack npx"
fi
alias npmg="npm i -g"
alias npms="npm i -S"
alias npmd="npm i -D"

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
if [ "$PLATFORM" = "macos" ]; then
  alias lsa="gls -lah"
  alias l="gls -lah --group-directories-first"
  alias la="gls -lAh --group-directories-first"
  alias ll="gls -alh --color=auto --group-directories-first"
  alias ls="gls -lh --color=auto --group-directories-first"
  alias lsa="gls -lah --group-directories-first"
else
  alias lsa="ls -lah"
  alias l="ls -lah --group-directories-first"
  alias la="ls -lAh --group-directories-first"
  alias ll="ls -alh --color=auto --group-directories-first"
  alias ls="ls -lh --color=auto --group-directories-first"
  alias lsa="ls -lah --group-directories-first"
fi

# Python/Django
alias py="python"
alias m="python manage.py"
alias pi="pipenv install"

# Ruby/Rails
alias rb="ruby"
alias b="bundle"
alias bi="bundle install"
alias ba="bundle add"
alias bu="bundle update"
alias be="bundle exec"

# DDEV/PHP
ddev_php() {
  if [ "$(pwd)" != "$HOME" ] && [ -d ".ddev" ]; then
    echo "DDEV found. Executing inside DDEV instead." >&2
    if [[ "$1" == "artisan" ]]; then
      ddev $@
    else
      ddev php $@
    fi
  else
    \php $@
  fi
}
ddev_composer() {
  if [ "$(pwd)" != "$HOME" ] && [ -d ".ddev" ]; then
    echo "DDEV found. Executing inside DDEV instead." >&2
    ddev composer $@
  else
    \composer $@
  fi
}
ddev_npm() {
  if [ "$(pwd)" != "$HOME" ] && [ -d ".ddev" ]; then
    echo "DDEV found. Executing inside DDEV instead." >&2
    ddev npm $@
  else
    \npm $@
  fi
}
alias php=ddev_php
alias composer=ddev_composer
alias npm=ddev_npm
alias tinker="php artisan tinker"

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

# .NET
alias Install-Package="dotnet add package"

# Crystal
if [ -f "$(which watchexec)" ]; then
  alias wcr="watchexec -w 'src' -w 'shard.yml' -rc -- shards run"
  alias wcrt="KEMAL_ENV=test watchexec -w spec -f '**/*.cr' -c -- crystal spec"
fi
