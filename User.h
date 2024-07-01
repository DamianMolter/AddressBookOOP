#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userId;
    string userName;
    string password;

public:

    int getUserId();
    string getUserName();
    string getPassword();

    void setUserId(int newUserId);
    void setUserName (string newUserName);
    void setPassword(string newPassword);
};

#endif
