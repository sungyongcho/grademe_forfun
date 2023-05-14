#!/bin/sh

gcc ./wdmatch.c -o wdmatch
./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
