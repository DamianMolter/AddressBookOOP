#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer :: rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    PlikZUzytkownikami plikZUzytkownikami;
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UzytkownikMenedzer :: pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer :: czyIstniejeLogin(string login) {

    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        } else {
            i++;
        }
    }
    return false;
}

void UzytkownikMenedzer :: wyswietlWszystkichUzytkownikow() {
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl << endl;
    }

}
Uzytkownik UzytkownikMenedzer :: podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;
    string login, haslo;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

void UzytkownikMenedzer :: wczytajUzytkownikowZPliku(){
    PlikZUzytkownikami plikZUzytkownikami;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
