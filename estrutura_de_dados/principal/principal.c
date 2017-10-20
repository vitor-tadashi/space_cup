#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct equipe_inscricao{
	
	struct equipe_inscricao *prox ;
	char equipe_nome[20];
};

typedef struct equipe_inscricao* tipopilha;


int POP (tipopilha *topo, char *nome)
{
tipopilha aux;
aux = *topo;
if (!IsPilhaEmpty(*topo)) {
	  strcpy(nome, aux->equipe_nome);
     *topo=aux->prox;
     free(aux);
     return(1);
     }
else {
       printf("pilha vazia \n ");
       return(0);
       }
}
int IsPilhaEmpty(tipopilha * topo){
	if(topo == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void INIT(tipopilha *topo)
{
*topo = NULL;
}
void PUSH (tipopilha *topo, char *nome, int elem)
{
tipopilha novo;
novo = (tipopilha) malloc (sizeof(struct equipe_inscricao));
if (novo != NULL)
	{
	strcpy(novo->equipe_nome, nome);
	novo->prox=*topo;
	*topo = novo;
	}
else
	printf("pilha cheia \n");
}


struct competicao{
	float distancia_alvo;
	float altitude;
	struct competicao *prox;
	char equipe_nome[20];
};

typedef struct competicao* tipofila;

void ENQUEUE(tipofila *inicio, tipofila *fim, char *nome,float distancia ,float altitude_f)
{
tipofila novo;
novo=(tipofila) malloc (sizeof(struct competicao));
if (novo==NULL) 
	 printf("Fila Cheia \n");
else  {
	 strcpy(novo->equipe_nome, nome);
	 novo->distancia_alvo=distancia;
	 novo->altitude=altitude_f;
	 novo->prox=NULL;
	if (IsFilaEmpty(*inicio,*fim)){
	     *inicio = novo;
	     }
	else{
	     (*fim)->prox= novo;
	     }
        *fim=novo;
	}
}

int DEQUEUE(tipofila *inicio, tipofila *fim, char *nome, float *distancia, float *altitude_f){
	tipofila novo;
    tipofila aux=*inicio;
   	if (!IsFilaEmpty(*inicio,*fim)){
	   		strcpy(nome, (*inicio)->equipe_nome);
		    *distancia =(*inicio)->distancia_alvo;
		    *altitude_f=(*inicio)->altitude;
		    (*inicio)=(*inicio)->prox;
		    free(aux);
		    if(*inicio==NULL){
		    	*fim=NULL;
			}
			return 1;
	    }
	    
	else{
		return 0;
	    	
	    }
    
}
int IsFilaEmpty(tipofila inicio, tipofila fim){
	if(inicio == NULL && fim == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void initFila (tipofila *inicio,tipofila *fim)
{
*inicio=NULL;
*fim=NULL;

}


int main(){
	tipopilha topop;
	tipofila inicio,fim; 
	char nome[20],nome2[20];
	int componentes,tempo,loop=1,loop2=0,qtd=0,cont=0,cont2=0,nro_tentativas=1,resp2=1,compc; 
	float distancia_alvo,compa=0,compd=9999;
	//inicia a pilha
	 INIT(&topop);
	do{
		printf("Nome da equipe: \n");
		fflush(stdin);
	    gets(nome); 	    
	   
		
		//insere um grupo na pilha
		PUSH(&topop,nome,componentes);
		
		printf("deseja inserir mais algum grupo ? digite 1 para sim e 0 para nao \n");		
		scanf("%d",&loop);
		fflush(stdin);
		qtd++;
		
    } while(loop!=0&&loop==1);
    
    
     initFila(&inicio,&fim);
    for(cont=0;cont<qtd;cont++){
	    if(POP(&topop,nome)==1)
		{
		    printf("a equipe %s lancara o foguete\n", nome);
		}  		
			
		nro_tentativas++;
		printf("o lancamento da equipe %s teve sucesso ? digite 1 para sim e 0 para nao \n",nome);
		scanf("%d",&loop2);
		fflush(stdin);
	    if(loop2==1){
	    	printf("qual a tempo do foguete da equipe %s: \n",nome);
	    	scanf("%f",&tempo);
	    	fflush(stdin);
	    	printf("qual a distancia do foguete ate o alvo da equipe %s: \n",nome);
	    	scanf("%f",&distancia_alvo);
	    	fflush(stdin);
		}else{
			tempo=0;
			distancia_alvo=9999;
		}
	    ENQUEUE(&inicio,&fim, nome, distancia_alvo, tempo);
	    
	    
	}
		for(nro_tentativas=1;nro_tentativas<3;nro_tentativas++){
		
			for(cont=0;cont<qtd;cont++){		
				DEQUEUE(&inicio, &fim, nome, &distancia_alvo, &tempo);
				printf("a equipe %s lancara o foguete pela segunda vez\n", nome);
				
				printf("o lancamento da equipe %s teve sucesso ? digite 1 para sim e 0 para nao \n",nome);
				scanf("%d",&resp2);
				
				if(resp2==1){
					fflush(stdin);
					printf("a foguete chegou mais proximo do alvo nesse lancamento?digite 1 para sim e 0 para nao \n");
					scanf("%d",&loop);
					fflush(stdin);
					
				    if(loop==1){
				    	printf("qual a tempo de propulsão do foguete da equipe %s: \n",nome);
				    	scanf("%f",&tempo);
				    	fflush(stdin);
				    	printf("qual a distancia do foguete ate o alvo da equipe %s: \n",nome);
				    	scanf("%f",&distancia_alvo);
				    	fflush(stdin);
					}
					
			    }
			    ENQUEUE(&inicio,&fim, nome, distancia_alvo, tempo);
			}
		}
		for(cont=0;cont<qtd;cont++){
			
				DEQUEUE(&inicio, &fim, nome, &distancia_alvo, &tempo);
				
					if(cont==0){
						compa=tempo;
						compd=distancia_alvo;
				     	strcpy(nome2,nome);
					}
					if(compd==distancia_alvo){
						if(compa<tempo){

							compa=tempo;
							compd=distancia_alvo;
							strcpy(nome2,nome);
						}
					}
					if(compd>distancia_alvo){
						compa=tempo;
						compd=distancia_alvo;
						strcpy(nome2,nome);
				    }
				    
					ENQUEUE(&inicio,&fim, nome, distancia_alvo, tempo);
			
		}
		//mostra as equipes participantes e as tira da fila
			printf("o campeao e a equipe %s \n com a distancia de %.2f e a tempo %.2f\n",nome2,compc,compd,compa);
			printf("essas sao as equipes que participaram :\n ");
		for(cont=0;cont<qtd;cont++){
			DEQUEUE(&inicio, &fim, nome, &distancia_alvo, &tempo);
			printf("equipe %s com \n com a distancia de %.2f e a tempo %.2f\n ",nome,distancia_alvo,tempo);
		}
		
   }

