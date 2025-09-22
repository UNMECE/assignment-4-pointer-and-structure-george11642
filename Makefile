CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main
SOURCES = main.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: clean
