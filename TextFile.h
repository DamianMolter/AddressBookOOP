#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile {
    string FILE_NAME;
protected:
    TextFile(string fileName): FILE_NAME(fileName){};
    bool isFileEmpty();
    string getFileName();

};

#endif
