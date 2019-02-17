#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 3

int main(){
	char *str[tam];
	int i;
	
	for(i=0;i<tam;i++){
		if((str[i] = malloc(128)) == NULL){
			printf("Erro de alocação");
			exit(1);
		}
		gets(str[i]);
		puts(str[i]);
	}

	for(i=0;i<tam;i++){
		free(str[i]);
	}
	
	return 0;
}
