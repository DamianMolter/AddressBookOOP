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
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
public:
    PlikZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);

};
