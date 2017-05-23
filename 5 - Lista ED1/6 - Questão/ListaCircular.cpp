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
int tamanhoLista(Lista* li){
	if(li == NULL || (*li) == NULL){
		return 0;
	}
	
	int cont = 0;
	Elem* no = *li;
	do{
		cont++;
		no = no->prox;
	}while(no != (*li));
	return cont;
}

int listaVazia(Lista* li){
	if(li == NULL && (*li) == NULL){
		return 1;
	} else {
		return 0;
	}
}

int removeListaInicio(Lista* li){
	if(li == NULL){
		return 0;
	}
	if((*li) == NULL){
		return 0;
	}
	if((*li) == (*li)->prox){
		free(*li);
		*li = NULL;
		return 1;
	}
	
	Elem *atual = *li;
	while(atual->prox != (*li)){
		atual = atual->prox;
	}
	Elem *no = *li;
	int cpf = no->dados.cpf;
	atual->prox = no->prox;
	*li = no->prox;
	free(no);
	return cpf;
}

void imprimirTodosOsElementos(Lista* list){
	if(list == NULL || (*list) == NULL){
		return;
	}
	
	Elem* aux = *list;
	int i=0;
	
	do{
		printf("Cliente %d: %s\n",(i+1), aux->dados.nome);
		i++;
		aux = aux->prox;
		}while(aux != (*list));
	
	
}

// Métodos da lista circular

Lista* criarLista(){
	
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}

void deletarLista(Lista* li){
	if(li != NULL && (*li) != NULL){
		Elem *aux;
		Elem *no = *li;
		while((*li) != no->prox){
			aux = no;
			no = no->prox;
			free(aux);
		}
		free(no);
		free(li);
	}
}

int insereListaInicio(Lista* li, struct cliente c){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = c;
	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}else{
		Elem *aux = *li;
		while(aux->prox != (*li)){
			aux = aux->prox;
		}
		aux->prox = no;
		no->prox = *li;
		*li = no;
	}
	return 1;
}

int insereMeioLista(Lista* list, struct cliente c, int pos){

	if(list == NULL){
		return 0;
	}
	
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) {
		return 0;
	}
	no->dados = c;
	if(listaVazia(list)){
		*list = no;
		no->prox = no;
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

int insereFinalLista(Lista* li, struct cliente c){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = c;
	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}else{
		Elem *aux = *li;
		while(aux->prox != (*li)){
			aux= aux->prox;
		}
		aux->prox = no;
		no->prox = *li;
	}
	return 1;
}

int removeDaLista(Lista* li, int c){
	if(li == NULL){
		return 0;
	}
	if((*li) == NULL){
		return 0;
	}
	
	Elem *no= *li;
	int cpf = no->dados.cpf;

	if(no->dados.cpf == c){
		removeListaInicio(li);
	}
	Elem *ant = no;
	no = no->prox;
	while(no != (*li) && no->dados.cpf != c){
		ant = no;
		no = no->prox;
	}
	if(no == *li){
		return 0;
	}
	ant->prox = no->prox;
	free(no);
	return cpf;
}

int buscarLista(Lista* list, struct cliente c){
	if(list == NULL){
	 return -1;
	 }
	
	int cont = 0;
	Elem *no = *list;
	
	while((no->prox != *list) && no->dados.cpf != c.cpf){
		cont++;
		no = no->prox;
	}
	
	if(no == NULL){ return -1;
	} else{
		return cont;
	}
}

// 5 Lista: Antonio Honorato Moreira Guedes


int main(){
	
	struct cliente Beth = {"Beth" , 100};
	struct cliente Vanessa = {"Vanessa" , 101};
	struct cliente Beatriz = {"Beatriz" , 102};
	
	Lista* list = criarLista();
	
	//Inserir no Inicio
	insereListaInicio(list, Vanessa);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Inserir no Final
	insereFinalLista(list, Beth);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Inserir no Meio
	insereMeioLista(list, Beatriz, 1);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Remover Elemento
	int z =	removeDaLista(list, 100);
	printf("CPF da pessoa removida: %d \n", z);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Buscar
	int x = buscarLista(list, Beatriz);
	printf("Posicao: %d", x);
	printf("\n");
	
	return 0;

}
