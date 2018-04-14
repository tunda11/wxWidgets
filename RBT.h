//Programmer: Mellissa Marie 41200217


#ifndef RBTREE_H
#define RBTREE_H


//===================================================================================
//                       RBt Node Class
//===================================================================================
class RBTNode
    {
        private:
            int ClientID;
            string FirstName;
            string Surname;
            string Destination;
            string Season;
            string Payment;
            string Booking;
            string colour;
    
        public:
            RBTNode* left;
            RBTNode* right;
            RBTNode* parent;

            // Constructor functions
            RBTNode(){right = left = parent= NULL; colour = "RED";}
            RBTNode(int, string, string, string, string, string);
    
            // Mutator functions
            void setData(int, string, string, string, string, string);
	    void setData(RBTNode*);
            void setColour(string col){colour = col;}

            // Accessor functions
            string getData();
	    int getClientID(){ return ClientID;}
            string getColour(){return colour;}
     };

//===================================================================================
//                       Member Functions for RBT Node
//===================================================================================


//===================================================================================
//                       Member Functions for RBT Node
//===================================================================================


// Constructor:
RBTNode::RBTNode(int idNo, string first, string last, string place, string timeOfYear, string bookType)
    {
        ClientID    = idNo;
        FirstName   = first;
        Surname     = last;
        Destination = place;
        Season      = timeOfYear;
        Booking     = bookType;
        right       = NULL;
        left        = NULL;
	colour 	    = "RED"; 
    }



// Mutator
void RBTNode::setData(int idNo, string first, string last, string place, string timeOfYear, string bookType)
    {
        ClientID    = idNo;
        FirstName   = first;
        Surname     = last;
        Destination = place;
        Season      = timeOfYear;
        Booking     = bookType;
        right       = NULL;
        left        = NULL;
    }



// Mutator
void RBTNode::setData(RBTNode* nodePtr)
    {
        ClientID    = nodePtr->ClientID;
        FirstName   = nodePtr->FirstName;
        Surname     = nodePtr->Surname;
        Destination = nodePtr->Destination;
        Season      = nodePtr->Season;
        Payment     = nodePtr->Payment;
        Booking     = nodePtr->Booking;
        right       = nodePtr->right;
        left        = nodePtr->left;
    }




// Accessor
string RBTNode::getData()
    {
        string str = "";
        str.append(to_string(ClientID));
        str.append("\t");
        str.append(FirstName);
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
        str.append("\t");
	
	//get the client ids of the left and right children
	str.append("[");
	if(left ==NULL)
	  str.append("NULL");
	else
	str.append(to_string(left->getClientID()));
	
	str.append(", ");
	
	if(right == NULL)
	  str.append("NULL");
	else
	str.append(to_string(right->getClientID()));
	str.append("]\t");
	
	//get the colour of the node
        str.append("[");
        str.append(getColour());
	str.append("] \n");
        
        return str;
    }

//===================================================================================
//                    END... Member Functions for RBT Node
//===================================================================================

//===================================================================================
//                    END... RBT Node Class
//===================================================================================








//===================================================================================
//                       RBT Container (ADT) Class
//===================================================================================
class RBT
    {
        private:
            RBTNode* root;
    
            // Utility functions
            void    rotateLeft( RBTNode* );
            void    rotateRight(RBTNode* );
            void    fixUp(RBTNode* );
            string  inOrderHelper(RBTNode* );//Recursive counterpart of inorder traversal
            string  preOrderHelper(RBTNode* );//Recursive counterpart of preorder traversal
            string  postOrderHelper(RBTNode* );//Recursive counterpart of postorder traversal
            void    deleteHelper(RBTNode* );//Recursive counterpart for deleting a node
            RBTNode* getMinimum(RBTNode *);
            RBTNode* getSuccessor(RBTNode *);
    
        public:
            // Constructor function
            RBT(){ root = NULL;}
    
            // Mutator functions
            void purgeRBT() { root = NULL; }//empties the RBT
            void insertRBT(int, string, string, string, string, string);//add a new node to the RBT
            string removeRBT(int idNo);//remove a node from the RBT
    
            // Accessor functions
            RBTNode* getRoot(){ return root;}
            string inOrderRBT();
            string preOrderRBT();
            string postOrderRBT();
            RBTNode* findNode(int );
	    
	    
     };





