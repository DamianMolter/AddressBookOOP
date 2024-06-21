#include "AdresatMenedzer.h"


int AdresatMenedzer :: dodajAdresata(){
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Adresat adresat;
    adresat = podajDaneNowegoAdresata(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return idOstatniegoAdresata + 1;
}

Adresat AdresatMenedzer :: podajDaneNowegoAdresata(int idZalogowanegoUzytkownika){
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

void AdresatMenedzer :: wyswietlWszystkichAdresatow(){
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i = 0; i < adresaci.size(); i++)
        {
            wyswietlDaneAdresata(i);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer :: wyswietlDaneAdresata(size_t index){
    cout << endl << "Id:         " << adresaci[index].pobierzId() << endl;
    cout << endl << "Id uzytkownika:" << adresaci[index].pobierzIdUzytkownika() << endl;
    cout << "Imie:               " << adresaci[index].pobierzImie() << endl;
    cout << "Nazwisko:           " << adresaci[index].pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresaci[index].pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresaci[index].pobierzEmail() << endl;
    cout << "Adres:              " << adresaci[index].pobierzAdres() << endl << endl;
}

void AdresatMenedzer :: wyszukajAdresatowPoImieniu(){

    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze :: wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (size_t i = 0; i < adresaci.size(); i++)
        {
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(i);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer :: wyszukajAdresatowPoNazwisku(){

    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze :: wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (size_t i = 0; i < adresaci.size(); i++)
        {
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(i);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer :: wyswietlIloscWyszukanychAdresatow(int iloscAdresatow){
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc poszukiwanych adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}
