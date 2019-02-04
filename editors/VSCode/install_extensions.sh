#!/usr/bin/env bash

folder="$(dirname "$(readlink -f "$0")")"
extensions="$(cat $folder/code_extensions)"

echo "Installing extensions"
for extension in ${extensions[@]}
do
  code --install-extension $extension
done
