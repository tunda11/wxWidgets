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
#include <stdio.h>
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
            //void setData(int, string, string, string, string, string, string);
            void setNextPtr(Node* ptr) { nextPtr = ptr;}   // Inline function
    };



//===========================================================================
//          Member functions' definition
//===========================================================================

/*Node::Node()
    {
        id = 0;
        string fname = " ";
        string lname = " ";
        string location = " ";
        string season = " ";
        string book = " ";
        nextPtr = NULL;
    }
*/



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
    
/*string Node::getRecord()
{
    string recStr = "";

    cout << id << " " << fname << " " << lname << " " << location << " " << season << " " << book << "\n"; //"YOU need to write that function which appends all the fields to recStr\n";
    
    /***** Enter the code here ****
    stringstream myRecord;
    string myRecStr = myRecord.str();
    recStr.append(myRecStr);
    
    return recStr;
}
*/



/*void Node::setData(int number, string firstName, string lastName, string, string, string)
    {
        id    = number;
        fname    = firstName;
        lname = lastName;
        location    = destination;
        season  = season;
        book = bookings;
    }*/

#endif // NODE_H
 
