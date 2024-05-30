#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"


using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    int IdZalogowanegoUzytkownika;
public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata(int IdZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
};

#endif
