/*
#ifndef THEMAINCLASS_H
#define THEMAINCLASS_H
#include "TheMainClass.h"
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
#include <ctime>


//my header file
#include "Decoration.h"
#include "MainMenu.h"
#include "Operations.h"
#include "Verify.h"
class TheMainClass
{
    public:
        TheMainClass(){}
        int main()
            {
             MainMenu main;
            Decoration mydecor;
            main.mainPage();
            system("cls");
            mydecor.slowDemDown();
            system("cls");


            start:char choice;
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t1)   <<CREATE ACCOUNT>>"<<endl;
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t2)   <<INSERT CARD>>"<<endl;
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t3)   <<REGISTER A NEW CARD>>"<<endl;
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t4)   <<EXIT>>"<<endl;
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t";
            cin >>choice;
            switch(choice)
            {
            case '1':
                system("cls");
                main.createAccount();
                break;
            case '2':
                {
                    string account;
                    cout <<"ENTER YOUR ACCOUNT NUMBER : ";
                    cin >>account;
                    Operations op(account);
                    system("cls");
                    main.insertCard(account);
                    break;
                }

            case '3':
                {
                    string account2;
                    cout <<"ENTER YOUR ACCOUNT NUMBER : ";
                    cin >>account2;
                    Operations op(account2);
                    system("cls");
                    main.addCardInfo(account2);
                    break;
                }
            case '4':
                system("cls");
                mydecor.callExit();
                break;
            default:
                cout <<"PLEASE ENTER A VALID OPTION";
                system("cls");
                goto start;

            }

            return 0;
        }

};

#endif // THEMAINCLASS_H
*/
