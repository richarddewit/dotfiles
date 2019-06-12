# vim: set ft=sh:
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

# Detect platform
case "$(uname -s)" in
  Linux)
    platform="linux";;
  Darwin)
    platform="macos";;
  CYGWIN*|MINGW*|MSYS*)
    platform="windows";;
  *)
    platform="other";;
esac
export PLATFORM="$platform"

export DOTFILES=$HOME/dotfiles
[ "$platform" = "linux" ] && [ -d "$HOME/dotmanjaro" ] && export DOTMANJARO=$HOME/dotmanjaro
[ "$platform" = "macos" ] && [ -d "$HOME/dotmacos" ]   && export DOTMACOS=$HOME/dotmacos

# $PATH
export PATH="./bin:$HOME/bin:$HOME/.local/bin:/usr/local/bin:$PATH"
# Dotfiles bin
export PATH="$DOTFILES/bin:$PATH"
[ -n "$DOTMANJARO" ] && [ -d "$DOTMANJARO/bin" ] && export PATH="$DOTMANJARO/bin:$PATH"
[ -n "$DOTMACOS" ]   && [ -d "$DOTMACOS/bin" ]   && export PATH="$DOTMACOS/bin:$PATH"
# Dart
export PATH="$HOME/.pub-cache/bin:$PATH"

[[ -f ~/.extend.profile ]] && . ~/.extend.profile
