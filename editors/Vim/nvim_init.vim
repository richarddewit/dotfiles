"         __         __          _
"        / /  _ __   \ \  __   _(_)_ __ ___  _ __ ___
"       | |  | '_ \   | | \ \ / / | '_ ` _ \| '__/ __|
"    _  | |  | | | |  | |  \ V /| | | | | | | | | (__
"   (_) | |  |_| |_|  | |   \_/ |_|_| |_| |_|_|  \___|
"        \_\         /_/
"
" Author: Richard de Wit
" Repo:   https://github.com/richarddewit/dotfiles/vim/nvim_init.vim


source ~/.vimrc

" Neovim specific settings -------------------------------------------------{{{

" Neovim Settings
  let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  let $NVIM_TUI_ENABLE_CURSOR_SHAPE=1

" See live substitution previews
  if exists('&inccommand')
    set inccommand=nosplit
  endif

" Keep my terminal window open when I navigate away
  autocmd TermOpen * set bufhidden=hide

" FZF
  tmap <C-p> <C-\><C-n>:FZF<CR>
  tmap <leader>a <C-\><C-n>:Ag<CR>
  tmap <leader>h <C-\><C-n>:History<CR>

" Neovim-qt Guifont command
  command -nargs=? Guifont call rpcnotify(0, 'Gui', 'SetFont', "<args>") | let g:Guifont="<args>"
  Guifont Hack:h9

" }}}
