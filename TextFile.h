#ifndef TEXTFILE_H
#define TEXTFILE_H
#include <iostream>
#include <vector>
#include <fstream>
#include "AuxiliaryMethods.h"
#include <cstdlib>
#include "Recipient.h"


class TextFile
{
    const string NAZWA_PLIKU;
protected:
    fstream textFile;
    bool isFileEmpty(fstream &textFile);
};
#endif
