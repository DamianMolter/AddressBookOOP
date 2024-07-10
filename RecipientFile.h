#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include "UserManager.h"
#include "AuxiliaryMethod.h"
#include "Recipient.h"
#include "TextFile.h"

using namespace std;

class RecipientFile : protected TextFile {
    Recipient recipient;
    int lastRecipientId;
    string temporaryRecipientFileName;
    string transformRecipientDataToSeparatedByVerticalBars(Recipient recipient);
    int getUserIdFromDataSeparatedByVerticakBars(string singleRecipientDataSeparatedByVerticalBars);
    Recipient getRecipientData(string recipientDataSeparatedByVerticalBars);
    int getRecipientIdFromDataSeparatedByVerticakBars(string recipientDataSeparatedByVerticalBars);
    int getLastRecipientId();
    void deleteFile(string fileName);
    void renameFile(string fileOldName, string fileNewName);
public:
    RecipientFile(string RECIPIENTFILENAME) : TextFile(RECIPIENTFILENAME) {
    lastRecipientId = 0;
    temporaryRecipientFileName = "Adresaci_temp.txt";
};
    void addRecipientToFile(Recipient recipient);
    vector <Recipient> loadLoggedUserRecipientsFromFile(int loggedUserId);
    int getNewRecipientId();
    void deleteChosenLineFromFile(int deletedRecipientId);
    void editChosenLineInFile(string recipientDataLineSeparatedByVerticalBars, int editedRecipientId);
    void updateChosenRecipientData(Recipient recipient, int editedRecipientId);
};
