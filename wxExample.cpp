/************************************************************************************
 *  Step 1: Always include the header file wx.h					    
 *************************************************************************************/
#include <wx/wx.h>



//Inclusion of all Linked List ADT headers
//#include <queue.h>
//#include <pQueue.h>
//#include <deque.h>
//#include <stack.h>
/************************************************************************************
 *  Step 2: Name an inherited application class from wxApp and declare it with 
 *	  the function to execute the program				    
 *************************************************************************************/
class MyApp: public wxApp
    {
        virtual bool OnInit();
    };



/************************************************************************************
 *   Step 3: Declare the inherited main frame class from wxFrame. In this class 
 *	   also will ALL the events handlers be declared    
 *************************************************************************************/
class MyFrame: public wxFrame
{
    private:
        DECLARE_EVENT_TABLE() //To declare events items
    
    public:
        MyFrame(const wxString& title, const wxPoint& pos, 
                const wxSize& size);
        
        void OnQuit(wxCommandEvent& event); 	//handle for Quit function
        void OnAbout(wxCommandEvent& event); 	//handle for About function
        void OnHelp(wxCommandEvent& event); 	//handle for Help function
        void OnOpenFile(wxCommandEvent& event); 	//handle for Quit function
        void OnCreateAvl(wxCommandEvent& event);  //handle for 'Create AVL' function
        void OnCreateBst(wxCommandEvent& event);  //handle for 'Create BST' function
        void OnCreateDeque(wxCommandEvent& event);  //handle for 'Create Deque' function
        void OnCreateHeap(wxCommandEvent& event);  //handle for 'Create Heap' function
        void OnCreatePQ(wxCommandEvent& event);  //handle for 'Create Priority Queue' function
        void OnCreateQueue(wxCommandEvent& event); 	//handle for 'Create Queue' function
        void OnCreateRbt(wxCommandEvent& event); 	//handle for 'Create RBT' function
        void OnCreateSet(wxCommandEvent& event); 	//handle for 'Create Set' function
        void OnCreateSplay(wxCommandEvent& event); 	//handle for 'Create Splay' function
        void OnCreateStack(wxCommandEvent& event); 	//handle for 'Create Stack' function
        void OnAddDataQ(wxCommandEvent& event);  //handle for 'Add Data' Queue function
        void OnAddDataPQ(wxCommandEvent& event);  //handle for 'Add Data' pQueue function
        void OnAddDataBST(wxCommandEvent& event);  //handle for 'Add Data' BST function
        void OnAddDataAVL(wxCommandEvent& event);  //handle for 'Add Data' AVL function
        void OnAddDataH(wxCommandEvent& event);  //handle for 'Add Data' Heap Tree function
        void OnAddDataRBT(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnAddDataSp(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnAddDataSet(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnAddHead(wxCommandEvent& event);  //hanle for 'Add Head' function
        void OnAddTail(wxCommandEvent& event);  //handle for 'Add Tail' function
        void OnDispAllQ(wxCommandEvent& event);  //handle for 'Display All' function
        void OnDispAllDQ(wxCommandEvent& event);  //handle for 'Display All' function
        void OnDispAllPQ(wxCommandEvent& event);  //handle for 'Display All' function
        void OnDispAllSt(wxCommandEvent& event);  //handle for 'Display All' function
        void OnDispAllH(wxCommandEvent& event);  //handle for 'Display All' function for Heap
        void OnDispSetA(wxCommandEvent& event);  //handle for 'Display SetA' function
        void OnDispSetB(wxCommandEvent& event);  //handle for 'Display SetB' function
        void OnDispInter(wxCommandEvent& event);  //handle for 'Display Intersection' function
        void OnDispUnion(wxCommandEvent& event);  //handle for 'Display Union' function
        void OnShowHeadQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowHeadDQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowHeadPQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowTailQ(wxCommandEvent& event);  //handle for show tail of Queue function
        void OnShowTailDQ(wxCommandEvent& event);  //handle for show tail of Queue function
        void OnShowTailPQ(wxCommandEvent& event);  //handle for show tail of Queue function
        void OnDequeueQ(wxCommandEvent& event);  //handle for 'Dequeue' for Queue function
        void OnDequeuePQ(wxCommandEvent& event);  //handle for 'Dequeue' for Dequeue function
        void OnDequeueH(wxCommandEvent& event);  //handle for 'Dequeue Head' function
        void OnDequeueT(wxCommandEvent& event);  //handle for 'Dequeue Tail' function
        void OnDelDataBST(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnDelDataAVL(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnDelDataH(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnDelDataRBT(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnDelDataSp(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnDelSetA(wxCommandEvent& event);  //handle for 'Delete from Set A' function
        void OnDelSetB(wxCommandEvent& event);  //handle for 'Delete from Set B' function
        void OnPush(wxCommandEvent& event);  //handle for 'Push' function
        void OnPop(wxCommandEvent& event);  //handle for 'Pop' function
        void OnHeapSort(wxCommandEvent& event);  //handle for 'Heap Sort' function
        void OnInOrderBST(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnInOrderAVL(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnInOrderRBT(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnInOrderSp(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnPreOrderBST(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPreOrderAVL(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPreOrderRBT(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPreOrderSp(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPostOrderBST(wxCommandEvent& event);  //handle for 'Postorder' function
        void OnPostOrderAVL(wxCommandEvent& event);  //handle for 'Postorder' function
        void OnPostOrderRBT(wxCommandEvent& event);  //handle for 'Postorder' function
        void OnPostOrderSp(wxCommandEvent& event);  //handle for 'Postorder' function
                
    };



/************************************************************************************
 *  Step 4. Declare the compiler directives				    
 *************************************************************************************/
DECLARE_APP(MyApp)		// Declare Application class
IMPLEMENT_APP(MyApp)		// Create Application class object


enum
        {
            ID_Quit = wxID_HIGHEST + 1,
            ID_About,
            ID_Help,
            ID_OpenFile = 2,
            ID_CreateAvl,
            ID_CreateBst,
            ID_CreateDeque,
            ID_CreateHeap,
            ID_CreatePQ,
            ID_CreateQueue,
            ID_CreateRbt,
            ID_CreateSet,
            ID_CreateSplay,
            ID_CreateStack,
            ID_AddDataQ,
            ID_AddDataPQ,
            ID_AddDataBST,
            ID_AddDataAVL,
            ID_AddDataH,
            ID_AddDataRBT,
            ID_AddDataSp,
            ID_AddDataSet,
            ID_AddHead,
            ID_AddTail,
            ID_DispAllQ,
            ID_DispAllDQ,
            ID_DispAllPQ,
            ID_DispAllSt,
            ID_DispAllH,
            ID_DispSetA,
            ID_DispSetB,
            ID_DispInter,
            ID_DispUnion,
            ID_ShowHeadQ,
            ID_ShowHeadDQ,
            ID_ShowHeadPQ,
            ID_ShowTailQ,
            ID_ShowTailDQ,
            ID_ShowTailPQ,
            ID_DequeueQ,
            ID_DequeuePQ,
            ID_DequeueH,
            ID_DequeueT,
            ID_DelDataBST,
            ID_DelDataAVL,
            ID_DelDataH,
            ID_DelDataRBT,
            ID_DelDataSp,
            ID_DelSetA,
            ID_DelSetB,
            ID_Push,
            ID_Pop,
            ID_HeapSort,
            ID_InOrderBST,
            ID_InOrderAVL,
            ID_InOrderRBT,
            ID_InOrderSp,
            ID_PreOrderBST,
            ID_PreOrderAVL,
            ID_PreOrderRBT,
            ID_PreOrderSp,
            ID_PostOrderBST,
            ID_PostOrderAVL,
            ID_PostOrderRBT,
            ID_PostOrderSp,
        };

BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
        EVT_MENU ( ID_Quit, MyFrame::OnQuit )
        EVT_MENU ( ID_About, MyFrame::OnAbout )
        EVT_MENU ( ID_Help, MyFrame::OnHelp )
        EVT_MENU ( ID_OpenFile, MyFrame::OnOpenFile )
        EVT_MENU ( ID_CreateAvl, MyFrame::OnCreateAvl )
        EVT_MENU ( ID_CreateBst, MyFrame::OnCreateBst )
        EVT_MENU ( ID_CreateDeque, MyFrame::OnCreateDeque )
        EVT_MENU ( ID_CreateHeap, MyFrame::OnCreateHeap )
        EVT_MENU ( ID_CreatePQ, MyFrame::OnCreatePQ )
        EVT_MENU ( ID_CreateQueue, MyFrame::OnCreateQueue )
        EVT_MENU ( ID_CreateRbt, MyFrame::OnCreateRbt )
        EVT_MENU ( ID_CreateSet, MyFrame::OnCreateSet )
        EVT_MENU ( ID_CreateSplay, MyFrame::OnCreateSplay )
        EVT_MENU ( ID_CreateStack, MyFrame::OnCreateStack )
        EVT_MENU ( ID_AddDataQ, MyFrame::OnAddDataQ )
        EVT_MENU ( ID_AddDataPQ, MyFrame::OnAddDataPQ )
        EVT_MENU ( ID_AddDataBST, MyFrame::OnAddDataBST )
        EVT_MENU ( ID_AddDataAVL, MyFrame::OnAddDataAVL )
        EVT_MENU ( ID_AddDataH, MyFrame::OnAddDataH )
        EVT_MENU ( ID_AddDataRBT, MyFrame::OnAddDataRBT )
        EVT_MENU ( ID_AddDataSp, MyFrame::OnAddDataSp )
        EVT_MENU ( ID_AddDataSet, MyFrame::OnAddDataSet )
        EVT_MENU ( ID_AddHead, MyFrame::OnAddHead )
        EVT_MENU ( ID_AddTail, MyFrame::OnAddTail )
        EVT_MENU ( ID_DispSetA, MyFrame::OnDispSetA )
        EVT_MENU ( ID_DispSetB, MyFrame::OnDispSetB )
        EVT_MENU ( ID_DispInter, MyFrame::OnDispInter )
        EVT_MENU ( ID_DispUnion, MyFrame::OnDispUnion )
        EVT_MENU ( ID_DispAllQ, MyFrame::OnDispAllQ )
        EVT_MENU ( ID_DispAllDQ, MyFrame::OnDispAllDQ )
        EVT_MENU ( ID_DispAllPQ, MyFrame::OnDispAllPQ )
        EVT_MENU ( ID_DispAllSt, MyFrame::OnDispAllSt )
        EVT_MENU ( ID_DispAllH, MyFrame::OnDispAllH )
        EVT_MENU ( ID_ShowHeadQ, MyFrame::OnShowHeadQ )
        EVT_MENU ( ID_ShowHeadDQ, MyFrame::OnShowHeadDQ )
        EVT_MENU ( ID_ShowHeadPQ, MyFrame::OnShowHeadPQ )
        EVT_MENU ( ID_ShowTailQ, MyFrame::OnShowTailQ )
        EVT_MENU ( ID_ShowTailDQ, MyFrame::OnShowTailDQ )
        EVT_MENU ( ID_ShowTailPQ, MyFrame::OnShowTailPQ )
        EVT_MENU ( ID_DequeueQ, MyFrame::OnDequeueQ )
        EVT_MENU ( ID_DequeuePQ, MyFrame::OnDequeuePQ )
        EVT_MENU ( ID_DequeueH, MyFrame::OnDequeueH )
        EVT_MENU ( ID_DequeueT, MyFrame::OnDequeueT )
        EVT_MENU ( ID_DelDataBST, MyFrame::OnDelDataBST )
        EVT_MENU ( ID_DelDataAVL, MyFrame::OnDelDataAVL )
        EVT_MENU ( ID_DelDataH, MyFrame::OnDelDataH )
        EVT_MENU ( ID_DelDataRBT, MyFrame::OnDelDataRBT )
        EVT_MENU ( ID_DelDataSp, MyFrame::OnDelDataSp )
        EVT_MENU ( ID_DelSetA, MyFrame::OnDelSetA )
        EVT_MENU ( ID_DelSetB, MyFrame::OnDelSetB )
        EVT_MENU ( ID_Push, MyFrame::OnPush )
        EVT_MENU ( ID_Pop, MyFrame::OnPop )
        EVT_MENU ( ID_HeapSort, MyFrame::OnHeapSort )
        EVT_MENU ( ID_InOrderBST, MyFrame::OnInOrderBST )
        EVT_MENU ( ID_InOrderAVL, MyFrame::OnInOrderAVL )
        EVT_MENU ( ID_InOrderRBT, MyFrame::OnInOrderRBT )
        EVT_MENU ( ID_InOrderSp, MyFrame::OnInOrderSp )
        EVT_MENU ( ID_PreOrderBST, MyFrame::OnPreOrderBST )
        EVT_MENU ( ID_PreOrderAVL, MyFrame::OnPreOrderAVL)
        EVT_MENU ( ID_PreOrderRBT, MyFrame::OnPreOrderRBT )
        EVT_MENU ( ID_PreOrderSp, MyFrame::OnPreOrderSp )
        EVT_MENU ( ID_PostOrderBST, MyFrame::OnPostOrderBST )
        EVT_MENU ( ID_PostOrderAVL, MyFrame::OnPostOrderAVL )
        EVT_MENU ( ID_PostOrderRBT, MyFrame::OnPostOrderRBT )
        EVT_MENU ( ID_PostOrderSp, MyFrame::OnPostOrderSp )
END_EVENT_TABLE () 


/************************************************************************************
 *  Step 5.  Define the Application class function to initialize the application
 *************************************************************************************/
bool MyApp::OnInit()
    {
        // Create the main application window
        MyFrame *frame = new MyFrame( wxT("COMP2611-Pelican Travels Database"), wxPoint(50,50), 
                                      wxSize(900,900) );
    
        // Display the window
        frame->Show(TRUE);
    
        SetTopWindow(frame);
    
        return TRUE;
    
    }



/************************************************************************************
 *  Step 6:   Define the Constructor functions for the Frame class
 *************************************************************************************/
MyFrame::MyFrame ( const wxString& title, const wxPoint& pos, const wxSize& size) : 
                    wxFrame((wxFrame *)NULL, -1, title, pos, size)
    {
        // Set the frame icon - optional
        SetIcon(wxIcon(wxT("uwiIcon.xpm")));
    
        // Create a "File" main-menu item
        wxMenu *menuFile = new wxMenu;
        menuFile->Append( ID_OpenFile, wxT("&Open File") );
        //menuFile->Append( ID_OpenFile, wxT("&Open File") );
        //menuFile->Append( ID_OpenFile, wxT("&Open File") );
        
        // Create a "Display File" main-menu item
        wxMenu *menuDispFile = new wxMenu;
        
        // Create a "Queue" main-menu item
        wxMenu *menuQueue = new wxMenu;
         menuQueue->Append( ID_CreateQueue, wxT("&Create Queue") );
         menuQueue->Append( ID_AddDataQ, wxT("&Add Data") );
         menuQueue->Append( ID_DispAllQ, wxT("&Display All") );
         menuQueue->Append( ID_ShowHeadQ, wxT("&Show Head") );
         menuQueue->Append( ID_ShowTailQ, wxT("&Show Tail") );
         menuQueue->Append( ID_DequeueQ, wxT("&Dequeue") );
         
        // Create a "Priority Queue" main-menu item
        wxMenu *menuPQueue = new wxMenu;
         menuPQueue->Append( ID_CreatePQ, wxT("&Create PQ") );
         menuPQueue->Append( ID_AddDataPQ, wxT("&Add Data") );
         menuPQueue->Append( ID_DispAllPQ, wxT("&Display All") );
         menuPQueue->Append( ID_ShowHeadPQ, wxT("&Show Head") );
         menuPQueue->Append( ID_ShowTailPQ, wxT("&Show Tail") );
         menuPQueue->Append( ID_DequeuePQ, wxT("&Dequeue") );
        
        // Create a "Double-ended Queue" main-menu item
        wxMenu *menuDeQue = new wxMenu;
        menuDeQue->Append( ID_CreateDeque, wxT("&Create Deque") );
        menuDeQue->Append( ID_AddHead, wxT("&Add Head") );
        menuDeQue->Append( ID_AddTail, wxT("&Add Tail") );
        menuDeQue->Append( ID_DispAllDQ, wxT("&Display All") );
        menuDeQue->Append( ID_ShowHeadDQ, wxT("&Show Head") );
        menuDeQue->Append( ID_ShowTailDQ, wxT("&Show Tail") );
        menuDeQue->Append( ID_DequeueH, wxT("&Dequeue Head") );
        menuDeQue->Append( ID_DequeueT, wxT("&Dequeue Tail") );
         
        
        // Create a "Stack" main-menu item
        wxMenu *menuStack = new wxMenu;
        menuStack->Append( ID_CreateStack, wxT("&Create Stack") );
        menuStack->Append( ID_Pop, wxT("&Pop") );
        menuStack->Append( ID_Push, wxT("&Push") );
        menuStack->Append( ID_DispAllSt, wxT("&Display All") );
        
        // Create a "Binary Search Tree" main-menu item
        wxMenu *menuBST = new wxMenu;
        menuBST->Append( ID_CreateBst, wxT("&Create BST") );
        menuBST->Append( ID_AddDataBST, wxT("&Add Data") );
        menuBST->Append( ID_DelDataBST, wxT("&Delete Data") );
        menuBST->Append( ID_InOrderBST, wxT("&Inorder") );
        menuBST->Append( ID_PreOrderBST, wxT("&Preorder") );
        menuBST->Append( ID_PostOrderBST, wxT("&Postorder") );
        
        // Create a "AVL Tree" main-menu item
        wxMenu *menuAvlTree = new wxMenu;
        menuAvlTree->Append( ID_CreateAvl, wxT("&Create AVL") );
        menuAvlTree->Append( ID_AddDataAVL, wxT("&Add Data") );
        menuAvlTree->Append( ID_DelDataAVL, wxT("&Delete Data") );
        menuAvlTree->Append( ID_InOrderAVL, wxT("&Inorder") );
        menuAvlTree->Append( ID_PreOrderAVL, wxT("&Preorder") );
        menuAvlTree->Append( ID_PostOrderAVL, wxT("&Postorder") );
        
        // Create a "Binary Heap Tree" main-menu item
        wxMenu *menuBhTree = new wxMenu;
        menuBhTree->Append( ID_CreateHeap, wxT("&Create Heap") );
        menuBhTree->Append( ID_AddDataH, wxT("&Add Data") );
        menuBhTree->Append( ID_DelDataH, wxT("&Delete Data") );
        menuBhTree->Append( ID_DispAllH, wxT("&Display All") );
        menuBhTree->Append( ID_HeapSort, wxT("&Heap Sort") );
        
        // Create a "Red-Black Tree" main-menu item
        wxMenu *menuRBTree = new wxMenu;
        menuRBTree->Append( ID_CreateRbt, wxT("&Create RBT") );
        menuRBTree->Append( ID_AddDataRBT, wxT("&Add Data") );
        menuRBTree->Append( ID_DelDataRBT, wxT("&Delete Data") );
        menuRBTree->Append( ID_InOrderRBT, wxT("&Inorder") );
        menuRBTree->Append( ID_PreOrderRBT, wxT("&Preorder") );
        menuRBTree->Append( ID_PostOrderRBT, wxT("&Postorder") );
        
        // Create a "Splay Tree" main-menu item
        wxMenu *menuSpTree = new wxMenu;
        menuSpTree->Append( ID_CreateSplay, wxT("&Create Splay") );
        menuSpTree->Append( ID_AddDataSp, wxT("&Add Data") );
        menuSpTree->Append( ID_DelDataSp, wxT("&Delete Data") );
        menuSpTree->Append( ID_InOrderSp, wxT("&Inorder") );
        menuSpTree->Append( ID_PreOrderSp, wxT("&Preorder") );
        menuSpTree->Append( ID_PostOrderSp, wxT("&Postorder") );
        
        // Create a "Sets" main-menu item
        wxMenu *menuSets = new wxMenu;
        menuSets->Append( ID_CreateSet, wxT("&Create Sets") );
        menuSets->Append( ID_AddDataSet, wxT("&Add Data") );
        menuSets->Append( ID_DispSetA, wxT("&Display SetA") );
        menuSets->Append( ID_DispSetB, wxT("&Display SetB") );
        menuSets->Append( ID_DispInter, wxT("&Display Intersection") );
        menuSets->Append( ID_DispUnion, wxT("&Display Union") );
        menuSets->Append( ID_DelSetA, wxT("&Delete from SetA") );
        menuSets->Append( ID_DelSetB, wxT("&Delete from SetB") );
        //menuFile->AppendSeparator();
        //menuFile->Append( ID_Quit, wxT("E&xit") );
        
        //Append menu items (About and Exit) to the "File" menu item
        menuFile->Append( ID_About, wxT("&About...") );
        menuFile->AppendSeparator();
        menuFile->Append( ID_Quit, wxT("E&xit") );
    
        //Create a "Help" main-menu item
        wxMenu *menuHelp = new wxMenu;
    
        //Append "Help" sub-menu item to it 
        menuHelp->Append(ID_Help, wxT("&Help..."));
    
        //Append "About" sub-menu item to it 
        menuHelp->Append(ID_About, wxT("&About"));
    
        //Create a Main menu bar
        wxMenuBar *menuBar = new wxMenuBar;
    
        //Append the main menu items ("File" and "Help") to it
        menuBar->Append( menuFile, wxT("&File") );
        menuBar->Append( menuDispFile, wxT("&Display File") );
        menuBar->Append( menuQueue, wxT("Queue"));
        menuBar->Append( menuDeQue, wxT("Deque"));
        menuBar->Append( menuPQueue, wxT("Priority Queue"));
        menuBar->Append( menuStack, wxT("Stack"));
        menuBar->Append( menuBST, wxT("BST"));
        menuBar->Append( menuAvlTree, wxT("AVL Tree"));
        menuBar->Append( menuBhTree, wxT("Heap"));
        menuBar->Append( menuRBTree, wxT("RB Tree"));
        menuBar->Append( menuSpTree, wxT("Splay"));
        menuBar->Append( menuSets, wxT("Set"));
        menuBar->Append( menuHelp, wxT("&Help") );
        
        // ... and now... attach this main menu bar to the frame
        SetMenuBar( menuBar );
    
        // Create a status bar just for fun
        CreateStatusBar(3);
    
        //Put something in the first section of the status bar
        SetStatusText( wxT("Ready...") );
    
        //Put something in the second section of the status bar
        SetStatusText( wxT("Assignment: Alec Gilkes"), 1 );
    
        //Put something in the third section of the status bar
        SetStatusText( wxT("415002420"), 2 );
    }


/************************************************************************************
 *  Step 7:  Define member functions for the Frame class
 *************************************************************************************/

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))   //
    {
        Close ( TRUE );
    }



void MyFrame::OnAbout ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxString msg;
    
        msg.Printf(wxT("Hello and welcome to %s"), wxVERSION_STRING);
    
        wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
    }


void MyFrame::OnHelp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxMessageBox(wxT("HELP!!!"), wxT("Minimal Help"), 
                     wxOK | wxCANCEL | wxICON_QUESTION, this);
    }
    
void MyFrame::OnOpenFile ( wxCommandEvent& event) //WXUNUSED ( event ) )
    {
        //wxLogMessage("Hello from ALEC!");
    }
    
void MyFrame::OnCreateAvl ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //ONLY FALL TRAVELS ARE REQUIRED
        
        //int id;
        //string fname;
        //string sname;
        //string location;
        //string season;
        //string book;
        
       // char comma;
    }
    
void MyFrame::OnCreateBst ( wxCommandEvent& WXUNUSED ( event ) )    //5
    {
     
    }
    
void MyFrame::OnCreateDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {
    
    }
    
void MyFrame::OnCreateHeap ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //SUMMER TRAVELS ONLY
      
    }
    
void MyFrame::OnCreatePQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
//QUEUE FUNCTION DEFINITIONS DECLARATION
void MyFrame::OnCreateQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnCreateRbt ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //ONLY WINTER SEASONS NECESSARY
        
        
    }
    
void MyFrame::OnCreateSet ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnCreateSplay ( wxCommandEvent& WXUNUSED ( event ) )  //12
    {
        
    }
    
void MyFrame::OnCreateStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //ONLY THE SPRING RECORDS ARE REQUIRED

        
    }
    
void MyFrame::OnAddDataQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataH ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataSp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddDataSet ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddHead ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnAddTail ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispAllQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispAllDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispAllPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispAllSt ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispAllH ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
void MyFrame::OnDispSetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispSetB ( wxCommandEvent& WXUNUSED ( event ) )     //19
    {
        
    }
    
void MyFrame::OnDispInter ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispUnion ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowHeadQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowHeadDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowHeadPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowTailQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowTailDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowTailPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDequeueQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDequeuePQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDequeueH ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDequeueT ( wxCommandEvent& WXUNUSED ( event ) ) //26
    {
        
    }
    
void MyFrame::OnDelDataBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDelDataAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDelDataH ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDelDataRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDelDataSp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDelSetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDelSetB ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPush ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPop ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnHeapSort ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnInOrderBST ( wxCommandEvent& WXUNUSED ( event ) )      //33
    {
        
    }
    
void MyFrame::OnInOrderAVL ( wxCommandEvent& WXUNUSED ( event ) )      
    {
        
    }
    
void MyFrame::OnInOrderRBT ( wxCommandEvent& WXUNUSED ( event ) )     
    {
        
    }
    
void MyFrame::OnInOrderSp ( wxCommandEvent& WXUNUSED ( event ) )   
    {
        
    }
    
void MyFrame::OnPreOrderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPreOrderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPreOrderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPreOrderSp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPostOrderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPostOrderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPostOrderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPostOrderSp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
    

//g++ wxExample.cpp -o example `wx-config --libs --cxxflags`
//./example
