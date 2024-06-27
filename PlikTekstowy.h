#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
    string NAZWA_PLIKU;
protected:
    PlikTekstowy(string nazwaPliku): NAZWA_PLIKU(nazwaPliku){};
    bool czyPlikJestPusty();
    string pobierzNazwePliku();

};




#endif
