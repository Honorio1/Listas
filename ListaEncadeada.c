https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html


A estrutura básica definida abaixo também pode ser definida em 2
passos.
Estrutura básica:
typedef struct elem{
	int info ;
	struct elem ∗link ;
} celula;

Estrutura básica definida em 2 passos:
struct elem{
	int info ;
	struct elem ∗link ;
};
typedef struct elem celula;





Definição de uma célula e de um ponteiro para célula.
typedef struct elem celula; //celula é um novo tipo de dado
celula c; //criou uma celula
celula ∗p; //criou um ponteiro para celula

Informação da célula:
c.info;
p−>info;
Endereço da célula seguinte:
c.link;
p−>link;



Criação de uma lista vazia sem cabeça
celula ∗T;
T = NULL;

Criação de uma lista vazia com cabeça
celula cabeca;
celula ∗T;
cabeca−>link = NULL;
T = &cabeca;

Outra forma de criar uma lista vazia com cabeça
celula ∗T;
T = malloc (sizeof(celula));
T−>link = NULL;
__________________________________________________________________
struct registro{
	int objeto1 ;
	struct registro ∗prox ;
};
typedef struct registro celula;

Imprime o conteúdo de uma lista T sem cabeça##########
void Imprime (celula ∗T) {
	celula ∗p;
	for (p = T; p != NULL; p = p−>prox){
		printf ("%d\n", p−>objeto1);//
	}
}
/*VERSÃO EQUIVALENTE RECURSIVA:
void imprime (celula *le) {
   if (le != NULL) {
      printf ("%d\n", le->conteudo);
      imprime (le->prox);
   }
}
*/

Imprime o conteúdo de uma lista T com cabeça
void Imprime (celula ∗T) {
	celula ∗p;
	for (p = T−>prox; p != NULL; p = p−>prox){
		printf ("%d\n", p−>objeto1);
	}
}

Insere uma célula em uma lista entre a célula T e a seguinte
void Insere (int objeto1, célula ∗T) {
	celula ∗nova;
	nova = malloc (sizeof (celula));
	
	nova−>objeto1 = objeto1;
	
	nova−>prox = T−>prox;
	T−>prox = nova;
}

Remoção de uma célula apontada por T
void Remove (celula ∗T) {
	celula ∗lixo;
	lixo = T−>prox;
	T−>prox = lixo−>prox;
	free (lixo);
}

Busca o elemento wanted em uma lista T com cabeça
celula ∗Busca (int wanted, celula ∗T) {
	//x é do tipo do objeto procurado, que se encontra no registro(struct);
	celula ∗p;
	p = T−>prox;
	while (p != NULL && p−>objeto1 != wanted){
		p = p−>prox;
		return p;
	}
}



Busca seguida de remoção em uma lista T com cabeça
void Busca_Remove (int wanted, celula ∗T) {
	celula ∗p, ∗q;
	p = T;
	q = T−>link;
	while (q != NULL && q−>objeto1 != wanted) {
		p = q;
		q = q−>link;
	}
	if (q != NULL) {
		p−>link = q−>link;
		free (q);
	}
}

Busca seguida de inserção em uma lista T com cabeça
void Busca_Insere (int x, int wanted, celula ∗T) {
	celula ∗p, ∗q, ∗nova;
	nova = malloc (sizeof (celula));
	nova−>objeto = x;
	p = T;
	q = T−>prox;
	while (q != NULL && q−>objeto != wanted) {
		p = q;
		q = q−>prox;
	}
	nova−>prox = q;
	p−>prox = nova;
}




Estrutura básica de uma lista duplamente encadeada:
typedef struct elem{
	int info ;
	struct elem ∗prox ;
	struct elem ∗ant ;
}celula;
