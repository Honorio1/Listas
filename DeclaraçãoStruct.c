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

Imprime o conteúdo de uma lista T sem cabeça
void Imprime (celula ∗T) {
	celula ∗p;
	for (p = T; p != NULL; p = p−>link){
		printf ("%d\n", p−>info);
	}
}

Imprime o conteúdo de uma lista T com cabeça
void Imprime (celula ∗T) {
	celula ∗p;
	for (p = T−>link; p != NULL; p = p−>link){
		printf ("%d\n", p−>info);
	}
}

Busca o elemento x em uma lista T com cabeça
celula ∗Busca (int x, celula ∗T) {
	celula ∗p;
	p = T−>link;
	while (p != NULL && p−>info != x){
		p = p−>link;
		return p;
	}
}

Remoção de uma célula apontada por p
void Remove (celula ∗p) {
	celula ∗lixo;
	lixo = p−>link;
	p−>link = lixo−>link;
	free (lixo);
}

Insere uma célula em uma lista entre a célula p e a seguinte
void Insere (int y, célula ∗p) {
	celula ∗nova;
	nova = malloc (sizeof (celula));
	nova−>info = y;
	nova−>link = p−>link;
	p−>link = nova;
}

Busca seguida de remoção em uma lista T com cabeça
void Busca_Remove (int x, celula ∗T) {
	celula ∗p, ∗q;
	p = T;
	q = T−>link;
	while (q != NULL && q−>info != x) {
		p = q;
		q = q−>link;
	}
	if (q != NULL) {
		p−>link = q−>link;
		free (q);
	}
}

Busca seguida de inserção em uma lista T com cabeça
void Busca_Insere (int y, int x, celula ∗T) {
	celula ∗p, ∗q, ∗nova;
	nova = malloc (sizeof (celula));
	nova−>info = y;
	p = T;
	q = T−>link;
	while (q != NULL && q−>info != x) {
		p = q;
		q = q−>link;
	}
	nova−>link = q;
	p−>link = nova;
}




Estrutura básica de uma lista duplamente encadeada:
typedef struct elem{
	int info ;
	struct elem ∗prox ;
	struct elem ∗ant ;
}celula;
