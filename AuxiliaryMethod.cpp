#include "AuxiliaryMethod.h"

string AuxiliaryMethod :: convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethod :: loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethod :: transformFirstUpperCaseAndRestToLowerCase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethod :: convertStringToInt(string figureSequence) {
    int intNumber;
    istringstream iss(figureSequence);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethod :: getNumber(string text, int characterPosition) {
    string number = "";
    while(isdigit(text[characterPosition]) == true) {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

char AuxiliaryMethod ::loadCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int AuxiliaryMethod :: loadInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
