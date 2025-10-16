#include <stdio.h>

/*
TARIFICADOR de Assegurançes SAFECAR
*/

int main () {
    char respostaVehicle;
    int edat, opcioMotor, anyFabricacio, vehicleAntic;
    int anyActual = 2025;
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
        resultat = scanf(" %d", &edat);
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
        resultat = scanf(" %d", &opcioMotor);
         if (resultat == 0) {
        while(getchar() != '\n');
        opcioMotor = 0;
        }
    } while (opcioMotor < 1 || opcioMotor > 3);
    // Validem l'any de fabricació del vehicle
    printf("-Any de fabricació del vehicle (1970-2025): ");
    do
    {
        resultat = scanf(" %d", &anyFabricacio);
        if (resultat == 0)
        {
           while (getchar() != '\n');
           anyFabricacio = 0;          
        }
        
        if(anyFabricacio < 1970 || anyFabricacio > 2025) {
            printf("Introdueix un any entre 1970 i 2025: ");
        }
    } while (anyFabricacio < 1970 || anyFabricacio > 2025);
    /*
    Ara hem de saber que si el vehicle té més de 10 anys de fabricació
    llavors no mostra el preu de tot risc i aplica un càrrec del 10% del preu base.
    */
   vehicleAntic = (anyActual-anyFabricacio) >10 ;
    return 0;
}