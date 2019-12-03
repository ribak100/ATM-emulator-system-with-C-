
#ifndef DECORATION_H
#define DECORATION_H
#include "structures.h"


class Decoration
{
private:
    date DATE;

public:
    Decoration();
    void date1();     // to get current date
    void delay();     // function for loading effect
    void callExit();  // function to exit the program
    void slowDemDown(); //function to display a please wait animation


};

#endif // DECORATION_H


