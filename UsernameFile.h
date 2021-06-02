#ifndef USERNAMEFILE
#define USERNAMEFILE

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class UsernameFile : public TextFile
{
    const string userFileName;
    string changeUserDataToLineDividedByPipes(User user);
    User getUserData(string SingleUserDataDividedByPipes);


public:
    UsernameFile(string userFileName) : userFileName(userFileName) {};
    void addUserToFile(User user);
    vector<User> getUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
