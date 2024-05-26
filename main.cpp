#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.wyswietlWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichUzytkownikow();

    return 0;
}
