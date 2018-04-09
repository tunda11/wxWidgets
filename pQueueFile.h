#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>
#include <string.h>
#include "NodeFile.h"

using namespace std;

class pQueue
{
    private: 
        Node* front;
        Node* back;
        int num_elements;
        
    public:
        pQueue(){front = NULL; back = NULL;}  //constructor
        
        string theFront();      //displays value at front of Queue
        string theBack();       //displays value at back of Queue
        string dList();         //displays list contents of Queue
        string dNames();        //displays the "string" values of the Queue
        
        void enqueue (int, string, string, string, string, string); //inserts value at the back of Queue
        void emptyQueue() {front = back = NULL;}
        string dequeue (); //remove from front of Queue
        int size(); //return num_elements
        bool isEmpty(); //declares if Queue is empty or not
        
        
};

    bool pQueue::isEmpty()
    {
        if (front == 0)
        {
            return true;
        }
        return false;
    }
    
    int pQueue::size()
    {
        return num_elements;
    }
    
    string pQueue::theFront()
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
    
    string pQueue::theBack()
    {
        if (isEmpty())
        {
            throw ("out of range");
        }
        else
        {
            return back->getRecord();
        }
    }
    string pQueue::dList()
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
    
    string pQueue::dNames()
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
    
    void pQueue::enqueue(int num, string a, string b, string c, string d, string e)
    {
        Node* newPtr = new Node(num, a, b, c, d, e);
        
        if (isEmpty())
        {
            front = back = newPtr;
            return;
        }
        
        if( a < front->getName())
        {
            newPtr->setNextPtr(front);
            front = newPtr;
            return;
            //back->setNextPtr(newPtr);
            //back = newPtr;
        }
        
        
        Node* tmpPtr = front;
        Node* curPtr = front->getNextPtr();
        
        while ( (curPtr != NULL) && (curPtr->getName() < a) )
        {
            tmpPtr = curPtr;
            curPtr = curPtr->getNextPtr();
        }
        
        if (curPtr == NULL)
            tmpPtr->setNextPtr(newPtr);
        else
        {
            newPtr->setNextPtr(curPtr);
            tmpPtr->setNextPtr(newPtr);
        }
        
      //int num_elements=num_elements + 1;
    }
    
    string pQueue::dequeue()
    {
       
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
        }
            return str;
      //int num_elements = num_elements - 1;
    }
#endif //PQUEUE_H
