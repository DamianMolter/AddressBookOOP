#include "AdresatMenedzer.h"


int AdresatMenedzer :: dodajAdresata() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Adresat adresat;
    adresat = podajDaneNowegoAdresata(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return idOstatniegoAdresata + 1;
}

Adresat AdresatMenedzer :: podajDaneNowegoAdresata(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;
    adresat.ustawId(plikZAdresatami.pobierzIdNowegoAdresata());
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze :: wczytajLinie();
    imie = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze :: wczytajLinie();
    nazwisko = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze :: wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze :: wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze :: wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer :: wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i = 0; i < adresaci.size(); i++) {
            wyswietlDaneAdresata(i);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer :: wyswietlDaneAdresata(size_t index) {
    cout << endl << "Id:         " << adresaci[index].pobierzId() << endl;
    cout << endl << "Id uzytkownika:" << adresaci[index].pobierzIdUzytkownika() << endl;
    cout << "Imie:               " << adresaci[index].pobierzImie() << endl;
    cout << "Nazwisko:           " << adresaci[index].pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresaci[index].pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresaci[index].pobierzEmail() << endl;
    cout << "Adres:              " << adresaci[index].pobierzAdres() << endl << endl;
}

void AdresatMenedzer :: wyszukajAdresatowPoImieniu() {

    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze :: wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (size_t i = 0; i < adresaci.size(); i++) {
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(i);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer :: wyszukajAdresatowPoNazwisku() {

    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze :: wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (size_t i = 0; i < adresaci.size(); i++) {
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(i);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer :: wyswietlIloscWyszukanychAdresatow(int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc poszukiwanych adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

int AdresatMenedzer :: podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze :: wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
};

void AdresatMenedzer :: usunAdresata() {

    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (size_t i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze :: wczytajZnak();
            if (znak == 't') {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(adresaci.begin() + i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

void AdresatMenedzer :: edytujAdresata() {
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (size_t i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze :: wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze :: wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze :: wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze :: wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze :: wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer :: wybierzOpcjeZMenuEdycja() {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze :: wczytajZnak();

    return wybor;
}
