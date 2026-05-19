#include <iostream>
#include "App.h"
#include "windows.h"

using namespace std;

int main() {

    App app("Users.txt" , "Recipients.txt");
    app.run();

    /*AddressBook addressBook;
    addressBook.wyswietlWszystkichUzytkownikow();
    addressBook.logowanieUzytkownika();
    addressBook.dodajAdresata();
    addressBook.wyswietlWszystkichAdresatow();
    addressBook.wylogowanieUzytkownika();*/


}
