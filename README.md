# Lista de Contatos em C

Um pequeno sistema de lista de contatos desenvolvido em **C**, que permite:

- Inserir novos contatos (nome e telefone)
- Listar todos os contatos cadastrados
- Buscar um contato por nome
- Remover contatos
- Utiliza **alocação dinâmica de memória** (`malloc`/`realloc`) para armazenar os contatos

---

## Funcionalidades

1. **Inserir contato**
   - Aceita nomes com espaços
   - Aceita números de telefone de até 19 caracteres
   - Salva dinamicamente no array de contatos

2. **Listar contatos**
   - Mostra todos os contatos cadastrados em uma lista numerada

3. **Buscar contato**
   - Pesquisa pelo nome completo
   - Retorna o contato encontrado com nome e telefone

4. **Remover contato**
   - Remove o contato pelo nome
   - Reorganiza a lista e libera a memória corretamente

---

## Como compilar

Se você estiver usando **Linux** ou **macOS**, pode compilar com `gcc`:

```bash
gcc -Wall -Wextra -std=c11 agenda.c -o agenda
