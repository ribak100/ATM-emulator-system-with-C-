
#include "Decoration.h"
#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<direct.h>
#include<process.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>

Decoration::Decoration()
{
    //ctor
}

void Decoration::date1()    // to get current date
{
    time_t T= time(NULL);
    struct tm tm= *localtime(&T);
    cout <<"\n\n\n\n";
    cout <<"\t\t\t\t\t\t\t\t  DATE : "<<tm.tm_mday<<"/"<<tm.tm_mon<<"/"<<tm.tm_year+1900<<endl;
    cout <<"\t\t\t\t\t\t\t\t  TIME : "<<tm.tm_hour<<":"<<tm.tm_min<<endl;


}

void Decoration::delay()     // function for loading effect
{
    Sleep(200);
}

void Decoration::callExit()  // function to exit the program
{
    int process = 0;
  system("cls");
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\tTaking You Out of The System";
  for(process=0;process<25;process++)
    {
      delay();
      cout <<".";
    }
  system("cls");
  cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout <<"\t\t\t\t\t\t\t\t\t\t";
  cout <<"You are out of the System.\n";
  cout <<"\t\t\t\t\t\t\t\t\t\t";
  cout << "Thank You !";
  cout <<"\n\n";
  cout <<"\t\t\t\t\t\t\t\t\t\t";
  system("pause");
  exit(0);

}

void Decoration::slowDemDown() //function to display a please wait animation
{
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
    system("pause");
    system("cls");
  cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading";
  int process = 0;
  for(process=0;process<25;process++)
  {
    delay();
    cout <<".";

  }

system("cls");
}


