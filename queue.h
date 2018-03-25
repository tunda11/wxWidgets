#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>

using namespace std;

class queue
{
    private: 
        Node* front;
        Node* back;
        int num_elements;
        
    public:
        queue(){front = NULL; back = NULL;}  //constructor
        
        void enqueue (int, string, string, float); //inserts value at the back of queue
        string dequeue (); //remove from front of queue
        int size(); //return num_elements
        bool isEmpty(); //declares if Queue is empty or not
        string theFront(); //displays value at front of queue
        string dList();//displays list contents of Queue
        string dNames();//
        
};

    bool queue::isEmpty()
    {
        if (front == 0)
        {
            return true;
        }
        return false;
    }
    
    int queue::size()
    {
        return num_elements;
    }
    
    string queue::theFront()
    {
        if (isEmpty())
        {
            throw ("out of range");
        }
        else
        {
            return front->getRecord();
        }
    }
    
    string queue::dList()
    {
       string myRecord = "";
       
       Node* curr = front;
       
       while (curr != NULL)
       {
            myRecord.append(curr->getRecord());
            myRecord.append("\n");
            curr = curr->getNextPtr();
        }
        return myRecord;
    }
    
    string queue::dNames()
{
    string rec = "";
    
    Node* cur = front;
    
    while (cur != NULL)
    {
        rec.append(cur->getName());
        rec.append("\n");
        cur = cur->getNextPtr();
    }
    
    return rec;
}
    
    void queue::enqueue(int num, string f, string l, float sc)
    {
        Node* newPtr = new Node(num, f, l, sc);
        
        if (isEmpty())
        {
            front = back = newPtr;
            return;
        }
        else
        {
            back->setNextPtr(newPtr);
            back = newPtr;
            //newPtr->link=frontPtr;
            //delete newPtr;
        }
      //int num_elements=num_elements + 1;
    }
    
    string queue::dequeue()
    {
       
        //Node* curPtr;
        string str = " ";
        
        if (isEmpty())
        {
            str = "out of range\n";
        }
        else
        {
            str = front->getRecord();
            Node* curPtr = front;
            front = front->getNextPtr();
            delete curPtr;
            
            if (front == NULL)
                back = NULL;
        }
            return str;
      //int num_elements = num_elements - 1;
    }
#endif //QUEUE_H
