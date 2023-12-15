
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "tipi-moodle.h"



int main(){
	
	int mod=0;
	int matricola;
	char nome[80];
	char cognome[80];
	
	Lista archivio = makeLista();
	Elemento El=NULL;
	while(mod==0){
	do{
	printf("\n MENU SCELTA\n ");
	printf("1)Aggiunta di uno studente in testa alla lista\n"
		   "2)Rimozione di uno studente data la matricola\n"
		   "3)Ordinare l’archivio corrente in ordine di matricola crescente\n"
		   "4)Ricerca di uno studente data la matricola\n"
		   "5)Stampa del contenuto della lista\n"
		   "6)Fine lavoro\n");  
	
	scanf("%d", &mod);
}while (mod > 6 || mod < 1);
	
		
	
	
	 if(mod==1){
		printf("Aggiunta di uno studente\n");
		printf("inserisci il nome studente\n");
		scanf("%s", nome);
		printf("inserisci il cognome\n");
		scanf("%s", cognome);
		printf("inserisci la matricola\n");
		scanf("%d", &matricola);
	    El=creaElemento(cognome, nome, matricola);
		
		inserisci(El,&archivio);
		stampa(archivio);
		mod=0;
	}
		
	if(mod==2){
		printf("Rimozione di uno studente\n");
		printf("inserisci la matricola da rimovere\n");
		scanf("%d", &matricola);
		archivio=rimuoviEL(archivio, matricola);
		mod=0;
	}
		
	
	if(mod==3){
		printf("Ordinare l’archivio corrente in ordine di matricola crescente\n");
		archivio=ordinamento(archivio);
		mod=0;
	}
	
		if(mod==4){
		printf("Ricerca di uno studente data la matricola\n");
		printf("Inserisci la matricola dello studente\n");
		scanf("%d", &matricola);
		archivio=ordinamento(archivio);
		ricercaStudente(archivio, matricola);
		mod=0;
	}
	
	if(mod==5){
		printf("visualizzazione del contenuto del'archivio\n");
		stampa(archivio);
		mod=0;
	}
		
	if(mod==6){
	return 0;
	}
}
	
	return 0;
	
}
