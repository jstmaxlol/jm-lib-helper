#!/bin/bash

# if you are having issues, report it on the repo
# but first try to 'chmod +x ./*.sh' just to be sure.

# note: when opening an issue, please also add the #n
#       of the last log that appeared on screen, thanks.

printf "#1 Creating work dir .."
mkdir ~/.jmlibhTemp/ || exit

printf "#2 Changing directory to work dir .."
cd ~/.jmlibhTemp || exit

printf "#3 Cloning repository .."
git clone https://github.com/jstmaxlol/escape.ansi.sux/ || exit

printf "#4 Copying library to /usr/include (Requires root perms)" || exit
sudo cp ./escape.ansi.sux/escape.ansi.h /usr/include/escape.ansi.h
sudo cp ./escape.ansi.sux/escape.ansi.h /usr/include/escape.ansi

printf "#5 Done! Include library in your projects with:"
printf "#include <escape.ansi.h>"
printf "..or if you prefer it:"
printf "#include <escape.ansi>"
