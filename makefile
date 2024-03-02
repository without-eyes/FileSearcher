CC = g++
CFLAGS = -c -Wall
SOURCES = src/FileSearcher.cpp src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARY = libfilesearch.a
EXECUTABLE  = FileSearcher

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(LIBRARY)
	$(CC) $(OBJECTS) $(LIBRARY) -o $@

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(LIBRARY) $(EXECUTABLE)
