#include "Verify.h"
#include "Operations.h"
#include "Decoration.h"
#include "NewVerify.h"
#include "MainMenu.h"
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
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

using namespace std;

Operations::Operations()
{
    //ctor
}

Operations::Operations(string& actnum)
{
    account_number = actnum;
}


void Operations::withdraw(string& acct) // function to withdraw
{

    withraw:Operations op;
    Decoration mydecor;
    Verify myvery;
    NewVerify newmyvey;
    ifstream money;
    money.open("money.txt", ios::app);
    ifstream accfile;
    accfile.open("account.txt");
    ofstream outTemp;
    outTemp.open("temporary.txt", ios::app);
    outTemp.setf(ios::fixed);
    outTemp.setf(ios::showpoint);
    string file_account_number;
    string account_number = acct;
    float file_ledger_balance ,file_available_balance;
    mydecor.slowDemDown();
    char theAmount[30];
    char next;
    char stupidStuff;
    cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
    cin.get(stupidStuff);
    system("cls");
    float amount;
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT TO WITHDRAW : ";


    std::cin.get(next);
    int i =0;
    int whatToCheck =1;
    while(next != '\n')
    {
        if((isdigit(next))&&(i < 30))
        {
            theAmount[i] = next;
            i++;

        }
        else
        {
            whatToCheck = 0;

        }

        cin.get(next);
    }
    theAmount[i] = '\0';

    if(whatToCheck == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
        outTemp.close();
        remove("temporary.txt");
        accfile.close();
        money.close();
        MainMenu main;
        Sleep(2000);
        system("cls");
        mydecor.slowDemDown();
        system("cls");

        main.menu(acct);
    }

     if(whatToCheck == 1)
    {
        amount = atof(theAmount);
    }



    if(myvery.existBeforeDeposit(account_number))
    {
        while(money>>file_account_number>>file_ledger_balance>>file_available_balance)
        {
            if(myvery.withdrawableCashCeck(amount))
            {
                if(account_number != file_account_number)
                {
                    outTemp<<setprecision(2)<<file_account_number<<" "<<setprecision(2)<<file_ledger_balance<<" "<<setprecision(2)<<file_available_balance<<endl;
                }
                if(account_number == file_account_number)
                {
                    if(file_ledger_balance >= amount)
                    {

                        outTemp<<setprecision(2)<<file_account_number<<" "<<setprecision(2)<<file_ledger_balance-amount<<" "<<setprecision(2)<<file_available_balance-amount<<endl;
                        system("cls");
                        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CASH";
                        Sleep(2000);
                    }
                    else
                    {
                        cout << "\n\n\t\t\t\t\t\t\t\tINSUFFICIENT FUND...."<<endl;
                        outTemp<<file_account_number<<" "<<file_ledger_balance<<" "<<file_available_balance<<endl;
                        money.close();
                        outTemp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temporary.txt","money.txt");
                        goto incomplete;
                    }

                }
            }
            else
            {
                goto withraw;
            }

        }
        money.close();
        outTemp.close();
        accfile.close();
        remove("money.txt");
        rename("temporary.txt","money.txt");
        goto complete;
    }
    else
    {
        cout <<"YOUR ACCOUNT IS EMPTY, YOU HAVE TO DEPOSIT TO MAKE ANY WITHRAWAL"<<endl;
        goto incomplete;

    }



     complete:system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t-----TRANSACTION COMPLETED SUCCESSFULLY-----"<<endl;
   incomplete:cout <<"\n\n\n\t\t\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t";
    system("pause");
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid2:cout <<"\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
    char choice2;
    cin >>choice2;
    if((choice2 == 'y')||(choice2 == 'Y'))
    {
        MainMenu main;
        system("cls");
        mydecor.slowDemDown();
        system("cls");
        main.menu(acct);
    }
    else if((choice2 == 'n')||(choice2 == 'N'))
    {
        cout << "OK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        system("cls");
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
        Sleep(1000);
        //will later call another function there to ask if user want to perform another operation
        mydecor.callExit();

    }
    else
    {
        cout <<"PLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid2;
    }

}

