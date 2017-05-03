SHELL = /bin/sh

PROJECT  := key_access

# ------------------
# External programs
# ------------------
CC  := gcc
RM  := rm -rf

# --------------------
# Directories & Files
# --------------------
D_SRC    := ./src
FILES_C  := $(wildcard $(D_SRC)/*.c)
FILES_O  := $(FILES_C:.c=.o)

# ------------
# Flags 
# ------------
CFLAGS  := -Wall
LFLAGS  :=
LIBS := `pkg-config --libs allegro-5 allegro_font-5 allegro_image-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5`

# ------------
# Targets 
# ------------
default: $(PROJECT)

%.o: %.c
	$(CC) -c -I $(D_SRC) $(CFLAGS) $< -o $@

$(PROJECT): $(FILES_O)
	$(CC) -I $(D_SRC) $(LFLAGS) $(FILES_O) -o $@ $(LIBS) -lm

.phony:	clean
clean:
	-$(RM) $(FILES_O) $(PROJECT) 
