#!/bin/bash

# Script to recursively rename all files to upper case on Linux

shopt -s globstar
for file in **/*
do
  if [[ -f "$file" ]] || [[ -d "$file" ]]; then
    if [[ "${file^^}" != *"RENAME.PS1"* ]] && [[ "${file^^}" != *"RENAME.SH"* ]] && [[ "${file^^}" != *"RUNCPM"* ]]; then
      dest="${file^^}"
      if [[ "$file" != "$dest" ]]; then
		echo "$file" '=>' "$dest"
        mv "$file" %TEMP%
		mv %TEMP% "$dest"
      fi
    fi
  fi
done
