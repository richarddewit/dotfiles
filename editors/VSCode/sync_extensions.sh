#!/usr/bin/env bash

folder="$(dirname "$(readlink -f "$0")")"
code --list-extensions > $folder/code_extensions
