function run_bg {
  nohup "$@" &>/dev/null & disown %%
}

# ZSH
alias "$"=""
alias sr="exec $SHELL"

alias vim=nvim

function mkcd {
  command mkdir -p $1 && cd $1
}
alias mkcd=mkcd
alias open=xdg-open

# NPM
alias npmg='npm i -g'
alias npms='npm i -S'
alias npmd='npm i -D'

# Vagrant
alias vsus='vagrant suspend'
alias vssh='vagrant ssh'
alias vup='vagrant up'

# Editors/IDEs
alias gmacs='run_bg emacs $@'
alias pstorm='run_bg phpstorm $@'

# Listing with directory first
alias l='ls -lah --group-directories-first'
alias la='ls -lAh --group-directories-first'
alias ll='ls -alh --color=auto --group-directories-first'
alias ls='ls -lh --color=auto --group-directories-first'
alias lsa='ls -lah --group-directories-first'

# Homestead
function homestead() {
  ( cd ~/Homestead && vagrant $* )
}
alias hs=homestead
alias hssus="homestead suspend"
alias hsssh="homestead ssh -- -t \"cd projects/`basename \"$PWD\"`; /bin/bash\""
alias hsus=hssus
alias hssh=hsssh
alias hsedit="vim ~/Homestead/Homestead.yaml"

# Python/Django
alias m='python manage.py'
alias pi='pipenv install'

# Emacs
function emc() {
  dir=${1:-.}
  if [ -n "$(ps -ax | grep "[e]macs --daemon")" ]; then
    emacsclient -a '' -n $dir
  else
    emacsclient -a '' -c -n $dir
  fi
}
