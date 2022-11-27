#ifndef QUEUEPTR_H
#define QUEUEPTR_H
#include <iostream>
#include "QueueNode.h"

using namespace std;

template <class T>
class QueuePtr
{
    public:
        QueuePtr();
        ~QueuePtr();
        bool isEmpty();
        void enqueue(const T& newItem);
        void dequeue();
        void dequeue(T& queueFront);
        void getFront(T& queueFront);
        QueuePtr(const QueuePtr<T>& rhs);
        QueuePtr<T>& operator = (const QueuePtr<T>& rhs);


    private:
        QueueNode<T>* backPtr;
        QueueNode<T>* frontPtr;
        QueueNode<T>* copyList(const QueueNode<T>* ptr);
};




template <class T>
QueuePtr<T>::QueuePtr() : frontPtr(NULL), backPtr(NULL){}


template <class T>
QueuePtr<T>::~QueuePtr()
{
    /*if(isEmpty()){
        cout << "QueueException: queue is empty, nothing to delete"<<endl;
    }
    else{
        */
        // i dont like the message its displaying all the time i run tbe code
        // the message goes:QueueException: queue is empty, nothing to delete
        //you can remove the multi line comment to check
        // i didn't delete it because it might be useful at some point
        while(! isEmpty()){
            dequeue();
        }
    //}
}



template <class T>
bool QueuePtr<T>::isEmpty()
{

 return backPtr == NULL;
}

template <class T>
void QueuePtr<T>::enqueue(const T& newItem)
{
    QueueNode<T>* newPtr = new QueueNode<T>;
    newPtr->item = newItem;
    newPtr->next = NULL;

    if (isEmpty()){
        frontPtr  = newPtr;
    }
    else{
        backPtr->next = newPtr;
    }

    backPtr = newPtr;
}

template <class T>
 void QueuePtr<T>::dequeue()
 {
     if (isEmpty()){
        cout << "QueueException: queue is empty on dequeue"<<endl;
     }
     else{
        QueueNode<T>* tmp = frontPtr;

        if (frontPtr == backPtr){
            frontPtr = NULL;
            backPtr = NULL;
        }
        else{
        frontPtr = frontPtr->next;
        }
        tmp->next = NULL;
        delete tmp;

     }

 }


template <class T>
void QueuePtr<T>::dequeue(T& queueFront)
{
    if(isEmpty()){
        cout<< "QueueException: queue is empty on dequeue"<<endl;
    }
    else{
        QueueNode<T>* tmp = frontPtr;
        queueFront = frontPtr->item;

        if(frontPtr == backPtr){
            frontPtr = NULL;
            backPtr = NULL;
        }
        else{
            frontPtr = frontPtr->next;
        }
       tmp->next = NULL;
        delete tmp;

        /*
        //alternatively using our dequeue function
        queueFront = frontPtr->item;
        dequeue();
        */
    }

}

template <class T>
void QueuePtr<T>::getFront(T& queueFront)
{
    if(isEmpty()){
        cout << "QueueException: queue is empty on getFront"<<endl;
    }
    else{

        queueFront = frontPtr->item;
    }

}


template <class T>
QueueNode<T>* QueuePtr<T>::copyList(const QueueNode<T>* ptr)//private member function to recursively copy the linked list
{
    if(ptr == NULL){
        return NULL;
    }
    else{
        QueueNode<T>* copyFront = new QueueNode<T>;
        copyFront->item = ptr->item;
        copyFront->next = copyList(ptr->next);
        return copyFront;
    }


}

template <class T>
QueuePtr<T>::QueuePtr(const QueuePtr<T>& rhs)
{
    frontPtr = copyList(rhs.frontPtr);
    backPtr = frontPtr;
    while(backPtr != NULL && backPtr->next != NULL){
        backPtr = backPtr->next;
    }

}


template <class T>
QueuePtr<T>& QueuePtr<T>::operator = (const QueuePtr<T>& rhs)
{
    if (this != &rhs){
        while(! isEmpty()){
            dequeue();
        }
        frontPtr = copyList(rhs.frontPtr);
        backPtr = frontPtr;
        while (backPtr != NULL && backPtr->next != NULL){
            backPtr = backPtr->next;
        }
    }
    return *this;
}










#endif // QUEUEPTR_H
