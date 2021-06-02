#include "UsernameFile.h"

void UsernameFile::addUserToFile(User user)
{
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(userFileName.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = changeUserDataToLineDividedByPipes(user);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
        textFile.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << userFileName << " i zapisac w nim danych." << endl;
}

vector<User> UsernameFile::getUsersFromFile()
{
    User user;
    vector<User> users;
    string userDataDividedByPipes = "";
    fstream textFile;

    textFile.open(userFileName.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, userDataDividedByPipes))
        {
            user = getUserData(userDataDividedByPipes);
            users.push_back(user);
        }
        textFile.close();
    }
return users;
}

User UsernameFile::getUserData(string userDataDividedByPipes)
{
    User user;
    string userData = "";
    int userDataNumber = 1;

    for (int characterPosition = 0; characterPosition < userDataDividedByPipes.length(); characterPosition++)
    {
        if (userDataDividedByPipes[characterPosition] != '|')
        {
            userData += userDataDividedByPipes[characterPosition];
        }
        else
        {
            switch(userDataNumber)
            {
            case 1:
                user.setId(atoi(userData.c_str()));
                break;
            case 2:
                user.setLogin(userData);
                break;
            case 3:
                user.setPassword(userData);
                break;
            }
            userData = "";
            userDataNumber++;
        }
    }
    return user;
}

void UsernameFile::saveAllUsersToFile(vector <User> &users)
{
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(userFileName.c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithUserData = changeUserDataToLineDividedByPipes(*itr);

            if (itr == itrEnd)
            {
               textFile << lineWithUserData;
            }
            else
            {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
        textFile.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << userFileName << endl;
    }
}

string UsernameFile::changeUserDataToLineDividedByPipes(User user)
{
    string lineWithUserData = "";

    lineWithUserData += AuxiliaryMethods::convertionFromIntegerToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}
