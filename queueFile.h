 
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <iostream>

using namespace std;

class Node
    {
      private:
             int idNo;
            string name;
            string surname;
            string destination;
            string season;
            string booking;
        
            Node* nextPtr;
		 
      public:
            // Constructor function
            Node(int, string, string, string, string, string);

            //Accessor functions
            int getID(){return idNo;}
            Node* getNextPtr(){return nextPtr;}
            string getRecord();

            //Mutator function
            void setNextPtr(Node* ptr){nextPtr = ptr;}
    };

  

  
Node::Node(int number, string firstName, string lastName, string loc, string time, string book)
    {
        idNo    = number;
        name    = firstName;
        surname = lastName;
        destination    = loc;
        season = time;
        booking = book;
        
        nextPtr = NULL;
    }


string Node::getRecord()
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

// The container (ADT) class for the Queue
//===========================================================================
  



class queue
{
    private: 
        Node* front;
        Node* back;
        int num_elements;
        
    public:
        queue(){front = NULL; back = NULL; num_elements = 0;}  //constructor
        
        void enqueue (int, string, string, string, string, string); //inserts value at the back of queue
        void emptyQueue() {front = back = NULL;}
        string dequeue(); //remove from front of queue
        int size(); //return num_elements
        bool isEmpty(); //declares if Queue is empty or not
        string theFront(); //displays value at front of queue
        string theBack();
        string dList();//displays list contents of Queue
        string dNames();//
        string displayQ();
        
};

    bool queue::isEmpty()
    {
        if (front == NULL)
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
        if (front == NULL)
        {
            throw ("out of range");
        }
        else
        {
            return front -> getRecord();
        }
    }
    
    string queue::theBack()
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
    
    string queue::displayQ()//display all the nodes in the queue
    {
        string str = "";

        if (front == NULL)// Queue is empty
            str = "Queue is empty...\n";
        else//if queue is not empty
            {
                Node* temp = front;

                while (temp != NULL)// Traverse the queue and collect the data
                    {
                        str.append(temp->getRecord());
                        temp = temp->getNextPtr();
                    }
            }

        return str;
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
    
 /*   string queue::dNames()
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
    
    void queue::enqueue(int num, string a, string b, string c, string d, string e)
    {
        Node* temp = new Node(num, a, b, c, d, e);
        
     /*   if (isEmpty())
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
      //int num_elements=num_elements + 1;*/
      
      	// Condition 1: Container is empty - make head and tail point to the new node
	if (front == NULL)
	  {
	      front = back = temp;
	      return;
	  }

	//else the container is NOT empty - add the new node to the end of the queue
	back->setNextPtr(temp);   
	back = temp;
	
    }
    
    
    
    string queue::dequeue()
    {
       string str = "";

        //Condition 1 : Container is empty
        if (front == NULL)
            return ("Queue is empty...\n");

        //Condition 2: Only ONE node in the container
        if (front == back)
            {
                str = front->getRecord();
                front = back = NULL;
                return str;
            }

        // Else container has more than one node, so remove the first node and make the second node the new first
        Node* temp = front;
        str = front->getRecord();
        front = front->getNextPtr();
        
        delete temp;
        return str;
        /*
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
             return str;
           // if (front == NULL)
             //   back = NULL;
             
             
        }
           
      //int num_elements = num_elements - 1;*/
    }
#endif //QUEUE_H
