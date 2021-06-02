#include <iostream>

#include "AdressBook.h"
#include "UsernameFile.h"

using namespace std;

char chooseOptionFromMenu();
char chooseOptionFromUserMenu();
char getCharacter();

int main()
{
    Adressbook adressbook("Uzytkownicy.txt", "Adresaci.txt");


    char choice;

    while (true)
    {

        if (adressbook.isUserLoggedIn() == false)
        {
            choice = chooseOptionFromMenu();

            switch (choice)
            {
            case '1':
                adressbook.registration();
                break;
            case '2':
                adressbook.logging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                adressbook.addRecipient();
                break;
            case '2':
                adressbook.findRecipientByName();
                break;
            case '3':
                adressbook.findRecipientByLastname();
                break;
            case '4':
                adressbook.displayAllRecipients();
                break;
            case '5':
                adressbook.deleteRecipient();
                break;
            case '6':
                adressbook.editRecipient();
                break;
            case '7':
                adressbook.loggedUserChangingPassword();
                break;
            case '8':
                adressbook.loggingOut();
                break;
            }
        }
    }
    return 0;
}

char chooseOptionFromMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = getCharacter();

    return choice;
}

char chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = getCharacter();

    return choice;
}

char getCharacter()
{
    string entrance = "";
    char character  = {0};
    cin.sync();

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            character = entrance[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