void RBT::rotateLeft( RBTNode* ptr )
	{
        RBTNode* rightChild = ptr->right;
        ptr->right = rightChild->left;
        
        if (rightChild->left != NULL)
            rightChild->left->parent = ptr;
        
        rightChild->parent = ptr->parent;
        
        if (ptr == root)
            root = rightChild;
        else
            {
                if( ptr == ptr->parent->left)
                    ptr->parent->left = rightChild;
                 else
                    ptr->parent->right = rightChild;
            }
    
        rightChild->left = ptr;
        ptr->parent = rightChild;
 	}




void RBT::rotateRight(RBTNode* ptr)
	{
        RBTNode* leftChild = ptr->left;
        ptr->left = leftChild->right;
        
        if (leftChild->right != NULL)
            leftChild->right->parent = ptr;
        
        leftChild->parent = ptr->parent;
        
        if (ptr == root)
            root = leftChild;
        else
            {
                if( ptr == ptr->parent->right)
                    ptr->parent->right = leftChild;
                 else
                    ptr->parent->left = leftChild;
            }
    
        leftChild->right = ptr;
        ptr->parent = leftChild;
    
    }





RBTNode* RBT::findNode(int idNo)
	{
		RBTNode* ptr = root;
		
		while ( ptr != NULL )
            {
                if  (ptr->getClientID() == idNo)        // Found it!
                    {
                        return ptr;
                    }
            
                if (idNo< ptr->getClientID() )//check the left subtree
                    ptr = ptr->left;
                else 
                    ptr = ptr->right;//check the right subtree
            }
    
        return NULL;            // Tree is empty OR did not find it
	}





void RBT::insertRBT(int idNo, string first, string last, string place, string timeOfYear, string bookType)
	{
    
        RBTNode* newnode = new RBTNode(idNo, first, last, place, timeOfYear, bookType);      // Create the new node
        
        if (root == NULL)                   // Tree is empty - newnode is first node
            {
                newnode->setColour("BLACK");
                root = newnode;
                return;
            }
        else                                // Tree is NOT empty
            {
                RBTNode* ancestor = NULL;
                RBTNode* current = root;
                while (current != NULL)
                    {
                        ancestor = current;
                        
                        if ( newnode->getClientID() < current->getClientID() )
                            current = current->left;
                        else if(newnode->getClientID() > current->getClientID())
                            current = current->right;
                    }
            
                newnode->parent = ancestor;
                
                if ( newnode->getClientID() < ancestor->getClientID() )
                    ancestor->left = newnode;
                else if( newnode->getClientID() > ancestor->getClientID() )
                    ancestor->right= newnode;
            
                fixUp(newnode);
            }
	}




