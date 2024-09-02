echo alias del=rm > t.tmp
source t.tmp
del *.o
del *.a
gcc -g -c *.c
del simplex_main.o
ar rcs libsmp.a *.o
gcc -g -lm simplex_main.c libsmp.a
