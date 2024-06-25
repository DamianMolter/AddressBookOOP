#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami() {

    idOstatniegoAdresata = 0;
    nazwaPlikuZAdresatami = "Adresaci.txt";
    nazwaTymczasowegoPlikuZAdresatami = "Adresaci_temp.txt";
}


int PlikZAdresatami :: pobierzIdNowegoAdresata() {
    fstream plikZAdresatami;
    plikZAdresatami.open("Adresaci.txt", ios::in);
    int idOstatniegoAdresata = 0;
    string linia = "";
    while(getline(plikZAdresatami, linia)) {
        size_t pozycjaPierwszejPionowejKreski = linia.find('|');
        idOstatniegoAdresata = stoi(linia.substr(0, pozycjaPierwszejPionowejKreski));
    }
    plikZAdresatami.close();
    return idOstatniegoAdresata + 1;
}

void PlikZAdresatami :: dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        plikTekstowy << liniaZDanymiAdresata << endl;
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

string PlikZAdresatami :: zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze :: konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze :: konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami :: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "abc";
    string daneOstatniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstatniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    return adresaci;
}

Adresat PlikZAdresatami :: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}


int PlikZAdresatami :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze :: konwersjaStringNaInt(MetodyPomocnicze :: pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze :: konwersjaStringNaInt(MetodyPomocnicze :: pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

void PlikZAdresatami :: usunWybranaLinieWPliku(int idUsuwanegoAdresata) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";

    odczytywanyPlikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            size_t pozycjaPierwszejPionowejKreski = wczytanaLinia.find('|');
            int numerIdZOdczytanegoPlikuTekstowego = stoi(wczytanaLinia.substr(0, pozycjaPierwszejPionowejKreski));
            if(numerIdZOdczytanegoPlikuTekstowego != idUsuwanegoAdresata) {
                tymczasowyPlikTekstowy << wczytanaLinia << endl;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(nazwaPlikuZAdresatami);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, nazwaPlikuZAdresatami);
    }
}

void PlikZAdresatami :: usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami :: zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami :: edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami, int idEdytowanegoAdresata) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";

    odczytywanyPlikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            size_t pozycjaPierwszejPionowejKreskiWeWczytanymKontakcie = wczytanaLinia.find('|');
            int idWczytanegoKontaktu = stoi(wczytanaLinia.substr(0, pozycjaPierwszejPionowejKreskiWeWczytanymKontakcie));
            if (idWczytanegoKontaktu == idEdytowanegoAdresata) {
                tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami << endl;
            } else {
                tymczasowyPlikTekstowy << wczytanaLinia << endl;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(nazwaPlikuZAdresatami);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, nazwaPlikuZAdresatami);
    }
}

void PlikZAdresatami :: zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata) {
    string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(liniaZDanymiAdresata, idEdytowanegoAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