void RBT::fixUp( RBTNode *ptr )
    {
        RBTNode *ptrsUncle = NULL;
    
        while ( ptr != root && ptr->parent->getColour() == "RED" )
            {
                if ( ptr->parent == ptr->parent->parent->left )
                    {       // ptr's parent is a LEFT child
                        ptrsUncle = ptr->parent->parent->right;
                        
                        if (  ptrsUncle != NULL && ptrsUncle->getColour() == "RED" )
                            {
                                ptr->parent->setColour("BLACK");
                                ptrsUncle->setColour("BLACK");
                                ptr->parent->parent->setColour("RED");
                                ptr = ptr->parent->parent;
                            }
                        else
                            {
                                if ( ptr == ptr->parent->right )
                                    {
                                        ptr = ptr->parent;
                                        rotateLeft( ptr );
                                    }
                                
                                ptr->parent->setColour("BLACK");
                                ptr->parent->parent->setColour("RED");
                                rotateRight( ptr->parent->parent );
                            }
                    }
                else            // ptr's parent is a RIGHT child
                    {
                        ptrsUncle = ptr->parent->parent->left;
                        
                        if ( ptrsUncle != NULL && ptrsUncle->getColour() == "RED" )
                            {
                                ptr->parent->setColour("BLACK");
                                ptrsUncle->setColour("BLACK");
                                ptr->parent->parent->setColour("RED");
                                ptr = ptr->parent->parent;
                            }
                        else
                            {
                                if ( ptr == ptr->parent->left )
                                    {
                                        ptr = ptr->parent;
                                        rotateRight( ptr );
                                    }
                                ptr->parent->setColour("BLACK");
                                ptr->parent->parent->setColour("RED");
                                rotateLeft( ptr->parent->parent );
                            }
                    }
            }
        
        root->setColour("BLACK");
        
        ptrsUncle = NULL;
    }




string RBT::removeRBT(int idNo)
    {
        RBTNode* markedNode = findNode(idNo);
	string str;
	if(markedNode == NULL)//if the Client ID wasn't found
	{
	 str = "That is an invalid Client ID"; 
	}
	
	else//if the Client ID was found
	{
	  str = markedNode ->getData();
	  deleteHelper(markedNode);  
	}
	
	return str;   
     }




void RBT::deleteHelper(RBTNode* node2Zap)
    {
        if (node2Zap == NULL)    //If node being deleted is NULL then do nothing.
            return;
        else
            {
                RBTNode *successor, *successorChild;
                successor = node2Zap;
            
                if (node2Zap->left == NULL || node2Zap->right == NULL)
                        //If either of the children is NULL
                    successor = node2Zap;
                else                    // node2Zap has 2 children
                    successor = getSuccessor(node2Zap);
            
                if (successor->left == NULL)
                    successorChild = successor->right;
                else
                    successorChild = successor->right;
                
                if (successorChild != NULL)
                    successorChild->parent = successor->parent;
                
                if (successor->parent == NULL)
                    root = successorChild;
                else if (successor == successor->parent->left)
                        successor->parent->left = successorChild;
                    else
                        successor->parent->right = successorChild;
                
                if (successor != node2Zap)
                    node2Zap->setData(successor);

                // Finally... If colour is black call fixup otherwise no fixup required
                if (successor->getColour() == "BLACK" && successorChild != NULL)
                    fixUp(successorChild);
            }
    }




RBTNode* RBT::getSuccessor(RBTNode* ptr)
    {
        if (ptr->right == NULL)
            return ptr->left;
        else
            return(getMinimum(ptr->right));
    }




RBTNode* RBT::getMinimum(RBTNode *ptr)
    {
        while(ptr->left != NULL)
            ptr = ptr->left;
    
        return ptr;
    }




string RBT::inOrderHelper(RBTNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
           {
             str.append( inOrderHelper(ptr->left) );
	     str.append(ptr->getData());
	     str.append( inOrderHelper(ptr->right) );
           }
	return str;
      
    }




string RBT::preOrderHelper(RBTNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
		str.append( ptr->getData() );
            
                str.append( preOrderHelper(ptr->left) );
                str.append( preOrderHelper(ptr->right) );
              }
	return str;
    }




string RBT::postOrderHelper(RBTNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
               
                str.append( postOrderHelper(ptr->left) );
                str.append( postOrderHelper(ptr->right) );
            
                str.append( ptr->getData() );
              }
	return str;
    }




string RBT::inOrderRBT()
    {
	  return inOrderHelper(root);	   
    }




string RBT::preOrderRBT()
    {
        return preOrderHelper(root);
    }




string RBT::postOrderRBT()
    {
        return postOrderHelper(root);
    }


#endif /* defined(RBTREE_H) */ 
