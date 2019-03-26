#!/usr/bin/bash

PWD=$(pwd)
cd /efs-dev/home/bmli/prep/src/

cc -Wall -std=c99 -c rotate.c
cc -Wall -std=c99 -c dedup.c
cc -Wall -std=c99 -o ../bin/rotate rotate.o
cc -Wall -std=c99 -o ../bin/dedup dedup.o

cd $PWD
