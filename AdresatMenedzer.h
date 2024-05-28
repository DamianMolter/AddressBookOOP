#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {

    Adresat adresat;
    UzytkownikMenedzer uzytkownikMenedzer;
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    Adresat podajDaneNowegoAdresata();
    int pobierzIdNowegoAdresata();
    void wyswietlDaneAdresata(size_t index);
public:
    AdresatMenedzer();
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
};




#endif