void Operations::Deposit(string& acct) // function to deposit into an account
{
    again:
    Operations op(acct);
    Decoration mydecor;
    Verify myvery;
    NewVerify newmyvey;
    MainMenu main;
    mydecor.slowDemDown();
    ifstream money;//i used an ifstream here because, using normal fstream will not allow anything to be read into the temp file
    money.open("money.txt", ios::app);
    ifstream accfile;
    accfile.open("account.txt");
    ofstream outTemp;
    outTemp.open("temporary.txt", ios::app);
    outTemp.setf(ios::fixed);
    outTemp.setf(ios::showpoint);
    string account_number;
    string accountnum, surname, firstName, lastName, phoneNumber, accountTyp;
    float  depBalance, depLedger;
    string depAccountNumber;
    account_number  = acct;

    /*int a;
    do
    {

        a = newmyvey.acctNumVerifystr(account_number);
    }while(a != 1);
*/

    comehere:
    char theAmount[30];
    char next;
    char stupidStuff;
    Sleep(1000);
    cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
    cin.get(stupidStuff);
    system("cls");
    float amount;
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT TO DEPOSIT : ";


    std::cin.get(next);
    int i =0;
    int whatToCheck =1;
    while(next != '\n')
    {
        if((isdigit(next))&&(i < 30))
        {
            theAmount[i] = next;
            i++;

        }
        else
        {
            whatToCheck = 0;

        }

        cin.get(next);
    }
    theAmount[i] = '\0';

    if(whatToCheck == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
        outTemp.close();
        remove("temporary.txt");
        accfile.close();
        money.close();
        MainMenu main;
        Sleep(2000);
        system("cls");
        main.menu(acct);
    }

     if(whatToCheck == 1)
    {
        amount = atof(theAmount);
    }

    if(amount <1 )
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tYOU CAN'T DEPOSIT MONEY LESS THAN #1";
        goto comehere;
    }
    if(amount >1000000000)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tYOU CANT DEPOSIT MORE THAN #1,000,000,000 AT ONCE";
        goto comehere;
    }




    if(! myvery.existBeforeAcc(account_number))
    {
        cout <<"\n\n\t\t\t\t\t\t\t\t\t\tTHE ACCOUNT NUMBER PROVIDED IS INVALID"<<endl
        <<"\n\n\t\t\t\t\t\t\t\t\t\tVERIFY AND ENTER A NEW ACCOUNT NUMBER"<<endl;
        mydecor.callExit();
    }
    cout.precision(2);
    cout <<"\n\n\t\t\t\t\t\t\t\t\t\tCHECK AND VERIFY THE DETAILS OF YOUR TRANSACTION"<<endl;
    while(accfile>>accountnum>>surname>>firstName>>lastName>>phoneNumber>>accountTyp)
    {
        if(account_number == accountnum)
        {
            char choice;
            int amount2 = static_cast<int>(amount);
            cout <<"\n\n\t\t\t\t\t\t\t\t\t\tNAME : "<<surname<<" "<<firstName<<" "<<lastName<<endl;
            cout <<"\n\n\t\t\t\t\t\t\t\t\t\tACCOUNT TYPE : "<<accountTyp<<endl;
            cout <<"\n\n\t\t\t\t\t\t\t\t\t\tAMOUNT : #"<<amount2<<endl;
            cout <<"\n\n\t\t\t\t\t\t\t\t\t\tWOULD YOU LIKE TO CONTINUE (y/n)"<<endl;
            invalid:cout <<"\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
            cin >>choice;
            if((choice == 'y')||(choice == 'Y'))
                {
                    if(myvery.existBeforeDeposit(accountnum))
                    {
                        while(money>>depAccountNumber>>depBalance>>depLedger)
                        {
                            if(account_number != depAccountNumber)
                            {
                                outTemp<<setprecision(2)<<depAccountNumber<<" "<<setprecision(2)<<depBalance<<" "<<setprecision(2)<<depLedger<<endl;

                            }
                            else
                            {
                                outTemp<<setprecision(2)<<depAccountNumber<<" "<<setprecision(2)<<depBalance+amount<<" "<<setprecision(2)<<depLedger+amount<<endl;
                            }

                        }

                        money.close();
                        outTemp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temporary.txt","money.txt");
                        Sleep(4000);
                        system("cls");
                         cout <<"\n\n\t\t\t\t\t\t\t\t\t\t-----TRANSACTION COMPLETED SUCCESSFULLY-----"<<endl
                        <<"\n\n\t\t\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
                        system("pause");
                        backhere:cout <<"\n\n\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
                        invalid3:cout <<"\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
                        char choice3;
                        cin >>choice3;
                        if((choice3 == 'y')||(choice3 == 'Y'))
                        {
                            //will call menu here
                            system("cls");
                            mydecor.slowDemDown();
                            system("cls");
                            op.Deposit(acct);
                        }
                        else if((choice3 == 'n')||(choice3 == 'N'))
                        {
                            cout << "\n\n\t\t\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
                            mydecor.delay();
                            system("cls");
                            cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
                            Sleep(3000);
                            mydecor.callExit();
                        exit(1);
                        }
                        else
                        {
                            cout <<"\n\n\t\t\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
                            goto invalid3;
                        }
                    }
                    else
                    {
                        int newbal;
                        newbal = amount-1000;
                        ofstream depo("money.txt", ios::app);
                        depo<<account_number<<" "<<newbal<<" "<<amount<<endl;
                        depo.close();
                        money.close();
                        outTemp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temporary.txt","money.txt");
                         cout <<"\n\n\t\t\t\t\t\t\t\t\t\t-----TRANSACTION COMPLETED SUCCESSFULLY-----"<<endl
                        <<"\n\n\t\t\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
                        system("pause");
                        cout <<"\n\n\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
                        invalid2:cout <<"\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
                        char choice2;
                        cin >>choice2;
                        if((choice2 == 'y')||(choice2 == 'Y'))
                        {
                            //will call menu here
                            system("cls");
                            mydecor.slowDemDown();
                            system("cls");
                            op.Deposit(acct);
                        }
                        else if((choice2 == 'n')||(choice2 == 'N'))
                        {
                            cout << "\n\n\t\t\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
                            mydecor.delay();
                            system("cls");
                            cout <<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
                            Sleep(1000);
                        //will later call another function there to ask if user want to perform another operation
                            mydecor.callExit();

                        }
                        else
                        {
                            cout <<"\n\n\t\t\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
                            goto invalid2;
                        }
                    }

                }
                else if((choice == 'n')||(choice == 'N'))
                {
                    cout << "\n\n\t\t\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
                    goto backhere;
                    //will later call another function there to ask if user want to perform another operation
                    mydecor.callExit();

                }
                else
                {
                    cout <<"\n\n\t\t\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
                    goto invalid;
                }
        }


    }

    }



