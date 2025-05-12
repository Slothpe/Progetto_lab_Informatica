#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "Scena_menager.h"

/*
 *ACCOUNT DI PROVA:

	ADMIN E UTENTE
 
 NOME: Antonio
 COGNOME: Perrulli
 PASSWORD: Ermitico2!
 POSTO PREFERITO: 100
 CIBO: Vegetariano
 CLASSE: Prima
 NUMERO PASSAPORTO: MA1234567

 */
/*
	Dal account amministratore dobbiamo creare i voli e slavarlo nel file binario fly, Dobbiamo poter cancellare i voli,
	Modificare i voli e salvare tutte le modifiche nel file;


 */

int main(void)
{

    PROGRAMMA programma;
    programma.stato_programma = true;
    programma.scena = 0;

    printAirPlane();

    while (programma.stato_programma == true)
        {

		
        programma.scena = Menu_Principale();

        switch (programma.scena)
            {

				case Utente:

					Scena_Panello_Utente(&programma);
						
				break;
				

				case Amministratore:

					Scena_Pannello_Amministratore(&programma);
				
				break;

            	case Chiusura:
            	
            	printf("Chiusura del programma\n");
            	programma.stato_programma = false;
            	
            	break;        
				
            default:

                printf("Scelta non valida\n");

                break;

            }

            system("clear");
        }

	printf("Utente: %s %s\n",programma.utente.nome, programma.utente.cognome);
    printf("Amministratore: %s %s ID: %s\n",programma.admin.nome, programma.admin.cognome, programma.admin.Id);


    return 0;
}
