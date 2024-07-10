#ifndef RECIPIENTMANAGER_H
#define RECIPIENTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include "UserManager.h"
#include "AuxiliaryMethod.h"
#include "Recipient.h"
#include "RecipientFile.h"

using namespace std;

class RecipientManager {

    RecipientFile recipientFile;
    const int LOGGED_USER_ID;
    int lastRecipientId;
    vector <Recipient> recipients;
    Recipient giveNewRecipientData(int loggedUserId);
    void displayRecipientData(size_t index);
    void displayFoundRecipientsAmount(int recipientsAmount);
    int giveChosenRecipientId();
    char loggedUserPasswordChange();
    char chooseRecipientEditMenuOption();
public:
    RecipientManager(int loggedUserId, string recipientFileName): recipientFile(recipientFileName), LOGGED_USER_ID(loggedUserId) {
        recipients = recipientFile.loadLoggedUserRecipientsFromFile(LOGGED_USER_ID);
    };
    int addRecipient();
    void displayAllRecipients();
    void findRecipientByName();
    void findRecipientBySurname();
    void deleteRecipient();
    void editRecipient();
};




#endif
