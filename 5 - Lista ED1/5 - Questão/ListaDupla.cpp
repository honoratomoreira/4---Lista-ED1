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
	struct elemento *ant;
};

typedef struct elemento* Lista;
typedef struct elemento Elem;

// Métodos de verificação


int tamanhoLista(Lista* li){
	if(li == NULL){
		return 0;
	}
	int cont = 0;
	Elem* no = *li;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

int listaVazia(Lista* li){
	if(li == NULL){
		return 1;
	}
	if(*li == NULL){
		return 1;
	}
	return 0;
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


// Métodos da Lista

Lista* criarListaVazia(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}

void deletarLista(Lista* li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
	 free(li);
	}
}

int inserirInicio(Lista* li, struct cliente c){
	if(li == NULL){
		return 0;
	}
	Elem* no = (Elem*) malloc(sizeof(Elem));
	no->dados = c;
	no->prox = (*li);
	no->ant = NULL;
	if(*li != NULL){
		(*li)->ant= no;
	}
	*li=no;
	return 1;

}

int inserirFinal(Lista* li, struct cliente c){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = c;
	no->prox = NULL;
	if((*li) == NULL){
		no->ant = NULL;
		*li = no;
	} else {
		Elem *aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
		no->ant = aux;
	}
	
}

int inserirMeio(Lista* list, struct cliente c, int pos){
	if(list == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) {
		return 0;
	}
	no->dados = c;
	if(listaVazia(list)){
	no->ant = NULL;
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
	no->ant = auxAnt;
	no->prox = auxPost;
	auxPost->ant = no;	
	}
	return 1;
}

int removerDaLista(Lista* list, int cpf){
	if(list == NULL){
		return 0;
	}
	
	Elem *ant = *list;
	Elem *no = *list;
	
	while(no != NULL && no->dados.cpf != cpf){
		ant = no;
		no = no->prox;
	}
	
	if(no == NULL){
	 return 0;
	 }
	
	if(no == *list){
		*list = no->prox;
	} else {
		ant->prox = no->prox;
		
		if(no->prox != NULL) {
			no->prox->ant = ant;
		}
		
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

// 5 Lista: Antonio Honorato Moreira Guedes


int main(){
	struct cliente Beth = {"Beth" , 100};
	struct cliente Vanessa = {"Vanessa" , 101};
	struct cliente Beatriz = {"Beatriz" , 102};
	
	Lista* list = criarListaVazia();
	
	//Inserir no Inicio
	inserirInicio(list, Vanessa);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Inserir no Final
	inserirFinal(list, Beth);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Inserir no Meio
	inserirMeio(list, Beatriz, 1);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Remover Elemento
	int z =	removerDaLista(list, 101);
	printf("CPF da pessoa removida: %d \n", z);
	imprimirTodosOsElementos(list);
	printf("\n");
	
	//Buscar
	int x = buscarLista(list, Beatriz);
	printf("Posicao: %d", x);
	printf("\n");
	
	return 0;
	
}
