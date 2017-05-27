#include <stdio.h>
#include <stdlib.h>

struct newNode{
	int dados;
	struct newNode *prox;
};

typedef struct newNode* Lista;		
typedef struct  newNode Elem;		

int remove_lista_inicio(Lista *li){
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
	atual->prox = no->prox;
	*li = no->prox;
	free(no);
	return 1;
}


int RemoverElementoLista(Lista*li, int c){
	if(li == NULL){
		return 0;
	}
	if((*li) == NULL){
		return 0;
	}
	Elem* no = *li;
	if(no->dados == c){										
		remove_lista_inicio(li);
		return 1;
	}
	Elem *ant = no;
	no = no->prox;
	while(no != (*li) && no->dados != c){					
		ant = no;
		no = no->prox;
	}
	if(no == *li){										
		return 0;
	}
	ant->prox = no->prox;
	free(no);
	return 1;
}


int InserirLista(Lista* li, int c){
	if(li == NULL){
		return 0;	
	}
	Elem* no = (Elem*) malloc(sizeof(Elem));
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
	}
	return 1;
}


Lista* Criar_lista_vazia(){
	Lista* li = (Lista*) malloc(sizeof(Lista));					
	if(li != NULL){
		*li = NULL;
	}
	return li;
}


void ImprimirLista(Lista* li){
	if(li == NULL || (*li) == NULL){
		return;
	}
	Elem* aux = *li;
	int i = 0;
	do{
		printf("Numero %d: %d\n", (i+1), aux->dados);
		i++;
		aux = aux->prox;
	} while(aux != (*li));
}


void Deletar_lista(Lista* li){
	if(li != NULL && (*li) != NULL){
		Elem *aux, *no = *li;							
		while((*li) != no->prox){					
			aux = no;								
			no = no->prox;
			free(aux);
		}
		free(no);
		free(li);
	}	
}

int tamanho_lista(Lista* li){
	if(li == NULL || (*li) == NULL){
		return 0;
	}
	int cont = 0;
	Elem* no = *li;
	do{							
		cont++;
		no = no->prox;
	} while(no != (*li));
	return cont;
}	



int main(){
	
	int cont = 0;
	int tam = 10;
	int numerosRestantes = tam;
	int i;
	int chave = 0;
	Lista* li = Criar_lista_vazia();

	printf("Inicio do Circulo \n");
	InserirLista(li,1);
	InserirLista(li,2);
	InserirLista(li,3);
	InserirLista(li,4);
	InserirLista(li,5);
	InserirLista(li,6);
	InserirLista(li,7);
	InserirLista(li,8);
	InserirLista(li,9);
	InserirLista(li,10);
	ImprimirLista(li);
	
	Elem* aux = *li;
	Elem* auxAnt = *li;
	Elem* auxAntRecover = *li;
	cont++;
	
	while(chave != 1){						
	for(i = 0; i<9; i++){					
		while(cont != 3){					
			auxAnt = aux;
			aux = aux->prox;
			cont++;
		}
		if(cont == 3){
			auxAnt = aux;
			auxAntRecover = aux;
			aux = aux->prox;
			cont = 1;
			RemoverElementoLista(li, auxAnt->dados);
			Elem* auxAnt = auxAntRecover;
			numerosRestantes--;
			printf("Retirada numero %d, tamanho do circulo : %d\n", (i+1), tamanho_lista(li));
			ImprimirLista(li);
		}
		if(numerosRestantes == 1){
			chave = 1;
		}
	}
}
	Elem* restou = *li;
	printf("Numero que restou: %d\n", restou->dados);
	
	
	Deletar_lista(li);
	
	system("pause");
	return 0;
}
