//
//  Node.h
//  Lab01
//
//  Created by The Charlerys on 08/02/2018.
//  Copyright © 2018 University of the West Indies. All rights reserved.
//

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

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
            // Constructor functions
            Node();
            Node(int, string, string, string, string, string);
        
            // Accessor functions;
            string getName();
            string getRecord();                     // You need to write that function!
            int getID() { return idNo;}             // Inline function
            //float getGPA() { return gpa; }          // Inline function
            Node* getNextPtr() { return nextPtr;}   // Inline function
        
            //Mutator functions
            void setData(int, string, string, string, string, string);
            //void setGPA(float score) { gpa = score;}       // Inline function
            void setNextPtr(Node* ptr) { nextPtr = ptr;}   // Inline function
    };



//===========================================================================
//          Member functions' definition
//===========================================================================

Node::Node()
    {
        idNo = 0;
        name = "";
        surname = "";
        destination = "";
        season = "";
        booking = "";
        nextPtr = NULL;
    }




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




string Node::getName()
    {
        string nameStr = name;
        nameStr.append(" ");
        nameStr.append(surname);
        
        return nameStr;
    }




string Node::getRecord()
{
    string recStr = "";

    cout << idNo << " " << name << " " << surname << " " << destination << " " << season << " " << booking << "\n"; //"YOU need to write that function which appends all the fields to recStr\n";
    
    /***** Enter the code here ****/
    stringstream myRecord;
    string myRecStr = myRecord.str();
    recStr.append(myRecStr);
    
    return recStr;
}




void Node::setData(int number, string firstName, string lastName, string loc, string time, string book)
    {
        idNo    = number;
        name    = firstName;
        surname = lastName;
         destination    = loc;
        season = time;
        booking = book;
    }

#endif // NODE_H
 
