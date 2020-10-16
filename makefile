CC=g++ 
CFLAGS=-c -Wall -std=c++98 -g
LDFLAGS=
SOURCES=test.cpp Card.cpp Node.h LinkedList.h Queue.h HandOfCards.cpp DeckOfCards.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=assignment2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
