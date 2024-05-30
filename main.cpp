#include <iostream>
#include "KsiazkaAdresowa.h"
#include "windows.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.wyswietlWszystkichUzytkownikow();
    int idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    idZalogowanegoUzytkownika = ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}
