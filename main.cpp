#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.wyswietlWszystkichUzytkownikow();
    int IdZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata(IdZalogowanegoUzytkownika);
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    return 0;
}
