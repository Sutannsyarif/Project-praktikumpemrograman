CC = gcc
CFLAGS = -Wall -Wextra -MMD

SRC = Main.c auth.c barang.c member.c penjualan.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
HEADERS = auth.h barang.h member.h penjualan.h

TARGETS = sistem_kasir

all: $(TARGETS)

$(TARGETS): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP) $(TARGETS)

-include $(DEP)

.PHONY: all clean
