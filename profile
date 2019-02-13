#
# ~/.profile
#
#

# Disable Ctrl-S (suspend) and Ctrl-Q (resume) in terminals
\stty -ixon

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
if [ -f /usr/bin/nvim ]; then
  export EDITOR='nvim'
else
  export EDITOR='vim'
fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
# export SSH_KEY_PATH="~/.ssh/rsa_id"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

# alias ssh='TERM=xterm ssh'

export DOTFILES=$HOME/dotfiles

# $PATH
export PATH=./bin:$HOME/bin:/usr/local/bin:$PATH
# Composer
export PATH=$HOME/.config/composer/vendor/bin:./vendor/bin:$PATH
# Dotfiles bin
export PATH=$DOTFILES/bin:$PATH

[ -s "$(which rustc)" ] && export RUST_SRC_PATH="$(rustc --print sysroot)/lib/rustlib/src/rust/src"
[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

export PATH="$HOME/.yarn/bin:$HOME/.config/yarn/global/node_modules/.bin:$PATH"

# DB parameter mapping to be able to use php artisan commands on host
export DB_HOST=127.0.0.1
export DB_PORT=33060

[[ -f ~/.extend.profile ]] && . ~/.extend.profile
