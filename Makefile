CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/countnames.c
TARGET = countnames

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)