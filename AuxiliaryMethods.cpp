#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertionFromIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertionFromStringToInteger(string number)
{
    int numberAsInteger;
    istringstream iss(number);
    iss >> numberAsInteger;
    return numberAsInteger;
}




