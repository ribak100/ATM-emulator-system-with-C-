#ifndef VERIFY_H
#define VERIFY_H
#include "structures.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
//#include "Exception.h"

class Verify
{
private :
    nameInfo NAMES;
    date DATE1;
    char phoneNum[11];
    int accountNum[10];


public :

    Verify();
    int acctNumVerify(char number[10]); // function to verify phone number
    int acctNumVerify(int& accoutNum, string& surname); // function to verify account number
    int phoneNumVerify(char number[11]); // function to verify phone number
    int nameCheck(char name[20]);  // function to check if name input is correct
    int nameCheck(string& name);  // function to check if name input is correct
    int nameCheckNew(string& name);  // function to check if name input is correct
    int numCheck(char num[30]); // function to check if input is number
    int numCheck(string& num); // function to check if input is number
    int withdrawableCashCeck(float& ammount); // function to verify the type of currency that can be withdrawn
    int dOfbCheck(int& Day, int& Month, int& Year);  // function to check if the date of birth is correct
    template <class T>
    int existBeforeNewAcc(T& item);
    template <class T>
    int existBeforeLogin(T& item);
    template <class T>
    int existBeforeAcc(T& item);
    template <class T>
    int existBeforeCardInfo(T& item);
    template <class T>
    int existBeforeDeposit(T& item);


};



template <class T>
int Verify::existBeforeNewAcc(T& item)
{
    fstream file("newAccount.txt");
    string line;

    while(std::getline(file, line))
    {
        istringstream ss(line);
        istream_iterator<std::string> begin(ss), end;
        std::vector<string> container(begin, end);
        vector<string>::iterator it;
        for(it = container.begin(); it != container.end(); it++)
        {
            if (item == *it)
            {
                return 1;
            }
            else
            {
                continue;
            }
        }

    }
    return 0;
}


template <class T>
int Verify::existBeforeAcc(T& item)
{
    fstream file("account.txt");
    string line;

    while(std::getline(file, line))
    {
        istringstream ss(line);
        istream_iterator<std::string> begin(ss), end;
        std::vector<string> container(begin, end);
        vector<string>::iterator it;
        for(it = container.begin(); it != container.end(); it++)
        {
            if (item == *it)
            {
                return 1;
            }
            else
            {
                continue;
            }
        }

    }
    return 0;
}


template <class T>
int Verify::existBeforeCardInfo(T& item)
{
    fstream file("newCardInfo.txt");
    string line;

    while(std::getline(file, line))
    {
        istringstream ss(line);
        istream_iterator<std::string> begin(ss), end;
        std::vector<string> container(begin, end);
        vector<string>::iterator it;
        for(it = container.begin(); it != container.end(); it++)
        {
            if (item == *it)
            {
                return 1;
            }
            else
            {
                continue;
            }
        }

    }
    return 0;
}


template <class T>
int Verify::existBeforeLogin(T& item)
{
    fstream file("login.txt");
    string line;

    while(std::getline(file, line))
    {
        istringstream ss(line);
        istream_iterator<std::string> begin(ss), end;
        std::vector<string> container(begin, end);
        vector<string>::iterator it;
        for(it = container.begin(); it != container.end(); it++)
        {
            if (item == *it)
            {
                return 1;
            }
            else
            {
                continue;
            }
        }

    }
    return 0;
}





template <class T>
int Verify::existBeforeDeposit(T& item)
{
    fstream file("money.txt");
    T line;

    while(std::getline(file, line))
    {
        istringstream ss(line);
        istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> container(begin, end);
        vector<std::string>::iterator it;
        for(it = container.begin(); it != container.end(); it++)
        {
            if (item == *it)
            {
                return 1;
            }
            else
            {
                continue;
            }
        }

    }
    return 0;
}

//use this for the date and year verification
/*
int day;
    int month;
    int year;
    int correct;
    here:do{
    cout <<"Enter day' : ";
    cin >>day;
    if((day < 1 )||(day >31))
    {
        cout << "THE DAY RANGE MUST BE BETWEEN 1-31"<<endl;
        goto here;
    }
    cout <<"Enter month' : ";
    cin >>month;
    if((month < 1 )||(month >12))
    {
        cout << "THE MONTH RANGE MUST BE BETWEEN 1-12"<<endl;
        goto here;
    }
    cout <<"Enter year' : ";
    cin >>year;

    correct = myveryf.dOfbCheck(day, month, year);
    }while (correct != 1);

*/


#endif // VERIFY_H
