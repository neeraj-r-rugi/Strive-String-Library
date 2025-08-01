# Compiler and flags
CC      := gcc
CFLAGS  := -Iinclude

# Source and output
SRC     := src/strive.c src/strive_string.c src/strive_error.c demo/main.c
OUT_DIR := demo
OUT     := $(OUT_DIR)/test

# Detect OS (Windows_NT is set in Windows)
ifeq ($(OS),Windows_NT)
    EXE := .exe
    RM  := del /Q
    MKDIR := if not exist $(OUT_DIR) mkdir $(OUT_DIR)
    SEP := \\
else
    EXE :=
    RM  := rm -f
    MKDIR := mkdir -p $(OUT_DIR)
    SEP := /
endif

# Targets
all: $(OUT)$(EXE)

$(OUT)$(EXE): $(SRC)
	@$(MKDIR)
	$(CC) $(SRC) -o $@ $(CFLAGS)

clean:
	$(RM) $(OUT)$(EXE)
