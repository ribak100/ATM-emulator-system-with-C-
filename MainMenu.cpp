#include "MainMenu.h"
#include "Verify.h"
#include "Decoration.h"
#include <iostream>
#include "Operations.h"
#include <conio.h>
#include <cstring>
#include <ctype.h>
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

using namespace std;

MainMenu::MainMenu(){}

void MainMenu::createAccount() // function to create a new account
{

    Verify myveryf;
    Operations op;
    MainMenu main;
    Decoration mydecor;
    string surname, firstName, lastName;
    int day, year, month;
    char phoneNumber[12];
    refill:mydecor.slowDemDown();
    cout <<"FILL YOUR NAME"<<endl;
    sur:cout << "ENTER YOUR SURNAME : ";
    cin >>surname;
    if (myveryf.nameCheck(surname)!= 1)
    {
        cout << "ONLY ENGLISH ALPHABETS ARE ALLOWED"<<endl;
        goto sur;
    }
    firs:cout << "ENTER YOUR FIRSTNAME : ";
    cin >>firstName;
    if (myveryf.nameCheck(firstName)!= 1)
    {
        cout << "ONLY ENGLISH ALPHABETS ARE ALLOWED"<<endl;
        goto firs;
    }
    sec:cout << "ENTER YOUR LASTNAME : ";
    cin >> lastName;
    if (myveryf.nameCheck(lastName)!= 1)
    {
        cout << "ONLY ENGLISH ALPHABETS ARE ALLOWED"<<endl;
        goto sec;
    }

    int c;
     cout <<"DO NOT INCLUDE THE FIRST ZERO TO YOUR PHONE HUMBER"<<endl;
    do{

    cout << "ENTER PHONE NUMBER : ";
    cin >>phoneNumber;
    c = myveryf.phoneNumVerify(phoneNumber);
    cout <<endl;
    }while(c != 1);

    cout <<"FILL YOUR DATE OF BIRTH"<<endl;
    int correct;
    here:do{
    cout <<"ENTER DAY : ";
    cin >>day;
    if((day < 1 )||(day >31))
    {
        cout << "THE DAY RANGE MUST BE BETWEEN 1-31"<<endl;
        goto here;
    }
    cout <<"ENTER MONTH : ";
    cin >>month;
    if((month < 1 )||(month >12))
    {
        cout << "THE MONTH RANGE MUST BE BETWEEN 1-12"<<endl;
        goto here;
    }
    cout <<"ENTER YEAR : ";
    cin >>year;

    correct = myveryf.dOfbCheck(day, month, year);
    }while (correct != 1);

    string fathername, motherName, nextOfKinName;
    char nextOfKinNumber[12];

    cout <<"FILL YOUR PARENT AND NEXT OF KIN INFORMATION"<<endl;
    cout <<"ENTER A FULL STOP '.' AFTER YOU FILL EACH PART, e.g KIM JE HA."<<endl;
    father:cout << "\nENTER YOUR FATHER'S FULL NAME : ";
     getline(cin, fathername, '.');
     if (myveryf.nameCheckNew(fathername)!= 1)
    {
        cout << "ONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
        goto father;
    }
    /*do
    {
        cin.get(fathername);
    }while(fathername!= '\n');
*/
    moth:cout << "\nENTER YOUR MOTHER'S FULL NAME : ";
     getline(cin, motherName, '.');
     if (myveryf.nameCheckNew(motherName)!= 1)
    {
        cout << "ONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
        goto moth;
    }
    /* do
    {
        cin.get(motherName);
    }while(motherName!= '\n');
*/
    kin:cout << "\nENTER YOUR NEXT OF KIN FULL NAME : ";
    getline(cin, nextOfKinName, '.');
    if (myveryf.nameCheckNew(nextOfKinName)!= 1)
    {
        cout << "ONLY ENGLISH ALPHABETS, '.' AND '-' ARE ALLOWED"<<endl;
        goto kin;
    }
    /* do
    {
        cin.get(nextOfKinName);
    }while(nextOfKinName!= '\n');
*/
     int v;
    cout <<"DO NOT INCLUDE THE FIRST ZERO TO YOUR PHONE HUMBER"<<endl;
    do{
    cout << "ENTER NEXT OF KIN PHONE NUMBER : ";
    cin >>nextOfKinNumber;
    v = myveryf.phoneNumVerify(nextOfKinNumber);
    }while(v != 1);
    string accountTyp;
    accountTyp = op.accountType();
    cout <<"VERIFY AND CONFIRM YOUR INFORMATION"<<endl;
    cout <<"YOUR NAME INFORMATION"<<endl;
    cout << "YOUR SURNAME : "<<surname<<endl;
    cout << "YOUR FIRSTNAME : "<<firstName<<endl;
    cout << "YOUR LASTNAME : "<<lastName<<endl;
    cout << "YOUR DATE OF BIRTH : "<<day<<"/"<< month<<"/"<<year<<endl;
    cout << "YOUR PHONE NUMBER : "<<phoneNumber<<endl;
    cout <<"YOUR PARENT AND NEXT OF KIN INFORMATION"<<endl;
    cout << "YOUR FATHER'S NAME : "<<fathername<<endl;
    cout << "YOUR MOTHER'S NAME : "<<motherName<<endl;
    cout << "YOUR NEXT OF KIN NAME : "<<nextOfKinName<<endl;
    cout << "ENTER NEXT OF KIN PHONE NUMBER : "<<nextOfKinNumber<<endl;
    cout <<"HAVE YOU CONFIRMED THE ABOVE INFORMATION (y/n)"<<endl;
    come2:cout << "ENTER YOUR CHOICE : ";
    char choice;
    cin >> choice;
    if ((choice == 'y')||(choice == 'Y'))
    {
        cout <<"**ACCOUNT CREATED SUCCESSFULLY**\n"<<"THANK YOU FOR BANKING WITH US"<<endl;

    }
    else if((choice != 'n')||(choice != 'N'))
    {
        cout <<"OK FILL IN THE INFORMATION AGAIN"<<endl;
        goto refill;
    }
    else
    {
        cout <<"PLEASE ENTER A VALID INPUY Y FOR YES AND N FOR NO"<<endl;
        goto come2;
    }

    string accountnum;
    if(accountnum == "ade")
    {
        exist:cout <<"SORRY THE ACCOUNT NUMBER WE CHOOSE FOR U IS NOT AVAILABE, YOU WILL RECIEVE A NEW ONE SHORTLY"<<endl;
        goto chooseNew;
    }

    chooseNew:cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR ACCOUNT NUMBER IS : ";
     op.randNum(accountnum);
    for(int i=0;i<10;i++)
    {

        cout <<accountnum[i];
    }
    fstream check("checkAccount.txt");
    for(int i=0;i<10;i++)
    {

        check <<accountnum[i];
    }
    string accnum;
    while(check>>accnum)
    {
        if(myveryf.existBeforeAcc(accnum))
        {
            goto exist;
        }
        else
        {
            goto putinfile;
        }
    }

    cout << "\nIS THE ACCOUNT NUMBER PROVIDED FOR YOU A VALID 10 DIGIT NUMBER, PLEASE VERIFY (Y/N)";
    char choice2;
    come3:cout << "ENTER YOUR CHOICE : ";
    cin >> choice2;
    if ((choice2 == 'y')||(choice2 == 'Y'))
    {
        cout << "OK"<<endl;
        cout <<"**ACCOUNT CREATED SUCCESSFULLY**\n"<<"THANK YOU FOR BANKING WITH US"<<endl;
        goto putinfile;

    }
    else if((choice2 != 'n')||(choice2 != 'N'))
    {

        cout <<"OK WE WILL PROVIDE ANOTHER"<<endl;
        system("cls");
        goto chooseNew;
    }
    else
    {
        cout <<"PLEASE ENTER A VALID INPUY Y FOR YES AND N FOR NO"<<endl;
        system("cls");
        goto come3;
    }


    //I WILL ALSO BE MOVING SOME INFO HERE TO THE ACCOUNT FILE
    putinfile:fstream infile("newAccount.txt", ios::app);
    for(int i=0;i<10;i++)
    {

        infile <<accountnum[i];
    }
    infile<<" "<<surname<<" "<<firstName<<" "<<lastName<<" "<<day<<" "
    <<month<<" "<<year<<" "<<phoneNumber<<" "<<fathername<<" "<<motherName
    <<" "<<nextOfKinName<<" "<<nextOfKinNumber<<" "<<accountTyp<<endl;

    fstream accfile("account.txt", ios::app);
    for(int i=0;i<10;i++)
    {

        accfile <<accountnum[i];
    }
    accfile<<" "<<surname<<" "<<firstName<<" "<<lastName<<" "<<phoneNumber<<" "<<accountTyp<<endl;

    remove("checkAccount.txt");
    infile.close();

    cout <<"**THANK YOU FOR BANKING WITH US**"<<endl;
    mydecor.delay();
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPLEASE TAKE YOUR CARD..."<<endl;
    Sleep(2000);
        //will later call another function there to ask if user want to perform another operation
    mydecor.callExit();

    /*
    system("pause");
    cout <<"DO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid8:cout <<"ENTER YOUR CHOICE : ";
    char choice8;
    cin >>choice8;
    if((choice8 == 'y')||(choice8 == 'Y'))
    {


    }
    else if((choice8 == 'n')||(choice8 == 'N'))
    {
        cout << "OK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        cout <<"PLEASE TAKE YOUR CARD..."<<endl;
        Sleep(1000);
        //will later call another function there to ask if user want to perform another operation
        mydecor.callExit();

    }
    else
    {
        cout <<"PLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid8;
    }
*/
}

