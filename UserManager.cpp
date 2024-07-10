#include "UserManager.h"

int UserManager :: getLoggedUserId() {
    return loggedUserId;
}

void UserManager :: userRegister() {
    User user;
    user = giveNewUserData();
    users.push_back(user);
    userFile.addUserToFile(user);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UserManager :: getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager :: userNameExists(string userName) {

    for(size_t i = 0; i < users.size(); i++) {
        if (users[i].setUserName() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        } else {
            i++;
        }
    }
    return false;
}

void UserManager :: displayAllUsers() {
    for (size_t i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getPassword() << endl << endl;
    }

}
Uzytkownik UserManager :: giveNewUserData() {
    string userName, password;
    User user;
    user.setId(getNewUserId());

    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        user.setUserName(userName);
    } while (userNameExists(user.getUserName()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

void UserManager :: loadUsersFromFile() {
    users = userFile.loadUsersFromFile();
}

int UserManager :: userSignIn() {
    string userName = "", password = "";

    cout << endl << "Podaj login: ";
    userName = AuxiliaryMethod:: loadLine();

    for(size_t i = 0; i < users.size(); i++) {
        if (users[i].getUserName() == userName) {
            for (int attemptsRemained = 3; attemptsRemained > 0; attemptsRemained--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsRemained << ": ";
                password = AuxiliaryMethod :: loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = users[i].getId();
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager :: loggedUserPasswordChange() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";

    newPassword = MetodyPomocnicze :: wczytajLinie();

    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getId() == loggedUserId) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    saveAllUsersToFile();
}

void UserManager :: saveAllUsersToFile() {

    plikZUzytkownikami.saveAllUsersToFile(users);
}

bool UserManager :: isUserLogged() {
    if(loggedUserId > 0) {
        return true;
    } else {
        return false;
    }
};

void UserManager :: userLogout() {
    loggedUserId = 0;
};
