#include <stdio.h>

void base(){
          printf("   ___              _      _   _         \n |  _ \\   ___ _   _| | ___| |_| |_  ___   \n | |_) | / _ \| | | | |/ _ \\ __| __|/ _ \\ \n |  _  |( (_)| |_| | |  __/ |_| |_|  __/ \n |_|  \\_\\ \___/\__,__|_|\____|\\__|\\__|\\___| \n                                         \n");
}

int main(){  
     menu();
     return 0;
}

void menu(){
	base();
    printf("               Benvenuto.\n\n\n");
    printf("\t1: Gioca\n\t2: Crediti\n\t3: Esci\n\n");
	gioca();
	crediti();
	esci();
}

int gioca() {
	int i,numgiocatori; // "i" è un contatore, "numgiocatori" è una variabile che contiene il numero di giocatori
	char risposta; // "risposta" contiene la risposta del giocatore , s S o n N .
	
	printf("\n Quanti giocatori ?\n");
	scanf("%d",&numgiocatori);
        
	for(i=0;i<numgiocatori;i++){ //tramite questo ciclo chiedo all'utente il numero di giocatori e per ogni giocatore voglio sapere se ha o no un profilo già creato
		printf("\n Hai un profilo? (S se hai un profilo , N se devi crearne uno) \n");
		scanf("%c",&risposta);
		if(risposta=='s' || risposta='S')accedi_profilo();
		else crea_profilo();
	}
	return 0; /*se decide di tornare indietro*/
}


int crediti() { //Stampa i crediti con i nomi dei realizzatori
	printf("Roulette\n\nProgetto realizzato da:\nConti Francesco\nDell'aguzzo Paolo\nProverbio Michele\n\nAnno accademico 2011/12");
}

int esci() { //funzione che viene richiamata ogni volta che l'utente vuole uscire dal gioco
	char risp;
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
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);// Selezionoil colore del testo, in questo caso verde
    printf("\n Inserisci il Nome \n");
    scanf("\n %s",nome);

    do {//verifico che il nome non susperi i 20 caratteri
		if(numcaratteri>21){
			printf("\n Il nome deve avere massimo 20 caratteri \n");
			printf("\n Inserisci nuovamente il nome\n");
			scanf("\n %s",nome);
			numcaratteri=strlen(nome);
		}
    } while(numcaratteri>21);    
    punt=fopen("accesso.txt","a+");//Apro il File e con "a+" lo rendo di scrittura e lettura creandolo nel caso non esista già
    fclose(punt);
    punt=fopen("accesso.txt","r");// apro il file in sola lettura
    for(i=0;i!=30;i++){
        fscanf(punt,"%s",controllo[i]);//trasferisco il contenuto del file nella matrice " controllo "
    }  
    fclose(punt);//chiudo il file
    for(i=0;i!=30;i++){
        if(!strcmp(nome,controllo[i])){//comparo le due stringhe e vedo se il nome è già presente o meno
            printf("\n Il nome inserito è già esistente \n");
            return 0;
        }
    }  
    punt=fopen("accesso.txt","a+");//Apro il File e con "a+" lo rendo di scrittura e lettura creandolo nel caso non esista già
    if(*punt==NULL) printf("\n Impossibile aprire il File \n");//controllo se il valore restituito al puntatore è NULL e se è NULL vuol dire che non è stato possibile aprire il file
    fprintf(punt,nome);//mando il contenuto di nome nel file
    fprintf(punt," - 200.000");// salvo anche affianco al nome nel file il suo credito 
    fprintf(punt,"\n");//a fine del nome faccio in modo che si vada a capo
    k= (int)fclose("accesso.txt");//chiudo il file salvando in modo permanente il contenuto
    if(k==EOF)printf("\n Impossibile salvare i dati \n");//verifico se è stato possibile chiuderlo
    printf("\n Il tuo credito iniziale è di 200 000 fish \n"); 
                              
    return 0; /*se decide di tornare indietro*/
}


void accedi_profilo() {
	menu_giochi();
}

void menu_giochi(){  
	base(); //richiama ogni volta lo screen roulette
	printf("                Giochi.\n\n\n");
	printf("\t1: Roulette Francese\n\t2: Roulette Americana\n\t3: Statistiche\n\t4: Minigiochi\n\t5: Torna\n\n");
	roulette_fra();
	roulette_usa();
	statistiche();
	minigame();
	return 0;
}

int roulette_fra() {
	regole(); //passa come argomento che tipo di gioco è
	inizia_fra(); //passa come argomento che tipo di gioco è
}

int roulette_usa() {
	regole(); //passa come argomento che tipo di gioco è
	inizia_usa(); //passa come argomento che tipo di gioco è
}

int minigame() {
	regole(); //passa come argomento che tipo di gioco è
	inizia_rus(); //passa come argomento che tipo di gioco è
}

int statistiche() {
	vedi();
	azzera();
}

int vedi() {
	
}

int azzera() {
	
}

int regole() {
	
}

int inizia_fra() {
	locale_fra();
	online_fra();
}

int inizia_usa() {
	locale_usa();
	online_usa();
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

