#include <stdio.h>

int main(void) {
	int lados, i, j;
	while(0 == 0){
		printf("Digite o tamanho do lado do quadrado (negativo para sair): ");
		scanf("%d", &lados);
		if(lados >= 0){
			for(i = 1; i <= lados; i++){
				for(j = 1; j <= lados; j++){
		  			if(i == 1 || i == lados){
		  				printf("*");
					} else if (j == 1 || j == lados) {
		  				printf("*");
					} else {
						printf(" ");
					}			
				}
				printf("\n");
			}
		} else {
			return 0;
		}
	}
}



