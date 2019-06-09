#!/usr/bin/env bash

folder="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
extensions="$(cat $folder/code_extensions)"

echo "Installing extensions"
for extension in ${extensions[@]}
do
  code --install-extension $extension
done
