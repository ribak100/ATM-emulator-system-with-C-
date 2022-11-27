#include "StackPtr.h"
#include "NodePtr.h"
#include <iostream>
//#define NDEBUG
//#include <cassert>

using namespace std;

int main()
{
    int x;

    StackPtr<int> myStack;


    myStack.push(5);
    myStack.push(3);

    StackPtr<int> myStack2 = myStack;

    myStack.getTop(x);
    cout <<"before first pop x = "<<x<<endl;
    myStack.getTop(x);
    myStack.pop();
    cout<<"after first pop x = " <<x<<endl;
    myStack.topAndPop(x);
    cout<<"after last pop x = " << x<<endl;
    //cout << myStack.isEmpty()<<endl;



    cout << "printing second stack"<<endl;
    while (! myStack2.isEmpty()){
        int x;
        myStack2.topAndPop(x);
        cout << x<<endl;
    }







    return 0;
}
