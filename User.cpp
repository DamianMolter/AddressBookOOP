#include "User.h"

using namespace std;

int User :: getUserId() {
    return userId;
}
string User :: getUserName() {
    return userName;
}
string User :: getPassword() {
    return password;
}

void User :: setUserId(int newUserId) {

    if(newUserId >= 0) {
        userId = newUserId;
    }
}
void User :: setUserName (string newUserName) {
    userName = newUserName;
}
void User :: setPassword(string newPassword) {
    password = newPassword;
}
