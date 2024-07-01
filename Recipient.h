#ifndef RECIPIENT_H
#define RECIPIENT_H
#include <iostream>

using namespace std;

class Recipient {

    int recipientId, userId;
    string name, surname, telephone, email, address;
public:
    Recipient(int recipientId=0, int userId=0, string name="", string surname="", string telephone="", string email="", string address="") {
        this->recipientId=recipientId;
        this->userId=userId;
        this->name=name;
        this->surname=surname;
        this->telephone=telephone;
        this->email=email;
        this->address=address;
    }
    int loadRecipientId();
    int loadUserId();
    string getName();
    string getSurname();
    string getTelephone();
    string getEmail();
    string getAddress();
    void setRecipientId(int newRecipientId);
    void setUserId(int newUserId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setTelephone(string newTelephone);
    void setEmail(string newEmail);
    void setAddress(string newAddress);
};

#endif
