//Programmer: Mellissa Marie 412002117


#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

//===========================================================================
// The Node class for the Linear ADTs
//===========================================================================

class Node
    {
      private:
            int ClientID;
            string Name;
            string Surname;
            string Destination;
	    string Season;
            string Payment;
            string Booking;
            Node* next;
		 
      public:
            // Constructor function
            Node(int, string, string, string, string, string, string);

            //Accessor functions
            int getClientID(){return ClientID;}
            Node* getNext(){return next;}
            string getRecord();

            //Mutator function
            void setNext(Node* ptr){next = ptr;}
    };

  

  
Node::Node(int idNo, string first, string last, string place, string timeOfYear,
           string payMethod, string bookType)
    {
        ClientID = idNo;
        Name = first;
        Surname = last;
        Destination = place;
	Season = timeOfYear;
        Payment = payMethod;
        Booking = bookType;
        next = NULL;
    }


string Node::getRecord()
    {
        string str = "";
        str.append(to_string(ClientID));
        str.append("\t");
        str.append(Name);
        str.append("\t");
        str.append(Surname);
        str.append("\t");
        str.append(Destination);
        str.append("\t");
        str.append(Season);
        str.append("\t");
        str.append(Payment);
        str.append("\t");
        str.append(Booking);
        str.append("\n");

        return str;
    }




//===========================================================================
// The container (ADT) class for the Queue
//===========================================================================
  
  class Queue
    {
        private:
            Node* head;//points to the head (first node in the ADT)
            Node* tail;//points to the tail (last node in the ADT)
            
        public:
	    //Constuctor function
            Queue() {head = tail = NULL;}
            
            //Accessor functions
            string showHead();
            string showTail();
            string displayQ();
	    
            // Mutator functions
            void enqueue(int, string, string, string, string, string, string);
            string dequeue();
            void purgeQueue(){ head = tail = NULL;}//empties the queue
    };
	
	
string Queue::showHead()//shows the first node in the queue
  {
      if (head == NULL)
	  return ("Queue is EMPTY!");
      else
	  return head->getRecord();
  }
		
		
string Queue::showTail()//shows the last node in the queue
   {
       if (tail == NULL)
	    return ("Queue is EMPTY!");
       else
	    return tail->getRecord();
   } 
	
	
void Queue::enqueue(int idNo, string first, string last, string place, string timeOfYear, string payMethod, string bookType)//add an node to the tail
   {
	// Create the new node with the data and let temp point to it
	Node* temp = new Node(idNo, first, last, place, timeOfYear, payMethod, bookType);

	// Condition 1: Container is empty - make head and tail point to the new node
	if (head == NULL)
	  {
	      head = tail = temp;
	      return;
	  }

	//else the container is NOT empty - add the new node to the end of the queue
	tail->setNext(temp);   
	tail = temp;
	
	return;
  }
		
		
string Queue::dequeue()//delete fist node in queue
    {
        string str = "";

        //Condition 1 : Container is empty
        if (head == NULL)
            return ("Queue is empty...\n");

        //Condition 2: Only ONE node in the container
        if (head == tail)
            {
                str = head->getRecord();
                head = tail = NULL;
                return str;
            }

        // Else container has more than one node, so remove the first node and make the second node the new first
        Node* temp = head;
        str = head->getRecord();
        head = head->getNext();
        
        delete temp;
        return str;
    }	
	
	
string Queue::displayQ()//display all the nodes in the queue
    {
        string str = "";

        if (head == NULL)// Queue is empty
            str = "Queue is empty...\n";
        else//if queue is not empty
            {
                Node* temp = head;

                while (temp != NULL)// Traverse the queue and collect the data
                    {
                        str.append(temp->getRecord());
                        temp = temp->getNext();
                    }
            }

        return str;
    }



#endif
