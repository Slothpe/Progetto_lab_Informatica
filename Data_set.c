//
// Created by Perrulli Antonio on 14/04/25.
//
#include "Data_set.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

UTENTE Iscrizione_Utente(void)
    {
        UTENTE temp;
    
        printf("Inserisci il nome:\n");
        scanf(" %s", temp.nome);

        printf("Inserisci il cognome:\n");
        scanf(" %s", temp.cognome);

        printf("Inserisci la password (Lunghezza max 19, almeno una lettera e un carattere speciale)\n");
        fflush(stdin);

        do {
            scanf("%s",temp.password);

        }while(Controlla_Password(temp.password) == false);

        Scelta_Pasto(temp.pasti); //Funzione Scelta_Pasto

        temp.posto_preferito = Scelta_Posto_Preferito();

        Scelta_Classe_Preferita(temp.classe_preferita);

        printf("Inserisci il numero del passaporto (Max 9 caratteri): ");
        do {

            scanf("%s",temp.numero_documeto);
        }while(Controlla_Documento(temp.numero_documeto) == false);

        temp.numero_biglietti_acquistati = 0;

    return temp;
    }

void Scelta_Pasto(char pasto[])
    {
   
    int scelta = 0;
    bool scelta_corretta = false; //e falso finche l'utente non fa una scelta corretta
    char* opzioni_pasto [5] = {"Vegetariano","Vegano","Lattosio","Glutine","niente"}; //scelte effetuabili dal utente

    printf("Inserisci una preferenza sul cibo:\n");
    while (scelta_corretta == false)
    {

        printf("Inserisci 0: Vegetariano\n");
        printf("Inserisci 1: Vegano\n");
        printf("Inserisci 2: Lattosio\n");
        printf("Inserisci 3: Glutine\n");
        printf("Inserisci 4: niente\n");

        fflush(stdin);
        scanf("%d",&scelta);

        if (scelta > 4|| scelta < 0) {
            printf("Errore nella scelta della preferenza, Riprova\n");
        }else {
            printf("Scelta corretta\n");
           strcpy(pasto,opzioni_pasto[scelta]);
            scelta_corretta = true;
        }

    }
    }

int Scelta_Posto_Preferito(void)  //funzione per scegliere il posto preferito
{
    int posto_inserito = 0;

    while(posto_inserito <= 0 || posto_inserito > MAX_PASSEGERI) {
        printf("Inserisci il posto preferito numero compreso tra 0 e 200: ");
        scanf("%d",&posto_inserito);
        puts("");
    }

    return posto_inserito;

}

bool Controlla_Password(char password[]) {

    bool stato_carattere = false;
    bool stato_speciale = false;
    int lunghezza_stringa = strlen(password);


    for(int i = 0; i < lunghezza_stringa; i++)
    {
        //Controllo se ci sono lettere maiuscole
        for (int j = 'A'; j <= 'Z'; j++) {
            if (password[i] == j) {
                stato_carattere = true;
            }
        }
        //Controllo se ci sono lettere minuscole
        for (int j = 'a'; j < 'z'; j++) {
            if (password[i] == j) {
                stato_carattere = true;
            }
        }
        //Controllo se ci sono caratteri speciali
        for (int j = '!'; j < '/'; j++) {
            if (password[i] == j) {
                stato_speciale = true;
            }
        }
    }

    (stato_speciale == false? printf("Inserisci un carattere speciale\n") : printf("Carattere speciale: ok\n"));
    (stato_carattere == false? printf("Inserisci almeno una lettera\n") : printf("Lettera: ok\n"));
    return stato_carattere && stato_speciale;
}

bool Controlla_Documento(char numero_passaporto[])  //funzione per i criteri del passaporto
{
    bool stato_1 = false;
    bool stato_2 = false;
    bool stato_3 = true;
    bool stato_4 =  false;

    stato_4 = (strlen(numero_passaporto) == 9? true: false);

    for (int i = 'A'; i <= 'Z'; i++) { //controllo il primo carattere della stringa
        if (numero_passaporto[0] == i) {
            stato_1 = true;
        }
    }

    for (int i = 'A'; i <= 'Z'; i++) { //controllo il secondo carattere della stringa
        if(numero_passaporto[1] == i) {
            stato_2 = true;
        }
    }

    for (int i = 2; i < MAX_DOCUMENTO; i++) { //controllo se i resitanti caratteri sonoi numeri
        if (isdigit(numero_passaporto[i] == 0)){
            stato_3 = false;
        }
    }
      if(stato_4 && stato_3 && stato_2 && stato_1 == true)
      {
          printf("Documento corretto\n");
      }else {
          printf("Documento errato, Riprova: \n");
      }
    return  stato_3 && stato_2 && stato_1 && stato_4;
}

