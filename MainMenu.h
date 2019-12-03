
#ifndef MAINMENU_H
#define MAINMENU_H
#include "structures.h"


class MainMenu
{
private:
    nameInfo NAMES;
    date DATE1;
    char phoneNum[11];
    int accountNum[10];

public:
    MainMenu();
    int enterPin(string& accountNum); // function to enter the ATM pin
    void addCardInfo(string& acct); // function to register an ATM card to an existing account
    void createAccount(); // function to create a new account
    void menu(string& acct); // function to get to the page where all transaction can be performed
    void mainPage(); // function to move to the main page
    void insertCard(string& acct); // function to insert the ATM card


};

#endif // MAINMENU_H


