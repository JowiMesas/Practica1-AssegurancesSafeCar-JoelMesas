

#include <stdio.h>
#include <windows.h>
int main() {
    /*
        Aixo més la lliberia windows.h es per a que a Windows es pugués veure bé els accents i caracters especials (UTF-8 per a WINDOWS)
    */
    SetConsoleOutputCP(65001); 
    char respostaVehicle, continuar;
    int edat, opcioMotor, anyFabricacio, vehicleAntic, us, cilindrada;
    int anyActual = 2025;
    int resultat;
    float modificador;
    float preusTercersBasic, preusTercersAvancat, preusTotRiscFranquicia, preusTotRiscSense;
    float preuFinalTercersBasic, preuFinaltercersAvancat, preuFinalTotRiscFranquicia, preuFinalTotRiscSense;
    
    printf("**********************************************\n");
    printf("****** TARIFICADOR ASSEGURANCES SAFECAR ******\n");
    printf("**********************************************\n");

    continuar = 'S';
    
    while (continuar == 'S' || continuar == 's') {
        
        // Bucle per saber la resposta del usuari i validar que sigui un cotxe (C) o una Moto (M)
        printf("- Vols assegurar un [C]otxe o una [M]oto? Prem C o M: ");
        do {
            resultat = scanf(" %c", &respostaVehicle);
            if (resultat == 0) {
                while(getchar() != '\n');
            }
            if(respostaVehicle != 'c' && respostaVehicle != 'm' && respostaVehicle != 'C' && respostaVehicle != 'M') {
                printf("Prem C o M: ");
            }
        } while (respostaVehicle != 'c' && respostaVehicle != 'm' && respostaVehicle != 'C' && respostaVehicle != 'M');
        
        // Bucle per comprobar que la edat de l'usuari sigui correcta i no un valor no desitjat
        printf("- Edat conductor (18-80): ");
        do {
            resultat = scanf("%d", &edat);
            if (resultat == 0) {
                while(getchar() != '\n');
                edat = 0;
            }
            if(edat < 18 || edat > 80) {
                printf("Introdueix una edat vàlida. No assegurem a menors de 18 ni majors de 80: ");
            }
        } while (edat < 18 || edat > 80);
        
        // Triar el tipus de motor del vehicle 
        printf("Tipus de motor:\n");
        printf("1-Combustió (diesel o gasolina)\n");
        printf("2-Híbrid\n");
        printf("3-Elèctric\n");
        do {
            printf("Escull la opció 1, 2 o 3: ");
            resultat = scanf("%d", &opcioMotor);
            if (resultat == 0) {
                while(getchar() != '\n');
                opcioMotor = 0;
            }
        } while (opcioMotor < 1 || opcioMotor > 3);
        
        // Validem l'any de fabricació del vehicle
        printf("- Any de fabricació del vehicle (1970-2025): ");
        do {
            resultat = scanf("%d", &anyFabricacio);
            if (resultat == 0) {
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
        vehicleAntic = (anyActual - anyFabricacio) > 10;
        
        // Si el vehicle es un cotxe hem de saber el seu ús
        if (respostaVehicle == 'c' || respostaVehicle == 'C') {
            printf("- Ús:\n");
            printf("1-Particular\n");
            printf("2-Lloguer\n");
            printf("3-Taxi\n");
            do {
                printf("Escull la opció 1, 2 o 3: ");
                resultat = scanf("%d", &us);
                if (resultat == 0) {
                    while (getchar() != '\n');
                    us = 0;
                }
            } while (us < 1 || us > 3);
        }
        
        // Cilindrada del vehicle
        printf("- Cilindrada:\n");
        
        // Ara hem de preguntar cilindrada i sabent si es cotxe o moto
        if (respostaVehicle == 'c' || respostaVehicle == 'C') {
            printf("1-Menys o igual de 1.000cc\n");
            printf("2-Més de 1.000 i menys o igual de 2.000cc\n");
            printf("3-Més de 3.000cc\n");
            do {
                printf("Escull la opció 1, 2 o 3: ");
                resultat = scanf("%d", &cilindrada);
                if(resultat == 0) {
                    while (getchar() != '\n');
                    cilindrada = 0;
                }
            } while (cilindrada < 1 || cilindrada > 3);
            
        } else {  // Moto
            printf("1-Menys o igual de 125cc\n");
            printf("2-Més de 125 i menys o igual de 500cc\n");
            printf("3-Més de 500cc i menys o igual de 1.000cc\n");
            printf("4-Més de 1.000cc\n");
            do {
                printf("Escull la opció 1, 2, 3 o 4: ");
                resultat = scanf("%d", &cilindrada);
                if(resultat == 0) {
                    while (getchar() != '\n');
                    cilindrada = 0;
                }
            } while (cilindrada < 1 || cilindrada > 4);
        }
        
        // Ara ficarem els preus base de cada vehicle
        if (respostaVehicle == 'c' || respostaVehicle == 'C') {
            preusTercersBasic = 200.0;
            preusTercersAvancat = 230.0;
            preusTotRiscFranquicia = 330.0;
            preusTotRiscSense = 400.0;
        } else {
            preusTercersBasic = 100.0;
            preusTercersAvancat = 120.0;
            preusTotRiscFranquicia = 200.0;
            preusTotRiscSense = 300.0;
        }

        // Inicialitzem el modificador en el que anira cambiant als preus amb els percentatges que demanen a la pràctica
        modificador = 1.0;

        // Primer afegim el modificador al rang d'edat
        if(edat >= 18 && edat <= 24) {
            modificador = modificador + 0.70;
        } else if(edat >= 25 && edat <= 29) {
            modificador = modificador + 0.30;
        } else if (edat >= 30 && edat <= 39) {
            modificador = modificador + 0.10;
        } else if (edat >= 60 && edat <= 80) {
            modificador = modificador + 0.20;
        }
        
        // Afegim el modificador al tipus de motor
        // Hibrid (opció 2), Elèctric (opció 3)
        if (opcioMotor == 2) {
            modificador = modificador - 0.10;
        } else if (opcioMotor == 3) {
            modificador = modificador - 0.20;
        } 
        
        // Aplicar modificador per any (només si té més de 10 anys)
        if (vehicleAntic) {
            modificador = modificador + 0.10;
        }
        
        // Afegir i aplicar el modificador per ús (només per al cotxe)
        if(respostaVehicle == 'c' || respostaVehicle == 'C') {
            // Lloguer (opció 2), Taxi (opció 3)
            if(us == 2) {  
                modificador = modificador + 0.05;
            } else if (us == 3) {
                modificador = modificador + 0.10;
            }           
        }

        // Aplicar i afegir modificador per a la cilindrada
        if (respostaVehicle == 'c' || respostaVehicle == 'C') {
            if (cilindrada == 2) {
                modificador = modificador + 0.10;
            } else if (cilindrada == 3) {
                modificador = modificador + 0.20;
            }          
        } else {  // Moto
            if (cilindrada == 2) {
                modificador = modificador + 0.10;
            } else if (cilindrada == 3) {
                modificador = modificador + 0.15;
            } else if (cilindrada == 4) {
                modificador = modificador + 0.30;
            }     
        }
        
        // Calculem els preus totals amb el modificador
        preuFinalTercersBasic = preusTercersBasic * modificador;
        preuFinaltercersAvancat = preusTercersAvancat * modificador;
        preuFinalTotRiscFranquicia = preusTotRiscFranquicia * modificador;
        preuFinalTotRiscSense = preusTotRiscSense * modificador;      
        
        // Mostrar el títol segons el tipus de vehicle
        if (respostaVehicle == 'c' || respostaVehicle == 'C') {
            printf("\nEls preus de l'assegurança pel teu cotxe són els següents:\n");
        } else {
            printf("\nEls preus de l'assegurança per la teva moto són els següents:\n");
        }

        /*
         Si el vehicle es mes antic de 10 anys hem de fer una taula diferent perquè
         no mostra el preu de tot risc        
        */
        if (vehicleAntic) {
            printf("---------------------------------------------------\n");
            printf("| Fraccionament | Tercers bàsic | Tercers avançat |\n");
            printf("---------------------------------------------------\n");
            printf("| MENSUAL       | %10.2f € | %15.2f € |\n", 
                   preuFinalTercersBasic * 1.06, preuFinaltercersAvancat * 1.06);
            printf("| TRIMESTRAL    | %10.2f € | %15.2f € |\n", 
                   preuFinalTercersBasic * 1.04, preuFinaltercersAvancat * 1.04);
            printf("| SEMESTRAL     | %10.2f € | %15.2f € |\n", 
                   preuFinalTercersBasic * 1.02, preuFinaltercersAvancat * 1.02);
            printf("| ANUAL         | %10.2f € | %15.2f € |\n", 
                   preuFinalTercersBasic, preuFinaltercersAvancat);
            printf("---------------------------------------------------\n");
            printf("* No assegurem a tot risc vehicles de més de 10 anys.\n");
        } else {
            printf("----------------------------------------------------------------------------------------------------------------\n");
            printf("| Fraccionament | Tercers bàsic | Tercers avançat | Tot risc amb franquícia (200€) | Tot risc sense franquícia |\n");
            printf("----------------------------------------------------------------------------------------------------------------\n");
            printf("| MENSUAL       | %10.2f € | %15.2f € | %26.2f € | %21.2f € |\n",
                   preuFinalTercersBasic * 1.06, preuFinaltercersAvancat * 1.06,
                   preuFinalTotRiscFranquicia * 1.06, preuFinalTotRiscSense * 1.06);
            printf("| TRIMESTRAL    | %10.2f € | %15.2f € | %26.2f € | %21.2f € |\n",
                   preuFinalTercersBasic * 1.04, preuFinaltercersAvancat * 1.04,
                   preuFinalTotRiscFranquicia * 1.04, preuFinalTotRiscSense * 1.04);
            printf("| SEMESTRAL     | %10.2f € | %15.2f € | %26.2f € | %21.2f € |\n",
                   preuFinalTercersBasic * 1.02, preuFinaltercersAvancat * 1.02,
                   preuFinalTotRiscFranquicia * 1.02, preuFinalTotRiscSense * 1.02);
            printf("| ANUAL         | %10.2f € | %15.2f € | %26.2f € | %21.2f € |\n",
                   preuFinalTercersBasic, preuFinaltercersAvancat,
                   preuFinalTotRiscFranquicia, preuFinalTotRiscSense);
            printf("----------------------------------------------------------------------------------------------------------------\n");
        }
        
        // Hem de preguntar si vol fer alguna altra tarificació  
        printf("\n");
        do {
            printf("Vols calcular el preu per un altre vehicle (S)í o (N)o? Prem S o N: ");
            resultat = scanf(" %c", &continuar);
            
            if (resultat == 0) {
                while (getchar() != '\n');
            }
        } while (continuar != 'S' && continuar != 's' && 
                 continuar != 'N' && continuar != 'n');
        
        printf("\n");
    }
    
    printf("Moltes gràcies per utilitzar el nostre tarificador. Fins la pròxima!\n");
    printf("Assegurances SafeCar\n");
    
    return 0;
}