#include "KsiazkaAdresowa.h"

KsiazkaAdresowa :: KsiazkaAdresowa(){

    uzytkownikMenedzer.wczytajUzytkownikowZPliku();

}

void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

int KsiazkaAdresowa :: logowanieUzytkownika(){

    return uzytkownikMenedzer.logowanieUzytkownika();

}

void KsiazkaAdresowa :: wyswietlWszystkichUzytkownikow(){

    uzytkownikMenedzer.wyswietlWszystkichUzytkownikow();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();

}

void KsiazkaAdresowa :: dodajAdresata(int IdZalogowanegoUzytkownika){

    adresatMenedzer.dodajAdresata(IdZalogowanegoUzytkownika);

}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow(){

    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa :: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){

    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);

}

int KsiazkaAdresowa :: wylogowanieUzytkownika(){
    idZalogowanegoUzytkownika = 0;
    cout << "Pomyslnie wylogowano." << endl;
    cout << idZalogowanegoUzytkownika << endl;
    return idZalogowanegoUzytkownika;
}
