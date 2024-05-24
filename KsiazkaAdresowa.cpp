#include "KsiazkaAdresowa.h"

KsiazkaAdresowa :: KsiazkaAdresowa(){

    uzytkownikMenedzer.wczytajUzytkownikowZPliku();

}

void KsiazkaAdresowa::rejestracjaUzytkownika(){

    uzytkownikMenedzer.rejestracjaUzytkownika();

}

void KsiazkaAdresowa :: logowanieUzytkownika(){

    uzytkownikMenedzer.logowanieUzytkownika();

}

void KsiazkaAdresowa::wyswietlWszystkichUzytkownikow(){

    uzytkownikMenedzer.wyswietlWszystkichUzytkownikow();
}

