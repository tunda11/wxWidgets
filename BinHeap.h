//
//  BinHeap.h
//  BinHeap
//
//  Created by Dr. John Charlery on 11/30/15.
//  Copyright (c) 2015 University of the West Indies. All rights reserved.
//
// Edited by: Alec Gilkes 415002420

#ifndef BINHEAP_H
#define BINHEAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//****************************************************************************************
//                           BINARY HEAP Node Creation
//****************************************************************************************
class BinHeapNode
    {
        private:
            int IdNo;
            string Fname;
            string Lname;
            string Destination;
            string Season;
            string Booking;
    
        public:
            // Constructor functions
            BinHeapNode(int, string, string, string, string, string);//{data = id; right = left = NULL;}
    
            // Mutator functions
            void setData(int, string, string, string, string, string);//{data = val;}
            void setData(BinHeapNode*);
            
            
            // Accessor functions
            string getDataBH();//{return data;}
            int getID(){return IdNo;}
     };

//Constructor
BinHeapNode::BinHeapNode(int num, string firstName, string lastName, string loc, string time, string book)
    {
        IdNo = num;
        Fname = firstName;
        Lname = lastName;
        Destination = loc;
        Season = time;
        Booking = book;
    }

void BinHeapNode::setData(int num, string firstName, string lastName, string loc, string time, string book)
    {
        IdNo = num;
        Fname = firstName;
        Lname = lastName;
        Destination = loc;
        Season = time;
        Booking = book;
    }
    
void BinHeapNode::setData(BinHeapNode* nodePtr)
    {
        IdNo    = nodePtr->IdNo;
        Fname   = nodePtr->Fname;
        Lname     = nodePtr->Lname;
        Destination = nodePtr->Destination;
        Season      = nodePtr->Season;
        Booking     = nodePtr->Booking;
    }

    
    
//Accessor
string BinHeapNode::getDataBH()
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
//                                   END OF NODE CLASS
//***************************************************************************************
    
    
//***************************************************************************************
//                          BINARY HEAP CLASS
//***************************************************************************************

class BinHeap
    {
        private:
                vector <BinHeapNode> elements;
        
        public:
                BinHeap();//{elements.resize(1);}
                    
                void addMinHeap(int num, string firstName, string lastName, string loc, string time, string book);               // Add to MinHeap
                void minHeapify(unsigned int);      // Heapify MinHeap
                string deleteMinHeapVal(int);         // Delete element from MinHeap
                void removeMinRoot();
                string displayHeap();
                string sortMinHeap();
                void purgeBH() {elements.clear();}
    };


BinHeap::BinHeap()
{
  BinHeapNode* b = new BinHeapNode(0, " "," "," "," "," ");
  elements.resize(1, *b);
}


//===================================================================================
// Add new element to MinHeap
//===================================================================================
void BinHeap::addMinHeap(int num, string firstName, string lastName, string loc, string time, string book)    
    {
        BinHeapNode* b = new BinHeapNode(num, firstName, lastName, loc, time, book);
        elements.push_back(*b);
        minHeapify(elements.size() - 1);
    }




//===================================================================================
// Recursive heapify function for a MinHeap
//===================================================================================
void BinHeap::minHeapify(unsigned int index)
    {
        unsigned int left, right, minn;
        left = 2*index;
        right = 2*index + 1;
    
        // Base case
        if (index == 0)
            return;
    
        // Check the children, if they exist and pick the larger for swapping
        if (left < elements.size() && elements[left].getID() < elements[index].getID())
            minn = left;
        else
            minn = index;
    
        if (right < elements.size() && elements[right].getID() < elements[minn].getID())
            minn = right;
    
        if (minn != index)
            {
                BinHeapNode temp = elements[minn];
                elements[minn] = elements[index];
                elements[index] = temp;
                minHeapify(minn);
            }
    
        // Now check the parent, if it exists
        minHeapify(index/2);
    }









string BinHeap::deleteMinHeapVal(int IdNo)
    {
        string str = "Invalid ID";
        int x = 0;
        
        while ( x <= elements.size() )
            {
                if ( IdNo == elements[x].getID() )
                    {
                        str = elements[x].getDataBH();
                        elements[x] = elements[ (elements.size() - 1) ];
                        
                        elements.pop_back();
                        
                        minHeapify(x);              // parent
                        minHeapify((2 * x) +1);     // left child
                        minHeapify((2 * x) +2 );    // right child
                        break;      //No need to search further
                    }
                x++;
            }
            return str;
    }

    
void BinHeap::removeMinRoot()
    {
    if (elements.size() < 2)
        return;
    else
        {
            elements[1] = elements[elements.size() - 1];
            BinHeapNode* b = new BinHeapNode(0," "," "," "," "," ");
            elements.resize(elements.size() - 1, *b);
            minHeapify(1);
        }
    
    }

    
string BinHeap::sortMinHeap()
    {
        string str ="";
        
        while (elements.size() > 1)
        {
            str.append((elements[1].getDataBH()));
            
            removeMinRoot();
        }
        str.append("\n");
        return str;
    }


string BinHeap::displayHeap()
{
    string str = "";
    for (int x = 1; x < elements.size(); x++)
        {
            str.append((elements[x].getDataBH()));
            
        }
    str.append("\n");
    return str;
}


#endif
