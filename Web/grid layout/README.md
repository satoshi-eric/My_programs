# CSS GRID

## GRID

- Bidimensional
- Divisão de toda a página em linhas e colunas
- Colocar elementos onde quiser nessa divisão

---

# GRID OU FLEXBOX
- Grid: duas dimensões (colunas e linhas)
- Flexbox: Uma dimensão (ou coluna ou linha)
- Um complementa o trabalho do outro
- verificar quais navegadores ainda não aceitam o grid

---

## PROPRIEDADES
Vamos separar em 2 grupos:
`container` e `item(s)`

### CONTAINER

- display: grid; inicia o container como um grid
- grid-template-columns; fatia as colunas 
- grid-template-rows; fatia as linhas
- grid-gap; espaçamentos
    - grid-row-gap
    - grid-column-gap
- grid-template-areas; delimita áreas

... e mais 4 propriedades e **alinhamento**

### ITEM(s)

- grid-column onde vai ficar o item na coluna
    - grid-column-start
    - grid-column-end
- grid-row onde vai ficar o item na linha
    - grid-row-start
    - gird-row-end
- grid-area

... e mais 2 propriedades de **alinhamento**