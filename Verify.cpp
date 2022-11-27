#include "Verify.h"
#include <iostream>
#include <conio.h>
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
#include <sstream>
#include <vector>
#include <iterator>
#include <ctime>
//#include "Exception.h"

using namespace std;

Verify::Verify()
{
    //intentionally empty
}


int Verify::acctNumVerify(int& accoutNum, string& surname) // function to verify account number
{
    int fileAccNum;
    int verify = 0;
    string fileSurname, fileFname, fileLname;

    ifstream outFile("account.txt");
    if(outFile.fail())
    {
        cout << "ERROR 309: FILE OPENING FAILED"<<endl;
    }
    else
    {

        while(!outFile.eof())
        {
            outFile>>fileAccNum>>fileSurname>>fileFname>>fileLname;
            if((accoutNum == fileAccNum)&&(surname == fileSurname))
            {
                verify= 1;
            }
            else
            {
                verify = 0;
            }
        }

    }

    return verify;
}

int Verify::phoneNumVerify(char number[11]) // function to verify phone number
{



    if(strlen(number) !=10){
        cout << "n\n\t\t\t\t\t\t\t\tPLEASE ENTER 10 DIGITS"<<endl;
        return 0;
    }
    else{
        if(number[0] == '0'){
            cout << "n\n\t\t\t\t\t\t\t\tPLEASE DO NOT INCLUDE THE FIRST ZERO IN THE NUMBER"<<endl;
            return 0;
        }
        if ((number[0] == '7')||(number[0] == '8')||(number[0] == '9')) {
                if ((number[0]== '7')&&(number[1] == '0'))
                {
                    return 1;
                }
                else if((number[0]== '8')&&((number[1]=='1')||(number[1] == '0')))
                {
                    return 1;
                }
                else if((number[0] == '9')&&(number[1]== '0'))
                {
                    return 1;
                }
                else{
                    cout << "n\n\t\t\t\t\t\t\t\tFIRST NUMBER INPUT MUST BE 0,1";
                return 0;
                }
        }

        else{
            cout <<"n\n\t\t\t\t\t\t\t\tFIRST NUMBER INPUT MUST BE 7,8,9,";
            return 0;
        }


   }

}



int Verify::acctNumVerify(char number[10]) // function to verify phone number
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
            cout <<"\n\n\t\t\t\t\t\t\t\INVALID INPUT, ONLY NUMBERS BETWEEN 0-9 ARE ACCEPTED"<<endl;
            return 0;
        }
    }
    if(strlen(number) != 10)
    {
        cout << "\n\n\t\t\t\t\t\t\t\ACCOUNT NUMBERS MUST BE 10 DIGITS"<<endl;
        return 0;
    }

    return 1;

}






int Verify::nameCheck(char name[20])  // function to check if name input is correct
{
    int i =0;
    while(name[i] !='\0')
    {
        if (((name[i] > 64) && (name[i] < 92)) || ((name[i] > 95) && (name[i] < 124)) || (name[i] ==' '))
        {
            i++;
            continue;
        }
        else
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH ALPHABET"<<endl;
            return 0;
        }
    }
    return 1;
}

int Verify::nameCheck(string& name)  // function to check if name input is correct
{
    int i =0;
    int slash =0;
    while(name[i] !='\0')
    {
        if (slash ==2)
        {
            cout << "YOU ARE ONLY ALLOWED TO USE 1 '-' IN EACH NAME"<<endl;
            return 0;
        }
        if (isalpha(name[i]))
        {
            i++;
            continue;
        }
        else if(name[i] ==' ')
        {
            i++;
            continue;
        }
        else if(name[i] =='-')
        {
            i++;
            slash++;
            continue;
        }
        else
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH ALPHABET"<<endl;
            return 0;
        }
    }
    return 1;
}

int Verify::nameCheckNew(string& name)  // function to check if name input is correct
{
    int i =0;
    int slash =0;
    while(name[i] !='\0')
    {
        if (slash ==2)
        {
            cout << "YOU ARE ONLY ALLOWED TO USE 2 '-' IN EACH NAME"<<endl;
            return 0;
        }
        if (isdigit(name[i]))
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH LETTER"<<endl;
            return 0;

        }
        else if((name[i]>32)&&(name[i]<45))
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH LETTER"<<endl;
            return 0;
        }
        else if((name[i]>46)&&(name[i]<65))
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH LETTER"<<endl;
            return 0;
        }
        else if((name[i]>90)&&(name[i]<97))
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH LETTER"<<endl;
            return 0;
        }
        else if((name[i]>122)&&(name[i]<126))
        {
            cout <<"INVALID INPUT, NAME MUST BE AN ENGLISH LETTER"<<endl;
            return 0;
        }
        else if(name[i] =='-')
        {
            i++;
            slash++;
            continue;
        }
        else
        {
            i++;
            continue;
        }
    }
    return 1;
}