int MainMenu::enterPin(string& accountNum)  // function to enter the ATM pin
{
    string pin, card_number, cvv, file_pin, file_account_number;
    cout << "\n\n\t\t\t\t\t\t\t\tENTER YOUR PIN : ";
    cin >>pin;
    ifstream outfile("newCardInfo.txt");
    while(outfile>>card_number>>cvv>>file_pin>>file_account_number)
    {
        if((accountNum == file_account_number)&&(pin == file_pin))
        {
            return 1;
        }

    }
    return 0;
}

void MainMenu::addCardInfo(string& acct)  // function to register an ATM card to an existing account
{
        Verify myverfy;
    Operations op;
    Decoration mydecor;
    int count =0;
    string account_number, surname, firsrname, lastname,  accountType;
    char  phone_number[11];
    string file_account_number, file_surname, file_firsrname, file_lastname, file_phone_number, file_accountType;

    acc:
    mydecor.slowDemDown();
    account_number = acct; //still need to verify this in some way


    cout <<"\nENTER YOUR SURNAME : ";
    int b;
    do
    {
         cin >> surname;
         b = myverfy.nameCheck(surname);
         if(b ==0)
            cout <<"ENTER YOUR SURNAME : ";
    }while(b != 1);

    cout <<"ENTER YOUR FIRSTNAME : ";
    int c;
    do
    {
        cin >> firsrname;
        c = myverfy.nameCheck(firsrname);
        if(c ==0)
            cout <<"ENTER YOUR FIRSTNAME : ";
    }while(c != 1);

    cout <<"ENTER YOUR LASTNAME : ";
    int d;
    do
    {
        cin >> lastname;
        d = myverfy.nameCheck(lastname);
        if(d ==0)
            cout <<"ENTER YOUR LASTNAME : ";
    }while(d != 1);
    cout<< "DO NOT ENTER THE FIRST ZERO (0) "<<endl;
    cout <<"ENTER YOUR PHONE NUMBER : ";
    int e;
    do
    {
        cin >> phone_number;
        e = myverfy.phoneNumVerify(phone_number);
        if(e ==0)
            cout <<"ENTER YOUR PHONE NUMBER : ";
    }while(e != 1);

     cout <<"ENTER YOUR ACCOUNT TYPE : ";
     int f;
     do
     {
         cin >> accountType;
         f = myverfy.nameCheck(accountType);
         if(f ==0)
            cout <<"ENTER YOUR ACCOUNT TYPE : ";
     }while(f != 1);


    ifstream infile("account.txt");
    fstream newCard("newCardInfo.txt", ios::app);
    //fstream check2("checkAccounts.txt", ios::app); //temporary file, will remove later
    //fstream check("checkAccount.txt", ios::app); //temporary file, will remove later

    if(count == 6)
    {
        cout <<"TOO MANY ATTEMPTS, YOU HAVE ENTERED TOO MANY WRONG INFORAMATION"
        <<"TRY AGAIN LATER"<<endl;
        //will later change exit to my own
        exit(0);
    }
    while(infile>>file_account_number>>file_surname>>file_firsrname>>file_lastname>>file_phone_number>>file_accountType)
    {
        if(myverfy.existBeforeCardInfo(account_number))
        {
            cout <<"THIS ACCOUNT NUMBER ALREADY HAS AN EXISTING CARD"<<endl;
            char choice;

                invalid:cout << "WHAT WOULD YOU LIKE TO ENTER ANOTHER ACCOUNT NUMBER (y/n) : ";
                cin >>choice;
                if((choice == 'y')||(choice == 'Y'))
                {
                    count++;
                    goto acc;
                }
                else if((choice == 'n')||(choice == 'N'))
                {
                    //will later call another function there to ask if user want to perform another operation
                    exit(0);
                }
                else
                {
                    cout <<"PLEASE INPUT A VALID OPTION, Y FOR YES AND N FOR NO"<<endl;
                    goto invalid;
                }
        }
        else
        {
            if(account_number == file_account_number)
            {
                if((surname == file_surname)&&(firsrname== file_firsrname)&&(lastname == file_lastname))
                {
                    if(phone_number == file_phone_number)
                    {
                        if(accountType == file_accountType)
                        {

                            string CVV, cardNumber;
                            char pin[4];
                            string verfypin;
                            pin:cout<< "ENTER PIN : ";
                            cin >>pin;
                            if(strlen(pin) != 4)
                            {
                                cout <<"PIN MUST BE FOUR NUMBERS"<<endl;
                                goto pin;
                            }
                            if(myverfy.numCheck(pin) != 1)
                                goto pin;

                            cout <<"VERIFY PIN : ";
                            cin >>verfypin;
                                if(pin != verfypin)
                                {
                                    cout << "PIN DOESN'T MATCH"<<endl;
                                    goto pin;
                                }


                            if(cardNumber == "ade")
                            {
                                cout <<"SORRY THE CARD NUMBER WE CHOOSE FOR U IS NOT AVAILABE, YOU WILL RECIEVE A NEW ONE SHORTLY"<<endl;
                                goto chooseNew2;
                            }

                            chooseNew2:cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYOUR CARD NUMBER IS : ";
                            op.randCardNum(cardNumber);
                            for(int i=0; i<16; i++)
                            {
                                cout <<cardNumber[i];
                            }
/*
                            for(int i=0;i<16;i++)
                            {
                                check2 <<cardNumber[i];
                            }
                            string cardnum;
                            check2>>cardnum;
                            cout << "thgsdnsnkngdgv= "<<cardnum;
                            while(check2>>cardnum)
                            {
                                if(myverfy.existBeforeCardInfo(cardnum))
                                {
                                    goto exist2;
                                }
                                else
                                {
                                */
                                cout << "\nIS THE CARD NUMBER PROVIDED FOR YOU A VALID 16 DIGIT NUMBER, WITH NO SPACE IN BETWEEN, PLEASE VERIFY(count) (y/n)"<<endl;
                                char choice;
                                come2:cout << "ENTER YOUR CHOICE : ";
                                cin >> choice;
                                if ((choice == 'y')||(choice == 'Y'))
                                {
                                    cout << "OK"<<endl;
                                    cout <<"**CARD NUMBER REGISTERED SUCCESSFULLY**\n"<<endl;
                                    goto putinfilecardnum;

                                }
                                else if((choice == 'n')||(choice == 'N'))
                                {
                                cout <<"OK WE WILL PROVIDE ANOTHER"<<endl;
                                system("cls");
                                goto chooseNew2;
                                }
                                else
                                {
                                cout <<"PLEASE ENTER A VALID INPUY Y FOR YES AND N FOR NO"<<endl;
                                system("cls");
                                goto come2;
                                }

                                /*
                                for (int i=0; i<16; i++)
                                    {
                                        if((cardNumber[i]>46 )&&(cardNumber[i]<58))
                                        {
                                           continue;
                                        }
                                        else
                                        {
                                            goto exist2;
                                        }
                                    }
                                */



                               // }

                            //}

                                putinfilecardnum:for(int i=0;i<16;i++)
                                {
                                    newCard <<cardNumber[i];
                                }

                            if(CVV == "kgh")
                            {
                                cout <<"SORRY THE CVV WE CHOOSE FOR U IS NOT AVAILABE, YOU WILL RECIEVE A NEW ONE SHORTLY"<<endl;
                                goto chooseNew;
                            }

                            chooseNew:cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYOUR CVV IS : ";
                            op.randCVVNum(CVV);
                            for(int i=0;i<3;i++)
                            {

                                cout <<CVV[i];

                            }
                    /*
                            //checkcv:
                            for(int i=0;i<3;i++)
                            {

                            check <<CVV[i];
                            }
                            string Cvvnum;
                            while(check>>Cvvnum)
                            {
                                if(myverfy.existBeforeCardInfo(Cvvnum))
                                {
                                    goto exist;
                                }
                                else
                                {
                            */
                                cout << "\nIS THE CVV PROVIDED FOR YOU A VALID 3 DIGIT NUMBER, WITH NO SPACE IN BETWEEN, PLEASE VERIFY(count) (Y/N)"<<endl;
                                char choice2;
                                come4:cout << "ENTER YOUR CHOICE : ";
                                cin >> choice2;
                                if ((choice2 == 'y')||(choice2 == 'Y'))
                                {
                                    cout << "OK"<<endl;
                                    cout <<"**CVV REGISTERED SUCCESSFULLY**\n"<<endl;
                                    goto putinfilecvv;

                                }
                                else if((choice2 == 'n')||(choice2 == 'N'))
                                {
                                cout <<"OK WE WILL PROVIDE ANOTHER"<<endl;
                                system("cls");
                                goto chooseNew;
                                }
                                else
                                {
                                cout <<"PLEASE ENTER A VALID INPUY Y FOR YES AND N FOR NO"<<endl;
                                system("cls");
                                goto come4;
                                }
                               // }

                                   /* for (int i=0; i<3; i++)
                                    {

                                        if((CVV[i] =='1')||(CVV[i] =='2')||(CVV[i] =='3')||(CVV[i] =='4')||(CVV[i] =='5')||(CVV[i] =='6')||(CVV[i] =='7')||(CVV[i] =='8')||(CVV[i] =='9')||(CVV[i] =='0') )
                                        {
                                           continue;
                                        }
                                        else
                                        {
                                            goto exist;
                                        }
                                    }
                                */



                               // }
                                putinfilecvv:newCard<<" ";
                                for(int i=0;i<3;i++)
                                {

                                    newCard << CVV[i];
                                }

                                newCard<<" "<<pin<<" "<<account_number<<endl;





                                cout <<"\n**CARD CREATED CREATED SUCCESSFULLY**\n"<<"THANK YOU FOR BANKING WITH US"<<endl;

                            }
                            else
                            {
                                count++;
                                cout <<"\nWRONG ACCOUNT TYPE PROVIDED"<<endl;
                                goto acc;
                            }





                    }
                    else
                    {
                        count++;
                        cout <<"\nWRONG PHONE NUMBER PROVIDED\n"
                        <<"REMEMBER NOT TO INPUT THE FIRST ZERO(0)";
                        goto acc;
                    }

                }
                else
                {
                    count++;
                    cout << "\nWRONG NAME PROVIDED";
                    goto acc;
                }


            }

        }




    }

    newCard.close();
    cout <<"**THANK YOU FOR BANKING WITH US**"<<endl;
    mydecor.delay();
    system("cls");
    cout <<"PLEASE TAKE YOUR CARD..."<<endl;
    Sleep(2000);
        //will later call another function there to ask if user want to perform another operation
    mydecor.callExit();

    /*
    system("pause");
    cout <<"DO YOU WANT TO PERFORM ANOTHER TRANSACTION (y/n)"<<endl;
    invalid8:cout <<"ENTER YOUR CHOICE : ";
    char choice8;
    cin >>choice8;
    if((choice8 == 'y')||(choice8 == 'Y'))
    {
        main();
    }
    else if((choice8 == 'n')||(choice8 == 'N'))
    {
        cout << "OK... THANK YOU FOR BANKING WITH US"<<endl;
        mydecor.delay();
        cout <<"PLEASE TAKE YOUR CARD..."<<endl;
        Sleep(1000);
        //will later call another function there to ask if user want to perform another operation
        mydecor.callExit();

    }
    else
    {
        cout <<"PLEASE INPUT A VALID OPTION, 'Y' FOR YES AND 'N' FOR NO"<<endl;
        goto invalid8;
    }
    */
}


