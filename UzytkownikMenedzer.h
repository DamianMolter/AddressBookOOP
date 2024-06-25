#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {
    Uzytkownik uzytkownik;
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void zapiszWszystkichUzytkownikowDoPliku();
public:
    UzytkownikMenedzer() {
        idZalogowanegoUzytkownika = 0;
        wczytajUzytkownikowZPliku();
    };
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
};
#endif
