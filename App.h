#include <iostream>
#include "AddressBook.h"
#include "windows.h"

class App{
    AddressBook addressBook;
public:
    App(string userFileName, string recipientFileName):addressBook(userFileName, recipientFileName){}
    void run();
};
