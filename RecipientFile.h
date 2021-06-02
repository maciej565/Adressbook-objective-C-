#ifndef RECIPIENTFILE_H
#define RECIPIENTFILE_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

#include "Recipient.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

class RecipientFile : public TextFile
{
    int recipientId;
    const string recipientFilename;
    string temporaryRecipientFilename;
    int getUserIdFromDataDividedByPipes(string RecipientDataDividedByPipes);
    Recipient getRecipientData(string recipientDataDividedByPipes);
    int getRecipientIdFromDataDividedByPipes(string RecipientDataDividedByPipes);
    string getNumber(string tekst, int pozycjaZnaku);
    void deleteLoadedFile(string filename);
    void changeTemporaryFilenameToNewLoadedFilename(string temporaryFilename, string filename);

public:
    RecipientFile(string FILENAME) :
        recipientFilename(FILENAME) {
        recipientId = 0;
        temporaryRecipientFilename = "Adresaci-tmp.txt";
    };
    vector<Recipient> loadLoggedUserRecipientsFromFile(int loggedUserId);
    void addRecipientToFile(Recipient recipient);
    int getRecipientId();
    void deleteLineInFile(int deletedRecipientLineNumber);
    int returnFindedRecipientLineNumber(int recipientId);
    void editLineInFile(int editedLineNumber, string lineWithRecipientDataDividedByPipes);
    string changingRecipientDataToLineWithDataDividedByPipes(Recipient recipient);
};

#endif
