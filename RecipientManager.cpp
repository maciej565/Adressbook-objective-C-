#include "RecipientManager.h"

void RecipientManager::addRecipient()
{
    Recipient recipient;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    recipient = typeNewRecipientData();

    recipients.push_back(recipient);
    recipientFile.addRecipientToFile(recipient);
}

Recipient RecipientManager::typeNewRecipientData()
{
    Recipient recipient;
    string name, lastname;
    recipient.setRecipientId(recipientFile.getRecipientId() + 1);
    recipient.setUserId(loggedUserId);

    cout << "Podaj imie: ";
    name = loadLine();
    recipient.setName(changingFirstLetterToBiggerButOthersToSmaller(name));

    cout << "Podaj nazwisko: ";
    lastname = loadLine();
    recipient.setLastname(changingFirstLetterToBiggerButOthersToSmaller(lastname));

    cout << "Podaj numer telefonu: ";
    recipient.setTelephoneNumber(loadLine());

    cout << "Podaj email: ";
    recipient.setEmail(loadLine());

    cout << "Podaj adres: ";
    recipient.setAdress(loadLine());

    return recipient;
}

void RecipientManager::displayAllRecipients()
{
    system("cls");
    if (!recipients.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Recipient> :: iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            displayRecipientData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}


void RecipientManager::displayRecipientData(Recipient recipient)
{
    cout << endl << "Id:                 " << recipient.getRecipientId() << endl;
    cout << "Imie:               " << recipient.getName() << endl;
    cout << "Nazwisko:           " << recipient.getLastname() << endl;
    cout << "Numer telefonu:     " << recipient.getTelephoneNumber() << endl;
    cout << "Email:              " << recipient.getEmail() << endl;
    cout << "Adres:              " << recipient.getAdress() << endl;
}

void RecipientManager::findRecipientByName()
{
    string FindedRecipientName = "";
    int RecipientNumber = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        FindedRecipientName = loadLine();
        FindedRecipientName = changingFirstLetterToBiggerButOthersToSmaller(FindedRecipientName);

        for (vector <Recipient>::iterator  itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getName() == FindedRecipientName)
            {
                displayRecipientData(*itr);
                RecipientNumber++;
            }
        }
        displayFindedRecipientsNumber(RecipientNumber);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::findRecipientByLastname()
{
    string findedRecipientLastname;
    int RecipientNumber = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        findedRecipientLastname = loadLine();
        findedRecipientLastname = changingFirstLetterToBiggerButOthersToSmaller(findedRecipientLastname);

        for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getLastname() == findedRecipientLastname)
            {
                displayRecipientData(*itr);
                RecipientNumber++;
            }
        }
         displayFindedRecipientsNumber(RecipientNumber);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::displayFindedRecipientsNumber(int RecipientNumber)
{
    if (RecipientNumber == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << RecipientNumber << endl << endl;
}

int RecipientManager::deleteRecipient()
{
    int deletedRecipientId = 0;
    int deletedRecipientLineNumber = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    deletedRecipientId = typeRecipientId();

    char character;
    bool isRecipientExist = false;

    for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
    {
        if (itr -> getRecipientId() == deletedRecipientId)
        {
            isRecipientExist = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            character = getCharacter();
            if (character == 't')
            {
                deletedRecipientLineNumber = recipientFile.returnFindedRecipientLineNumber(deletedRecipientId);
                recipientFile.deleteLineInFile(deletedRecipientLineNumber);
                recipients.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return deletedRecipientId;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (isRecipientExist == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}


string RecipientManager::getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

void RecipientManager::editRecipient()
{
    system("cls");
    Recipient recipient;
    int editedRecipientId = 0;
    int editedRecipientLineNumber = 0;
    string recipientLineWithData = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    editedRecipientId = typeRecipientId();

    char choice;
    bool isRecipientExist = false;

    for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
    {
        if (itr -> getRecipientId() == editedRecipientId)
        {
            isRecipientExist = true;
            choice = chooseOptionFromEditionMenu();

            switch (choice)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                itr -> setName(loadLine());
                itr -> setName(changingFirstLetterToBiggerButOthersToSmaller(itr -> getName()));
                updateEditedRecipientData(*itr, editedRecipientId);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                itr -> setLastname(loadLine());
                itr -> setLastname(changingFirstLetterToBiggerButOthersToSmaller(itr -> getLastname()));
                updateEditedRecipientData(*itr, editedRecipientId);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr -> setTelephoneNumber(loadLine());
                updateEditedRecipientData(*itr, editedRecipientId);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                itr -> setEmail(loadLine());
                updateEditedRecipientData(*itr, editedRecipientId);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                itr -> setAdress(loadLine());
                updateEditedRecipientData(*itr, editedRecipientId);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (isRecipientExist == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

int RecipientManager::typeRecipientId()
{
    int chosenRecipientId = 0;
    cout << "Podaj numer ID Adresata: ";
    chosenRecipientId  = getInteger();
    return chosenRecipientId;
}

int RecipientManager::getInteger()
{
    string entrance = "";
    int number = 0;
    cin.sync();

    while (true)
    {
        getline(cin, entrance);

        stringstream myStream(entrance);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

char RecipientManager::chooseOptionFromEditionMenu()
{
    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    choice = getCharacter();

    return choice;
}

char RecipientManager::getCharacter()
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

string RecipientManager::loadLine()
{
    string entrance;
    cin.sync();
    getline(cin, entrance);
    return entrance;
}

void RecipientManager::updateEditedRecipientData(Recipient recipient, int editedRecipientId)
{
    int editedRecipientLineNumber = 0;
    string recipientLineWithData = "";

    editedRecipientLineNumber = recipientFile.returnFindedRecipientLineNumber(editedRecipientId);
    recipientLineWithData = recipientFile.changingRecipientDataToLineWithDataDividedByPipes(recipient);
    recipientFile.editLineInFile(editedRecipientLineNumber, recipientLineWithData);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

string RecipientManager::changingFirstLetterToBiggerButOthersToSmaller(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int RecipientManager::getRecipientIdFromDataDividedByPipes(string RecipientDataDividedByPipes)
{
    int recipientIdStartingPosition = 0;
    int recipientsId = AuxiliaryMethods::convertionFromStringToInteger(getNumber(RecipientDataDividedByPipes, recipientIdStartingPosition));
    return recipientsId;
}
