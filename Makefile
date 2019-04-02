PREFIX=/usr/local
TARGET=countdown
CFLAGS=-O2 -std=c11 -Werror -Wall -Wextra -pedantic

all: $(TARGET)

install: $(TARGET)
	cp countdown $(PREFIX)/bin/countdown

clean:
	rm $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c