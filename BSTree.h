//
//  BSTree.h
//  BST
//
//  Created by Dr. John Charlery on 6/8/15.
//  Copyright (c) 2015 University of the West Indies. All rights reserved.
//

#ifndef BST_BSTree_h
#define BST_BSTree_h
#include <sstream>
#include <string>


using namespace std;

//****************************************************************************************
//                      Binary Search Tree Node Class Creation
//****************************************************************************************
class BSTNode
    {
        private:
            int IdNo;
            string Fname;
            string Lname;
            string Destination;
            string Season;
            string Booking;
    
        public:
            BSTNode* left;
            BSTNode* right;

            // Constructor functions
            BSTNode(){right = left = NULL;}
            BSTNode(int, string, string, string, string, string);//{data = id; right = left = NULL;}
    
            // Mutator functions
            void setData(int, string, string, string, string, string);//{data = val;}
            void setData(BSTNode*);
            
            
            // Accessor functions
            string getDataBST();//{return data;}
            int getID(){return IdNo;}
     };

//Constructor
BSTNode::BSTNode(int num, string firstName, string lastName, string loc, string time, string book)
    {
        IdNo = num;
        Fname = firstName;
        Lname = lastName;
        Destination = loc;
        Season = time;
        Booking = book;
        right       = NULL;
        left        = NULL; 
    }

void BSTNode::setData(int num, string firstName, string lastName, string loc, string time, string book)
    {
        IdNo = num;
        Fname = firstName;
        Lname = lastName;
        Destination = loc;
        Season = time;
        Booking = book;
        right = NULL;
        left = NULL;
    }
    
void BSTNode::setData(BSTNode* nodePtr)
    {
        IdNo    = nodePtr->IdNo;
        Fname   = nodePtr->Fname;
        Lname     = nodePtr->Lname;
        Destination = nodePtr->Destination;
        Season      = nodePtr->Season;
        Booking     = nodePtr->Booking;
        right       = nodePtr->right;
        left        = nodePtr->left;
    }

    
    
//Accessor
string BSTNode::getDataBST()
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
        str.append("\t");

        //get the client ids of the left and right children
	str.append("[");
	if(left == NULL)
	  str.append("NULL");
	else
	  str.append(to_string(left->getID()));
	
	str.append(", ");
	
	if(right == NULL)
	  str.append("NULL");
	else
	  str.append(to_string(right->getID()));
	
	str.append("]\n");
    
        return str;
    }
    
    
//***************************************************************************************
//                      BST CLASS
//***************************************************************************************
    
class BST
    {
        private:
            BSTNode* root;
    
            // Recursive counterpart for inserting a node
            BSTNode* insertHelper(BSTNode*, int, string, string, string, string, string);
    
            // Recursive counterpart for deleting a node
            BSTNode* deleteNode(BSTNode*, int);
    
            // Recursive counterpart of preorder traversal
            string preOrderHelper(BSTNode* );
    
            // Recursive counterpart of postorder traversal
            string postOrderHelper(BSTNode* );

            // Recursive counterpart of inorder traversal
            string inOrderHelper(BSTNode* );
    
        public:
            //  Constructor function
            BST() { root = NULL;}
    
            // Mutator functions
            void purgeBST() { root = NULL;}
            void insert(int, string, string, string, string, string); //{ root = insertHelper(root, num, firstName, lastName, loc, time, book); }
            string remove(int IdNo) { root = deleteNode(root, IdNo); }
   
            // Accessor functions
            BSTNode* getRoot() { return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }
            BSTNode* find(int);
    
            string showLevels();        //Display nodes by level
    };



void BST::insert(int IdNo, string Fname, string Lname, string Destination, string Season, string Booking)
    {
            root = insertHelper(root, IdNo, Fname, Lname, Destination, Season, Booking);
    }


