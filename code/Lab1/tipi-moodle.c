#include <stdio.h>
#include <stdlib.h>

#include "tipi-moodle.h"

void termina(char *messaggio){
	perror(messaggio);
	exit(EXIT_FAILURE);
}

Elemento creaElemento(char *cognome, char *nome , int matricola){
	Elemento El=malloc(sizeof(struct elemento));
	if(El==NULL)  termina("malloc fallità\n");
	strcpy(El->cognome,cognome);
		strcpy(El->nome,nome);
		El->matricola=matricola;
		return El;
}

 
/* *************************************************************************************** */
/* Implementazione funzioni delle liste                                                  */
/* *************************************************************************************** */

int emptyL(Lista l){
	return (l == NULL);
}

void inserisci(Elemento el,Lista  *l){
	Lista l1=NULL;
	l1 = (Lista) malloc(sizeof(Nodo_lista));
	if (l1 != NULL) {
	  l1 ->inf = el;
	  l1 ->next = (*l);
       (*l) = l1;
}
}

Elemento primo(Lista l){
	if (l != NULL) 
	return (l->inf);
	return NULL;
}


Elemento rimuovi(Lista *lptr){
	if ((* lptr) != NULL) {
	    Elemento el=primo(*lptr);
	    Lista l = (* lptr);
	    (* lptr) = (* lptr)->next;
	    free(l);
	    return el;
	    }
	    return NULL;
}

Lista makeLista(){ 
	return NULL;
}
Lista rimuoviEL(Lista l,int matricola){
	if(l==NULL) return l;
	if(primo(l)->matricola==matricola){
		 rimuovi(&l);
		 return l;}
	Lista p=l;
	while(p->next!=NULL){
		if(p->next->inf->matricola==matricola){
			Lista tmp=p->next;
			p->next=tmp->next;
			free(tmp);
			return l;
		}
		p=p->next;
	}
	return l;
}

int numEl(Lista l){
if(l==NULL) return 1;
else
return 1+ numEl(l->next);
}	
	
Lista ordinamento(Lista l){	
	Lista p=l; int conta=numEl(l);
	for(int i=0; i<conta ; i++){
		while(p->next!=NULL){
			if(p->inf->matricola > p->next->inf->matricola){
				Elemento tmp=p->inf;
				p->inf=p->next->inf;
				p->next->inf=tmp;
			}
			p=p->next;
		}
		p=l;
	}
	
	return l;			
}

void ricercaStudente(Lista l, int matricola){
	Lista p=l; int trovato=0; int conta = numEl(l);
	//if(p==NULL) return;
	
		for(int i=0; i<conta && (matricola >= p->inf->matricola); i++){
			if(matricola==p->inf->matricola) {
				trovato=1;
				printf("\n matricola:%d cognome:%s  nome:%s \n", p->inf->matricola, p->inf->cognome, p->inf->nome);}
	         p=p->next;
		 }
	 
	if(trovato==0) printf("studente non trovato\n");
	
}

void stampa(Lista lista){
	Lista l=lista;
	if(l==NULL) return;
	else{
		printf("\n matricola:%d cognome:%s  nome:%s \n", l->inf->matricola, l->inf->cognome, l->inf->nome);
		return stampa(l->next);
	}
}
/* *************************************************************************************** */
/* Implementazione funzioni delle pile                                                  */
/* *************************************************************************************** */

int emptyP(Pila p){
	return emptyL(p);
}

void push(Elemento el,Pila *p){
	inserisci(el, p);
}

Elemento pop(Pila *p){
	return rimuovi(p);
}

Elemento top(Pila p){
	return primo(p);
}

Pila makePila(){
	return makeLista();
}

/* *************************************************************************************** */
/* Implementazione funzioni delle code                                                  */
/* *************************************************************************************** */


int emptyC(Coda c){
	return emptyL(c.primo);
}

void enqueue(Elemento el,Coda *c){
	Lista l=NULL;
	inserisci(el, &l);
	if(emptyC(*c))
	{
		(*c).primo = l;
		(*c).ultimo = l;
		
	} else {
		(*c).ultimo->next = l;
		(*c).ultimo = l;
	}
}

Elemento dequeue(Coda *c){
	return rimuovi(&((*c).primo));
} 

Elemento first(Coda c){
	return primo(c.primo);
}

Coda makeCoda(){
	Coda c;
	c.primo =c.ultimo = NULL;
	return c;
}
