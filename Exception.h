#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>


/*
class NegativeNum
  {
  public :
    NegativeNum();
    NegativeNum(int negativeNum);
    int get_negative();// throw (sum);
  private :
    int negative;
  };

  class TooFewNum
  {
    public :
      TooFewNum();
      TooFewNum(int fewNum);
      int get_few();// throw (sum);
  private :
    int few;
  };

  class NumberRange
  {
    public :
      NumberRange();
      NumberRange(int rangeNum);
      int get_range();// throw (sum);
  private :
    int range;
  };


  class IntOnly
  {
    public :
      IntOnly();
      IntOnly(int IntNum);
      int get_Int();// throw (sum);
  private :
    int Int;
  };


  class NumSum
  {
  public :
    NumSum();
    NumSum(int sumNum);
    int get_sum();// throw (sum);
  private :
    int sum;
  };
*/


class Exception
{
public:
    Exception();
    Exception(ostream& out, string error);
    //friend ostream& operator << (ostream& outs, OutOverloaded& amount)

};

Exception::Exception(){}

Exception::Exception(ostream& out, string error)
{
    out << error<<endl;
}

/*
friend ostream& operator << (ostream& outs, Exception& error){
        outs << amount.moneyRemaining;
        return outs;

    }
*/

#endif // EXCEPTION_H
