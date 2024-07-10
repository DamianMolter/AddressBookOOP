#include <iostream>
#include "AddressBook.h"
#include "windows.h"

using namespace std;

int main() {

    AddressBook addressBook("Users.txt" , "Recipients.txt");

    while (true) {
        if (!addressBook.isUserLogged()) {
            char choice = addressBook.pickOptionMainMenu();

            switch (choice) {
            case '1':
                addressBook.userRegister();
                break;
            case '2':
                addressBook.userSignIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            char choice = addressBook.pickOptionUserMenu();

            switch (choice) {
            case '1':
                addressBook.addRecipient();
                break;
            case '2':
                addressBook.findRecipientByName();
                break;
            case '3':
                addressBook.findRecipientBySurname();
                break;
            case '4':
                addressBook.displayAllRecipients();
                break;
            case '5':
                addressBook.deleteRecipient();
                break;
            case '6':
                addressBook.editRecipient();
                break;
            case '7':
                addressBook.loggedUserPasswordChange();
                break;
            case '8':
                addressBook.userLogout();
                break;
            }
        }
    }







    /*AddressBook addressBook;
    addressBook.wyswietlWszystkichUzytkownikow();
    addressBook.logowanieUzytkownika();
    addressBook.dodajAdresata();
    addressBook.wyswietlWszystkichAdresatow();
    addressBook.wylogowanieUzytkownika();*/

    return 0;
}
