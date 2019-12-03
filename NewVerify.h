#ifndef NEWVERIFY_H
#define NEWVERIFY_H
#include <iostream>
#include <string>

using std::string;
class NewVerify
{
    public:
        NewVerify();
        int acctNumVerifystr(string& number); // function to verify phone number
        int ifNumber(int& n);
        int turnToInt(int& n);
        void read_and_clean(int& n);
        int ledgerBalanceCheck(string& accountnumber, float& amount);
};

#endif // NEWVERIFY_H




    /** TO KNOW IF THEY HAVE CARD FROM THE BEGINING*/
    /*if(myvery.existBeforeCardInfo(account_number))
    {
        goto start;
    }
    else
    {
        cout <<"YOUR ACCOUNT DOES NOT HAVE AN EXISTING CARD, REGIESTER FOR AN ATM CARD AT OUR NEAREST BRANCH"<<endl;
        cout <<"**THANK YOU FOR BANKING WITH US**"<<endl;
        goto another;

    }
    */
