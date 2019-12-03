#ifndef STACKPTR_H
#define STACKPTR_H
#include "NodePtr.h"
#include <iostream>
//#include "stackException"


template <class T>
class StackPtr
{
    public:
        StackPtr();
        StackPtr(const StackPtr& rhs);
        ~StackPtr();
        StackPtr& operator = (const StackPtr& rhs);
        bool isEmpty()const;
        void push(const T& newItem);
        void pop();
        void topAndPop(T& stackTop);
        void getTop(T& stackTop);




    private:
        StackNode<T>* topPtr;
};

template <class T>
StackPtr<T>::StackPtr(): topPtr(NULL){}

template <class T>
StackPtr<T>::~StackPtr(){
if (! isEmpty()){
    while(!isEmpty())
    pop();
    //std::cout<< "delete should be happening now!!!"<<std::endl;
}
else{
    std::cout << "stack is empty, nothing to clean"<<std::endl;
}
}


template <class T>
bool StackPtr<T>::isEmpty() const
{
    return topPtr == NULL;
}


template <class T>
void StackPtr<T>::push(const T& newItem)
{
    StackNode<T>* newPtr = new StackNode<T>; //create a new node
    newPtr->item = newItem;   // insert data

    newPtr->next =  topPtr;     //link this node to the stack
    topPtr = newPtr;       //update the stack top


}

template <class T>
void StackPtr<T>::pop()
{
    if (isEmpty()){
        //throw Exception("stackException: stack is empty on pop");
        std::cout << "stackException: stack is empty on pop"<<std::endl;
    }
    else{
    StackNode<T>* tmp = topPtr;

    topPtr = topPtr->next;
    delete tmp;
    }


}


template <class T>
void StackPtr<T>::topAndPop(T& stackTop)
{
    if(isEmpty()){
       //throw Exception("stackException: stack is empty on pop");
        std::cout << "stackException: stack is empty on topAndPop"<<std::endl;
    }
    else{
        stackTop = topPtr->item;
        StackNode<T>* tmp = topPtr;

        topPtr = topPtr->next;

        delete tmp;
    }
}


template <class T>
void StackPtr<T>::getTop(T& stackTop)
{
    if(isEmpty()){
      //throw Exception("stackException: stack is empty on pop");
        std::cout << "stackException: stack is empty on getTop"<<std::endl;
    }
    stackTop = topPtr->item;

}

template <class T>
StackPtr<T>&StackPtr<T>::operator=(const StackPtr& rhs)
{
    if (this != &rhs){
        if(!rhs.topPtr){
            topPtr = NULL;
        }else{
            topPtr = new StackNode<T>;
            topPtr->item = rhs.topPtr->item;
            StackNode<T>* q = rhs.topPtr->next;
            StackNode<T>* p = topPtr;
            while(q){
                p->next = new StackNode<T>;
                p->next->item = q->item;
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
        }
    }
}


template <class T>
StackPtr<T>::StackPtr(const StackPtr& rhs)
{
    *this = rhs;
}




#endif // STACKPTR_H
