#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>
#include "UserManager.h"
#include "RecipientManager.h"


using namespace std;

class AddressBook {
    UserManager userManager;
    RecipientManager *recipientManager;
    const string RECIPIENT_FILE_NAME;
public:
    AddressBook(string userFileName, string recipientFileName)
    :userManager(userFileName), RECIPIENT_FILE_NAME(recipientFileName) {
        recipientManager = NULL;
    };
    ~AddressBook() {
        delete recipientManager;
        recipientManager = NULL;
    }
    void userRegister();
    void displayAllUsers();
    void userSignIn();
    void loggedUserPasswordChange();
    void addRecipient();
    void displayAllRecipients();
    void userLogout();
    bool isUserLogged();
    char pickOptionMainMenu();
    char pickOptionUserMenu();
    void findRecipientByName();
    void findRecipientBySurname();
    void deleteRecipient();
    void editRecipient();
};

#endif
