#include "UsersManager.h"

void UsersManager::registration()
{
    User user = typeNewUserData();
    users.push_back(user);
    usernameFile.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie." << endl << endl;
    system("pause");
}

User UsersManager::typeNewUserData()
{
    User user;
    user.setId(getNewUserId());
    string login;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    string password;

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UsersManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UsersManager::isLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UsersManager::writeAllUsers(){
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UsersManager::logging()
{
    string login = "", password = "";

    cout << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    loggedUserId = itr -> getId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UsersManager::loggingOut()
{
    loggedUserId = 0;
}

void UsersManager::loggedUserChangingPassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usernameFile.saveAllUsersToFile(users);
}

bool UsersManager::isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UsersManager::getLoggedUserId()
{
    return loggedUserId;
}
