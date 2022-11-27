

/**
  * A program written to emulate
  * the ATM operations
  * By: Adekanye abdulkabir (Hidden)
  */

//c++ header file
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <ctime>
#include <direct.h>
#include <process.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <ctime>


//my header file
#include "Decoration.h"
#include "MainMenu.h"
#include "Operations.h"
#include "Verify.h"

using namespace std;


int main()
{

    MainMenu main;
    Decoration mydecor;
    //main.mainPage();
    system("cls");



    start:char choice;
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t1)   <<CREATE ACCOUNT>>"<<endl;
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t2)   <<INSERT CARD>>"<<endl;
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t3)   <<REGISTER A NEW CARD>>"<<endl;
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t4)   <<DEPOSIT>>"<<endl;
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t5)   <<EXIT>>"<<endl;
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t   ENTER YOUR CHOICE : ";
    cin >>choice;
    switch(choice)
    {
    case '1':
        system("cls");
        cout<<"\n\n\n\n\n\n\n";
        //mydecor.slowDemDown();
        main.createAccount();

        break;
    case '2':
        {
            system("cls");
            string account;
            mydecor.slowDemDown();
            cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER YOUR ACCOUNT NUMBER : ";
            cin >>account;
            Operations op(account);
            main.insertCard(account);
            break;
        }

    case '3':
        {
            system("cls");
            string account2;
            mydecor.slowDemDown();
            system("cls");
            cout <<"\n\n\n\n\n\n\nENTER YOUR ACCOUNT NUMBER : ";
            cin >>account2;
            Operations op(account2);
            main.addCardInfo(account2);
            break;
        }
    case '4':
        {
            system("cls");
            string account2;
            mydecor.slowDemDown();
            cout <<"\n\n\n\n\n\n\nENTER YOUR ACCOUNT NUMBER : ";
            cin >>account2;
            Operations op(account2);
            op.Deposit(account2);
            break;
        }
    case '5':
        system("cls");
        mydecor.callExit();
        break;
    default:
        cout <<"\t\t\t\t\t\t\t\tPLEASE ENTER A VALID OPTION";
        Sleep(2000);
        system("cls");
        goto start;

    }

    return 0;
}



















