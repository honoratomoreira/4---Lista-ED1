#include <stdio.h>
#include <stdlib.h>

// 5 Lista: Antonio Honorato Moreira Guedes

struct cliente{
	char nome[30];
	int cpf;
};

typedef struct cliente Cliente;

struct elemento{
	struct cliente dados;
	struct elemento *prox;
};

typedef struct elemento* Lista;
typedef struct elemento Elem;

// Métodos de verificação

int listaVazia(Lista* list){
	
	if(list == NULL){
		return 1;
	}
	
	if(*list == NULL){
		return 1;
	}
	
	return 0;
}

int tamanhoLista(Lista* list){
	if(list == NULL){ return 0;	}
	int cont = 0;
	Elem* no = *list;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

// Métodos da lista

Lista* criarListaVazia(){
	Lista* list = (Lista*) malloc(sizeof(Lista));
	
	if (list != NULL){
		*list = NULL;
	}
	
	return list;
}

void deletarLista(Lista* list){
	if(list != NULL){
		Elem* no;
		while((*list) != NULL){
			no = *list;
			*list = (*list)->prox;
			free(no);
		}
	free(list);
	}
}

int inserirListaInicio(Lista* list, struct cliente c){
	if(list == NULL){
		return 0;
	}
	
	Elem* no = (Elem*) malloc(sizeof(Elem));
	
	if(no == NULL){
		return 0;
	}
	
	no->dados = c;
	no->prox = (*list);
	*list = no;
	
	return 1;
}

int inserirListaFinal(Lista* list, struct cliente c){
	
	if(list == NULL) {return 0; }
	
	Elem *no = (Elem*) malloc(sizeof(Elem));

	if(no == NULL){return 0;}
	
	no->dados = c;
	no->prox = NULL;
	
	if ((*list) == NULL){ 
	*list == no;
	} else {
		Elem *aux = *list;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}
	
	return 1;
}

int inserirListaMeio(Lista* list, struct cliente c, int pos){

	if(list == NULL){
		return 0;
	}
	
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) {
		return 0;
	}
	no->dados = c;
	if(listaVazia(list)){
			no->prox = (*list);
		*list = no;
		return 1;
	}else{
	int cont1 = 0;
	int cont2 = 0;
	Elem* auxAnt = *list;
	Elem* auxPost = *list;	
	while(cont1 != (pos-1)){
		auxAnt = auxAnt->prox;
		cont1++;
	}
	while(cont2 != (pos)){
		auxPost	= auxPost->prox;
		cont2++;
	}
	auxAnt->prox = no;
	no->prox = auxPost;	
	}
	return 1;
}
	

int removerDaLista(Lista* list, int cpf){
	if(list == NULL){
		return 0;
	}
	
	Elem *ant;
	Elem *no = *list;
	
	while(no != NULL && no->dados.cpf != cpf){
		ant = no;
		no = no->prox;
	}
	
	if(no == NULL){ return 0; }
	
	if(no == *list){
		*list = no->prox;
	} else {
		ant->prox = no->prox;
	}
	int cpfRe = no->dados.cpf;
	free(no);
	return cpfRe;
}

int buscarLista(Lista* list, struct cliente c){
	if(list == NULL){
	 return -1;
	 }
	
	int cont = 0;
	Elem *no = *list;
	
	while(no != NULL && no->dados.cpf != c.cpf){
		cont++;
		no = no->prox;
	}
	
	if(no == NULL){ return -1;
	} else{
		return cont;
	}
}


void imprimirTodosOsElementos(Lista* list){
	if(list == NULL){
		return;
	}
	
	Elem* aux = *list;
	int i=0;
	while(aux != NULL){
		printf("Cliente %d: %s\n",(i+1), aux->dados.nome);
		i++;
		aux = aux->prox;
	}
	
}

// 5 Lista: Antonio Honorato Moreira Guedes

int main(){
	struct cliente Beth = {"Beth" , 100};
	struct cliente Vanessa = {"Vanessa" , 101};
	struct cliente Beatriz = {"Beatriz" , 102};
	
	Lista* list = criarListaVazia();
	
	//Inserir no Inicio
	inserirListaInicio(list, Vanessa);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Inserir no Final
	inserirListaFinal(list, Beth);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Inserir no Meio
	inserirListaMeio(list, Beatriz, 1);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Remover Elemento
	int z =	removerDaLista(list, 100);
	printf("CPF da pessoa removida: %d \n", z);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Buscar
	int x = buscarLista(list, Beatriz);
	printf("Posicao: %d", x);
	printf("\n");
	
	return 0;
}
