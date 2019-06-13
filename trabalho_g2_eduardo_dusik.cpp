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

void maior_10(struct nodo **pilha1, struct nodo **pilha2, struct nodo **pilha3){
	struct nodo *aux1;
	aux1 = *pilha1;
	while(aux1){
		push(pilha3, aux1->dados);
		pop(&aux1);
	}

/*	while((*pilha1) != NULL){
		if((*pilha1)->dados >= 10 && (*pilha1) != NULL){
			push(pilha3, (*pilha1)->dados);
			pop(pilha1);
		}else if(*pilha1 != NULL){
			pop(pilha1);
		}
	}
	printf("cheguei a sair do laço");
	while(*pilha2 != NULL){
		printf("bah cheguei aqui tlgd");
		if((*pilha2)->dados >= 10 && *pilha2 != NULL){
			printf("entrei aqui 2");
			push(pilha3, (*pilha2)->dados);
			pop(pilha2);
		}else if(*pilha2 != NULL){
			pop(pilha2);
		}
	} */
	
}

int main () {
	struct nodo *pilha1, *pilha2, *pilha3;
	int valor=1;
	while(valor != 0){
		printf("Digite um valor para armazenar na pilha 1 e zero (0) para passar para pilha 2: ");
		scanf("%i", &valor);
		push(&pilha1, valor);
		if(valor == 0){
			valor  = 1;
			while(valor != 0){
				printf("Digite um valor para armazenar (pilha 2) e zero (0) para sair: ");
				scanf("%i", &valor);
				push(&pilha2, valor);
			}
		}
		
	
	}
	maior_10(&pilha1, &pilha2, &pilha3);
	mostrar_pilha(&pilha3);
}
