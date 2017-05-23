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

struct fila{
	struct elemento *inicio;
	struct elemento *final;
};

typedef struct fila Fila;
typedef struct elemento Elem;

// Métodos de verificação

int tamanhoFila(Fila* fi){
	if(fi == NULL){
		return 0;
	}
	
	int contador = 0;
	
	Elem* no = fi->inicio;
	while(no != NULL){
		contador++;
		no = no->prox;
	}
	return contador;
}

int FilaVazia(Fila* fi){
	if(fi == NULL){
		return 1;
	}
	
	if(fi->inicio == NULL){
		return 1;
	}
	
	return 0;
}

void imprimirTodosOsElementos(Fila* fi){
	if(fi == NULL){
		return;
	}
	
	Elem* no = fi->inicio;
	int i=0;
	while(no != NULL){
		printf("Cliente %d: %s\n",(i+1), no->dados.nome);
		i++;
		no = no->prox;
	}
}

// Métodos da Pilha

Fila* criarFilaVazia(){
	Fila* fi = (Fila*) malloc(sizeof(Fila));
	if(fi != NULL){
		fi->final = NULL;
		fi->inicio = NULL;
	}	
}

void deletarFila(Fila* fi){
	if(fi != NULL){
		Elem* no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

int insereNaFila(Fila* fi, struct cliente c){
	if(fi == NULL){
		return 0;
	}
	
	Elem *no = (Elem*) malloc(sizeof(Elem));

	if(no == NULL){
		return 0;
	}
	
	no->dados = c;
	no->prox = NULL;
	if(fi->final == NULL){
		fi->inicio = no;
	}
	else{
		fi->final->prox = no;
	}
	fi->final = no;
	return 1;
}

int removeFila(Fila* fi){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){
		return 0;
	}
	Elem *no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	int cpf = no->dados.cpf;
	
	if(fi->inicio == NULL){
		fi->final = NULL;
	}
	free(no);
	return cpf;
}

// 5 Lista: Antonio Honorato Moreira Guedes


int main(){
	struct cliente Beth = {"Beth" , 100};
	struct cliente Vanessa = {"Vanessa" , 101};
	struct cliente Beatriz = {"Beatriz" , 102};
	
	Fila* fil = criarFilaVazia();
	
	//Inserir 
	insereNaFila(fil, Beth);
	insereNaFila(fil, Vanessa);
	insereNaFila(fil, Beatriz);
	imprimirTodosOsElementos(fil);
	printf("\n");
	
	//Remover Elemento
	removeFila(fil);
	imprimirTodosOsElementos(fil);
	printf("\n");
	
	//Deletar pilha
	deletarFila(fil);
	
	return 0;
}
