/* Kinan Haj Rashid
* 4 / oktober / 2021
* Betyg: E   
*/
#include "maze.h"
void inmatning_for_meny();

int main() { 

    std::cout << " ======================================== " << std::endl << std::endl;
    std::cout << " 1) Generera en labyrint av storlek 11 x 11 " << std::endl;
    std::cout << " 2) Avsluta programmet " << std::endl << std::endl;
    std::cout << " ======================================== " << std::endl << std::endl;
    std::cout << " Mata in ett alternativ: " << std::endl;
    inmatning_for_meny();

    return 0;
}

void inmatning_for_meny() {
    int alternativ;
    std::cin >> alternativ;

    while (std::cin.fail()) { // Nummer check(1)källan
        std::cout << " FEL INMATNING :: 1-Skapa en labyrent    2 - Avsulta programmet : ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> alternativ;
        std::cout << std::endl;
    }

    if (alternativ == 1) { //Om alternativet ( inamtningen ) = 1 skriv ut labyrint och anropa main
        Maze a;
        a.print();
        main();
    }

    else if (alternativ == 2) { // Avsluta
        exit(1);
    }

    else (alternativ != 1 && alternativ != 2); { // Om inmatningen inte är 1 och 2 anropa "inamtning_for_meny"
        std::cout << " FEL INMATNING :: 1-Skapa en labyrent    2 - Avsulta programmet : ";
        inmatning_for_meny();
    }
}

//(1)Källa: https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
