#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"

using namespace std;

class AdresatMenedzer {

    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(size_t index);
public:
    AdresatMenedzer();
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
};




#endif
