#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "AuxiliaryMethod.h"
#include "TextFile.h"

using namespace std;

class UserFile : protected TextFile{

    string singleUserDataSeparatedByVerticalBars;
    string transformUserDataToSeparatedByVerticalBars(User user);
    User loadSingleUserData(string singleUserDataSeparatedByVerticalBars);
public:
    UserFile(string userFileName) : TextFile(USERFILENAME){};
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector <User> users);

};
#endif
