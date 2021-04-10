# Specify extensions of files to delete when cleaning
CLEANEXTS   = o gch so

# Specify the target file and the install directory
OUTPUTFILE  = liblogger
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
$(OUTPUTFILE): logger.o
	$(CC) -shared -o $@.so $^

.PHONY: install
install:
	mkdir -p $(INSTALLDIR)/dynamic
	cp -p $(OUTPUTFILE).so $(INSTALLDIR)/dynamic

.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -f *.$$file; done
	rm -f $(INSTALLDIR)/dynamic/$(OUTPUTFILE).so

# Dependencies
logger.o: logger.c