/*
void Operations::transfer(string& acct) // function to transfer money to another account
{

    begin:
    Verify myvery;
    NewVerify newmyvey;
    Menu main;
    Decoration mydecor;
    ifstream trans("money.txt", ios::in);
    ifstream money("money.txt", ios::in);
    fstream temp("temp.txt", ios::app);
    fstream accfile("account.txt", ios::in);
    again:temp.setf(ios::fixed);
    temp.setf(ios::showpoint);
    string accountnum,surname,firstName,lastName,phoneNumber,accountTyp;
    string accountNumber;
    float aval_balance, ledger_balance;

    string myaccount;
    myaccount = account_number;
    string destination_account;
    account_number = acct;
    int a =0;
    cout <<"ENTER DESTINATION ACCOUNT NUMBER : ";
    cin >>destination_account;
    a = newmyvey.acctNumVerifystr(destination_account);
    if(a != 1)
        goto again;

    float amount;
    comehere:cout <<"\nENTER AMOUNT TO TRANSFER : ";
    cin >>amount;
    if(amount< 50 )
    {
        cout << "YOU CAN'T TRANSFER MONEY LESS THAN #50";
        goto comehere;
    }
    if(amount >1000000000)
    {
        cout << "YOU CANT TRANSFER MORE THAN #1,000,000,000 AT ONCE";
        goto comehere;
    }

    if(destination_account == myaccount)
    {
        cout <<"YOU CANT TRANSFER TO THE SAME ACCOUNT"<<endl;
        //goto backhere;
        goto begin;
    }

    if(! myvery.existBeforeAcc(destination_account))
    {

        cout << "THE ACCOUNT PROVIDED IS INVALID, PLEASE VERIFY AND TEYB AGAIN"<<endl;
        goto newTrans;

    }
    if(! myvery.existBeforeDeposit(myaccount))
    {

        cout << "HEY AM NOT SEEING YOUR ACCOUNT"<<endl;
        goto newTrans;

    }

    cout <<"CHECK AND VERIFY THE DETAILS OF YOUR TRANSACTION"<<endl;
    while(accfile>>accountnum>>surname>>firstName>>lastName>>phoneNumber>>accountTyp)
    {
        float ledger_balance, available_balance;

        if(destination_account == accountnum)
        {
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            char choice;
            cout <<"NAME : "<<surname<<" "<<firstName<<" "<<lastName<<endl;
            cout <<"ACCOUNT TYPE : "<<accountTyp<<endl;
            cout <<"AMOUNT : #"<<setprecision(2)<<amount<<endl;
            cout <<"WOULD YOU LIKE TO CONTINUE (y/n)"<<endl;
            invalid:cout <<"ENTER YOUR CHOICE : ";
            cin >>choice;
            if((choice == 'y')||(choice == 'Y'))
                {

                    while(money>>accountNumber>>ledger_balance>>aval_balance)
                    {
                        if(accountNumber == myaccount)
                        {
                            if(ledger_balance >= amount)
                            {
                                break;
                            }
                            else
                            {
                                cout <<"INSUFFICIENT FUNDS..."<<endl;
                                goto newTrans;
                            }
                        }
                    }
                    if(myvery.existBeforeDeposit(destination_account))
                    {


                        while(trans>>accountNumber>>ledger_balance>>aval_balance)
                        {
                            if(accountNumber == myaccount)
                            {
                                temp<<setprecision(2)<<accountNumber<<" "<<setprecision(2)<<ledger_balance-amount<<" "<<setprecision(2)<<aval_balance-amount<<endl;
                            }
                            else if(accountNumber == destination_account)
                            {

                                temp<<setprecision(2)<<accountNumber<<" "<<setprecision(2)<<ledger_balance+amount<<" "<<setprecision(2)<<aval_balance+amount<<endl;
                            }
                            else
                            {

                                temp<<setprecision(2)<<accountNumber<<" "<<setprecision(2)<<ledger_balance<<" "<<setprecision(2)<<aval_balance<<endl;
                            }

                        }

                        trans.close();
                        money.close();
                        temp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temp.txt", "money.txt");

                }
                else
                {


                    float new_ledger_balance, available_balance;
                    new_ledger_balance += amount-1000.00;
                    available_balance += amount;
                    temp<<setprecision(2)<<destination_account<<" "<<setprecision(2)<<new_ledger_balance<<" "<<setprecision(2)<<available_balance<<endl;
                    while(trans>>accountnum>>ledger_balance>>aval_balance)
                    {
                        if(accountnum == myaccount)
                        {
                            temp<<setprecision(2)<<myaccount<<" "<<setprecision(2)<<ledger_balance-amount<<" "<<setprecision(2)<<aval_balance-amount<<endl;

                        }
                        if((accountnum != destination_account)&&(accountnum != myaccount))
                            {

                                temp<<setprecision(2)<<accountnum<<" "<<setprecision(2)<<ledger_balance<<" "<<setprecision(2)<<aval_balance<<endl;
                            }

                    }



                        trans.close();
                        money.close();
                        temp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temp.txt","money.txt");

                }



                }

                else if((choice == 'n')||(choice == 'N'))
                {
                    cout << "OK... THANK YOU FOR BANKING WITH US"<<endl;

                    //will later call another function there to ask if user want to perform another operation
                    //mydecor.callExit();
                    exit(0);
                }
                else
                {
                    cout <<"PLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
                    goto invalid;
                }
        }
    }

        newTrans:cout <<"-----TRANSACTION COMPLETED SUCCESSFULLY-----"<<endl
        <<"**THANK YOU FOR BANKING WITH US**"<<endl;
        system("pause");
        backhere:cout <<"DO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
        invalid3:cout <<"ENTER YOUR CHOICE : ";
        char choice3;
        cin >>choice3;
        if((choice3 == 'y')||(choice3 == 'Y'))
        {
                            //will call menu here
            goto begin;
        }
        else if((choice3 == 'n')||(choice3 == 'N'))
        {
            cout << "OK... THANK YOU FOR BANKING WITH US"<<endl;
            mydecor.delay();
            cout <<"PLEASE TAKE YOUR CARD..."<<endl;
            Sleep(1000);
            mydecor.callExit();
            exit(1);
        }
        else
        {
            cout <<"PLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
            goto invalid3;
        }
}
*/

