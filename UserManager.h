#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager {
    UserFile userFile;
    int loggedUserId;
    vector <User> users;
    User giveNewUserData();
    int getNewUserId();
    bool userNameExists(string userName);
    void saveAllUsersToFile();
public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId = 0;
        loadUsersFromFile();
    };
    bool isUserLogged();
    int getLoggedUserId();
    void userRegister();
    void displayAllUsers();
    void loadUsersFromFile();
    int userSignIn();
    void loggedUserPasswordChange();
    void userLogout();
};
#endif
