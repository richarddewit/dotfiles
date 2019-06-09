#!/usr/bin/env bash

folder="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
code --list-extensions > $folder/code_extensions
