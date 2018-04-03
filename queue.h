#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node
    {
        private:
            int id;
            std::string fname;
            std::string lname;
            string location;
            string season;
            string book;
        
            Node* nextPtr;
        

        public:
            // Constructor functions
            Node(int, string, string, string, string, string, string);
        
            // Accessor functions;
            int getID() { return id;}               // Inline function
            Node* getNextPtr() { return nextPtr;}   // Inline function
            string getRecord();                     
            
            //Mutator functions
            void setData(int, string, string, string, string, string, string);
            void setNextPtr(Node* ptr) { nextPtr = ptr;}   // Inline function
    };



//===========================================================================
//          Member functions' definition
//===========================================================================

Node::Node()
    {
        id = 0;
        string fname = " ";
        string lname = " ";
        string location = " ";
        string season = " ";
        string book = " ";
        nextPtr = NULL;
    }




Node::Node(int number, string firstName, string lastName, string destination, string season, string bookings)
    {
        id = number;
        fname = firstName;
        lname = lastName;
        location = destination;
        season = season;
        book = bookings;
        
        nextPtr = NULL;
    }

string Node::getRecord()
    {
        string str = "";
        str.append(to_string(id));
        str.append("\t");
        str.append(fname);
        str.append("\t");
        str.append(lname);
        str.append("\t");
        str.append(location);
        str.append("\t");
        str.append(season);
        str.append("\t");
        str.append(book);
        str.append("\n");

        return str;
    }
    


class queue
{
    private: 
        Node* front;
        Node* back;
        int num_elements;
        
    public:
        queue(){front = NULL; back = NULL;}  //constructor
        
        //Accessor functions 
        string theFront();
        string theBack();
        string myQ();
        
        //Mutator Functions
        void emptyQueue();
        void enqueue (int, string, string, string, string, string, string); //inserts value at the back of queue
        string dequeue (); //remove from front of queue
        int size(); //return num_elements
        bool isEmpty(); //declares if Queue is empty or not
        string dList();//displays list contents of Queue
        string dNames();//
        
};

    void emptyQueue()
    {
        head = tail = NULL;
    }

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
    
    string theBack()
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
    
  /*  string queue::dList()
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
    }*/
    
  /*  string queue::dNames()
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
}*/
    
    void queue::enqueue(int number, string firstName, string lastName, string destination, string season, string bookings)
    {
        Node* newPtr = new Node(number, firstName, lastName, destination, season, bookings);
        
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
            return;
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
            
        }
            return str;
      //int num_elements = num_elements - 1;
    }
#endif //QUEUE_H
