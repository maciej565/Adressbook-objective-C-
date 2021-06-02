#ifndef RECIPIENT_H
#define RECIPIENT_H
#include <iostream>

using namespace std;

class Recipient {
    int recipientId;
    int userId;
    string name;
    string lastname;
    string telephoneNumber;
    string email;
    string adress;

public:
    void setRecipientId (int newRecipientId);
    void setUserId (int newUserId);
    void setName (string newName);
    void setLastname (string newLastname);
    void setTelephoneNumber (string newTelephoneNumber);
    void setEmail (string newEmail);
    void setAdress (string newAdress);

    int getRecipientId ();
    int getUserId ();
    string getName ();
    string getLastname ();
    string getTelephoneNumber ();
    string getEmail ();
    string getAdress ();
};

#endif
