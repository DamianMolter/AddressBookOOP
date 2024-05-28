#include "AdresatMenedzer.h"

AdresatMenedzer :: AdresatMenedzer(){

    if(adresaci.empty()){
        idOstatniegoAdresata = 0;
    } else {
        idOstatniegoAdresata = adresaci.back().pobierzId();
    }
}

int AdresatMenedzer :: dodajAdresata()
{
    PlikZAdresatami plikZAdresatami;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return idOstatniegoAdresata + 1;
}

Adresat AdresatMenedzer :: podajDaneNowegoAdresata()
{
    adresat.ustawId(pobierzIdNowegoAdresata());
    adresat.ustawIdUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze :: wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze :: wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze :: wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze :: wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze :: wczytajLinie());

    return adresat;
}

int AdresatMenedzer :: pobierzIdNowegoAdresata() {
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}

void AdresatMenedzer :: wyswietlWszystkichAdresatow()
{
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

void AdresatMenedzer :: wyswietlDaneAdresata(size_t index)
{
    cout << endl << "Id:         " << adresaci[index].pobierzId() << endl;
    cout << endl << "Id uzytkownika:" << adresaci[index].pobierzIdUzytkownika() << endl;
    cout << "Imie:               " << adresaci[index].pobierzImie() << endl;
    cout << "Nazwisko:           " << adresaci[index].pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresaci[index].pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresaci[index].pobierzEmail() << endl;
    cout << "Adres:              " << adresaci[index].pobierzAdres() << endl << endl;
}
