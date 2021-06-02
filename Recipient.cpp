#include "Recipient.h"

void Recipient::setRecipientId (int newRecipientId)
{
    recipientId = newRecipientId;
}

void Recipient::setUserId (int newUserId)
{
    userId = newUserId;
}
void Recipient::setName (string newName)
{
    name = newName;
}
void Recipient::setLastname (string newlastname)
{
    lastname = newlastname;
}

void Recipient::setTelephoneNumber (string newTelephoneNumber)
{
    telephoneNumber = newTelephoneNumber;
}
void Recipient::setEmail (string newEmail)
{
    email = newEmail;
}

void Recipient::setAdress (string newAdress)
{
    adress = newAdress;
}

int Recipient::getRecipientId ()
{
    return recipientId;
}

int Recipient::getUserId ()
{
    return userId;
}
string Recipient::getName ()
{
    return name;
}
string Recipient::getLastname ()
{
    return lastname;
}

string Recipient::getTelephoneNumber ()
{
    return telephoneNumber;
}

string Recipient::getEmail ()
{
    return email;
}

string Recipient::getAdress ()
{
    return adress;
}
