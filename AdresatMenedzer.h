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

    PlikZAdresatami plikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(size_t index);
public:
    AdresatMenedzer(int idZalogowanegoUzytkownika): ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
};




#endif