void Operations::transfer(string& accountnumber) // function to transfer money to another account
{

    begin:
    Verify myvery;
    NewVerify newmyvey;
    MainMenu main;
    Decoration mydecor;
    string acct = accountnumber;
    ifstream trans("money.txt", ios::in);
    ifstream money("money.txt", ios::in);
    fstream temp("temp.txt", ios::app);
    fstream accfile("account.txt", ios::in);
    temp.setf(ios::fixed);
    temp.setf(ios::showpoint);
    mydecor.slowDemDown();
    string accountnum,surname,firstName,lastName,phoneNumber,accountTyp;
    string accountNumber;
    float aval_balance, ledger_balance;
    string myaccount;
    myaccount = accountnumber;
    string destination_account;
    int a =0;
    again:cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER DESTINATION ACCOUNT NUMBER : ";
    cin >>destination_account;
    a = newmyvey.acctNumVerifystr(destination_account);
    if(a != 1)
        goto again;


    comehere:
    char theAmount[30];
    char next;
    char stupidStuff;
    Sleep(1000);
    cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
    cin.get(stupidStuff);
    system("cls");
    float amount;
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT TO TRANSFER : ";


    std::cin.get(next);
    int i =0;
    int whatToCheck =1;
    while(next != '\n')
    {
        if((isdigit(next))&&(i < 30))
        {
            theAmount[i] = next;
            i++;

        }
        else
        {
            whatToCheck = 0;

        }

        cin.get(next);
    }
    theAmount[i] = '\0';

    if(whatToCheck == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
        temp.close();
        remove("temporary.txt");
        accfile.close();
        money.close();
        MainMenu main;
        Sleep(2000);
        system("cls");
        main.menu(acct);
    }

     if(whatToCheck == 1)
    {
        amount = atof(theAmount);
    }
    if(amount< 50 )
    {
        cout << "\n\n\t\t\t\t\t\t\t\tYOU CAN'T TRANSFER MONEY LESS THAN #50";
        goto comehere;
    }
    if(amount >1000000000)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tYOU CANT TRANSFER MORE THAN #1,000,000,000 AT ONCE";
        goto comehere;
    }

    if(destination_account == myaccount)
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tYOU CANT TRANSFER TO THE SAME ACCOUNT"<<endl;
        //goto backhere;
        goto begin;
    }

    if(! myvery.existBeforeAcc(destination_account))
    {

        cout << "\n\n\t\t\t\t\t\t\t\tTHE ACCOUNT PROVIDED IS INVALID, PLEASE VERIFY AND TEYB AGAIN"<<endl;
        goto newNew;

    }
    /*if(! myvery.existBeforeDeposit(myaccount))
    {

        cout << "HEY AM NOT SEEING YOUR ACCOUNT"<<endl;
        goto newTrans;

    }*/

    cout <<"\n\n\t\t\t\t\t\t\t\tCHECK AND VERIFY THE DETAILS OF YOUR TRANSACTION"<<endl;
    while(accfile>>accountnum>>surname>>firstName>>lastName>>phoneNumber>>accountTyp)
    {
        float ledger_balance, available_balance;

        if(destination_account == accountnum)
        {
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            char choice;
            cout <<"\n\n\t\t\t\t\t\t\t\tNAME : "<<surname<<" "<<firstName<<" "<<lastName<<endl;
            cout <<"\n\n\t\t\t\t\t\t\t\tACCOUNT TYPE : "<<accountTyp<<endl;
            cout <<"\n\n\t\t\t\t\t\t\t\tAMOUNT : #"<<setprecision(2)<<amount<<endl;
            cout <<"\n\n\t\t\t\t\t\t\t\tWOULD YOU LIKE TO CONTINUE (y/n)"<<endl;
            invalid:cout <<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
            cin >>choice;
            if((choice == 'y')||(choice == 'Y'))
                {

                    while(money>>accountNumber>>ledger_balance>>aval_balance)
                    {
                        if(accountNumber == myaccount)
                        {
                            if(ledger_balance >= amount)
                            {
                                break;
                            }
                            else
                            {
                                cout <<"\n\n\t\t\t\t\t\t\t\tINSUFFICIENT FUNDS..."<<endl;
                                goto newTrans;
                            }
                        }
                    }
                    if(myvery.existBeforeDeposit(destination_account))
                    {


                        while(trans>>accountNumber>>ledger_balance>>aval_balance)
                        {
                            if(accountNumber == myaccount)
                            {
                                temp<<setprecision(2)<<accountNumber<<" "<<setprecision(2)<<ledger_balance-amount<<" "<<setprecision(2)<<aval_balance-amount<<endl;
                            }
                            else if(accountNumber == destination_account)
                            {

                                temp<<setprecision(2)<<accountNumber<<" "<<setprecision(2)<<ledger_balance+amount<<" "<<setprecision(2)<<aval_balance+amount<<endl;
                            }
                            else
                            {

                                temp<<setprecision(2)<<accountNumber<<" "<<setprecision(2)<<ledger_balance<<" "<<setprecision(2)<<aval_balance<<endl;
                            }

                        }

                        trans.close();
                        money.close();
                        temp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temp.txt", "money.txt");

                }
                else
                {


                    float new_ledger_balance, available_balance;
                    new_ledger_balance += amount-1000.00;
                    available_balance += amount;
                    temp<<setprecision(2)<<destination_account<<" "<<setprecision(2)<<new_ledger_balance<<" "<<setprecision(2)<<available_balance<<endl;
                    while(trans>>accountnum>>ledger_balance>>aval_balance)
                    {
                        if(accountnum == myaccount)
                        {
                            temp<<setprecision(2)<<myaccount<<" "<<setprecision(2)<<ledger_balance-amount<<" "<<setprecision(2)<<aval_balance-amount<<endl;

                        }
                        if((accountnum != destination_account)&&(accountnum != myaccount))
                            {

                                temp<<setprecision(2)<<accountnum<<" "<<setprecision(2)<<ledger_balance<<" "<<setprecision(2)<<aval_balance<<endl;
                            }

                    }



                        trans.close();
                        money.close();
                        temp.close();
                        accfile.close();
                        remove("money.txt");
                        rename("temp.txt","money.txt");

                }



                }

                else if((choice == 'n')||(choice == 'N'))
                {
                    cout << "\n\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;

                    //will later call another function there to ask if user want to perform another operation
                    //mydecor.callExit();
                    exit(0);
                }
                else
                {
                    cout <<"\n\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
                    goto invalid;
                }
        }
    }

        system("cls");
        newTrans:cout <<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t-----TRANSACTION COMPLETED SUCCESSFULLY-----"<<endl;
        newNew:cout <<"\n\n\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
        system("pause");
        backhere:cout <<"\n\n\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
        invalid3:cout <<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
        char choice3;
        cin >>choice3;
        if((choice3 == 'y')||(choice3 == 'Y'))
        {
                            //will call menu here
            system("cls");
            mydecor.slowDemDown();
            system("cls");
            main.menu(acct);
        }
        else if((choice3 == 'n')||(choice3 == 'N'))
        {
            cout << "\n\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
            mydecor.delay();
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
            Sleep(1000);
            mydecor.callExit();

        }
        else
        {
            cout <<"\n\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
            goto invalid3;
        }
}





