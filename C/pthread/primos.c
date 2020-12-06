#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct estrutura_verificar_primo
{
    long long verificar_num;
    int res;
};

/* 
 * função que verifica se o número é primo ou não
 * "retorna" 1 para primo e 0 para não primo
 */
void* verificar_primo(void* num_in)
{
    /********** pré-configurações ***************/
    // criando ponteiro para estrutura_verificar_primo para facilitar a manipular os dados de entrada e saida 
    struct estrutura_verificar_primo *nums = (struct estrutura_verificar_primo*)num_in;
    // criando uma variável para facilitar a manipular a entrada
    long long num = nums->verificar_num;

    /********** verificação do número de entrada ***************/
    int num_divisores = 0;
    // verificação antecipada para 1
    if(num == 1)
    {
        nums->res = 0;
        pthread_exit(NULL);
    }
    // verificação para 2
    if(num == 2)
    {
        nums->res = 1;
        pthread_exit(NULL);
    }
    // verificação para pares maiores que 2
    if((num % 2) == 0)
    {
        nums->res = 0;
        pthread_exit(NULL);
    }
    // verificação para ímpares maiores que 1
    for(int i = 3; i <= num; i+=2)
    {
        if((num % i) == 0)
        {
            num_divisores++;
        }
    }

    if(num_divisores == 2)
    {
        nums->res = 0;
    }
    else 
    {
        nums->res = 1;
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Uso: %s <num1> <num2> .. <num-n>\n", argv[0]);
        exit(-1);
    }

    int num_args = argc - 1;
    struct estrutura_verificar_primo params[num_args];
    pthread_t threads[num_args];
    
    /*************** criando threads *******************/
    for(int i = 0; i < num_args; i++)
    {
        params[i].verificar_num = atoll(argv[i+1]);
        pthread_create(&threads[i], NULL, verificar_primo, &params[i]);
    }
    
    /********* esperando as threads terminarem ************/
    for(int i = 0; i < num_args; i++)
    {
        pthread_join(threads[i], NULL);
    }

    /******** printando resultados: se o número é primo ou não ***********/
    for(int i = 0; i < num_args; i++)
    {
        if(params[i].res == 1)
        {
            printf("Thread %i: O numero %lld eh primo\n", i, params[i].verificar_num);
        }
        else
        {
            printf("Thread %i: O numero %lld nao eh primo\n", i, params[i].verificar_num);
        }
        
    }
}