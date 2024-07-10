#include "UserFile.h"

string UserFile :: transformUserDataToSeparatedByVerticalBars(User user) {
    string lineWithUserData = "";

    lineWithUserData += AuxiliaryMethod::convertIntToString(user.pobierzId())+ '|';
    lineWithUserData += user.getUserName() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

void UserFile :: addUserToFile(User user) {
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithUserData = transformUserDataToSeparatedByVerticalBars(user);

        if (AuxiliaryMethod :: isFileEmpty() == true) {
            textFile << lineWithUserData;
        } else {
            textFile << lineWithUserData << endl;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;
    textFile.close();
}

vector <User> UserFile :: loadUsersFromFile() {
    User user;
    vector <User> users;
    string singleUserDataSeparatedByVerticalBars = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singleUserDataSeparatedByVerticalBars)) {
            user = loadSingleUserData(singleUserDataSeparatedByVerticalBars);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}

User UserFile :: loadSingleUserData(string singleUserDataSeparatedByVerticalBars) {
    User user;
    string userSingleField = "";
    int userSingleFieldNumber = 1;

    for (size_t characterPosition = 0; characterPosition < singleUserDataSeparatedByVerticalBars.length(); characterPosition++) {
        if (singleUserDataSeparatedByVerticalBars[characterPosition] != '|') {
            userSingleField += singleUserDataSeparatedByVerticalBars[characterPosition];
        } else {
            switch(userSingleFieldNumber) {
            case 1:
                user.setUserId(atoi(userSingleField.c_str()));
                break;
            case 2:
                user.setUserName(userSingleField);
                break;
            case 3:
                user.setPassword(userSingleField);
                break;
            }
            userSingleField = "";
            userSingleFieldNumber++;
        }
    }
    return user;
}

void UserFile :: saveAllUsersToFile(vector <User> users) {
    fstream textFile;
    string lineWithUserData = "";

    textFile.open(getFileName().c_str(), ios::out);

    if (textFile.good() == true) {
        for (size_t i = 0; i < users.size(); i++) {
            lineWithUserData = transformUserDataToSeparatedByVerticalBars(users[i]);
            textFile << lineWithUserData << endl;
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }
    textFile.close();
}


