#include <stdio.h>
#include <stdlib.h>

struct endereco{
	char nome[40];
	char rua[40];
	char cidade[40];
	char estado[2];
};

struct endereco *get_struct(void){
	struct endereco *p;
	
	if((p = malloc(sizeof(struct endereco))) == NULL){
		printf("Erro de alocação:");
		exit(1);
	}
	return p;
}
