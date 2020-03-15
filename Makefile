CC = g++
DESTDIR = build
TARGET = $(DESTDIR)/sim
INCPATH = -I/home/izochor/Pobrane/gsl/include
LIBS = -L/home/izochor/Pobrane/gsl/lib
STDVER = c++11
FLAGS = -lgsl -lgslcblas -lm -std=$(STDVER)

SOURCES = src/init.cpp \
		  src/utils.cpp \
		  src/fhp.cpp \
		  src/main.cpp \
		  src/measurements.cpp

OBJ = init.o \
	  utils.o \
	  fhp.o	\
	  main.o \
	  measurements.o

OBJFILES:=$(SOURCES:.cpp=.o)
OBJFILES:=$(SOURCES: src=$(DESTDIR))


all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJFILES) $(LIBS) $(INCPATH) $(FLAGS)

init.o:
	$(CC) src/init.cpp -c -o $(DESTDIR)/init.o $(LIBS) $(INCPATH) $(FLAGS)

utils.o:
	$(CC) src/utils.cpp -c -o $(DESTDIR)/utils.o $(LIBS) $(INCPATH) $(FLAGS)

fhp.o:
	$(CC) src/fhp.cpp -c -o $(DESTDIR)/fhp.o $(LIBS) $(INCPATH) $(FLAGS)

main.o:
	$(CC) src/main.cpp -c -o $(DESTDIR)/main.o $(LIBS) $(INCPATH) $(FLAGS)

measurements.o:
	$(CC) src/measurements.cpp -c -o $(DESTDIR)/measurements.o $(LIBS) $(INCPATH) $(FLAGS)

clean:
	rm -rf $(DESTDIR)/*.o $(TARGET)