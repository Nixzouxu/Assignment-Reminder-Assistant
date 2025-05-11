CC = gcc
INCLUDES = -Iinclude
CFLAGS = -Wall -g
TARGET = ASISTEN PENGINGAT TUGAS
SRC = src/main.c src/task.c src/ui.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)