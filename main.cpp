#include <iostream>
#include "KsiazkaAdresowa.h"
#include "windows.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.wyswietlWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}