BSTNode* BST::insertHelper(BSTNode* ptr, int IdNo, string Fname, string Lname, string Destination, string Season, string Booking)
    {
        if ( ptr == NULL )         // The tree is empty - new first node!
            {
                ptr = new BSTNode(IdNo, Fname, Lname, Destination, Season, Booking);
            }
        else                       // choose which sub-tree to follow
            {
                if (IdNo >= ptr->getID())  // insert in right subtree - Operational defn.
                    ptr->right = insertHelper(ptr->right, IdNo, Fname, Lname, Destination, Season, Booking);
                else
                    ptr->left = insertHelper(ptr->left, IdNo, Fname, Lname, Destination, Season, Booking);
            }
        return ptr;
    }





BSTNode*  BST::deleteNode(BSTNode* ptr, int IdNo)
    {
        BSTNode* successor;
        
        if ( ptr == NULL)           // Node not found!
            {
                return NULL;
            }
        else
            if ( IdNo > ptr->getID() )                // Search in Right subtree
                    ptr->right = deleteNode(ptr->right, IdNo);
            else if( IdNo < ptr->getID() )           // Search in Left subtree
                        ptr->left = deleteNode(ptr->left, IdNo);
        
                 else   //Node to to be deleted is found
                     {
                        if ( ptr->right != NULL )
                            {  // delete its inorder succesor
                                successor = ptr->right;                 // Go right...
                                while ( successor->left != NULL )       // ...then go deep left
                                    successor = successor->left;
                                
                                // Transfer data from successor to ptr
                                ptr->setData( successor );
                                
                                // Now reset ptr's right child
                                ptr->right = deleteNode( ptr->right, ptr->getID() );
                            }
                        else
                            return (ptr->left);
                    }
        return (ptr);
    }



BSTNode* BST::find(int IdNo)
{
  BSTNode* ptr = root;
		
    while ( ptr != NULL )
	{
	    if  (ptr->getID() == IdNo)        // Found it!
                {
		    return ptr;
                }
            
             if (IdNo< ptr->getID() )//check the left subtree
		ptr = ptr->left;
             
	     else 
		ptr = ptr->right;//check the right subtree
	}
    
    return NULL;// Tree is empty OR did not find it
}



string BST::inOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );
            
                str.append( ptr->getDataBST() );
                str.append( "  ");
            
                str.append( inOrderHelper(ptr->right) );
            
              }
		return str;
	}




string BST::preOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( ptr->getDataBST() );
                str.append( "  ");
            
                str.append( preOrderHelper(ptr->left) );
                str.append( preOrderHelper(ptr->right) );
               
              }
		return str;
	}




string BST::postOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( postOrderHelper(ptr->left) );
                str.append( postOrderHelper(ptr->right) );
            
                str.append( ptr->getDataBST() );
                str.append( "  ");
                
                
             }
		return str;
	}


/*
string BST::showLevels()
    {
        vector <BSTNode*> listA;
        vector <BSTNode*> listB;
    
        string str = "";
        
        listA.resize(0);
        listB.resize(0);
        
        if (root == NULL)
            {
                str.append("Tree is Empty...\n");
                return str;
            }
        else
            listA.push_back(root);

    
        while (!listA.empty())
            {
                //Display the contents of listA
                for (int x = 0; x < listA.size(); x++)
                    {
                        str.append(to_string(listA[x]->getID()));
                        str.append("\t");
                    }
                str.append("\n");
            
                //Transfer contents of listA to listB
                listB = listA;
            
                // Now purge listA and copy listB's children into listA
                listA.resize(0);

                for (int x = 0; x < listB.size(); x++)
                    {
                        if (listB[x]->left != NULL)
                            listA.push_back(listB[x]->left);
                        if (listB[x]->right != NULL)
                            listA.push_back(listB[x]->right);
                    }
            }
        return str;
    }*/
/*
string BST::searchRight(BSTNode* curPtr) {
    BSTNode* R = curPtr->right;
    if (R == NULL) {
        return "NULL     ";
    }
    else {
        return toString(R->getID());
    }
}

string BST::searchLeft(BSTNode* curPtr) {
    BSTNode* L = curPtr->left;
    if (L == NULL) {
        return "NULL     ";
    }
    else {
        return toString(L->getID());
}

}
*/
#endif
