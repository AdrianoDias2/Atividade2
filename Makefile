# Definindo o compilador
CC = gcc

# Definindo os flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
TARGET = main

# Lista de arquivos fonte
SRCS = main.c

# Verificação do sistema operacional
ifeq ($(OS),Windows_NT)
    RM = del
    EXE = .exe
else
    RM = rm -f
    EXE =
endif

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET)$(EXE) $(SRCS)

# Regra para limpar os arquivos gerados pela compilação
clean:
	$(RM) $(TARGET)$(EXE)

# Regra para rodar o executável
run: $(TARGET)
	./$(TARGET)$(EXE)

# Regra para depuração
debug: $(SRCS)
	$(CC) $(CFLAGS) -g -o $(TARGET)$(EXE) $(SRCS)
	gdb ./$(TARGET)$(EXE)
