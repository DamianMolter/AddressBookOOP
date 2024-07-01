#include "Recipient.h"

int Recipient :: loadRecipientId() {
    return recipientId;
}

int Recipient :: loadUserId() {
    return userId;
}

string Recipient :: getName() {
    return name;
}

string Recipient :: getSurname() {
    return surname;
}

string Recipient :: getTelephone() {
    return telephone;
}

string Recipient :: getEmail() {
    return email;
}

string Recipient :: getAddress() {
    return address;
}

void Recipient :: setRecipientId(int newRecipientId) {
    if(newRecipientId >= 0) {
        recipientId = newRecipientId;
    }
}

void Recipient :: setUserId(int newUserId) {
    if(newUserId >= 0) {
        userId = newUserId;
    }
}

void Recipient :: setName (string newName) {
    name = newName;
}

void Recipient :: setSurname(string newSurname) {
    surname = newSurname;
}

void Recipient :: setTelephone (string newTelephone) {
    telephone = newTelephone;
}

void Recipient :: setEmail(string newEmail) {
    email = newEmail;
}

void Recipient :: setAddress(string newAddress) {
    address = newAddress;
}
