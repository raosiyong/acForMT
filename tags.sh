#!/usr/bin/bash 
ctags -R --fields=+lS
cscope -Rbq 
