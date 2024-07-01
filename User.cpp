#include "User.h"

using namespace std;

int Uzytkownik :: getUserId() {
    return userId;
}
string User :: getUserName() {
    return userName;
}
string User :: getPassword() {
    return password;
}

void User :: setId(int newUserId) {

    if(newId >= 0) {
        id = newId;
    }
}
void User :: setUserName (string newUserName) {
    userName = newUserName;
}
void User :: setPassword(string newPassword) {
    password = newPassword;
}
