
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void termina(char *messaggio);

typedef struct elemento {
char cognome[80];
char nome[80];
int matricola;
} *Elemento;

//typedef int Elemento;
Elemento creaElemento(char *cognome, char *nome , int matricola);


/* *************************************************************************************** */
/* Definizione del tipo lista i cui elementi sono di tipo Elemento (per il momento int)
 * con le operazioni di inserzione in testa, estrazione dalla testa,  accesso all'emento 
 * in testa (primo),  costruzione della lista vuota (makeLista) e test se vuota (emptyL)     */
/* *************************************************************************************** */


struct Nodo_lista {
    Elemento    inf;
    struct Nodo_lista *next;
} Nodo_lista;

typedef struct Nodo_lista *Lista ;

int emptyL(Lista);
void inserisci(Elemento,Lista*);
Elemento rimuovi(Lista*);
Elemento primo(Lista);
Lista makeLista();
Lista rimuoviEL(Lista,int);
Lista ordinamento(Lista);
void ricercaStudente(Lista, int);
void stampa(Lista);
/* *************************************************************************************** */
/* Definizione del tipo Pila con le operazioni pop push top test se vuota (emptyP) e
 * costruzione della pila vuota (makePila) implementato con una lista                      */
/* *************************************************************************************** */

typedef Lista Pila;

int emptyP(Pila);
void push(Elemento,Pila*);
Elemento pop(Pila*);
Elemento top(Pila);
Pila makePila();

/* *************************************************************************************** */
/* Definizione del tipo Coda con le operazioni enqueue dequeue first test se vuota (emptyC)
 * costruzione dalla coda vuota (makeCoda) implementato con una struttura contenente
 * una lista (cont) e puntatori al primo e ultimo elemento  (primo, ultimo)                  */
/* *************************************************************************************** */

struct coda {
	Lista primo;
	Lista ultimo; 
} coda;

typedef struct coda Coda ;

int emptyC(Coda);

void enqueue(Elemento,Coda*);

Elemento dequeue(Coda*);

Elemento first(Coda);

Coda makeCoda();
