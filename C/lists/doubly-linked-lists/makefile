# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

# Arquivo de origem
SOURCE = main.c dlist.c

# Nome do executável
TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)
