#ifndef RECIPIENTMANAGER_H
#define RECIPIENTMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "Recipient.h"
#include "RecipientFile.h"
#include "AuxiliaryMethods.h"

class RecipientManager
{
    const int loggedUserId;
    vector <Recipient> recipients;
    RecipientFile recipientFile;
    Recipient typeNewRecipientData();
    void displayRecipientData(Recipient recipient);
    string loadLine();
    string changingFirstLetterToBiggerButOthersToSmaller(string text);
    void displayFindedRecipientsNumber(int RecipientsNumber);
    int typeRecipientId();
    int getInteger();
    char getCharacter();
    int getRecipientIdFromDataDividedByPipes(string RecipientDataDividedByPipes);
    string getNumber(string text, int charPosition);
    char chooseOptionFromEditionMenu();
    void updateEditedRecipientData(Recipient recipient, int editetRecipientId);

public:
    RecipientManager (string recipientFileName, int LOGGEDUSERID) :
        recipientFile(recipientFileName), loggedUserId(LOGGEDUSERID)
    {
        recipients = recipientFile.loadLoggedUserRecipientsFromFile(loggedUserId);
    };
    void addRecipient();
    void displayAllRecipients();
    void findRecipientByName();
    void findRecipientByLastname();
    int deleteRecipient();
    void editRecipient();

};

#endif