int Verify::numCheck(char num[30]) // function to check if input is number
{

    int i=0;
    while(num[i] != '\0')
    {
        if((num[i]> 47)&&(num[i] < 58))
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


int Verify::numCheck(string& num) // function to check if input is number
{

    int i=0;
    while(num[i] != '\0')
    {
        if((num[i]> 47)&&(num[i] < 58))
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


int Verify::withdrawableCashCeck(float& ammount) // function to verify the type of currency that can be withdrawn
{

    bool flag = false;
    do
    {
        int a;
        a = static_cast<int>(ammount)%1000;
        if(a != 0)
        {
           int b = a % 500;
            if(b != 0)
            {
                int c  = b%200;
                if(c != 0)
                {
                    cout << "INVALID AMMOUNT\n"
                    <<"WITHDRAW IN MULTIPLE OF 1000, 500, 200 ONLY"<<endl;
                    return 0;
                }
                else
                {
                    flag = true;
                    return 1;
                }
            }
            else
            {
                flag = true;
                return 1;
            }
        }
        else
        {
            flag = true;
            return 1;

        }


    }while(flag != true);


}

int Verify::dOfbCheck(int& Day, int& Month, int& Year)  // function to check if the date of birth is correct
{

    bool flag = false;
    int dayFlag =0;
    int monthFlag= 0;
    string month;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    int today = (tm.tm_year+1900);
    int current = (tm.tm_year+1900)-18;
    int remain = 18 -((tm.tm_year+1900)-Year);

    if(Day < 0)
    {
        cout << "NO MONTH HAS A NEGATIVE DAY"<<endl;
        return 0;
    }

    if(Year < 1900 )
    {
        cout <<"CANT ACCEPT THIS AGE, TOO OLD"<<endl;
        return 0;

    }
    if(Year > today)
    {
        cout << "HOW CAN YOU POSSIBLY BE YOUNGER THAN THE CURRENT DATE"<<endl;
        return 0;
    }
    if (Year > current)
    {
        cout << "YOU ARE TOO YOUNG, COME BACK AFTER "<<remain<<" YEAR(s)"<<endl;
        exit(1);
        return 0;
    }

    if(Month == 1)
    {
        month = "JANUARY";
    }
    else if(Month == 2)
    {
        month = "FEBRUARY";
    }
    else if(Month == 3)
    {
        month = "MARCH";
    }
    else if(Month == 4)
    {
        month = "APRIL";
    }
    else if(Month == 5)
    {
        month = "MAY";
    }
    else if(Month == 6)
    {
        month = "JUNE";
    }
    else if(Month == 7)
    {
        month = "JULY";
    }
    else if(Month == 8)
    {
        month = "AUGUST";
    }
    else if(Month == 9)
    {
        month = "SEPTEMBER";
    }
    else if(Month == 10)
    {
        month = "OCTOBER";
    }
    else if(Month == 11)
    {
        month = "NOVEMBER";
    }
    else if(Month == 12)
    {
        month = "DECEMBER";
    }
    else
    {
        cout << "INVALID MONTH, PLEASE CHOOSE BETEWEEN 1-12"<<endl;
    }
    do
    {
        switch(Month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            {
                if((Day>0)&&(Day<32))
                {
                    dayFlag = 1;
                    monthFlag = 1;
                }
                else
                {
                    cout <<month<< " DOES NOT HAVE "<<Day<<" DAY"<<endl;
                    return 0;
                }
                break;
            }
            case 4:case 6: case 9: case 11:
                {
                    if((Day>0)&&(Day<31))
                    {
                        dayFlag = 1;
                        monthFlag = 1;
                    }
                     else
                     {
                        cout <<month<< " DOES NOT HAVE "<<Day<<" DAY"<<endl;
                        return 0;
                     }
                break;
                }
            case 2:
                {
                    if((Day>0)&&(Day<29))
                    {
                        dayFlag =1;
                        monthFlag = 1;
                        return 1;
                    }
                    /*if((Day == 29)&&((Day % 400 == 0)&&(Day % 100 != 0)&&(Day % 4 == 0)))
                        {
                            dayFlag =1;
                            monthFlag = 1;
                            return 1;
                        }
                    else if((Day == 29)&&((Day % 400 != 0)&&(Day % 100 == 0)&&(Day % 4 != 0)))
                        {
                            cout <<"THE DATE CAN'T BE 29, THIS YEAR IS NOT A LEAP YEAR"<<endl;
                            return 0;
                        }*/

                        if(Day == 29)
                        {
                            if(Year % 400 == 0)
                            {
                                dayFlag =1;
                                monthFlag = 1;
                                return 1;
                            }
                            else if(Year % 100 == 0)
                            {
                                cout <<Year<< " IS NOT A LEAP YEAR, DATE CAN'T BE 29"<<endl;
                                return 0;
                            }
                            else if(Year % 4 == 0)
                            {
                                dayFlag =1;
                                monthFlag = 1;
                                return 1;
                            }
                            else
                            {
                                cout <<Year<< " IS NOT A LEAP YEAR, DATE CAN'T BE 29"<<endl;
                                return 0;
                            }

                        }

                    else
                    {
                        cout <<month<< " DOES NOT HAVE "<<Day<< " DAYs"<<endl;
                        return 0;
                    }

                }
        }

    }while((dayFlag !=1)&&(monthFlag != 1));

    if((dayFlag == 1)&& (monthFlag == 1))
    {
        return 1;
    }


}

/*
template<class T>
int Verify::existBefore(string filename, T& item)
{
    fstream file(filename);
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
                return 0;
            }
        }

    }

}
*/