void Operations::changePin(string& acct) // function to change account card pin
{
    Operations op;
    Decoration mydecor;
    Verify myvery;
    MainMenu main;
    NewVerify newmyvey;
    changePin:string pin;
    mydecor.slowDemDown();
    account_number = acct;
    string file_pin, file_CVV;
    string file_card_number, file_account_number;
    ifstream card_info("newCardInfo.txt", ios::app);
    ofstream outTemp("temp.txt", ios::app);
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER OLD PIN : ";
    cin >>pin;

    /*if(strlen(pin) != 4)
    {
        cout <<"PIN MUST BE FOUR NUMBERS"<<endl;
        goto changePin;
    }*/
    if(myvery.numCheck(pin) != 1)
        goto changePin;

    while(card_info>>file_card_number>>file_CVV>>file_pin>>file_account_number)
    {
        if(account_number == file_account_number)
        {
            if(file_pin == pin)
            {
                char new_pin[4];
                string verfypin;
                new_pin:cout<< "\n\n\t\t\t\t\t\t\t\tENTER NEW PIN : ";
                cin >>new_pin;
                if(strlen(new_pin) != 4)
                {
                    cout <<"\n\n\t\t\t\t\t\t\t\tPIN MUST BE FOUR NUMBERS"<<endl;
                    goto new_pin;
                }
                if(myvery.numCheck(new_pin) != 1)
                    goto new_pin;
                cout <<"\n\n\t\t\t\t\t\t\t\tVERIFY NEW PIN : ";
                cin >>verfypin;
                if(new_pin != verfypin)
                {
                    cout << "\n\n\t\t\t\t\t\t\t\tPIN DOESN'T MATCH"<<endl;
                    goto new_pin;
                }
                cout <<"\n\n\t\t\t\t\t\t\t\t**PIN CHANGED SUCESSFULLY**"<<endl;
                outTemp<<file_card_number<<" "<<file_CVV<<" "<<new_pin<<" "<<file_account_number<<endl;
            }
            else
            {
                cout <<"\n\n\t\t\t\t\t\t\t\tNEW PIN DOESN'T MATCH OLD PIN"<<endl;
                outTemp<<file_card_number<<" "<<file_CVV<<" "<<file_pin<<" "<<file_account_number<<endl;
            }
        }
        else
        {
            outTemp<<file_card_number<<" "<<file_CVV<<" "<<file_pin<<" "<<file_account_number<<endl;
        }
    }

    outTemp.close();
    card_info.close();
    remove("newCardInfo.txt");
    rename("temp.txt","newCardInfo.txt");



    //another:
    Sleep(2000);
    system("cls");
    system("pause");
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid2:cout <<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
    char choice2;
    cin >>choice2;
    if((choice2 == 'y')||(choice2 == 'Y'))
    {
        system("cls");
        mydecor.slowDemDown();
        system("cls");
        main.menu(acct);

    }
    else if((choice2 == 'n')||(choice2 == 'N'))
    {
        cout << "\n\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        system("cls");
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
        Sleep(1000);
        //will later call another function there to ask if user want to perform another operation
        //mydecor.callExit();
        exit(1);
    }
    else
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid2;
    }
}


void Operations::buyAirtime(string& acct) // function to by airtime
{
    Airtime:Operations op;
    Decoration mydecor;
    Verify myvery;
    MainMenu main;
    NewVerify newmyvey;
    mydecor.slowDemDown();
    ifstream money("money.txt", ios::app);
    fstream outTemp("temp.txt", ios::app);
    outTemp.setf(ios::fixed);
    outTemp.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    phone:
    char phone_number[11];
    string file_accountNum;
    account_number = acct;
    float file_ledger_balance, file_available_balance;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tENTER YOUR PHONE NUMBER WITHOUT THE FIRST ZERO '0'";
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER YOUR PHONE NUMBER : ";
    cin >> phone_number;
    if(! myvery.phoneNumVerify(phone_number))
        goto phone;


    char theAmount[30];
    char next;
    char stupidStuff;
    Sleep(1000);
    cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
    cin.get(stupidStuff);
    system("cls");
    float amount;
    cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


    std::cin.get(next);
    int i =0;
    int whatToCheck =1;
    while(next != '\n')
    {
        if((isdigit(next))&&(i < 30))
        {
            theAmount[i] = next;
            i++;

        }
        else
        {
            whatToCheck = 0;

        }

        cin.get(next);
    }
    theAmount[i] = '\0';

    if(whatToCheck == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
        outTemp.close();
        remove("temporary.txt");

        money.close();
        MainMenu main;
        Sleep(2000);
        system("cls");
        main.menu(acct);
    }

     if(whatToCheck == 1)
    {
        amount = atof(theAmount);
    }

    if(amount <50)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tYOU CANNOT BUY AIRTIME LESS THAN #50"<<endl;
        goto incomplete;
    }
    else if(amount >1000000)
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tYOU CANNOT BUY AIRTIME MORE THAN #1,000,000 AT A TIME"<<endl;
        goto incomplete;
    }


    if(myvery.existBeforeDeposit(account_number))
    {
    outTemp.precision(2);
    invalid3:cout << "\n\n\t\t\t\t\t\t\t\tYOU WANT TO PURCHASE AN AIRTIME OF #"<<setprecision(2)<<amount<<" TO 0"<<phone_number<<endl;
    cout << "\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE (Y/N) : ";
    char choice;
    cin >>choice;
    if((choice == 'y')||(choice == 'Y'))
    {
        goto startTran;
    }
    else if((choice == 'n')||(choice == 'N'))
    {
        goto incomplete;
    }
    else
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid3;
    }
    startTran:while(money>>file_accountNum>>file_ledger_balance>>file_available_balance)
    {

        if(file_accountNum == account_number)
        {
            if(file_ledger_balance >= amount)
            {
                outTemp<<setprecision(2)<<file_accountNum<<" "<<setprecision(2)<<file_ledger_balance-amount<<" "<<setprecision(2)<<file_available_balance-amount<<endl;
                cout <<"\n\n\t\t\t\t\t\t\t\tAIRTIME PURCHASE SUCESSFUL..."<<endl;

            }
            else
            {
                outTemp<<setprecision(2)<<file_accountNum<<" "<<setprecision(2)<<file_ledger_balance<<" "<<setprecision(2)<<file_available_balance<<endl;
                cout <<"\n\n\t\t\t\t\t\t\t\tINSUFICIENT FUNDS..."<<endl;

            }
        }
        else
        {
            outTemp<<file_accountNum<<" "<<file_ledger_balance<<" "<<file_available_balance<<endl;
        }
    }

    money.close();
    outTemp.close();
    remove("money.txt");
    rename("temp.txt", "money.txt");
    //complete:cout <<"-----TRANSACTION COMPLETED SUCCESSFULLY-----"<<endl;
    incomplete:

    cout <<"\n\n\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
    cout <<"\n\n\t\t\t\t\t\t\t\t";
    system("pause");
    system("cls");
    mydecor.slowDemDown();
    system("cls");
    cout <<"\n\n\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid2:cout <<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
    char choice2;
    cin >>choice2;
    if((choice2 == 'y')||(choice2 == 'Y'))
    {
        system("cls");
        mydecor.slowDemDown();
        system("cls");
        main.menu(acct);
    }
    else if((choice2 == 'n')||(choice2 == 'N'))
    {
        cout << "\n\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        system("cls");
        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
        Sleep(2000);
        //will later call another function there to ask if user want to perform another operation
        mydecor.callExit();

    }
    else
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid2;
    }

    }
  else
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tYOUR ACCOUNT IS EMPTY, YOU HAVE TO DEPOSIT TO MAKE ANY WITHRAWAL"<<endl;
        goto incomplete;

    }

}



