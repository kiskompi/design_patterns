CC=g++
CFLAGS=-I.
DEPS = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
CFLAGS=-c -Wall
LDFLAGS=
OBJECTS=$(DEPS:.cpp=.o)
EXECUTABLE=build/application.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)

