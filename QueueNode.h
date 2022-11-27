#ifndef QUEUENODE_H
#define QUEUENODE_H

template <class T>
class QueueNode
{
    public:
    QueueNode(const T& e = T(), QueueNode* n = NULL)
    : item(e), next(n){}

    T item;
    QueueNode* next;

};

#endif // QUEUENODE_H
