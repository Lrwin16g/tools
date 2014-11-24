# Makefile

CC = g++
CFLAGS = -O
INCPATH += `pkg-config --cflags opencv`
LIBS += `pkg-config --libs opencv`

EXEDIR = ./bin
OBJDIR = ./obj
SRCDIR = ./src

all:
	$(CC) $(SRCDIR)/gray.cpp -o $(EXEDIR)/gray `pkg-config --cflags --libs opencv`
	$(CC) $(SRCDIR)/extconv.cpp -o $(EXEDIR)/extconv `pkg-config --cflags --libs opencv`
	$(CC) $(SRCDIR)/gnoise.cpp -o $(EXEDIR)/gnoise `pkg-config --cflags --libs opencv`
	$(CC) $(SRCDIR)/psnr.cpp -o $(EXEDIR)/psnr `pkg-config --cflags --libs opencv`

clean:
	rm -f $(EXEDIR)/*.o
