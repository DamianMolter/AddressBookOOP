#include "AddressBook.h"


void AddressBook::userRegister() {

    userManager.userRegister();

}

bool AddressBook :: isUserLogged() {
    if(userManager.isUserLogged()) {
        return true;
    } else {
        return false;
    }
}

void AddressBook :: userSignIn() {

    userManager.userSignIn();

    if(userManager.isUserLogged()) {
        recipientManager = new RecipientManager(userManager.getLoggedUserId(), RECIPIENT_FILE_NAME);
    }

}

void AddressBook :: displayAllUsers() {

    userManager.displayAllUsers();
}

void AddressBook :: loggedUserPasswordChange() {

    userManager.loggedUserPasswordChange();

}

void AddressBook :: addRecipient() {

    if(userManager.isUserLogged()) {
        recipientManager->addRecipient();
    }
}

void AddressBook :: displayAllRecipients() {

    if(userManager.isUserLogged()) {
        recipientManager->displayAllRecipients();
    }
}

void AddressBook :: userLogout() {
    userManager.userLogout();
    delete recipientManager;
    recipientManager = NULL;
    cout << "Pomyslnie wylogowao." << endl;
}

char AddressBook :: pickOptionMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethod :: loadCharacter();

    return choice;
}

char AddressBook :: pickOptionUserMenu() {
    char choice;

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
    cout << "Twoj choice: ";
    choice = AuxiliaryMethod :: loadCharacter();

    return choice;
}

void AddressBook :: findRecipientByName() {

    recipientManager->findRecipientByName();

}

void AddressBook :: findRecipientBySurname() {

    recipientManager->findRecipientBySurname();

}

void AddressBook :: deleteRecipient() {
    recipientManager->deleteRecipient();
}

void AddressBook :: editRecipient() {
    recipientManager->editRecipient();
}