void Operations::payBills(string& acct) // function to pay different kinds of bills
{

    menu:
    Operations op;
    Verify myvery;
    Verify myveryf;
    NewVerify mynewvery;
    Decoration mydecor;
    MainMenu main;
    mydecor.slowDemDown();
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t1) <<ELECTRIC>> \t\t\t\t\t\t\t\t\t\t\t\t\t\t <<SCHOOL>>       (2";
    cout << "\n\n\n\t\t3) <<INSURANCE>> \t\t\t\t\t\t\t\t\t\t\t\t\t\t <<AIR-LINE>>     (4";
    cout << "\n\n\n\t\t5) <<TV>> \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t <<TAX>>          (6";
    cout << "\n\n\n\t\t7) <<TRANSFER>> \t\t\t\t\t\t\t\t\t\t\t\t\t\t <<EXIT>>         (8";
    char x;
    account_number = acct;
    cout <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t";
    cin >>x;
    system("cls");
    switch(x)
    {
    case '1':
        {


        father:
        string companyName;

        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER A FULL STOP '.' AFTER YOU FILL THE ELECTRICITY COMPANY NAME"<<endl;
        cout <<"\n\n\t\t\t\t\t\t\t\tENTER ELECTRICITY COMPANY NAME : ";
         getline(cin, companyName, '.');
         if (myveryf.nameCheckNew(companyName)!= 1)
        {

            cout << "\n\n\t\t\t\t\t\t\t\tONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
            goto father;
        }

        comehere:
        char theAmount[30];
        char next;
        char stupidStuff;
        Sleep(1000);
        cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
        cin.get(stupidStuff);
        system("cls");
        float amount;
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


        std::cin.get(next);
        int i =0;
        int whatToCheck =1;
        while(next != '\n')
        {
            if((isdigit(next))&&(i < 30))
            {
                theAmount[i] = next;
                i++;

            }
            else
            {
                whatToCheck = 0;

            }

            cin.get(next);
        }
        theAmount[i] = '\0';

        if(whatToCheck == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
            MainMenu main;
            Sleep(2000);
            system("cls");
            main.menu(acct);
        }

        if(whatToCheck == 1)
        {
            amount = atof(theAmount);
        }
        if(amount< 50 )
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CAN'T PAY MONEY LESS THAN #50";
            goto comehere;
        }
        if(amount >1000000000)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CANT PAY MORE THAN #1,000,000,000 AT ONCE";
            goto comehere;
        }
        int a;
        a=mynewvery.ledgerBalanceCheck(account_number, amount);
        if(a ==1)
        {
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\nELECTRICITY BILL PAYMENT TO "<<companyName<<" IS SUCCESSFUL"<<endl;
        }
        else
        {
            cout <<"\n\n\t\t\t\t\t\t\t\tBILL PAYMENT FAILED"<<endl;
        }

        break;
        }
    case '2':
        {

        father1:
        string companyName;

         char schoolAcc[10];
        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER SCHOOL ACOUNT NUMBER : ";
        int b;
        do
        {
            cin >> schoolAcc;
            b = myvery.acctNumVerify(schoolAcc);
        }while(b != 1);

        cout <<"\n\t\t\t\t\t\t\t\tENTER A FULL STOP '.' AFTER YOU FILL THE SCHOOL NAME"<<endl;
        cout <<"\n\t\t\t\t\t\t\t\tENTER SCHOOL NAME : ";
         getline(cin, companyName, '.');
         if (myveryf.nameCheckNew(companyName)!= 1)
        {
            cout << "\n\t\t\t\t\t\t\t\tONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
            goto father1;
        }



        comehere1:
        char theAmount[30];
        char next;
        char stupidStuff;
        Sleep(1000);
        cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
        cin.get(stupidStuff);
        system("cls");
        float amount;
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


        std::cin.get(next);
        int i =0;
        int whatToCheck =1;
        while(next != '\n')
        {
            if((isdigit(next))&&(i < 30))
            {
                theAmount[i] = next;
                i++;

            }
            else
            {
                whatToCheck = 0;

            }

            cin.get(next);
        }
        theAmount[i] = '\0';

        if(whatToCheck == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
            MainMenu main;
            Sleep(2000);
            system("cls");
            main.menu(acct);
        }

         if(whatToCheck == 1)
        {
            amount = atof(theAmount);
        }
        if(amount< 50 )
        {
            cout << "\n\t\t\t\t\t\t\t\tYOU CAN'T PAY MONEY LESS THAN #50";
            goto comehere1;
        }
        if(amount >1000000000)
        {
            cout << "\n\t\t\t\t\t\t\t\tYOU CANT PAY MORE THAN #1,000,000,000 AT ONCE";
            goto comehere1;
        }
        int a;
        a=mynewvery.ledgerBalanceCheck(account_number, amount);
        if(a ==1)
        {
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\nSCHOOL FEE PAYMENT TO "<<companyName<<" IS SUCCESSFUL"<<endl;
        }
        else
        {
            cout <<"\n\t\t\t\t\t\t\t\tFEE PAYMENT FAILED"<<endl;
        }
        break;
        }
    case '3':
        {

        father2:
        string companyName;

        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER A FULL STOP '.' AFTER YOU FILL THE SCHOOL NAME"<<endl;
        cout <<"\n\n\t\t\t\t\t\t\t\tENTER INSURANCE COMPANY NAME : ";
         getline(cin, companyName, '.');
         if (myveryf.nameCheckNew(companyName)!= 1)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
            goto father2;
        }

         comehere2:
        char theAmount[30];
        char next;
        char stupidStuff;
        Sleep(1000);
        cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
        cin.get(stupidStuff);
        system("cls");
        float amount;
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


        std::cin.get(next);
        int i =0;
        int whatToCheck =1;
        while(next != '\n')
        {
            if((isdigit(next))&&(i < 30))
            {
                theAmount[i] = next;
                i++;

            }
            else
            {
                whatToCheck = 0;

            }

            cin.get(next);
        }
        theAmount[i] = '\0';

        if(whatToCheck == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
            MainMenu main;
            Sleep(2000);
            system("cls");
            main.menu(acct);
        }

         if(whatToCheck == 1)
        {
            amount = atof(theAmount);
        }
        if(amount< 50 )
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CAN'T PAY MONEY LESS THAN #50";
            goto comehere2;
        }
        if(amount >1000000000)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CANT PAY MORE THAN #1,000,000,000 AT ONCE";
            goto comehere2;
        }
        int a;
        a=mynewvery.ledgerBalanceCheck(account_number, amount);
        if(a ==1)
        {
            cout <<"\n\n\n\n\nINSURANCE BILL PAYMENT TO "<<companyName<<" IS SUCCESSFUL"<<endl;
        }
        else
        {
            cout <<"\n\n\t\t\t\t\t\t\t\tBILL PAYMENT FAILED"<<endl;
        }
        break;
        }
    case '4':
        {

        father3:
        string companyName;

        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER A FULL STOP '.' AFTER YOU FILL THE AIR-LINE COMPANY NAME"<<endl;
        cout <<"\n\n\n\t\t\t\t\t\t\t\tENTER AIR-LINE COMPANY NAME : ";
         getline(cin, companyName, '.');
         if (myveryf.nameCheckNew(companyName)!= 1)
        {
            cout << "\n\n\n\t\t\t\t\t\t\t\tONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
            goto father3;
        }

        comehere3:
        char theAmount[30];
        char next;
        char stupidStuff;
        Sleep(1000);
        cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
        cin.get(stupidStuff);
        system("cls");
        float amount;
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


        std::cin.get(next);
        int i =0;
        int whatToCheck =1;
        while(next != '\n')
        {
            if((isdigit(next))&&(i < 30))
            {
                theAmount[i] = next;
                i++;

            }
            else
            {
                whatToCheck = 0;

            }

            cin.get(next);
        }
        theAmount[i] = '\0';

        if(whatToCheck == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;
            MainMenu main;
            Sleep(2000);
            system("cls");
            main.menu(acct);
        }

         if(whatToCheck == 1)
        {
            amount = atof(theAmount);
        }
        if(amount< 50 )
        {
            cout << "\n\n\n\t\t\t\t\t\t\t\tYOU CAN'T PAY MONEY LESS THAN #50";
            goto comehere3;
        }
        if(amount >1000000000)
        {
            cout << "\n\n\n\t\t\t\t\t\t\t\tYOU CANT PAY MORE THAN #1,000,000,000 AT ONCE";
            goto comehere3;
        }
        int a;
        a=mynewvery.ledgerBalanceCheck(account_number, amount);
        if(a ==1)
        {
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\nAIR-LINE TICKET SPACE BOOKING PAYMENT TO "<<companyName<<" IS SUCCESSFUL"<<endl;
        }
        else
        {
            cout <<"\n\n\n\t\t\t\t\t\t\t\tBILL PAYMENT FAILED"<<endl;
        }
        break;
        }
    case '5':
        {

        father4:
        string companyName;

        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER A FULL STOP '.' AFTER YOU FILL THE COMPANY NAME"<<endl;
        cout <<"\n\n\t\t\t\t\t\t\t\tENTER COMPANY NAME : ";
         getline(cin, companyName, '.');
         if (myveryf.nameCheckNew(companyName)!= 1)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
            goto father4;
        }

        comehere4:
        char theAmount[30];
        char next;
        char stupidStuff;
        Sleep(1000);
        cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
        cin.get(stupidStuff);
        system("cls");
        float amount;
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


        std::cin.get(next);
        int i =0;
        int whatToCheck =1;
        while(next != '\n')
        {
            if((isdigit(next))&&(i < 30))
            {
                theAmount[i] = next;
                i++;

            }
            else
            {
                whatToCheck = 0;

            }

            cin.get(next);
        }
        theAmount[i] = '\0';

        if(whatToCheck == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;

            MainMenu main;
            Sleep(2000);
            system("cls");
            main.menu(acct);
        }

         if(whatToCheck == 1)
        {
            amount = atof(theAmount);
        }
        if(amount< 50 )
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CAN'T PAY MONEY LESS THAN #50";
            goto comehere4;
        }
        if(amount >1000000000)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CANT PAY MORE THAN #1,000,000,000 AT ONCE";
            goto comehere4;
        }
        int a;
        a=mynewvery.ledgerBalanceCheck(account_number, amount);
        if(a ==1)
        {
            cout <<"\n\n\n\n\nTV BILL PAYMENT TO "<<companyName<<" IS SUCCESSFUL"<<endl;
        }
        else
        {
            cout <<"\n\n\t\t\t\t\t\t\t\tBILL PAYMENT FAILED"<<endl;
        }
        break;
        }
    case '6':
        {
        father5:
        string companyName;
        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER A FULL STOP '.' AFTER YOU FILL THE TAX COMPANY NAME"<<endl;
        cout <<"\n\n\t\t\t\t\t\t\t\tENTER TAX COMPANY NAME : ";
         getline(cin, companyName, '.');
         if (myveryf.nameCheckNew(companyName)!= 1)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
            goto father5;
        }

        comehere5:
        char theAmount[30];
        char next;
        char stupidStuff;
        Sleep(1000);
        cout <<"\n\n\t\t\t\t\t\t\t\tpress 'enter' to continue... ";
        cin.get(stupidStuff);
        system("cls");
        float amount;
        cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER AMOUNT : ";


        std::cin.get(next);
        int i =0;
        int whatToCheck =1;
        while(next != '\n')
        {
            if((isdigit(next))&&(i < 30))
            {
                theAmount[i] = next;
                i++;

            }
            else
            {
                whatToCheck = 0;

            }

            cin.get(next);
        }
        theAmount[i] = '\0';

        if(whatToCheck == 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tTHE AMOUNT MUST BE A NUMBER"<<endl;

            MainMenu main;
            Sleep(2000);
            system("cls");
            main.menu(acct);
        }

         if(whatToCheck == 1)
        {
            amount = atof(theAmount);
        }
        if(amount< 50 )
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CAN'T PAY MONEY LESS THAN #50";
            goto comehere5;
        }
        if(amount >1000000000)
        {
            cout << "\n\n\t\t\t\t\t\t\t\tYOU CANT PAY MORE THAN #1,000,000,000 AT ONCE";
            goto comehere5;
        }
        int a;
        a=mynewvery.ledgerBalanceCheck(account_number, amount);
        if(a ==1)
        {
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\nTAX PAYMENT TO "<<companyName<<" IS SUCCESSFUL"<<endl;
        }
        else
        {
            cout <<"\n\n\t\t\t\t\t\t\t\tTAX BILL PAYMENT FAILED"<<endl;
        }
        break;
        }
    case '7':
        {
           op.transfer(account_number);
            break;
        }

    case '8':
        {
            cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEXIT SUCCESSFULL";
            mydecor.callExit(); //will later call my exit here
            break;
        }

    default:
        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE ENTER A VALID OPTION"<<endl;
        system("cls");
        goto menu;
        break;
    }
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
    Sleep(5000);
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
    system("pause");
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid8:cout <<"\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
    char choice8;
    cin >>choice8;
    if((choice8 == 'y')||(choice8 == 'Y'))
    {
        system("cls");
        mydecor.slowDemDown();
        system("cls");
        main.menu(acct);
    }
    else if((choice8 == 'n')||(choice8 == 'N'))
    {
        cout << "\n\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        system("cls");
        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
        Sleep(1000);
        //will later call another function there to ask if user want to perform another operation
        mydecor.callExit();

    }
    else
    {
        cout <<"\n\n\t\t\t\t\t\t\t\tPLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid8;
    }


}


