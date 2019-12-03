#include "NewVerify.h"
#include "Verify.h"
#include "Operations.h"
#include "Decoration.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <ctype.h>
#include <direct.h>
#include <process.h>
#include <windows.h>
#include <vector>
//#include <random>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

NewVerify::NewVerify()
{
    //ctor
}


int NewVerify::acctNumVerifystr(string& number) // function to verify phone number
{
    int i=0;
    while(number[i] != '\0')
    {
        if((number[i]> 47)&&(number[i] < 58))
        {
            i++;
            continue;
        }
        else
        {
            cout <<"INVALID INPUT, ONLY NUMBERS BETWEEN 0-9 ARE ACCEPTED"<<endl;
            return 0;
        }
    }

    return 1;

}


int NewVerify::ifNumber(int& n)
{
    using namespace std;
    const int ARRAY_SIZE = 11;
    char digit_string[ARRAY_SIZE];
    if(isdigit(n))
    {
        return 1;
    }
    else
    {
        cout <<"INPUT CAN ONLY BE NUMBERS FROM 0-9";
        return 0;
    }

}



int NewVerify::turnToInt(int& n)  // function to read in numbers and clean the unnecessary characters
{
    using namespace std;
    const int ARRAY_SIZE = 20;
    char digit_string[ARRAY_SIZE];

    char next;
    cin.get(next);
    int index = 0;
    while (next != '\n')
    {
        if ((isdigit(next)) && (index < ARRAY_SIZE - 1))
        {
        digit_string[index] = next;
        index++;
        }
        else
        {
            cout <<"INPUT CAN ONLY BE NUMBERS FROM 0-9";
            return 0;
        }
        cin.get(next);
    }
    digit_string[index] = '\0';
    n = atoi(digit_string);



}




void NewVerify::read_and_clean(int& n)
{
    using namespace std;
 const int ARRAY_SIZE = 6;
 char digit_string[ARRAY_SIZE];

 char next;
 cin.get(next);
 int index = 0;
 while (next != '\n')
 {
 if ((isdigit(next)) && (index < ARRAY_SIZE - 1))
 {
 digit_string[index] = next;
 index++;
 }

 cin.get(next);
 }
 digit_string[index] = '\0';
 n = atoi(digit_string);
 }




int NewVerify::ledgerBalanceCheck(string& accountnumber, float& amount)
{

    ifstream money("money.txt");
    Decoration mydecor;
    Verify myvery;
    NewVerify newmyvey;
    ofstream outTemp;
    outTemp.open("temporary.txt", ios::app);
    outTemp.setf(ios::fixed);
    outTemp.setf(ios::showpoint);
    string file_account_number;
    float file_ledger_balance ,file_available_balance;
    outTemp.setf(ios::fixed);
    outTemp.setf(ios::showpoint);
    outTemp.precision(2);
    int whatTOReturn = 0;

    if(myvery.existBeforeDeposit(accountnumber))
    {
        while(money>>file_account_number>>file_ledger_balance>>file_available_balance)
        {
            if(file_account_number == accountnumber)
            {
                if(file_ledger_balance >= amount)
                {
                    money.close();
                    goto pay;
                }
                else
                {
                    cout << "\n\t\t\t\t\t\t\t\tINSUFFICIENT FUNDS...."<<endl;
                    whatTOReturn =0;
                    return whatTOReturn;
                }
        }
        }
    }
    else
    {
        cout <<"\n\t\t\t\t\t\t\t\tNO DEPOSIT HAVE BEEN MADE TO THIS ACCOUNT BEFORE,"<<
        " PLEASE DEPOSIT AND TRY AGAIN"<<endl;
        whatTOReturn =0;
        Sleep(50);
        mydecor.callExit();
    }

    pay:
        int amount2 = static_cast<int>(amount);
        cout << "\n\t\t\t\t\t\t\t\tYOU WANT TO PAY SUM OF #"<<amount2<<endl;
        cout <<"\n\t\t\t\t\t\t\t\tDO YOU WISH TO CONTINUE (y/n)"<<endl;
        invalid2:cout <<"\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
        char choice2;
        cin >>choice2;
        if((choice2 == 'y')||(choice2 == 'Y'))
        {
            ifstream money2("money.txt");
            while(money2>>file_account_number>>file_ledger_balance>>file_available_balance)
            {


                if(accountnumber == file_account_number)
                {
                    outTemp<<setprecision(2)<<file_account_number<<" "<<setprecision(2)<<file_ledger_balance-amount<<" "<<setprecision(2)<<file_available_balance-amount<<endl;

                }
                else
                {
                    outTemp<<setprecision(2)<<file_account_number<<" "<<setprecision(2)<<file_ledger_balance<<" "<<setprecision(2)<<file_available_balance<<endl;

                }
                    whatTOReturn =1;
            }
        }
        else if((choice2 == 'n')||(choice2 == 'N'))
        {
            cout << "\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
            mydecor.delay();
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
            Sleep(1000);
            //will later call another function there to ask if user want to perform another operation
            //mydecor.callExit();
            exit(1);
        }
        else
        {
            cout <<"\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
            goto invalid2;
        }



    outTemp.close();
    money.close();
    remove("money.txt");
    rename("temporary.txt", "money.txt");

    return whatTOReturn;
}
