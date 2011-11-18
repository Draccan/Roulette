#include <stdio.h>

#ifdef WIN32 
	#include "win.h"
#endif
#ifndef WIN32
	#include "unix.h"
#endif

void base(){
	printf("   ___              _      _   _         \n |  _ \\   ___ _   _| | ___| |_| |_  ___   \n | |_) | / _ \| | | | |/ _ \\ __| __|/ _ \\ \n |  _  |( (_)| |_| | |  __/ |_| |_|  __/ \n |_|  \\_\\ \___/\__,__|_|\____|\\__|\\__|\\___| \n                                         \n");
}

int main (){  
	while (menu());
	return 0;
}

int menu(){
	CLS; //pulisce lo schermo. la macro si trova in linux.h e win.h
	base();
	int scelta = 0;
	char input;
	
	do {
		printf("               Benvenuto.\n\n\n");
		printf("\tGioca"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tCrediti"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tEsci"); if(scelta==2) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 2; break;
			case 66: if(scelta != 2) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: gioca(); break;
		case 1: crediti(); break;
		case 2: esci(); break;
	}
	return 1;
}

int gioca() {
	int i,numgiocatori; // "i" è un contatore, "numgiocatori" è una variabile che contiene il numero di giocatori
	char risposta; // "risposta" contiene la risposta del giocatore , s S o n N .
	
	CLS;
	printf("\n Quanti giocatori ?\n");
	scanf("%d",&numgiocatori);
        
	for(i=0;i<numgiocatori;i++){ //tramite questo ciclo chiedo all'utente il numero di giocatori e per ogni giocatore voglio sapere se ha o no un profilo già creato
		CLS;
		printf("\n Hai un profilo? (S se hai un profilo , N se devi crearne uno) \n");
		scanf("%c",&risposta);
		if(risposta=='s' || risposta='S')accedi_profilo();
		else crea_profilo();
	}
	return 0; /*se decide di tornare indietro*/
}


int crediti() { //Stampa i crediti con i nomi dei realizzatori
	CLS;
	printf("Roulette\n\nProgetto realizzato da:\nConti Francesco\nDell'aguzzo Paolo\nProverbio Michele\n\nAnno accademico 2011/12\n");
	printf("\nPremere un tasto per tornare al menu'...");
	getch();
}

int esci() { //funzione che viene richiamata ogni volta che l'utente vuole uscire dal gioco
	char risp;
	CLS;
	printf("Sei sicuro di voler uscire? (y/n)\n");
	scanf("%c", &risp);
	do {
		if (risp == "y" || risp == "Y") quit(0);
		else if (risp == "n" || risp == "N") return 0; //ritorna alla funzione che ha richiamato esci()
		printf("risposta non consentita!\n");
	} while(1);
}

int crea_profilo() {
    char nome[20],risposta;
    char controllo[30][30];//mi servirà per vedere se il nome è già stato scelto
    FILE *punt;//è un puntatore a FILE , ovvero punta al file accesso.txt
    int numcaratteri,k,i;
    
    CLS;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);// Selezionoil colore del testo, in questo caso verde
    printf("\n Inserisci il Nome \n");
    scanf("\n %s",nome);

	do { //verifico che il nome non susperi i 20 caratteri
		if (numcaratteri>21) {
			printf("\n Il nome deve avere massimo 20 caratteri \n");
			printf("\n Inserisci nuovamente il nome\n");
			scanf("\n %s", nome);
			numcaratteri = strlen(nome);
		}
    } while (numcaratteri > 21);    
    punt = fopen("accesso.txt", "a+"); //Apro il File e con "a+" lo rendo di scrittura e lettura creandolo nel caso non esista già
    fclose(punt);
    punt = fopen("accesso.txt", "r"); // apro il file in sola lettura
    for(i=0; i!=30; i++) {
        fscanf(punt, "%s", controllo[i]); //trasferisco il contenuto del file nella matrice " controllo "
    }  
    fclose(punt); //chiudo il file
    for(i=0; i!=30; i++){
        if(!strstr(nome,controllo[i])) { //comparo le due stringhe e vedo se il nome è già presente o meno
            printf("\n Il nome inserito è già esistente \n");
            return 0;
        }
    }  
    punt = fopen("accesso.txt", "a+"); //Apro il File e con "a+" lo rendo di scrittura e lettura creandolo nel caso non esista già
    if(punt == NULL) printf("\n Impossibile aprire il File \n"); //controllo se il valore restituito al puntatore è NULL e se è NULL vuol dire che non è stato possibile aprire il file
    fprintf(punt, nome); //mando il contenuto di nome nel file
    fprintf(punt, " - 200.000"); // salvo anche affianco al nome nel file il suo credito 
    fprintf(punt, "\n"); //a fine del nome faccio in modo che si vada a capo
    k = (int)fclose("accesso.txt"); //chiudo il file salvando in modo permanente il contenuto
    if(k == EOF) printf("\n Impossibile salvare i dati \n"); //verifico se è stato possibile chiuderlo
    printf("\n Il tuo credito iniziale è di 200 000 fish \n"); 
                              
    return 0; /*se decide di tornare indietro*/
}


