function run_bg
{
  nohup "$@" &>/dev/null & disown %%
}

# ZSH
alias "$"=""
alias sr="exec $SHELL"


function mkcd
{
  command mkdir -p $1 && cd $1
}
alias mkcd=mkcd

# NPM
alias npmg='npm i -g'
alias npms='npm i -S'
alias npmd='npm i -D'

# Vagrant
alias vsus='vagrant suspend'
alias vssh='vagrant ssh'
alias vup='vagrant up'

# Emacs
alias gmacs='run_bg emacs $@'

# Python (virtualenv)
alias wo='workon'
alias workoff='deactivate'
alias wf='workoff'

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
alias hssus=homestead suspend
alias hsssh=homestead ssh -- -t "cd projects/`basename "$PWD"`; /bin/bash"