void MainMenu::menu(string& acct) // function to get to the page where all transaction can be performed
{
    Operations op;
    Decoration mydecor;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t1) <<WITHDRAW>> \t\t\t\t\t\t\t\t\t\t\t\t <<DEPOSIT>>      (2";
    cout << "\n\n\n\t\t3) <<TRANSFER>> \t\t\t\t\t\t\t\t\t\t\t\t <<BALANCE>>      (4";
    cout << "\n\n\n\t\t5) <<PAYBILLS>> \t\t\t\t\t\t\t\t\t\t\t\t <<BUY AIRTIME>>  (6";
    cout << "\n\n\n\t\t7) <<CHANGE PIN>> \t\t\t\t\t\t\t\t\t\t\t\t <<EXIT>>         (8";
    char x;
    cout <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t";
    menu:cin >>x;
    switch(x)
    {
    case '1':
        system("cls");
        op.withdraw(acct);
        break;
    case '2':
        system("cls");
        op.Deposit(acct);
        break;
    case '3':
        system("cls");
        op.transfer(acct);
        break;
    case '4':
        system("cls");
        op.balance(acct);
        break;
    case '5':
        system("cls");
        op.payBills(acct);
        break;
    case '6':
        system("cls");
        op.buyAirtime(acct);
        break;
    case '7':
        system("cls");
        op.changePin(acct);
        break;
    case '8':
        cout <<"EXIT SUCCESSFULL";
        mydecor.callExit(); //will later call my exit here
        break;
    default:
        cout <<"PLEASE ENTER A VALID OPTION"<<endl;
        system("cls");
        goto menu;
        break;
    }



}

