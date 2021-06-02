#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <iostream>

#include "UsersManager.h"
#include "RecipientManager.h"



using namespace std;

class Adressbook
{
    UsersManager usersManager;
    RecipientManager *recipientManager;
    const string recipientsFilename;

public:


     Adressbook(string usersFilename, string RECIPIENTSFILENAME) :
	usersManager(usersFilename), recipientsFilename(RECIPIENTSFILENAME){};


    bool isUserLoggedIn();
    void registration();
    void writeAllUsers();
    void logging();
    void loggedUserChangingPassword();
    void loggingOut();
    void addRecipient();
    void findRecipientByName();
    void findRecipientByLastname();
    void displayAllRecipients();
    int deleteRecipient();
    void editRecipient();

};
#endif
