#ifndef USERSMANAGER_H
#define USERSMANAGER_H
#include <iostream>
#include <vector>

#include "User.h"
#include "UsernameFile.h"

class UsersManager
{
    int loggedUserId;
    vector <User> users;
    UsernameFile usernameFile;
    User typeNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    UsersManager(string UsernameFileName) : usernameFile(UsernameFileName) {
        loggedUserId = 0;
        users = usernameFile.getUsersFromFile();
        };
    void registration();
    void writeAllUsers();
    void logging();
    void loggedUserChangingPassword();
    void loggingOut();
    bool isUserLoggedIn();
    int getLoggedUserId();
};

#endif
