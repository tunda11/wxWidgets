//Programmed by Alec Gilkes : 415002420 

#ifndef AVL_AVLTree_H
#define AVL_AVLTree_H
#include <sstream>
#include <string>


//************************************************************
//***************        AVL NODE CLASS        ***************
//************************************************************
class AVLNode
    {
        private:
            int idNo;
            string fname;
            string lname;
            string destination;
            string season;
            string booking;
            int height;
    
        public:
            AVLNode* left;
            AVLNode* right;

            // Constructor functions
            AVLNode()        {right = left = NULL; height = 0;}
            AVLNode(int, string, string, string, string, string); //{data = val; height = 0; right = left = NULL;}
    
            // Mutator functions
            void setData(int, string, string, string, string, string); //  {data = val;}
            void setData(AVLNode*);
            void setHeight(int ht)  {height = ht;}

            // Accessor functions
            string getData();
            int getID()   {return idNo;}
            int getHeight() { return height;}
     };

// Constructor:    
AVLNode::AVLNode(int num, string firstName, string lastName, string loc, string time, string book)
    {
        idNo = num;
        fname = firstName;
        lname = lastName;
        destination = loc;
        season = time;
        booking = book;
        right       = NULL;
        left        = NULL;
    }



// Mutator
void AVLNode::setData(int num, string firstName, string lastName, string loc, string time, string book)
    {
        idNo = num;
        fname = firstName;
        lname = lastName;
        destination = loc;
        season = time;
        booking = book;
    }



// Mutator
void AVLNode::setData(AVLNode* nodePtr)
    {
        idNo    = nodePtr->idNo;
        fname   = nodePtr->fname;
        lname     = nodePtr->lname;
        destination = nodePtr->destination;
        season      = nodePtr->season;
        booking     = nodePtr->booking;
        right       = nodePtr->right;
        left        = nodePtr->left;
    }



// Accessor
string AVLNode::getData()
    { 
        string str = "";
        str.append(to_string(idNo));
        str.append("\t");
        str.append(fname);
        str.append("\t");
        str.append(lname);
        str.append("\t");
        str.append(destination);
        str.append("\t");
        str.append(season);
        str.append("\t");
        str.append(booking);
        str.append("\t");
	
	//get the client ids of the left and right children
	str.append("[");
	if(left ==NULL)
	  str.append("NULL");
	else
	str.append(to_string(left->getID()));
	
	str.append(", ");
	
	if(right == NULL)
	  str.append("NULL");
	else
	str.append(to_string(right->getID()));
	str.append("]\t");
        
        return str;
    }


//****************************************************************************
//                              END OF NODE CLASS
//****************************************************************************
    
//*******************************************************************************
//                              AVL ADT Class
//*******************************************************************************

class AVL
    {
        private:
            AVLNode* root;
    
            AVLNode* insertHelper(AVLNode*, int, string, string, string, string, string);       // Recursive counterpart of insert
            AVLNode* deleteNode(AVLNode*, int);         // Recursive counterpart of delete
            string   preOrderHelper(AVLNode* );         // Recursive counterpart of preorder
            string   postOrderHelper(AVLNode* );        // Recursive counterpart of postorder
            string   inOrderHelper(AVLNode* );          // Recursive counterpart of inorder
            AVLNode* rotateRight(AVLNode* );
            AVLNode* rotateLeft(AVLNode* );
            AVLNode* rotateDoubleRight(AVLNode* );
            AVLNode* rotateDoubleLeft(AVLNode* );
            AVLNode* rotateLeftRight(AVLNode* );
            AVLNode* rotateRightLeft(AVLNode* );
            int      calcHeight(AVLNode* );
            int      calcBalance(AVLNode* );
        
        public:
            AVL() { root = NULL;}
    
            AVLNode* getRoot()       { return root;}
            void     insertAVL(int idNo, string fname, string lname, string loc, string season, string booking);// { root = insertHelper(root, val); }
            string   remove(int idNo); //{ root = deleteNode(root, idNo); return root; }
            string   preOrderAVL()      { return preOrderHelper(root); }
            string   postOrderAVL()     { return postOrderHelper(root); }
            string   inOrderAVL()       { return inOrderHelper(root); }
            void     purgeAVL()         { root = NULL; }
            string getAVLList(AVLNode*);
    };



void AVL::insertAVL(int idNo, string fname, string lname, string destination, string season, string booking)
    {
        root = insertHelper(root, idNo, fname, lname, destination, season, booking);
    }

