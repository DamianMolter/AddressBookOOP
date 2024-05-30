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
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    int pobierzIdNowegoAdresata();
    void wyswietlDaneAdresata(size_t index);
public:
    AdresatMenedzer();
    int dodajAdresata(int IdZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};




#endif
