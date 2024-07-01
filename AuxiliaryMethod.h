#ifndef AUXILIARYMETHOD_H
#define AUXILIARYMETHOD_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class AuxiliaryMethod {
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string figureSequence);
    static string loadLine();
    static string getNumber(string text, int characterPosition);
    static string transformFirstUpperCaseAndRestToLowerCase(string tekst);
    static char loadCharacter();
    static int loadInteger();
};
#endif
