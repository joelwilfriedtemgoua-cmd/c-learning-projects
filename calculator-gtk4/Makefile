CC = gcc
CFLAGS = `pkg-config --cflags gtk4` -Wall -Wextra -std=c99
LIBS = `pkg-config --libs gtk4`
TARGET = calculatrice

SOURCES = premiere_fenetre.c addition.c soustraction.c multiplication.c division.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean run help

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

help:
	@echo "Available targets:"
	@echo "  make          - Compile the calculator"
	@echo "  make run      - Compile and run"
	@echo "  make clean    - Remove compiled files"
	@echo "  make help     - Show this help"

# Dependencies
premiere_fenetre.o: premiere_fenetre.c operations.h
addition.o: addition.c operations.h
soustraction.o: soustraction.c operations.h
multiplication.o: multiplication.c operations.h
division.o: division.c operations.h