AVLNode* AVL::insertHelper(AVLNode* ptr, int idNo, string fname, string lname, string destination, string season, string booking)
    {
        if ( ptr == NULL )
            {
                ptr = new AVLNode(idNo, fname, lname, destination, season, booking);
            }
        else
            if(idNo >= ptr->getID())          // insert in right subtree; OP definition
                {
                    ptr->right = insertHelper(ptr->right, idNo, fname, lname, destination, season, booking);
                    if(calcBalance(ptr) == -2)          // Too heavy on the right
                        {
                            if(idNo > ptr->right->getID() )    // Regular right-heavy
                                ptr = rotateDoubleRight(ptr);
                            else                        // It's a special case: ">"
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                if( idNo < ptr->getID() )
                    {
                        ptr->left = insertHelper(ptr->left, idNo, fname, lname, destination, season, booking);
                        if(calcBalance(ptr) == 2)       // Too heavy on the left
                            {
                                if( idNo < ptr->left->getID() )     // Regular left-heavy
                                    ptr = rotateDoubleLeft(ptr);
                                else                    // It's a special case: "<"
                                    ptr = rotateLeftRight(ptr);
                            }
                    }
    
        ptr->setHeight(calcHeight(ptr));
        return(ptr);
    }





AVLNode*  AVL::deleteNode(AVLNode* ptr, int idNo)
{
    AVLNode* successor;
    
    if ( ptr == NULL)           // Node location is empty
        {
            return NULL;
        }
    else
        if( idNo > ptr->getID() )                // Search in Right sub-tree
            {
                ptr->right = deleteNode(ptr->right, idNo);
                if ( calcBalance(ptr) == 2)
                    {
                        if(calcBalance(ptr->left) >= 0)
                            ptr = rotateDoubleLeft(ptr);
                        else
                            ptr = rotateLeftRight(ptr);
                    }
            }
        else
            if( idNo < ptr->getID() )          // Search the Left sub-tree
                {
                    ptr->left = deleteNode(ptr->left, idNo);
                    if( calcBalance(ptr) == -2 )                   //Rebalance during windup
                        {
                            if( calcBalance(ptr->right) <= 0)
                                ptr = rotateDoubleRight(ptr);
                            else
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                {
                    //Node to to be deleted is found
                    if ( ptr->right != NULL)
                        {  //delete its inorder succesor
                            successor = ptr->right;
                            while ( successor->left != NULL)
                                successor = successor->left;
                            
                            ptr->setData( successor );
                            ptr->right = deleteNode( ptr->right, ptr->getID() );
                            if(calcBalance(ptr) == 2) // Rebalance during windup
                                {
                                    if(calcBalance(ptr->left) >= 0)
                                        ptr = rotateDoubleLeft(ptr);
                                    else
                                        ptr = rotateLeftRight(ptr);
                                }
                    }
                else
                    return(ptr->left);
                
                }
    ptr->setHeight(calcHeight(ptr));
    return(ptr);
}
/*
string AVL::getAll(AVLNode* ptr)
{
    string str = ptr->getData();
    
    //get the weight of the node
    str.append("]\t");
    str.append("[");   
    if(calcBalance(ptr) == -1)
    str.append("left-heavy");
    else if(calcBalance(ptr) == 1)
      str.append("right-heavy");
    else if(calcBalance(ptr) == 0)
      str.append("balanced");
      
    str.append("] \n");
    
    
    return str;
}

string AVL::remove(int idNo) 
{ 
  AVLNode* ptr = find(idNo);
  string str = "";
  if(ptr == NULL)//if the Client ID wasn't found
  {
    str = "That is an invalid Client ID";
  }
  else//if the Client ID was found
  {
    str = getAVLList(ptr);
    root = deleteHelper(root, idNo); 
  }
  return str;
}

*/

AVLNode*  AVL::rotateRight(AVLNode* ptr)
    {
        AVLNode* newParent;
    
        newParent = ptr->left;
        ptr->left = newParent->right;
        newParent->right = ptr;
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }





AVLNode*  AVL::rotateLeft(AVLNode* ptr)
    {
        AVLNode* newParent;
    
        newParent = ptr->right;
        ptr->right = newParent->left;
        newParent->left = ptr;
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }





AVLNode*  AVL::rotateDoubleRight(AVLNode* ptr)
    {
        ptr = rotateLeft(ptr);
        return(ptr);
    }





AVLNode*  AVL::rotateDoubleLeft(AVLNode* ptr)
    {
        ptr = rotateRight(ptr);
        return(ptr);
    }





AVLNode*  AVL::rotateLeftRight(AVLNode* ptr)
    {
        ptr->left = rotateLeft(ptr->left);
        ptr = rotateRight(ptr);
        return(ptr);
    }






AVLNode*  AVL::rotateRightLeft(AVLNode* ptr)
    {
        ptr->right = rotateRight(ptr->right);
        ptr = rotateLeft(ptr);
        return(ptr);
    }





int AVL::calcHeight(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
        
        if( ptr == NULL)
            return(0);
        
        if(ptr->left == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->left->getHeight();
        
        if(ptr->right == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->right->getHeight();

    
        if(leftHeight > rightHeight)
            return(leftHeight);
    
        return(rightHeight);
    }





int AVL::calcBalance(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
    
        if(ptr == NULL)
            return (0);
    
        if(ptr->left == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->left->getHeight();
    
        if(ptr->right == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->right->getHeight();
    
        return(leftHeight - rightHeight);
    }






string AVL::inOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );
            
                str.append( getAVLList(ptr) );
                str.append( "  ");
            
                str.append( inOrderHelper(ptr->right) );
              }
		return str;
	}




string AVL::preOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( getAVLList(ptr) );
                str.append( "  ");
            
                str.append( preOrderHelper(ptr->left) );
                str.append( preOrderHelper(ptr->right) );
              }
		return str;
	}




string AVL::postOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );
                str.append( inOrderHelper(ptr->right) );
            
                str.append( getAVLList(ptr) );
                str.append( "  ");
             }
		return str;
	}


string AVL::getAVLList(AVLNode* ptr)
{
    string str = ptr->getData();
    
    //get the weight of the node
    str.append("]\t");
    str.append("[");   
    if(calcBalance(ptr) == -1)
    str.append("heavy on the left");
    else if(calcBalance(ptr) == 1)
      str.append("heavy on the right");
    else if(calcBalance(ptr) == 0)
      str.append("balanced");
      
    str.append("] \n");
    
    
    return str;
}


#endif // defined(AVL_AVLTree_H)
