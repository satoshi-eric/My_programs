#include <stdio.h>
#define TRUE 1

void print_square(int square_size);

int main(int argc,char **argv) 
{
    int square_size;
    while(TRUE) // Loop infinito
    {
        printf("Insert the square_size of the square (negative to exit):\n");
        scanf("%d", &square_size);
        if(square_size < 0)
        {
            printf("Negative number typed\n");
            break;
        }
        else 
            print_square(square_size);
    }
    return 0;
}

/**
 * Função para printar o quadrado com *
 */ 
void print_square(int square_size)
{
    // Loop para printar as colunas
    for(int i = 1; i <= square_size; i++)
    {
        // Loop para printar as linhas
        for(int j = 1; j <= square_size; j++)
            
            if(i == 1 || i == square_size) // Printa o * somente se estiver na primeira ou na última posição das colunas
                printf("*");
            else if (j == 1 || j == square_size) // Printa o * somente se estiver na primeira e última posição das linhas
                printf("*"); 
            else // Printa a área vazia do quadrado
                printf(" ");
        printf("\n");
    }
}