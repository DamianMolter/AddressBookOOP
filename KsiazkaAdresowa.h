#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"


using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    int idOstatniegoAdresata;
public:
    KsiazkaAdresowa(){
        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa(){
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wylogowanieUzytkownika();
};

#endif
