#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"
#include <fstream>
#include <sstream>

using namespace std;

class KsiazkaAdresowa {
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    int liczba;
    vector <Uzytkownik> uzytkownicy;
    string nazwaPlikuZUzytkownikami;
    fstream plikTekstowy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string konwerjsaIntNaString(int liczba);

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wyswietlWszystkichUzytkownikow();
};

