#include <stdio.h>

/*
TARIFICADOR de Assegurançes SAFECAR
*/

int main () {
    char respostaVehicle;
    int edat, opcioMotor;
    int resultat;
    printf("**********************************************\n");
    printf("****** TARIFICADOR ASSEGURANCES SAFECAR ****** \n");
    printf("********************************************** \n");
    printf("- Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
    //Bucle per saber la resposta del usuari i validar que sigui un cotxe (C) o una Moto (M)
    do {
    resultat = scanf(" %c", &respostaVehicle);
    if (resultat == 0) {
        while(getchar() != '\n');
    }
        if(respostaVehicle != 'c' && respostaVehicle!= 'm' && respostaVehicle!= 'C' && respostaVehicle!= 'M') {
            printf("Prem C o M:");
        }
    } while (respostaVehicle != 'c' && respostaVehicle!= 'm' && respostaVehicle!= 'C' && respostaVehicle!= 'M');
    //Bucle per comprobar que la edat de l'usuari sigui correcta i no un valor no desitjat
    printf("-Edat conductor (18-80): ");
    do {
        resultat = scanf(" %i", &edat);
        if (resultat == 0) {
        while(getchar() != '\n');
        edat = 0;
        }
        if(edat < 18 || edat > 80) {
            printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni majors de 80: ");
        }
    } while (edat < 18 || edat > 80);
    //Triar el tipus de motot del vehicle 
    printf("-Tipus de motor:\n ");
    printf("1- Combustió (diesel o gasolina) \n");
    printf("2- Híbrid \n");
    printf("3- Elèctric \n");
    do {
        printf("Escull la opció: 1, 2 o 3: ");
        resultat = scanf(" %i", &opcioMotor);
         if (resultat == 0) {
        while(getchar() != '\n');
        opcioMotor = 0;
        }
    } while (opcioMotor < 1 || opcioMotor > 3);
    return 0;
}