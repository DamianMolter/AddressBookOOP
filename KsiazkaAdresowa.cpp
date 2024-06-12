#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

void KsiazkaAdresowa :: logowanieUzytkownika(){

   uzytkownikMenedzer.logowanieUzytkownika();

   if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer = new AdresatMenedzer(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
   }

}

void KsiazkaAdresowa :: wyswietlWszystkichUzytkownikow(){

    uzytkownikMenedzer.wyswietlWszystkichUzytkownikow();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();

}

void KsiazkaAdresowa :: dodajAdresata(){

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer->dodajAdresata();
   }
}

void KsiazkaAdresowa :: wyswietlWszystkichAdresatow(){

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer->wyswietlWszystkichAdresatow();
   }
}

void KsiazkaAdresowa :: wylogowanieUzytkownika(){
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
    cout << "Pomyslnie wylogowao." << endl;
}
