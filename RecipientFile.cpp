#include "RecipientFile.h"

int RecipientFile :: getNewRecipientId() {
    fstream recipientFile;
    recipientFile.open(getFileName().c_str(), ios::in);
    int lastRecipientId = 0;
    string line = "";
    while(getline(recipientFile, line)) {
        size_t firstVerticalBarPosition = line.find('|');
        lastRecipientId = stoi(line.substr(0, firstVerticalBarPosition));
    }
    recipientFile.close();
    return lastRecipientId + 1;
}

void RecipientFile :: addRecipientToFile(Recipient recipient) {
    string lineWithRecipientData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithRecipientData = transformRecipientDataToSeparatedByVerticalBars(recipient);
        textFile << lineWithRecipientData << endl;
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    textFile.close();
    system("pause");
}

string RecipientFile :: transformRecipientDataToSeparatedByVerticalBars(Recipient recipient) {
    string lineWithRecipientData = "";

    lineWithRecipientData += AuxiliaryMethod :: convertIntToString(recipient.loadRecipientId()) + '|';
    lineWithRecipientData += AuxiliaryMethod :: convertIntToString(recipient.loadUserId()) + '|';
    lineWithRecipientData += recipient.getName() + '|';
    lineWithRecipientData += recipient.getSurname() + '|';
    lineWithRecipientData += recipient.getTelephone() + '|';
    lineWithRecipientData += recipient.getEmail() + '|';
    lineWithRecipientData += recipient.getAddress() + '|';

    return lineWithRecipientData;
}

vector <Recipient> RecipientFile :: loadLoggedUserRecipientsFromFile(int loggedUserId) {
    Recipient recipient;
    vector <Recipient> recipients;
    string singleRecipientDataSeparatedByVerticalBars = "";
    string lastRecipientDataInFile = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singleRecipientDataSeparatedByVerticalBars)) {
            if(loggedUserId == getUserIdFromDataSeparatedByVerticakBars(singleRecipientDataSeparatedByVerticalBars)) {
                recipient = getRecipientData(singleRecipientDataSeparatedByVerticalBars);
                recipients.push_back(recipient);
            }
        }
        lastRecipientDataInFile = singleRecipientDataSeparatedByVerticalBars;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    textFile.close();

    return recipients;
}

Recipient RecipientFile :: getRecipientData(string recipientDataSeparatedByVerticalBars) {
    string singleRecipientField = "";
    int singleRecipientFieldNumber = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < recipientDataSeparatedByVerticalBars.length(); pozycjaZnaku++) {
        if (recipientDataSeparatedByVerticalBars[pozycjaZnaku] != '|') {
            singleRecipientField += recipientDataSeparatedByVerticalBars[pozycjaZnaku];
        } else {
            switch(singleRecipientFieldNumber) {
            case 1:
                recipient.setRecipientId(atoi(singleRecipientField.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(singleRecipientField.c_str()));
                break;
            case 3:
                recipient.setName(singleRecipientField);
                break;
            case 4:
                recipient.setSurname(singleRecipientField);
                break;
            case 5:
                recipient.setTelephone(singleRecipientField);
                break;
            case 6:
                recipient.setEmail(singleRecipientField);
                break;
            case 7:
                recipient.setAddress(singleRecipientField);
                break;
            }
            singleRecipientField = "";
            singleRecipientFieldNumber++;
        }
    }
    return recipient;
}


int RecipientFile :: getUserIdFromDataSeparatedByVerticakBars(string singleRecipientDataSeparatedByVerticalBars) {
    int userBeginPosition = singleRecipientDataSeparatedByVerticalBars.find_first_of('|') + 1;
    int userId = AuxiliaryMethod :: convertStringToInt(AuxiliaryMethod :: getNumber(singleRecipientDataSeparatedByVerticalBars, userBeginPosition));

    return userId;
}

int RecipientFile :: getRecipientIdFromDataSeparatedByVerticakBars(string singleRecipientDataSeparatedByVerticalBars) {
    int recipientIdBeginPosition = 0;
    int recipientId = AuxiliaryMethod :: convertStringToInt(AuxiliaryMethod :: getNumber(singleRecipientDataSeparatedByVerticalBars, recipientIdBeginPosition));
    return recipientId;
}

void RecipientFile :: deleteChosenLineFromFile(int deletedRecipientId) {
    fstream textFile, temporaryTextFile;
    string loadedLine = "";

    textFile.open(getFileName().c_str(), ios::in);
    temporaryTextFile.open(temporaryRecipientFileName.c_str(), ios::out | ios::app);

    if (textFile.good() == true && deletedRecipientId != 0) {
        while (getline(textFile, loadedLine)) {
            size_t firstVerticalBarPosition = loadedLine.find('|');
            int recipientIdLoadedFromTextFile = stoi(loadedLine.substr(0, firstVerticalBarPosition));
            if(recipientIdLoadedFromTextFile != deletedRecipientId) {
                temporaryTextFile << loadedLine << endl;
            }
        }
        textFile.close();
        temporaryTextFile.close();

        deleteFile(getFileName());
        renameFile(temporaryRecipientFileName, getFileName());
    }
}

void RecipientFile :: deleteFile(string fileName) {
    if (remove(fileName.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << fileName << endl;
}

void RecipientFile :: renameFile(string fileOldName, string fileNewName) {
    if (rename(fileOldName.c_str(), fileNewName.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << fileOldName << endl;
}

void RecipientFile :: editChosenLineInFile(string recipientDataLineSeparatedByVerticalBars, int editedRecipientId) {
    fstream textFile, temporaryTextFile;
    string loadedLine = "";

    textFile.open(getFileName().c_str(), ios::in);
    temporaryTextFile.open(temporaryRecipientFileName.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        while (getline(textFile, loadedLine)) {
            size_t firstVerticalBarPosition = loadedLine.find('|');
            int loadedRecipientId = stoi(loadedLine.substr(0, firstVerticalBarPosition));
            if (loadedRecipientId == editedRecipientId) {
                temporaryTextFile << recipientDataLineSeparatedByVerticalBars << endl;
            } else {
                temporaryTextFile << loadedLine << endl;
            }
        }
        textFile.close();
        temporaryTextFile.close();

        deleteFile(getFileName());
        renameFile(temporaryRecipientFileName, getFileName());
    }
}

void RecipientFile :: updateChosenRecipientData(Recipient recipient, int editedRecipientId) {
    string lineWithRecipientData = "";
    lineWithRecipientData = transformRecipientDataToSeparatedByVerticalBars(recipient);
    editChosenLineInFile(lineWithRecipientData, editedRecipientId);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
