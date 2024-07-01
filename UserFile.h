#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZUzytkownikami : protected PlikTekstowy{

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami;
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI) : PlikTekstowy(NAZWAPLIKUZUZYTKOWNIKAMI){};
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);

};
#endif
