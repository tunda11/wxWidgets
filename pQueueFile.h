#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;


class NodePQ
    {
      private:
             int idNo;
            string name;
            string surname;
            string destination;
            string season;
            string booking;
        
            NodePQ* nextPtr;
		 
      public:
            // Constructor function
            NodePQ(int, string, string, string, string, string);

            //Accessor functions
            int getID(){return idNo;}
            NodePQ* getNextPtr(){return nextPtr;}
            string getRecord();
            string getName();

            //Mutator function
            void setNextPtr(NodePQ* ptr){nextPtr = ptr;}
    };

  

  
NodePQ::NodePQ(int number, string firstName, string lastName, string loc, string time, string book)
    {
        idNo    = number;
        name    = firstName;
        surname = lastName;
        destination    = loc;
        season = time;
        booking = book;
        
        nextPtr = NULL;
    }


string NodePQ::getRecord()
    {
        string str = "";
        str.append(to_string(idNo));
        str.append("\t");
        str.append(name);
        str.append("\t");
        str.append(surname);
        str.append("\t");
        str.append(destination);
        str.append("\t");
        str.append(season);
        str.append("\t");
        str.append(booking);
        str.append("\n");

        return str;
    }
    

string NodePQ::getName()
    {
        string nameStr = name;
        nameStr.append(" ");
        nameStr.append(surname);
        
        return nameStr;
    }



class pQueue
{
    private: 
        NodePQ* front;
        NodePQ* back;
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
       
       NodePQ* curr = front;
       
       while (curr != NULL)
       {
            myRecord.append(curr->getRecord());
            myRecord.append("\n");
            curr = curr->getNextPtr();
        }
        return myRecord;
    }
    
   /* string pQueue::dNames()
{
    string rec = "";
    
    NodePQ* cur = front;
    
    while (cur != NULL)
    {
        rec.append(cur->getName());
        rec.append("\n");
        cur = cur->getNextPtr();
    }
    
    return rec;
}*/
    
    void pQueue::enqueue(int num, string a, string b, string c, string d, string e)
    {
        NodePQ* newPtr = new NodePQ(num, a, b, c, d, e);
        
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
        
        
        NodePQ* tmpPtr = front;
        NodePQ* curPtr = front->getNextPtr();
        
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
            NodePQ* curPtr = front;
            front = front->getNextPtr();
            delete curPtr;
        }
            return str;
      //int num_elements = num_elements - 1;
    }
#endif //PQUEUE_H
