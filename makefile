# Nome compilador
CC = gcc

#Flags compilação
CFLAGS = -Wall -Wextra -std=c11 -g

# Nome executavel final
TARGET = lista_contatos

# Arquivo fonte
SRCS = lista_contatos.c

# Regra padrão
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Limpar arquivos de compilação
clean:
	rm -f $(TARGET)