#include "Adressbook.h"

void Adressbook::registration()
{
    usersManager.registration();
}
void Adressbook::writeAllUsers()
{
    usersManager.writeAllUsers();
}
void Adressbook::logging()
{
    usersManager.logging();
    if (usersManager.isUserLoggedIn())
    {
        recipientManager = new RecipientManager (recipientsFilename, usersManager.getLoggedUserId());
    }
}
void Adressbook::loggedUserChangingPassword()
{
    usersManager.loggedUserChangingPassword();
}
void Adressbook::loggingOut()
{
    usersManager.loggingOut();
    delete recipientManager;
    recipientManager = NULL;
}
void Adressbook::addRecipient()
{
    if (usersManager.isUserLoggedIn())
    {
        recipientManager->addRecipient();
    }
    else
    {
        cout << "Zaloguj sie, by dodac adresata." << endl;
        system("pause");
    }
}
void Adressbook::displayAllRecipients()
{
    recipientManager->displayAllRecipients();
}
bool Adressbook::isUserLoggedIn()
{
    usersManager.isUserLoggedIn();
}

void Adressbook::findRecipientByName()
{
    recipientManager->findRecipientByName();
}

void Adressbook::findRecipientByLastname()
{
    recipientManager->findRecipientByLastname();
}

int Adressbook::deleteRecipient()
{
    recipientManager->deleteRecipient();
}

void Adressbook::editRecipient()
{
    recipientManager->editRecipient();
}
