#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

bool KsiazkaAdresowa :: czyUzytkownikJestZalogowany(){
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        return true;
    } else {
        return false;
    }
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

char KsiazkaAdresowa :: wybierzOpcjeZMenuGlownego(){
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze :: wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa :: wybierzOpcjeZMenuUzytkownika(){
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze :: wczytajZnak();

    return wybor;
}
