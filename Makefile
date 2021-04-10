# Specify extensions of files to delete when cleaning
CLEANEXTS   = o

# Specify the target file and the library directory
OUTPUTFILE  = Proyecto1
LIBDIR  = bin

# Compiler args
CC = gcc
args = -g -Wall -llogger -lsis -lm

# Default target
.PHONY: all
all: libs $(OUTPUTFILE)

libs:
	cd lib/logger && make && make install
	cd lib/sis && make && make install

# Build main
$(OUTPUTFILE): src/main.c
	$(CC) $^ -L$(LIBDIR) $(args) -o $@.o

.PHONY: clean 
clean:
	cd lib/logger && make clean
	cd lib/sis && make clean
	for file in $(CLEANEXTS); do rm -f *.$$file; done