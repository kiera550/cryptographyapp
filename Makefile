CC=gcc
CXX=g++
LD=gcc
CFLAGS=-Wall -Werror -g
LDFLAGS=$(CFLAGS)

TARGETS=main

all: $(TARGETS)

main: main.o
	$(CXX) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.o: %.cc
	$(CXX) $(CFLAGS) -c $<

clean:
	rm -f *.o

distclean: clean
