#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
	int chave;
	int dado;
};

//Busca do elemento x na lista L com n elementos:
int busca1(struct lista *L, int x, int n){
	int i=0;
	while(i <= n-1){	
		if(L[i].chave == x){
			return i;//chave encontrada
		}else
			i++;//pesquisa prossegue
	}
	return -1;
}

//Busca do elemento x na lista L, conhecendo sua chave:
int busca2(struct lista *L, int x, int n){
	int i=0;
	L[n].chave = x;
	while(L[i].chave != x){
		i++;
	}
	if(i != n){
		return i;
	}else
		return -1;
}

//Busca do elemento x na lista L ordenada, conhecendo sua chave;
int busca_binaria(struct lista *L, int x, int n){
	int inf = 0, sup = n-1, meio;
	
	while(inf <= sup){
		meio = (int)(inf + sup)/2;
		if(L[meio].chave == x){
			return meio;
		}else
		if(L[meio].chave < x){
			inf = meio+1;
		}else
			sup = meio-1;
	}
	return -1;
}

//Inserção de um nó na lista L não ordenada:
int insercao(struct lista *L, int x, int *n, int M, int novo_valor){
//M é o número máximo de elementos que a lista L pode armazenar	
	if(*n < M){
		if(busca2(L, x, *n) == -1){
			L[n].chave = x;
			L[n].dado = novo_valor;
			(*n)++;
		}else{
			printf("valor já existe na lista");
			return -1;
		}
	}else{
		printf("Overflow");//Número de elementos ultrapassou o tamanho da lista;
		return -1;
	}
}
	