int Conta_Elementi(char* stringa) {

    FILE* ptr = fopen(stringa,"rb");
    int utenti_iscritti = 0;
    long size = 0;

    fseek(ptr,0,SEEK_END);//Sposto la "testina del file" alla fine

    size = ftell(ptr); //restiuisce la poszione corrente del file in byte

    utenti_iscritti = size / sizeof(UTENTE);

    rewind(ptr);

    fclose(ptr);

    return utenti_iscritti;

}

void Inserisci_Utente(UTENTE utente) {

   FILE* ptr =  fopen(FILE_NAME_USER,"ab"); //Apro il file in modalità append per aggiungere il nuovo utente

    fwrite(&utente,sizeof(UTENTE),1, ptr);
    printf("salvo l'utente nel file\n");

    fclose(ptr);
}

UTENTE Accesso_Utente(bool* trovato) {

    UTENTE temp;

    *trovato = false;
    char utente_nome [20];
    char password [20];

    printf("Inserisci il nome_utente: ");


    scanf("%s",utente_nome);
    fflush(stdin);

    puts("");

    printf("Inserisci la password: ");
    scanf("%s",password);
    fflush(stdin);



    FILE* ptr = fopen(FILE_NAME_USER,"rb");


    while (fread(&temp,sizeof(UTENTE),1,ptr) != 0) {
        if ((strcmp(password, temp.password) == 0) && (strcmp(utente_nome, temp.nome) == 0)) {
            *trovato = true;
            return temp;
        }
    }

    fclose(ptr);

    return temp;
}

bool Trova_Utente(UTENTE utente) {

    bool stato = false;

    UTENTE temp;

    FILE* ptr = fopen(FILE_NAME_USER,"rb");

    while (fread(&temp,sizeof(UTENTE),1,ptr) != 0) {
        if ((strcmp(utente.numero_documeto, temp.numero_documeto)) == 0) {
            stato = true;
        }
    }

    fclose(ptr);
    return stato;
}

void Scelta_Classe_Preferita(char classe[])
{

    int scelta = 0;
    char* preferenza_utente = NULL; //Contiene la preferenza scelta dal utente
    bool scelta_corretta = false; //e falso finche l'utente non fa una scelta corretta
    char* opzioni_classe [3] = {"Prima","Bussines","Economy"}; //scelte effetuabili dal utente

    printf("Inserisci una preferenza sulla classe:\n");
    while (scelta_corretta == false)
    {

        printf("Inserisci 0: Prima\n");
        printf("Inserisci 1: Bussines\n");
        printf("Inserisci 2: Economy\n");

        fflush(stdin);
        scanf("%d",&scelta);

        if (scelta > 4|| scelta < 0) {
            printf("Errore nella scelta della preferenza, Riprova\n");
        }else {
            printf("Scelta corretta\n");
            strcpy(classe,opzioni_classe[scelta]);
            scelta_corretta = true;
        }

    }

}

VOLO Crea_Volo(void){
	
	VOLO temp;

	Generazione_ID(temp.Id_Volo);

	Inserisci_Luogo_Partenza(temp.partenza_origine);

	Inserisci_Luogo_Destinazione(temp.destinazione);
	
	temp.data = Inserisci_Data_Volo();

	return temp;
}


void Inserisci_Luogo_Partenza(char partenza[]){

	printf("Inserisci il luogo di partenza: ");
	scanf("%s",partenza);
	puts("");

	partenza[0] = toupper(partenza[0]);
}

void Inserisci_Luogo_Destinazione(char destinazione[])
{
	printf("Inserisci il luodo di destinazione: ");
	scanf("%s",destinazione);
	puts("");

	destinazione[0] = toupper(destinazione[0]);
}

