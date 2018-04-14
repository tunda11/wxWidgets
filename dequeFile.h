 
#ifndef DEQUE_H
#define DEQUE_H


#include <iostream>

using namespace std;


class NodeD
    {
      private:
             int idNo;
            string name;
            string surname;
            string destination;
            string season;
            string booking;
        
            NodeD* nextPtr;
		 
      public:
            // Constructor function
            NodeD(int, string, string, string, string, string);

            //Accessor functions
            int getID(){return idNo;}
            NodeD* getNextPtr(){return nextPtr;}
            string getRecord();
            string getName();

            //Mutator function
            void setNextPtr(NodeD* ptr){nextPtr = ptr;}
    };

  

  
NodeD::NodeD(int number, string firstName, string lastName, string loc, string time, string book)
    {
        idNo    = number;
        name    = firstName;
        surname = lastName;
        destination    = loc;
        season = time;
        booking = book;
        
        nextPtr = NULL;
    }


string NodeD::getRecord()
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
    
string NodeD::getName()
    {
        string nameStr = name;
        nameStr.append(" ");
        nameStr.append(surname);
        
        return nameStr;
    }



class deque
{
    private: 
        NodeD* front;
        NodeD* back;
        int num_elements;
        
    public:
        deque(){front = NULL; back = NULL;}  //constructor
        
        string theFront();    //displays value at front of Queue
        string theTail();    //displays value at back of Queue
        string dList();     //displays list contents of Queue
        string dNames();    //Displays string values only
        
        void inBack (int, string, string, string, string, string); //inserts value at the back of Queue
        void inFront (int, string, string, string, string, string); //inserts value at the back of Queue
        void emptyQueue() {front = back = NULL;}
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
       
       NodeD* cur = front;
       
       while (cur != NULL)
       {
            myRecord.append(cur->getRecord());
            myRecord.append("\n");
            cur = cur->getNextPtr();
        }
        return myRecord;
    }

  /*  string deque::dNames()
{
    string rec = "";
    
    NodeD* cur = front;
    
    while (cur != NULL)
    {
        rec.append(cur->getName());
        rec.append("\n");
        cur = cur->getNextPtr();
    }
    
    return rec;
}*/

    void deque::inBack(int num, string a, string b, string c, string d, string e)
    {
        NodeD* newPtr = new NodeD(num, a, b, c, d, e);
        
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
    
    void deque::inFront(int num, string a, string b, string c, string d, string e)
    {
        NodeD* newPtr = new NodeD(num, a, b, c, d, e);
        
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
            //NodeD* curPtr = top;
        }
    }
    
    string deque::outFront()
    {
       
        //NodeD* curPtr;
        string str = " ";
        
        if (isEmpty())
        {
            str = "out of range\n";
        }
        else
        {
            str = front->getRecord();
            NodeD* curPtr = front;
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
            NodeD* curPtr = front;
            
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
