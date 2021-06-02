#include "RecipientFile.h"

vector<Recipient> RecipientFile::loadLoggedUserRecipientsFromFile(int loggedUserId)
{
    Recipient recipient;
    vector <Recipient> recipients;
    string recipientDataDividedByPipes = "";
    string recipientDataInFile = "";
    fstream textFile;

    textFile.open(recipientFilename.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, recipientDataDividedByPipes))
        {
            if(loggedUserId == getUserIdFromDataDividedByPipes(recipientDataDividedByPipes))
            {
                recipient = getRecipientData(recipientDataDividedByPipes);
                recipients.push_back(recipient);
            }
        }
        recipientDataInFile = recipientDataDividedByPipes;
        textFile.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (recipientDataInFile != "")
    {
        recipientId = getRecipientIdFromDataDividedByPipes(recipientDataInFile);
    }
    return recipients;
}

int RecipientFile::getUserIdFromDataDividedByPipes(string recipientDataDividedByPipes)
{
    int startedUserIdPosition = recipientDataDividedByPipes.find_first_of('|') + 1;
    int userId = AuxiliaryMethods::convertionFromStringToInteger(getNumber(recipientDataDividedByPipes, startedUserIdPosition));

    return userId;
}

Recipient RecipientFile::getRecipientData(string recipientDataDividedByPipes)
{
    Recipient recipient;
    string recipientData = "";
    int recipientDataNumber = 1;

    for (int characterPosition = 0; characterPosition < recipientDataDividedByPipes.length(); characterPosition++)
    {
        if (recipientDataDividedByPipes[characterPosition] != '|')
        {
            recipientData += recipientDataDividedByPipes[characterPosition];
        }
        else
        {
            switch(recipientDataNumber)
            {
            case 1:
                recipient.setRecipientId(atoi(recipientData.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(recipientData.c_str()));
                break;
            case 3:
                recipient.setName(recipientData);
                break;
            case 4:
                recipient.setLastname(recipientData);
                break;
            case 5:
                recipient.setTelephoneNumber(recipientData);
                break;
            case 6:
                recipient.setEmail(recipientData);
                break;
            case 7:
                recipient.setAdress(recipientData);
                break;
            }
            recipientData = "";
            recipientDataNumber++;
        }
    }
    return recipient;
}

void RecipientFile::addRecipientToFile(Recipient recipient)
{
    string lineWithRecipientData = "";
    fstream textFile;
    textFile.open(recipientFilename.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithRecipientData = changingRecipientDataToLineWithDataDividedByPipes(recipient);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithRecipientData;
        }
        else
        {
            textFile << endl << lineWithRecipientData ;
        }

        textFile.close();
        cout << endl << "Dodano adresata." << endl << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    system("pause");
}

string RecipientFile::changingRecipientDataToLineWithDataDividedByPipes(Recipient recipient)
{
    string lineWithRecipientData = "";
    lineWithRecipientData += AuxiliaryMethods::convertionFromIntegerToString(recipient.getRecipientId()) + '|';
    lineWithRecipientData += AuxiliaryMethods::convertionFromIntegerToString(recipient.getUserId()) + '|';
    lineWithRecipientData += recipient.getName() + '|';
    lineWithRecipientData += recipient.getLastname() + '|';
    lineWithRecipientData += recipient.getTelephoneNumber() + '|';
    lineWithRecipientData += recipient.getEmail() + '|';
    lineWithRecipientData += recipient.getAdress() + '|';

    return lineWithRecipientData;
}

int RecipientFile::getRecipientId()
{
    return recipientId;
}

void RecipientFile::deleteLineInFile(int deletedLineNumber)
{
    fstream loadedTextfile, temporaryTextfile;
    string loadedLine = "";
    int loadedLineNumber = 1;

    loadedTextfile.open(recipientFilename.c_str(), ios::in);
    temporaryTextfile.open(temporaryRecipientFilename.c_str(), ios::out | ios::app);

    if (loadedTextfile.good() == true && deletedLineNumber != 0)
    {
        while (getline(loadedTextfile, loadedLine))
        {
            if (loadedLineNumber == deletedLineNumber) {}
            else if (loadedLineNumber == 1 && loadedLineNumber != deletedLineNumber)
                temporaryTextfile << loadedLine;
            else if (loadedLineNumber == 2 && deletedLineNumber == 1)
                temporaryTextfile << loadedLine;
            else if (loadedLineNumber > 2 && deletedLineNumber == 1)
                temporaryTextfile << endl << loadedLine;
            else if (loadedLineNumber > 1 && deletedLineNumber != 1)
                temporaryTextfile << endl << loadedLine;
            loadedLineNumber++;
        }
        loadedTextfile.close();
        temporaryTextfile.close();

        deleteLoadedFile(recipientFilename);
        changeTemporaryFilenameToNewLoadedFilename(temporaryRecipientFilename, recipientFilename);
    }
}

int RecipientFile::returnFindedRecipientLineNumber(int recipientId)
{
    bool isRecipientExist = false;
    int textFileLineNumber = 1;
    string recipientDataDividedByPipes = "";
    fstream textFile;
    textFile.open(recipientFilename.c_str(), ios::in);

    if (textFile.good() == true && recipientId != 0)
    {
        while(getline(textFile, recipientDataDividedByPipes))
        {
            if(recipientId == getRecipientIdFromDataDividedByPipes(recipientDataDividedByPipes))
            {
                isRecipientExist = true;
                textFile.close();
                return textFileLineNumber;
            }
            else
                textFileLineNumber++;
        }
        if (isRecipientExist = false)
        {
            textFile.close();
            return 0;
        }
    }
    return 0;
}

int RecipientFile::getRecipientIdFromDataDividedByPipes(string recipientDataDividedByPipes)
{
    int startedRecipientIdPosition = 0;
    int recipientId = AuxiliaryMethods::convertionFromStringToInteger(getNumber(recipientDataDividedByPipes, startedRecipientIdPosition));
    return recipientId;
}

string RecipientFile::getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

void RecipientFile::editLineInFile(int editedLineNumber, string lineWithRecipientDataDivededByPipes)
{
    fstream loadedTextfile, temporaryTextfile;
    string loadedLine = "";
    int loadedLineNumber = 1;

    loadedTextfile.open(recipientFilename.c_str(), ios::in);
    temporaryTextfile.open(temporaryRecipientFilename.c_str(), ios::out | ios::app);

    if (loadedTextfile.good() == true)
    {
        while (getline(loadedTextfile, loadedLine))
        {
            if (loadedLineNumber == editedLineNumber)
            {
                if (loadedLineNumber == 1)
                    temporaryTextfile << lineWithRecipientDataDivededByPipes;
                else if (loadedLineNumber > 1)
                    temporaryTextfile << endl << lineWithRecipientDataDivededByPipes;
            }
            else
            {
                if (loadedLineNumber == 1)
                    temporaryTextfile << loadedLine;
                else if (loadedLineNumber > 1)
                    temporaryTextfile << endl << loadedLine;
            }
            loadedLineNumber++;
        }
        loadedTextfile.close();
        temporaryTextfile.close();

        deleteLoadedFile(recipientFilename);
        changeTemporaryFilenameToNewLoadedFilename(temporaryRecipientFilename, recipientFilename);
    }
}

void RecipientFile::deleteLoadedFile(string fileName)
{
    if (remove(fileName.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << fileName << endl;
}

void RecipientFile::changeTemporaryFilenameToNewLoadedFilename(string temporaryFilename, string fileName)
{
    if (rename(temporaryFilename.c_str(), fileName.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << fileName << endl;
}
