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

typedef struct elemento* Pilha;
typedef struct elemento Elem;

// Métodos de verificação

int TamanhoDaPilha(Pilha* pilh){
	if(pilh == NULL){
		return 0;
	}
	
	int contador = 0;
	Elem* no = *pilh;
	while(no != NULL){
		contador++;
		no = no->prox;
	}
	return contador;
}

int PilhaVazia(Pilha* pilh){
	if(pilh == NULL){
		return 1;
	}
	
	if(*pilh == NULL){
		return 1;
	}
	
	return 0;
}

void imprimirTodosOsElementos(Pilha* pilh){
	if(pilh == NULL){
		return;
	}
	
	Elem* no = *pilh;
	int i=0;
	while(no != NULL){
		printf("Cliente %d: %s\n",(i+1), no->dados.nome);
		i++;
		no = no->prox;
	}
	
}

// Métodos da pilha

Pilha* criarPilhaVazia(){
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha));

	if(pi != NULL){
		*pi = NULL;
	}
	
}

void DeletarPilha(Pilha *pilh){
	if(pilh != NULL){
		Elem* no;
		while((*pilh) != NULL){
			no = *pilh;
			*pilh = (*pilh)->prox;
			free(no);
		}
		free(*pilh);
	}	
}

int inserirPilha(Pilha *pilh,struct cliente c){
	if(pilh == NULL){
		return 0;
	}
	
	Elem* no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	
	no->dados = c;
	no->prox = (*pilh);
	*pilh = no;
	return 1;
}

int removerPilha(Pilha* pilh){
	if(pilh == NULL){
		return 0;
	}
	
	if((*pilh) == NULL){
		return 0;
	}
	
	int valorRemovido;
	Elem *no = *pilh;
	*pilh = no->prox;
	valorRemovido = no->dados.cpf;
	free(no);
	return valorRemovido;
}

// 5 Lista: Antonio Honorato Moreira Guedes


int main(){
	struct cliente Beth = {"Beth" , 100};
	struct cliente Vanessa = {"Vanessa" , 101};
	struct cliente Beatriz = {"Beatriz" , 102};
	
	Pilha* pil = criarPilhaVazia();
	
	//Inserir 
	inserirPilha(pil, Beth);
	inserirPilha(pil, Vanessa);
	inserirPilha(pil, Beatriz);
	imprimirTodosOsElementos(pil);
	printf("\n");
	
	//Remover Elemento
	removerPilha(pil);
	imprimirTodosOsElementos(pil);
	printf("\n");
	
	//Deletar pilha
	DeletarPilha(pil);
	
	return 0;
}
