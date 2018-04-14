//Programmed by Alec Gilkes

#ifndef RBTREE_H
#define RBTREE_H
#include <sstream>
#include <string>


//************************************************************
//***************        RBT NODE CLASS        ***************
//************************************************************
class RBTNode
    {
        private:
            int idNo;
            string fname;
            string lname;
            string destination;
            string season;
            string booking;
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
            string getData();//{return data;}
            void setID(int id){idNo = id;}
            int getID(){return idNo;}
            string getColour(){return colour;}
     };

     // Constructor:
     
/*RBTNode::RBTNode()
    {
        int idNo = 0;
        string fname = "";
        string lname = "";
        string destination = "";
        string season = "";
        string booking = "";
        right       = NULL;
        left        = NULL;
	colour 	    = "RED"; 
    }*/
    
RBTNode::RBTNode(int num, string firstName, string lastName, string loc, string time, string book)
    {
        idNo = num;
        string fname = firstName;
        string lname = lastName;
        string destination = loc;
        string season = time;
        string booking = book;
        right       = NULL;
        left        = NULL;
	colour 	    = "RED"; 
    }



// Mutator
void RBTNode::setData(int num, string firstName, string lastName, string loc, string time, string book)
    {
        idNo = num;
        string fname = firstName;
        string lname = lastName;
        string destination = loc;
        string season = time;
        string booking = book;
    }



// Mutator
void RBTNode::setData(RBTNode* nodePtr)
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
string RBTNode::getData()
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
	
	//get the colour of the node
        str.append("[");
        str.append(getColour());
	str.append("] \n");
        
        return str;
     
        /*string recStr = "";
    
    cout << idNo << " " << fname << " " << lname << " " << destination << " " << season << " " << booking << "[" << getColour() << "]" << "\n"; //"YOU need to write that function which appends all the fields to recStr\n";
    
    /***** Enter the code here ****/
    /*
    recStr.append("[");
	if(left ==NULL)
	  recStr.append("NULL");
	else
	recStr.append(to_string(left->getID()));
	
	recStr.append(", ");
	
	if(right == NULL)
	  recStr.append("NULL");
	else
	recStr.append(to_string(right->getID()));
	recStr.append("]\t");
	
	//get the colour of the node
        recStr.append("[");
        recStr.append(getColour());
	recStr.append("] \n");
    
    stringstream myRecord;
    string myRecStr = myRecord.str();
    recStr.append(myRecStr);
    recStr.append(getColour());
    
    return recStr;*/
    
    }
    
//****************************************************************************
//                              END OF NODES CLASS
//****************************************************************************
    
//*******************************************************************************
//                              RBT ADT Class
//*******************************************************************************
class RBT
    {
        private:
            RBTNode* root;
    
            // Utility functions
            void    rotateLeft( RBTNode* );
            void    rotateRight(RBTNode* );
            void    fixUp(RBTNode* );
            string  inOrderHelper(RBTNode* );
            string  preOrderHelper(RBTNode* );
            string  postOrderHelper(RBTNode* );
            void    deleteNode(RBTNode* );
            //RBTNode* findNode(int );
            RBTNode* getMinimum(RBTNode *);
            RBTNode* getSuccessor(RBTNode *);
    
        public:
            // Constructor function
            RBT(){ root = NULL;}
    
            // Mutator functions
            void emptyRBTree(){root = NULL;}
            void insert(int, string, string, string, string, string);
            string remove(int idNo);
    
            // Accessor functions
            RBTNode* getRoot(){ return root;}
            string inOrder();
            string preOrder();
            string postOrder();
            string showLevels();
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
                if  (ptr->getID() == idNo)        // Found it!
                    {
                        return ptr;
                    }
            
                if (idNo < ptr->getID() )
                    ptr = ptr->left;
                else 
                    ptr = ptr->right;
            }
    
        return NULL;            // Tree is empty OR did not find it
	}





void RBT::insert(int val, string a, string b, string c, string d, string e)
	{
    
        RBTNode* newnode = new RBTNode(val, a, b, c, d, e);      // Create the new node
        
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
                        
                        if ( newnode->getData() < current->getData() )
                            current = current->left;
                        else
                            current = current->right;
                    }
            
                newnode->parent = ancestor;
                
                if ( newnode->getData() < ancestor->getData() )
                    ancestor->left = newnode;
                else
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




string RBT::remove(int val)
    {
        RBTNode* markedNode = findNode(val);
        string str;
	if(markedNode == NULL)//if the Client ID wasn't found
	{
	 str = "Not a valid ID number"; 
	}
	
	else//if the Client ID was found
	{
	  str = markedNode ->getData();
        deleteNode(markedNode);
    }
    
    return str;
    }




void RBT::deleteNode(RBTNode* node2Zap)
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
                    node2Zap->setID(successor->getID());

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
            
                str.append( (ptr->getData()) );
                //str.append( "  ");
            
                str.append( inOrderHelper(ptr->right) );
              }
		return str;
	}




string RBT::preOrderHelper(RBTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( (ptr->getData()) );
                //str.append( "  ");
            
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
            
                str.append( (ptr->getData()) );
                //str.append( "  ");
              }
		return str;
	}




string RBT::inOrder()
	{
		return inOrderHelper(root);
	}




string RBT::preOrder()
    {
        return preOrderHelper(root);
    }




string RBT::postOrder()
    {
        return postOrderHelper(root);
    }




string RBT::showLevels()
    {
        vector <RBTNode*> listA;
        vector <RBTNode*> listB;
    
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
                        str.append( listA[x]->getData() );
                        str.append("{");
                        str.append( listA[x]->getColour());
                        str.append("} \t");
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
    }



#endif /* defined(RBTREE_H) */
