#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $DIR/rofi-settings.sh

rofi \
  -i \
  -show window \
  -show-icons \
  -p 'λ ' \
  -fullscreen \
  -m $monitor \
  -hide-scrollbar \
  -color-window "$color_window" \
  -color-normal "$color_normal" \
  -location $location \
  -lines $lines \
  -bw $border_width \
  -font "$font" \
  -padding $padding \
  -separator-style $separator \
  -opacity $opacity