DATA Inserisci_Data_Volo(void)
{
	DATA temp;
	bool verifica = false;

    while (verifica == false) {
        printf("Inserisci il giorno della partenza: ");
        scanf("%d",&temp.giorno);
        puts("");
        if (temp.giorno >= 1 && temp.giorno <= 31) {
            verifica = true;
        }else {
            printf("il numero del giorno deve essere compreso tra 1 e 31\n");
        }
    }

    verifica = false;

     while (verifica == false) {
         printf("Inserisci il mese della partenza: ");
         scanf("%d",&temp.mese);
         puts("");
         if (temp.mese >= 1 && temp.mese <= 12) {
             verifica = true;
         }else {
             printf("Il numero del mese dev'essere copreso tra 1 e 12\n");
         }
     }

    verifica = false;

    while (verifica == false) {
        printf("Inserisci l'anno della partenza(soglia massima 2025 - 2030): ");
        scanf("%d",&temp.anno);
        puts("");
        if (temp.anno >= 2025 && temp.anno <= 2030) {
            verifica = true;
        }
    }

    verifica = false;

    while (verifica == false) {
        printf("Inserisci l'ora della partenza (0:00 - 23 : 59: ");
        scanf("%d",&temp.ora);
        puts("");
        if (temp.ora >= 0 && temp.ora <= 23) {
            verifica = true;
        }
    }

    verifica = false;

    while (verifica == false) {
        printf("Inserisci i minuti(00-59): ");
        scanf("%d",&temp.minuti);
        puts("");

        if (temp.minuti >= 0 && temp.minuti <= 59) {
            verifica = true;
        }
    }
	return temp;
}


AMMINISTRATORE Iscrizione_Amministratore(void) {  //funzione per l'iscrizione dell'amministratore
    AMMINISTRATORE temp;

    printf("Inserisci il nome: ");
    scanf(" %s", temp.nome);

    puts("");
	system("clear");
	
    printf("Inserisci il cognome: ");
    scanf(" %s", temp.cognome);

    puts("");
	system("clear");
	
    printf("Inserisci la password (Lunghezza max 19, almeno una lettera e un carattere speciale)\n");
    fflush(stdin);
	system("clear");

    do {
        scanf("%s",temp.password);
    }while(Controlla_Password(temp.password) == false);

    Generazione_ID(temp.Id);

    temp.account_sbloccato = true;

    return temp;
}


void Generazione_ID(char Id[]) { //funzione per la generazione dell'ID
    srand(time(NULL));  //per generare l'id in modo casuale

    for (int i = 0; i < 3; i++) {
        Id[i] = 'A' + rand() % 26;  //genera lettere random maiuscole nelle prime 3 posizioni
    }
    for (int i = 3; i < MAX_ID-1; i++) {
        Id[i] = '0' + rand() % 10;  //genera numeri random nelle poszioni successive dopo le lettere maiuscole
    }

    Id[MAX_ID-1] ='\0';
}

bool Trova_Admin(AMMINISTRATORE admin)
{
	bool stato = false;
	AMMINISTRATORE temp;

	FILE* pt_file =fopen (FILE_NAME_ADMIN,"rb");

	while(fread(&temp,sizeof(AMMINISTRATORE),1,pt_file)!= 0)
	{
		if(strcmp(temp.nome,admin.nome) == 0 && strcmp(temp.cognome, admin.cognome) == 0)
		{
			stato = true;
		}
	}
	fclose(pt_file);

	return stato;
}

void Inserici_Admin(AMMINISTRATORE admin){

	FILE* ptr_file = fopen(FILE_NAME_ADMIN, "ab");

	fwrite(&admin,sizeof(AMMINISTRATORE),1,ptr_file);
	printf("Account salvato\n");
	system("clear");

	fclose(ptr_file);
	
}

AMMINISTRATORE accesso_Amministratore(bool* stato)
{
	char nome_admin[MAX_STRINGHE];
	char password[MAX_STRINGHE];
	AMMINISTRATORE temp;

	printf("Inserisci il nome del utente: ");
	scanf("%s",nome_admin);
	puts("");

	system("clear");
	
	printf("Inserisci la password: ");
	scanf("%s",password);
	puts("");

	system("clear");

	FILE* ptr_file = fopen(FILE_NAME_ADMIN,"rb");

	while(fread(&temp,sizeof(AMMINISTRATORE),1,ptr_file) != 0)
	{
		if(strcmp(temp.nome, nome_admin) == 0 && strcmp(temp.password,password) == 0 ){

			*stato = true;
			
		}else
		{
			*stato = false;
		}
	}

	return temp;
}
