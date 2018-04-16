//
//  SplayTree.h
//  Splay
//
//  Created by Dr. John Charlery on 11/15/16.
//  Copyright (c) 2016 University of the West Indies. All rights reserved.
//

#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayNode
    {
        private:
                int IdNo;
            string Fname;
            string Lname;
            string Destination;
            string Season;
            string Booking;
    
        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree
    
                //Constructor
                SplayNode( int, string, string, string, string, string); //{data = val; left = right= 0;}
                SplayNode() {left = right= NULL;}
    
                //Accessors
                string getData();
                int getID() {return IdNo;}
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
    
    
                //Mutators
                void setData(int, string, string, string, string, string);
                void setData(SplayNode*);
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
    };

SplayNode::SplayNode(int num, string firstName, string lastName, string loc, string time, string book)
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
    
void SplayNode::setData(int num, string firstName, string lastName, string loc, string time, string book)
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
    
void SplayNode::setData(SplayNode* nodePtr)
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
string SplayNode::getData()
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

    
    
//===================================================================================
//                    END... Splay Node Class
//===================================================================================








//===================================================================================
//                       Splay Container (ADT) Class
//===================================================================================


class SplayTree
    {
        private:
                SplayNode *root;
    
                    // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(int, SplayNode*);
                SplayNode* InsertHelper(SplayNode*, int, string, string, string, string, string);
                SplayNode* deleteHelper(SplayNode*, int);
                string InOrderHelper(SplayNode*);
                string PreOrderHelper(SplayNode*);
                string PostOrderHelper(SplayNode*);
                void insertSplayNodeHelper(SplayNode **, int );
                string displayNodesHelper( SplayNode * ) const;
                SplayNode* find(int);
    
            public:
                SplayTree(){ root = 0; };
    
                SplayNode* getRoot(){return root;}
                void Insert(int, string, string, string, string, string);
                string removeSplay(int);
                string InOrder(){ return InOrderHelper(root);}
                string PreOrder(){ return PreOrderHelper(root);}
                string PostOrder(){ return PostOrderHelper(root);}
                void insertSplayNode( int, string, string, string, string, string );
                string displayNodes();
                void purgeSplay(){root = NULL;}
    };



//=================================================================================
//          The NEW RightRotate function
//=================================================================================

SplayNode* SplayTree::RightRotate(SplayNode* ptr)
{
    SplayNode* leftchild = ptr->left;
    if (leftchild != NULL)
        {
            ptr->left = leftchild->right;
            leftchild->right = ptr;
        }
    return leftchild;
}



//=================================================================================
//          The NEW LeftRotate function
//=================================================================================

SplayNode* SplayTree::LeftRotate(SplayNode* ptr)
{
    SplayNode* rightchild = ptr->right;
    if (rightchild != NULL)
        {
            ptr->right = rightchild->left;
            rightchild->left = ptr;
        }
    return rightchild;
}





//=================================================================================
//          The NEW Splay function
//=================================================================================

SplayNode* SplayTree::Splay(int IdNo, SplayNode* root)
    {
        if(root == NULL)            // Empty sub-tree; should never be, but...
            return NULL;

        SplayNode *LeftTreeMax, *RightTreeMin;
        SplayNode* header = new SplayNode();

        LeftTreeMax = RightTreeMin = header;

        while(root->left != NULL || root->right != NULL)
            {
                if( IdNo < root->getID() )
                {
                    if( IdNo < root->left->getID() )
                        LeftRotate( root->left );

                    if( root->left == NULL )
                        break;
                    
                    // Link Right
                    RightTreeMin->left = root;
                    RightTreeMin = root;
                    root = root->left;
                }
                else // if( key > root->getData() )
                {
                    if( root->right->getID() < IdNo )
                        RightRotate( root->right );
                    
                    if( root->right == NULL )
                        break;
                    
                    // Link Left
                    LeftTreeMax->right = root;
                    LeftTreeMax = root;
                    root = root->right;
                }

            }
        
        // Assemble Left Tree, Middle Tree and Right tree together
        LeftTreeMax->right = root->left;
        RightTreeMin->left = root->right;
        root->left = header->right;
        root->right = header->left;

        return root;
    }








SplayNode* SplayTree::InsertHelper( SplayNode* root, int num, string firstName, string lastName, string loc, string time, string book)
    {
        SplayNode* newnode = new SplayNode(num, firstName, lastName, loc, time, book);
    
        if(root == NULL)
            return newnode;
    
        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;
    
        if(num == temp->getID())      // No duplication
            return root;
        
        while(temp != NULL)
            {
                parent_temp = temp;
            
                if(num < temp->getID())
                    temp = temp->left;
                else
                    temp = temp->right;
             }
    
        if(num <= parent_temp->getID())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;
    
        root = Splay(num, root);
        return (root);
    }




void SplayTree::Insert(int num, string firstName, string lastName, string loc, string time, string book)
{
    root = InsertHelper(root, num, firstName, lastName, loc, time, book);

}



string SplayTree::InOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( InOrderHelper(ptr->left) );
            
                str.append( ptr->getData() );
            
                str.append( InOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PreOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( ptr->getData() );
            
                str.append( PreOrderHelper(ptr->left) );
                str.append( PreOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PostOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( PostOrderHelper(ptr->left) );
                str.append( PostOrderHelper(ptr->right) );
            
                str.append( ptr->getData() );
            
              }
		return str;
    }

    
SplayNode* SplayTree::deleteHelper(SplayNode* ptr, int IdNo)
{
    SplayNode* temp;
    
    
    if(ptr == NULL)// Node not found
      return NULL;
    
    ptr = Splay(IdNo, ptr);
    
    if(IdNo != ptr->getID())
      return ptr;
    
    else
    {
      
      if(ptr->left == NULL)
      {
	temp = ptr;
	ptr = ptr->right;
      }
      
      else
      {
	temp = ptr;
	
	ptr = Splay(IdNo, ptr->left);
	ptr->right = temp->right;
      }
      
      return ptr;
    }
  
}

string SplayTree::removeSplay(int IdNo)
{
  SplayNode* ptr = find(IdNo);
  string str;
  if(ptr == NULL)//if the ID is not found
  {
    str = "Invalid ID";
  }
  else
  {
    str = ptr ->getData();
    root = deleteHelper(root, IdNo);
  }
   
  return str;
}

SplayNode* SplayTree::find(int IdNo)
{
  SplayNode* ptr = root;
		
		while ( ptr != NULL )
            {
                if  (ptr->getID() == IdNo)        // Found it!
                    {
                        return ptr;
                    }
            
                if (IdNo < ptr->getID() )
                    ptr = ptr->left;
                else 
                    ptr = ptr->right;
            }
    
        return NULL;            // Tree is empty OR did not find it
}


#endif
