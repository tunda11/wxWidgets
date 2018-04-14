#ifndef STACK_H
#define STACK_H


#include <iostream>

using namespace std;

/*


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

    */
    
class stack
{
    private: 
        Node* top;
        Node* bottom;
        int num_elements;
        
    public:
        stack(){top = NULL; bottom = NULL;}  //constructor
        
        void push (int, string, string, string, string, string); //inserts value at the back of Stack
        void emptyStack() {top = bottom = NULL;}//emptys the Stack
        string pop ();      //remove from top of Stack
        int size();         //return num_elements
        bool isEmpty();     //declares if Stack is empty or not
        string theTop();    //displays value at front of Stack
        string dList();     //displays list contents of Stack
        string dNames();    //Displays string values only
        
};

    bool stack::isEmpty()
    {
        if (top == 0)
        {
            return true;
        }
        return false;
    }
    
    int stack::size()
    {
        return num_elements;
    }
    
    string stack::theTop()
    {
        if (isEmpty())
        {
            throw ("out of range");
        }
        else
        {
            return top->getRecord();
        }
    }
    
    string stack::dList()
    {
       string myRecord = "";
       
       Node* cur = top;
       
       while (cur != NULL)
       {
            myRecord.append(cur->getRecord());
            myRecord.append("\n");
            cur = cur->getNextPtr();
        }
        return myRecord;
    }
    
  /*  string stack::dNames()
{
    string rec = "";
    
    Node* cur = top;
    
    while (cur != NULL)
    {
        rec.append(cur->getName());
        rec.append("\n");
        cur = cur->getNextPtr();
    }
    
    return rec;
}*/
    
    void stack::push(int num, string a, string b, string c, string d, string e)
    {
        Node* newPtr = new Node(num, a, b, c, d, e);
        
        if (isEmpty())
        {
            bottom = top = newPtr;
            return;
        }
        else
        {
            
            newPtr->setNextPtr(top);
            top = newPtr;
            return;
            //Node* curPtr = top;
        }
    }
    
    string stack::pop()
    {
       
        string str = " ";
        
        if (isEmpty())
        {
            str = "out of range\n";
        }
        else
        {
            str = top->getRecord();
            Node* curPtr = top;
            top = top->getNextPtr();
            delete curPtr;
        }   
            //if (top == NULL)
            //    bottom = NULL; 
        
            return str;
      //int num_elements = num_elements - 1;
    }
#endif //STACK_H
 
