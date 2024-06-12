#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"

using namespace std;

class PlikZAdresatami{
    Adresat adresat;
    string nazwaPlikuZAdresatami;
    size_t idOstatniegoAdresata;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdOstatniegoAdresata();
public:
    PlikZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdNowegoAdresata();

};
