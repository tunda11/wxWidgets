 
#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"
#include <iostream>

using namespace std;

class deque
{
    private: 
        Node* front;
        Node* back;
        int num_elements;
        
    public:
        deque(){front = NULL; back = NULL;}  //constructor
        
        string theFront();    //displays value at front of Queue
        string theTail();    //displays value at back of Queue
        string dList();     //displays list contents of Queue
        string dNames();    //Displays string values only
        
        void inBack (int, string, string, float); //inserts value at the back of Queue
        void inFront (int, string, string, float); //inserts value at the back of Queue
        string outBack ();      //remove from top of Queue
        string outFront ();      //remove from top of Queue
        int size();         //return num_elements
        bool isEmpty();     //declares if Stack is empty or not

        
};

    bool deque::isEmpty()
    {
        if (front == 0)
        {
            return true;
        }
        return false;
    }
    
    int deque::size()
    {
        return num_elements;
    }
    
    string deque::theFront()
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
    
    string deque::theTail()
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
    
    string deque::dList()
    {
       string myRecord = "";
       
       Node* cur = front;
       
       while (cur != NULL)
       {
            myRecord.append(cur->getRecord());
            myRecord.append("\n");
            cur = cur->getNextPtr();
        }
        return myRecord;
    }
    
    string deque::dNames()
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

    void deque::inBack(int num, string f, string l, float sc)
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
    
    void deque::inFront(int n, string f, string l, float sc)
    {
        Node* newPtr = new Node(n, f, l, sc);
        
        if (isEmpty())
        {
            back = front = newPtr;
            return;
        }
        else
        {
            
            newPtr->setNextPtr(front);
            front = newPtr;
            return;
            //Node* curPtr = top;
        }
    }
    
    string deque::outFront()
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
    
    string deque::outBack()
    {
       
        string str = " ";
     
        if (isEmpty())
        {
            return str = "out of range\n";
        }
        else
        {
            str = back->getRecord();
            Node* curPtr = front;
            
            while (curPtr->getNextPtr() != back)
            curPtr = curPtr->getNextPtr();
           
            delete back;
            
            back = curPtr;
            curPtr->setNextPtr(NULL);
        }   
            
            return str;
      //int num_elements = num_elements - 1;
    }
#endif //DEQUE_H
