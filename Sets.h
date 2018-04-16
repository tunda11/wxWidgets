//
//  Set.h
//  Set
//
//  Created by Dr. John Charlery on 11/2/16.
//  Copyright (c) 2016 University of the West Indies. All rights reserved.
//

#ifndef SET_H
#define SET_H
#include <vector>
#include <iostream>

using namespace std;

//****************************************************************************************
//                      Binary Search Tree Node Class Creation
//****************************************************************************************
class SetNode
    {
        private:
            int IdNo;
            string Fname;
            string Lname;
            string Destination;
            string Season;
            string Booking;
    
        public:
            
            SetNode(int, string, string, string, string, string);//{data = id; right = left = NULL;}
    
            // Mutator functions
            void setData(int, string, string, string, string, string);//{data = val;}
            void setData(SetNode*);
            
            
            // Accessor functions
            string getData();//{return data;}
            int getID(){return IdNo;}
            string getBook(){return Booking;}
     };

//Constructor
SetNode::SetNode(int num, string firstName, string lastName, string loc, string time, string book)
    {
        IdNo = num;
        Fname = firstName;
        Lname = lastName;
        Destination = loc;
        Season = time;
        Booking = book;
    }

void SetNode::setData(int num, string firstName, string lastName, string loc, string time, string book)
    {
        IdNo = num;
        Fname = firstName;
        Lname = lastName;
        Destination = loc;
        Season = time;
        Booking = book;
    }
    
void SetNode::setData(SetNode* nodePtr)
    {
        IdNo    = nodePtr->IdNo;
        Fname   = nodePtr->Fname;
        Lname     = nodePtr->Lname;
        Destination = nodePtr->Destination;
        Season      = nodePtr->Season;
        Booking     = nodePtr->Booking;
    }

    
    
//Accessor
string SetNode::getData()
    { 
        string str = "";
        str.append(to_string(IdNo));
        str.append("\t");
        str.append(Fname);
        str.append("\t");
        str.append(Lname);
        str.append("\t");
        str.append(Destination);
        str.append("\t");
        str.append(Season);
        str.append("\t");
        str.append(Booking);
        str.append("\n");
        
        return str;
    }
    
//***************************************************************************************
//                    END... Member Functions for Set Node
//***************************************************************************************

//***************************************************************************************
//                    END... Set Node Class
//***************************************************************************************
class Set
   {
		private:
    	    vector <SetNode> elements;

		public:
            Set ();// Create an empty set   
	      Set (SetNode s);

            int getNumElements () {return elements.size();}
            bool find (int);
            string displaySet();
            string getSetBook(int x){return elements[x].getBook();}
            string getOne(int x){return elements[x].getData();}
            
            void show()const;
            void unionSet(Set*, Set*);          // Union of 2 sets
            void intersectionSet(Set*, Set*);   // Intersection of 2 sets
            bool isSubset (Set*);
            bool isDisjoint (Set*);
           
           string add (int, string, string, string, string, string );
           string remove (int );
           void purgeSet() { elements.clear();}
   };


Set::Set ()
{    
  elements.clear();
	  
} 
	
	

Set::Set (SetNode s) 
{    
  elements.clear();    
  elements.push_back (s);
} 



bool Set::find (int IdNo) 
    {
 	 	for (int i = 0; i < elements.size(); i++)
            {
                if (elements[i].getID() == IdNo)
                    return true;
            }
	  	return false;
   }





string Set::add (int num, string firstName, string lastName, string loc, string time, string book)
   {
        string result = "";

        // Check if the element is already in the set
        bool found = find (num);

        if (found)      //elem is in the set already
            result.append("Data already in the set...");

        else     //elem is Not found in set
            {               // add the new elements
                SetNode* e = new SetNode(num, firstName, lastName, loc, time, book);
                elements.push_back(*e);
                result.append("New element added..");
            }
        return result;
  }


string Set::remove (int IdNo)
    {
    string str = " Invalid ID";
    int x;
    // search for IdNo
    for (x = 0; x < elements.size() && elements[x].getID() != IdNo; x++);

    // was it found?
    if ( x == elements.size()) 		//Didn’t find it!
    return str; 
    else          // found it at subscript x; slide the other elements to the left
        
        str = elements[x].getData();
    for (int y = x; y < elements.size(); y++)
    {
        elements[y] = elements[y+1];
    }
    SetNode* s = new SetNode(0, " "," "," "," "," ");
    elements.resize( elements.size() -1, *s);
    return str; 
    } 


void Set::unionSet(Set* setA,  Set* setB)
    {
        int y;
        
        elements.clear();
        
        //	Copy contents of setA to the union-set
        elements = setA->elements;
        y = setA->elements.size();
        
        //	Copy contents of setB which are missing from setA to the union-set
        for (int x = 0; x < setB->elements.size(); x++)
            {
                if (!find(setB->elements[x].getID()) )
                    {
                        elements.push_back(setB->elements[x]);
                        y++;
                    }
            }
    }




void Set::intersectionSet(Set* setA,  Set* setB)
    {string str= "";
        for (int x = 0;  x  <  setA->elements.size();  x++)
        {
            for (int y = 0;  y  < setB->elements.size();  y++)
            {
                if ( setA->elements[x].getID() == setB->elements[y].getID() )//for each element in set A compare its client id to every element in set B until a match is found
                {
                    if(setA->getSetBook(x) == strip("Internet"))//if the booking of set A is "Internet" add the element to the intersection set
                    {
                    elements.push_back ( setA->elements[x] );
                    str.append("\n");
                }
                    else if(setB->getSetBook(y) == strip("Internet"))//if the booking of  set B is internet add the element to the intersection set 
                    {
                    elements.push_back(setB->elements[y]);
                    str.append("\n");
                    }
                }
            }
        }
    }




string Set::displaySet()
    {
        string str = "";
        if (getNumElements ()== 0)// Set is empty
            str = "Set is empty...\n";
        else
        {
           for (int x = 0; x < elements.size(); x++)
                    {
                        str.append(elements[x].getData());
                    }
        }

        return str;
    }



/*bool Set::isSubset(Set* SetA)
    {
 	 	for (int x = 0; x < elements.size(); x++)
            {
                if ( !SetA->find(elements[x]) )
                    return false;
            }
	  	return true;
    }


bool Set::isDisjoint(Set* SetA)
    {
 	 	for (int x = 0; x < elements.size(); x++)
            {
                if ( SetA->find(elements[x]) )
                    return false;
            }
	  	return true;
    }

*/

#endif