void accedi_profilo() {
	menu_giochi();
}

int menu_giochi(){	
	int scelta = 0;
	char input;
	
	do {
		CLS;  
		base(); //richiama ogni volta lo screen roulette
		printf("               Giochi.\n\n\n");
		printf("\tRoulette francese"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tRoulette americana"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tStatistiche"); if(scelta==2) printf("<-"); printf("\n");
		printf("\tMinigame"); if(scelta==3) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==4) printf("<-"); printf("\n");
		printf("\tEsci dal gioco"); if(scelta==5) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 5; break;
			case 66: if(scelta != 5) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: roulette_fra(); break;
		case 1: roulette_usa(); break;
		case 2: statistiche(); break;
		case 3: minigame(); break;
		case 4: return 0;
		case 5: esci(); break;
	}
	return 0;
}

int roulette_fra() {
	int scelta = 0;
	char input;
	
	do {
		CLS;
		base();
		printf("               Roulette Francese\n\n\n");
		printf("\tRegole"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tInizia il gioco"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==2) printf("<-"); printf("\n");
		printf("\tEsci dal gioco"); if(scelta==3) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 3; break;
			case 66: if(scelta != 3) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: regole(1); break; //passa come argomento che tipo di gioco è
		case 1: inizia_fra(); break;
		case 2: return 0;
		case 3: esci(); break;
	}
}

int roulette_usa() {
	int scelta = 0;
	char input;
	
	do {
		CLS;
		base();
		printf("               Roulette Americana\n\n\n");
		printf("\tRegole"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tInizia il gioco"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==2) printf("<-"); printf("\n");
		printf("\tEsci dal gioco"); if(scelta==3) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 3; break;
			case 66: if(scelta != 3) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: regole(1); break; //passa come argomento che tipo di gioco è
		case 1: inizia_usa(); break;
		case 2: return 0;
		case 3: esci(); break;
	}
}

int minigame() {
	int scelta = 0;
	char input;
	
	do {
		CLS;
		base();
		printf("               Roulette Russa\n\n\n");
		printf("\tRegole"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tInizia il gioco"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==2) printf("<-"); printf("\n");
		printf("\tEsci dal gioco"); if(scelta==3) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 3; break;
			case 66: if(scelta != 3) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: regole(1); break; //passa come argomento che tipo di gioco è
		case 1: inizia_rus(); break;
		case 2: return 0;
		case 3: esci(); break;
	}
}

int statistiche() {
	int scelta = 0;
	char input;
	
	do {
		CLS;
		base();
		printf("               Statistiche\n\n\n");
		printf("\tControlla le tue statistiche"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tAzzera le tue statistiche (il tuo credito rimane il medesimo)"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==2) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 2; break;
			case 66: if(scelta != 2) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: vedi(); break; 
		case 1: azzera(); break;
		case 2: return 0;
	}
}

int vedi() {
	
}

int azzera() {
	
}

int regole(int arg) {
	
}

int inizia_fra() {
	int scelta = 0;
	char input;
	
	do {
		CLS;
		base();
		printf("               Scegliere la modalità di gioco\n\n\n");
		printf("\tRGioca in locale"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tGioca in LAN"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==2) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 2; break;
			case 66: if(scelta != 2) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: locale_fra(); break; //passa come argomento che tipo di gioco è
		case 1: online_fra(); break;
		case 2: return 0;
	}
}

int inizia_usa() {
	int scelta = 0;
	char input;
	
	do {
		CLS;
		base();
		printf("               Scegliere la modalità di gioco\n\n\n");
		printf("\tRGioca in locale"); if(scelta==0) printf("<-"); printf("\n");
		printf("\tGioca in LAN"); if(scelta==1) printf("<-"); printf("\n");
		printf("\tTorna indietro"); if(scelta==2) printf("<-"); printf("\n");
		input = (int) getch();
		switch (input) {
			case 65: if(scelta != 0) scelta--; else scelta = 2; break;
			case 66: if(scelta != 2) scelta++; else scelta = 0; break;
			default: break;
		}
	} while(input != '\n');
    switch (scelta) {
		case 0: locale_usa(); break; //passa come argomento che tipo di gioco è
		case 1: online_usa(); break;
		case 2: return 0;
	}
}

int inizia_rus() {
	
}

int locale_fra() {
	
}

int locale_usa() {
	
}

int online_fra() {
	
}

int online_usa() {
	
}

