//
// Created by Perrulli Antonio on 14/04/25.
#include <stdbool.h>
#include<stdio.h>

#define FILE_NAME_USER "Data_User.bin"
#define FILE_NAME_ADMIN "Data_Admin.bin"
#define FILE_NAME_FLY "Data_Fly.bin"
#define MAX_PASSEGERI 100
#define MAX_BIGLIETTI_UTENTE 10
#define MAX_PASSWORD 20 //Numero massimo di caratteri per la password
#define MAX_DOCUMENTO 10
#define MAX_PREFERENZE 12
#define MAX_STRINGHE 20
#define MAX_ID 10

<<<<<<< HEAD
typedef struct
{
	int giorno;
    int mese;
    int anno;
    int ora;
    int minuti;
 }DATA;

typedef struct    //struttura per i dati del volo
{
    char Id_Volo[MAX_ID];
    char partenza_origine[MAX_STRINGHE];
    char destinazione[MAX_STRINGHE];
    DATA data;
    int posti_disponibili[MAX_PASSEGERI];    //massimo posti disponibili 100
    bool Stato_volo; //se il volo è attivo in ritardo o cancellato
    char messaggio[MAX_STRINGHE]; //Messaggio tipo di notifica se il volo e cancellato o in ritardo
}VOLO;

typedef struct{

	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	int numero_posto;
	char classe[MAX_STRINGHE];
	VOLO volo;	
	
}BIGLIETTO;

=======

typedef struct BIGLIETTO {

    int numero_biglietto;
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    int numero_postoo;

}BIGLIETTO;


>>>>>>> 7255264ebdb790bb9dce20bb944f46f4435eee42
typedef struct   //struttura per inserire dati passeggeri
{
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    char numero_documeto[MAX_DOCUMENTO];
    char password[MAX_PASSWORD];
    char pasti[MAX_PREFERENZE]; //pasto preferito
    int posto_preferito;
    char classe_preferita[MAX_PREFERENZE];  //economy, business, firstclass
    BIGLIETTO biglietti_utente[MAX_BIGLIETTI_UTENTE];
    int numero_biglietti_acquistati;

}UTENTE;


<<<<<<< HEAD
=======

typedef struct
{
	int giorno;
    int mese;
    int anno;
    int ora;
    int minuti;
 }DATA;



typedef struct    //struttura per i dati del volo
{
    char Id_Volo[MAX_ID];
    char partenza_origine[MAX_STRINGHE];
    char destinazione[MAX_STRINGHE];
    DATA data;
    int posti_disponibili[MAX_PASSEGERI];    //massimo posti disponibili 100
    bool Stato_volo; //se il volo è attivo in ritardo o cancellato
    char messaggio[MAX_STRINGHE]; //Messaggio tipo di notifica se il volo e cancellato o in ritardo
}VOLO;


>>>>>>> 7255264ebdb790bb9dce20bb944f46f4435eee42
struct NOTIFICA   //struttura per le notifiche del volo
{
    char messaggio[500];   //massimo di caratteri che può contenere un messaggio
    char tipo[MAX_STRINGHE];   //ritardi, cambio di orario
    VOLO volo_interessato;
};

typedef struct {   //struttura per i dati dell'amministratore
    char nome[MAX_STRINGHE];
    char cognome[MAX_STRINGHE];
    char password[MAX_PASSWORD];
    char Id[MAX_ID];
    bool account_sbloccato;

}AMMINISTRATORE;

typedef struct {

<<<<<<< HEAD
	char nome[20];
	char cognome[20];
	char ruolo[20]; //pilota hostess
	char Id[10];  //3 lettere e gli altri restanti numeri
	bool occupato;
=======
	char nome[MAX_STRINGHE];
	char cognome[MAX_STRINGHE];
	char ruolo[MAX_STRINGHE]; //pilota hostess
	char Id[MAX_ID];  //3 lettere e gli altri restanti numeri
>>>>>>> 7255264ebdb790bb9dce20bb944f46f4435eee42
	
}PERSONALE_VOLO;



<<<<<<< HEAD

=======
>>>>>>> 7255264ebdb790bb9dce20bb944f46f4435eee42
UTENTE Iscrizione_Utente(void); //funzione per aggiungere i passeggeri
void Scelta_Pasto(char[]);
int Scelta_Posto_Preferito(void);
bool Controlla_Password(char[]);
bool Controlla_Documento(char*);
int Conta_Elementi(char*);
void Inserisci_Utente(UTENTE);
UTENTE Accesso_Utente(bool*);
void Scelta_Classe_Preferita(char[]);
bool Trova_Utente(UTENTE);
VOLO Crea_Volo(void);
void Inserisci_Luogo_Partenza(char[]);
void Inserisci_Luogo_Destinazione(char[]);
DATA Inserisci_Data_Volo(void);
AMMINISTRATORE Iscrizione_Amministratore(void);
void Generazione_ID(char[]);
bool Trova_Admin(AMMINISTRATORE);
void Inserici_Admin(AMMINISTRATORE);
AMMINISTRATORE accesso_Amministratore(bool*);
