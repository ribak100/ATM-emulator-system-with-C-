
#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "structures.h"
#include "StackPtr.h"


//class for all ATM operations
class Operations
{
private:
    nameInfo NAMES;
    date DATE1;
    char phoneNum[11];
    int accountNum[10];
    string account_number;

public:

    Operations();
    Operations(string& actnum);
    void withdraw(string& acct); // function to withdraw
    void Deposit(string& acct); // function to deposit into an account
    //void transfer(string& acct); // function to transfer money to another account
    void transfer(string& accountnumber); // function to transfer money to another account
    void changePin(string& acct); // function to change account card pin
    void buyAirtime(string& acct); // function to by airtime
    void payBills(string& acct); // function to pay different kinds of bills
    void balance(string& acct); // function to get the ledger and available balance
    string accountType(); // function to choose between the three available account types
    void randNum(string& accountNumber); // function to generate random account numbers
    char randCardNum(); // generate random card number
    char randCVVNum(); //generate random CVV number
    void readAndClean(int& n);  // function to read in numbers and clean the unnecessary characters





};
#endif // OPERATIONS_H