void MainMenu::mainPage() // function to move to the main page
{
  Decoration mydecor;
  int process=0;
  system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPreparing the system";
    int delay = 0;
    for(delay=0;delay<25;delay++)
    {
        mydecor.delay();
        cout <<".";
    }
  system("cls");
  mydecor.date1();
  cout << "\n";
  cout <<"\t\t\t\t\t\t\t    ----------------------------------\n";
  cout <<"\t\t\t\t\t\t\t    |       ATM EMULATOR SYSTEM       |\n";
  cout <<"\t\t\t\t\t\t\t    ----------------------------------\n";
  cout <<"\n\n";
  cout <<"\t\t\t\t\t\t\t";
  cout <<"PREPARED BY    ";
  cout <<":";
  cout <<"  ADEKANYE ABDULKABIR (HIDDEN)";
  cout <<"\n\n";
  cout <<"\t\t\t\t\t\t\t";
  cout <<"PROJECT   ";
  cout <<":";
  cout <<"   \tATM Emulator System";
  cout <<"\n\n";
  cout <<"\t\t\t\t\t\t\t";
  cout <<"\n\n";
  cout <<"\n\n";
  cout <<"\t\t\t\t\t\t\t";
  system("pause");
  cout <<"\n\t\t\t\t\t\t\tLoading";

  for(process=0;process<25;process++)
  {
    mydecor.delay();
    cout <<".";
  }
}

void MainMenu::insertCard(string& acct) // function to insert the ATM card
{
    MainMenu main;
    Verify myverfy;
    Decoration mydecor;

    string accountNumber;
    int verify, counts(4);
    input:

    accountNumber = acct;
    verify = main.enterPin(accountNumber);
    if(myverfy.existBeforeCardInfo(accountNumber))
    {
        if(verify == 1)
        {
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t**ACCESS GRANTED**   ";//WILL LATER CALL MENU HERE
            Sleep(2000);
            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
            //system("pause");
            system("cls");
            mydecor.slowDemDown();
            main.menu(acct);
        }
        else
        {
            cout <<"INVALID PIN"<<endl;
            counts--;
            goto counting;
        }
    }

    counting:cout <<counts<<" ATTEMPTS REMAINING"<<endl;
    if(counts== 0)
    {
        cout <<"TOO MANY ATTEMPTS..."<<endl;
        mydecor.callExit();
    }
    else
    {
        goto input;
    }


}






