# Specify extensions of files to delete when cleaning
CLEANEXTS   = o gch so

# Specify the target file and the install directory
OUTPUTFILE  = libsis
INSTALLDIR  = ../../bin

# Compiler args
CC = gcc
args = -g -Wall -lm -fPIC

# Pattern rule to build an object file from a .c file
%.o: %.c
	$(CC) $(args) -c $^

# Default target
.PHONY: all
all: $(OUTPUTFILE)

# Build dynamic library
$(OUTPUTFILE): loader.o queries.o
	$(CC) -shared -o $@.so $^

.PHONY: install
install:
	mkdir -p $(INSTALLDIR)
	cp -p $(OUTPUTFILE).so $(INSTALLDIR)

.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -f *.$$file; done
	rm -f $(INSTALLDIR)/$(OUTPUTFILE).so

# Dependencies
loader.o: loader.c types.h ../logger/logger.h
queries.o: queries.c types.h