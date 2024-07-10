#include "RecipientManager.h"


int RecipientManager :: addRecipient() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Recipient recipient;
    recipient = giveNewRecipientData(LOGGED_RECIPIENT_ID);
    recipients.push_back(recipient);
    recipientFile.addRecipientToFile(recipient);

    return lastRecipientId + 1;
}

Recipient RecipientManager :: giveNewRecipientData(int loggedRecipientId) {
    Recipient recipient;
    string name, surname, telephone, email, address;
    recipient.setId(recipientFile.getNewRecipientId());
    recipient.setUserId(loggedRecipientId);

    cout << "Podaj imie: ";
    name = AuxiliaryMethod :: loadLine();
    name = AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(imie);

    cout << "Podaj nazwisko: ";
    surname = AuxiliaryMethod :: loadLine();
    surname = AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(nazwisko);

    cout << "Podaj numer telefonu: ";
    telephone = AuxiliaryMethod :: loadLine();

    cout << "Podaj email: ";
    email = AuxiliaryMethod :: loadLine();

    cout << "Podaj adres: ";
    adres = AuxiliaryMethod :: loadLine();

    recipient.setName(name);
    recipient.setSurname(surname);
    recipient.setTelephone(telephone);
    recipient.setEmail(email);
    recipient.setAddress(address);

    return recipient;
}

void RecipientManager :: displayAllRecipients() {
    system("cls");
    if (!recipients.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
            displayRecipientData(i);
        for (size_t i = 0; i < recipients.size(); i++) {
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void RecipientManager :: displayRecipientData(size_t index) {
    cout << endl << "Id:         " << recipients[index].loadId() << endl;
    cout << endl << "Id uzytkownika:" << recipients[index].loadUserId() << endl;
    cout << "Imie:               " << recipients[index].getName() << endl;
    cout << "Nazwisko:           " << recipients[index].getSurname() << endl;
    cout << "Numer telefonu:     " << recipients[index].getTelephone() << endl;
    cout << "Email:              " << recipients[index].getEmail() << endl;
    cout << "Adres:              " << recipients[index].getAddress() << endl << endl;
}

void RecipientManager :: findRecipientByName() {

    string wantedRecipientName = "";
    int recipientsAmount = 0;

    system("cls");
    if (!recipients.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        wantedRecipientName = AuxiliaryMethod :: loadLine();
        wantedRecipientName = AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(wantedRecipientName);

        for (size_t i = 0; i < recipients.size(); i++) {
            if (recipients[i].getName() == wantedRecipientName) {
                displayRecipientData(i);
                recipientsAmount++;
            }
        }
        displayFoundRecipientsAmount(recipientsAmount);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager :: findRecipientBySurname() {

    string wantedRecipientSurname = "";
    int recipientsAmount = 0;

    system("cls");
    if (!recipients.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        wantedRecipientSurname = AuxiliaryMethod :: loadLine();
        wantedRecipientSurname = AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(wantedRecipientSurname);

        for (size_t i = 0; i < recipients.size(); i++) {
            if (recipients[i].getSurname() == wantedRecipientSurname) {
                displayRecipientData(i);
                recipientsAmount++;
            }
        }
        displayFoundRecipientsAmount(recipientsAmount);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager :: displayFoundRecipientsAmount(int recipientsAmount) {
    if (recipientsAmount == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc poszukiwanych adresatow w ksiazce adresowej wynosi: " << recipientsAmount << endl << endl;
}

int RecipientManager :: giveChosenRecipientId() {
    int chosenRecipientId = 0;
    cout << "Podaj numer ID Adresata: ";
    chosenRecipientId  = AuxiliaryMethod :: loadInteger();
    return chosenRecipientId;
};

void RecipientManager :: deleteRecipient() {

    int deletedRecipientId = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    deletedRecipientId = giveChosenRecipientId();

    char character;
    bool doesRecipientExist = false;

    for (size_t i = 0; i < recipients.size(); i++) {
        if (recipients[i].loadRecipientId() == deletedRecipientId) {
            doesRecipientExist = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            character = AuxiliaryMethod :: loadCharacter();
            if (character == 't') {
                recipientFile.deleteChosenLineFromFile(deletedRecipientId);
                recipients.erase(recipients.begin() + i);
                cout << endl << endl << "Szukany recipient zostal USUNIETY" << endl << endl;
                system("pause");
            } else {
                cout << endl << endl << "Wybrany recipient NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (doesRecipientExist == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

void RecipientManager :: editRecipient() {
    system("cls");
    Recipient recipient;
    int editedRecipientId = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    editedRecipientId = giveChosenRecipientId();

    char choice;
    bool doesRecipientExist = false;

    for (size_t i = 0; i < recipients.size(); i++) {
        if (recipients[i].loadRecipientId() == editedRecipientId) {
            doesRecipientExist = true;
            choice = chooseRecipientEditMenuOption();

            switch (choice) {
            case '1':
                cout << "Podaj nowe imie: ";
                recipients[i].setName(AuxiliaryMethod :: loadLine());
                recipients[i].setName(AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(recipients[i].pobierzImie()));
                recipientFile.updateChosenRecipientData(recipients[i], editedRecipientId);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                recipients[i].setSurname(AuxiliaryMethod :: loadLine());
                recipients[i].setSurname(AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(recipients[i].pobierzNazwisko()));
                recipientFile.updateChosenRecipientData(recipients[i], editedRecipientId);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                recipients[i].setTelephone(AuxiliaryMethod :: loadLine());
                recipientFile.updateChosenRecipientData(recipients[i], editedRecipientId);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                recipients[i].setEmail(AuxiliaryMethod :: loadLine());
                recipientFile.updateChosenRecipientData(recipients[i], editedRecipientId);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                recipients[i].setAddress(AuxiliaryMethod :: loadLine());
                recipientFile.updateChosenRecipientData(recipients[i], editedRecipientId);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (doesRecipientExist == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char RecipientManager :: chooseRecipientEditMenuOption() {
    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj choice: ";
    choice = AuxiliaryMethod :: loadCharacter();

    return choice;
}
