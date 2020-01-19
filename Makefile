CC = g++
TARGET = fhp.o
INCPATH = /home/izochor/Pobrane/gsl/include
LIBS = /home/izochor/Pobrane/gsl/lib
FLAGS = -lgsl -lgslcblas -lm
STDVER = c++11

FILES = src/fhp.cpp \
		src/init.cpp \
		src/utils.cpp 

all:
	$(CC) -o build/$(TARGET) $(FILES) -L$(LIBS) -I$(INCPATH)  $(FLAGS) -std=$(STDVER)

clean:
	rm -rf *.o