void Operations::balance(string& acct) // function to get the ledger and available balance
{
    ifstream money("money.txt");
    account_number = acct;
    MainMenu main;
    Decoration mydecor;
    mydecor.slowDemDown();
    string accountNum, ledger_balance, available_balance;
    while(money>>accountNum>>ledger_balance>>available_balance)
    {
        if(accountNum == account_number)
        {
            cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tAVAILABLE BALANCE : "<<available_balance<<".00"<<endl;
            cout <<"\n\t\t\t\t\t\t\t\tLEDGER BALANCE : "<<ledger_balance<<".00"<<endl;
        }
    }
    money.close();
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t**THANK YOU FOR BANKING WITH US**"<<endl;
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
    system("pause");
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tDO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid9:cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
    char choice9;
    cin >>choice9;
    if((choice9 == 'y')||(choice9 == 'Y'))
    {
        system("cls");
        mydecor.slowDemDown();
        system("cls");
        main.menu(acct);
    }
    else if((choice9 == 'n')||(choice9 == 'N'))
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tOK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        system("cls");
        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
        Sleep(1000);
        //will later call another function there to ask if user want to perform another operation
        mydecor.callExit();

    }
    else
    {
        cout <<"PLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid9;
    }
}

string Operations::accountType() // function to choose between the three available account types
{
    cout << "CHOOSE YOUR PREFFERED ACCOUNT TYPE"
    <<endl<< "FOR MORE INFORMATION VISIT OUR NEAREST BRANCH"<<endl;
    cout << "<<1>> SAVINGS\n"
    <<"<<2>> CURRENT\n"
    <<"<<3>> DEPOSIT"<<endl;
    cout <<"ENTER YOUR CHOICE : ";

    int choice;
    string accountT;
    cin >> choice;
    switch(choice)
    {
        case 1:
            {
                accountT = "SAVINGS";
                break;
            }
        case 2:
            {
                accountT = "CURRENT";
                break;
            }
        case 3:
            {
                accountT = "DEPOSIT";
                break;
            }

        default:
            cout <<"WORNG OPTION, PLEASE ENTER A VALID OPTION"<<endl;
    }

    return accountT;
}

void Operations::randNum(string& accountNumber) // function to generate random numbers
{
    srand(time(0));




    char numbers[10]= {'1','2','3','4','5','6','7','8','9','0'};

    for (int i=0; i<10; i++)
    {
        accountNumber[i] = numbers[(rand()%10)+1];
    }
    /*
    for(int i=0;i<10;i++)
    {

        cout <<accountNumber[i];
    }
*/




}


void Operations::readAndClean(int& n)  // function to read in numbers and clean the unnecessary characters
{
    using namespace std;
    const int ARRAY_SIZE = 11;
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



char Operations::randCVVNum() // function to generate random numbers
{
    srand(time(0));
    char mynum;
    char numbers[10]= {'1','2','3','4','5','6','7','8','9','0'};


        mynum = numbers[(rand()%9)+1];

return mynum;

}


char Operations::randCardNum() // function to generate random numbers
{
    srand(time(0));

    char mynum;


    char numbers[10]= {'1','2','3','4','5','6','7','8','9','0'};

     mynum = numbers[(rand()%9)+1];


return mynum;
}






