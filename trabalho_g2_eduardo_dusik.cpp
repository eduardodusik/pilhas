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

int main () {
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
