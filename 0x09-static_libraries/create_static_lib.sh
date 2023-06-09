#!/bin/bash
gcc _wall _pedantic _werror _wextra _c *.c
ar -rc liball.a *.o
ranlib liball.a
