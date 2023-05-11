#!/bin/sh

gcc ./rev_wstr.c -o rev_wstr
./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
./rev_wstr "abcdefghijklm"
./rev_wstr "Wingardium Leviosa" | cat -e
