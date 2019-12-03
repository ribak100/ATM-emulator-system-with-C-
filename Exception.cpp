/*
#include "Exception.h"
#include <iostream>

using namespace std;




NegativeNum::NegativeNum(){}
NegativeNum::NegativeNum(int negativeNum) :negative(negativeNum){}
NegativeNum::get_negative()
{
    return negative;
}



TooFewNum::TooFewNum(){}
TooFewNum::TooFewNum(int fewNum) : few(fewNum){}
TooFewNum::get_few()
{
    return few;
}

NumberRange::NumberRange(){}
NumberRange::NumberRange(int rangeNum) : range(rangeNum){}
NumberRange::get_range()
{
    return range;
}

IntOnly::IntOnly(){}
IntOnly::IntOnly(int IntNum) : Int(IntNum){}
IntOnly::get_Int()
{
    return Int;
}

NumSum::NumSum(){}
NumSum::NumSum(int sumNum): sum(sumNum){}
NumSum::get_sum()
{
    return sum;
}


        catch(NegativeNum neg)
        {
            cout << neg.get_negative()<<" is not a positive numbers, only positive numbers are allowed"<<endl;
        }

        catch(TooFewNum few)
        {
            cout << few.get_few()<<" is too small ,the least allowed is 10 "<<endl;
        }

        catch(NumberRange rang)
        {
            cout << rang.get_range()<<" is not allowed , you can only enter numbers in range 0-9"<<endl;
        }

        catch(IntOnly Int)
        {
            cout << Int.get_Int()<<" can only be an integer"<<endl;
        }

        catch(NumSum sum)
        {
            cout <<"sum can only be greater than "<<sum.get_sum()<<" to be allowed"<<endl;
        }
*/
