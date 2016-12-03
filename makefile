CFLAGS = -g -Wall -Weffc++ -std=c++11
CC = g++

# All Targets
all: reviiyot

# Executable "hello" depends on the files hello.o and run.o.
reviiyot: bin/reviiyot.o    bin/Card.o   bin/Deck.o   bin/Hand.o
	@echo 'Building target: reviiyot'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/reviiyot  bin/reviiyot.o  bin/Card.o  bin/Deck.o  bin/Hand.o
	@echo 'Finished building target: reviiyot'
	@echo '********************************** '
	@echo ' '

# Depends on the source and header files
bin/reviiyot.o:   src/reviiyot.cpp
	$(CC) $(CFLAGS)  -c  -Linclude  -o  bin/reviiyot.o   src/reviiyot.cpp

# Depends on the source and header files 
bin/Card.o:  src/Card.cpp   include/Card.h
	$(CC) $(CFLAGS)  -c  -Linclude  -o  bin/Card.o    src/Card.cpp

#Depends on the source and header files 
bin/Deck.o:  src/Deck.cpp   include/Deck.h
	$(CC) $(CFLAGS)  -c  -Linclude  -o  bin/Deck.o    src/Deck.cpp

#Depends on the source and header files 
bin/Hand.o:  src/Hand.cpp   include/Hand.h
	$(CC) $(CFLAGS)  -c  -Linclude  -o  bin/Hand.o    src/Hand.cpp

#Clean the build directory
clean: 
	rm -rf bin/*
