#include <stdio.h>
#include <malloc.h>


struct nodo {
 int dados;
 struct nodo *proximo;
};

void push (struct nodo **topo, int valor){
	struct nodo *p;
	p = (nodo *)malloc(sizeof(struct nodo));
		p->dados = valor;
		p->proximo = *topo;
		*topo = p;
	
}

int pop (struct nodo **topo){
	int valor;
	struct nodo *p;

		valor = (*topo)->dados;
		p = *topo;
		*topo = p->proximo;
		free(p);
	
	
	return valor;
}

void mostrar_pilha(struct nodo **fila){
  struct nodo *aux;
  aux=*fila;
  
  while (aux != NULL)
  {
    printf("Valores-> %i\n",aux->dados);
    aux=aux->proximo;
  }
}


void retira_3(struct nodo **pilha1, int cont){
	struct nodo *aux1;
	aux1 = NULL;
	while(cont > 0){
		if((*pilha1)->dados % 3 ==0){
			pop(pilha1);
			cont--;
		}else if (cont != 0){
			push(&aux1, (*pilha1)->dados);
			pop(pilha1);
			cont--;
		}
	}
	*pilha1 = aux1;
}


void enfileirar (nodo **fila, int valor) {
	struct nodo *auxi;
	struct nodo *x = (nodo *)malloc(sizeof(struct nodo));
	x->dados = valor;
	x->proximo = NULL;
	
	if(*fila == NULL){
		*fila = x;
	}else {
		auxi = *fila;
		while (auxi->proximo != NULL){
			auxi = auxi->proximo;
		}
		auxi->proximo = x;
	}	
}

int desenfileirar (nodo **fila){
	int valor;
	struct nodo *aux;
	
	aux = *fila;
	valor = aux->dados;
	*fila = aux->proximo;
	free(aux);
	return valor;
}

void maior_10(struct nodo **fila1, struct nodo **fila2, struct nodo **fila3){
	struct nodo *aux1;
	struct nodo *aux2;
	
	aux1 = *fila1;
	aux2 = *fila2;
	
	while(aux1 != NULL){
		if(aux1->dados > 10){
			enfileirar(fila3, aux1->dados);
			aux1 = aux1->proximo;
		}else {
			aux1 = aux1->proximo;
		}
	}
	
	while(aux2 != NULL){
		if(aux2->dados > 10){
			enfileirar(fila3, aux2->dados);
			aux2 = aux2->proximo;
		}else {
			aux2 = aux2->proximo;
		}
	}
}

void filas (){
	struct nodo *fila1;
	struct nodo *fila2;
	struct nodo *fila3;
	int valor = 1;
	
	while(valor !=0){
		printf("Digite um valor para armazenar na fila 1 (0 para sair): ");
		scanf("%i", &valor);
		if(valor != 0){
			enfileirar(&fila1, valor);
		}
	}
	valor = 1;
	while(valor != 0){
		printf("Digite um valor para armazenar na fila 2 (0 para sair): ");
			scanf("%i", &valor);
		if(valor !=0){
			enfileirar(&fila2, valor);
		}
	} 
	mostrar_pilha(&fila3);
	
	
}

void pilhas () {
	struct nodo *pilha1;
	int valor=1;
	int cont = 0;
	
	while(valor != 0){
		printf("Digite um valor para armazenar na pilha 1 e zero (0): ");
		scanf("%i", &valor);
		if(valor !=0) {
			cont++;
			push(&pilha1, valor);
		}		
	
	}
	retira_3(&pilha1, cont);
	mostrar_pilha(&pilha1);	
}



int main () {
	int resposta = 1;
	while(resposta != 0){
		printf("Digite uma opcao:\n1 - Pilhas\n2 - Filas\n\nSua opcao: ");
		scanf("%i", &resposta);
		switch (resposta){
			case 1:
				pilhas();
				break;
			case 2:
				filas();
				break;
			case 0:
				printf("Voce escolheu sair :(");
				break;
			default:
				printf("Escolha uma opcao: ");
		}
	}
	
}
