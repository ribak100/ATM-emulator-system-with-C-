#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <string>
using namespace std;
//structure for names
struct nameInfo
{
    string surname;
    string firstName;
    string lastName;
    string fatherName;
    string motherName;
    string nextOfKIn;
};

//structure for date

struct date
{
    int day;
    int month;
    int year;
};

#endif // STRUCTURES_H
