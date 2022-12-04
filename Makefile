FIRFilter.o:
	clang -c FIRFilter.c

a.out:
	clang main.c FIRFilter.o -I/Users/hmlai/Desktop/軟體實驗助教/project2/AudioFile

.PHONY: all a.out
all: a.out

