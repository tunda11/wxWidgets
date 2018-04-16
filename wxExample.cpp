//Programmed by: Alec Gilkes

/************************************************************************************
 *  Step 1: Always include the header file wx.h					    
 *************************************************************************************/

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/listbox.h>
#include <wx/numdlg.h>
#include <wx/textdlg.h>
#include <wx/platinfo.h>
#include <wx/numdlg.h>
#endif


#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "DataDialog.h"
#include "DeleteDialog.h"

using namespace std;

string to_string(int);
string strip(string);
string makeRecord(int, string, string, string, string, string);


// the ADTs header files
#include "queueFile.h"
#include "pQueueFile.h"
#include "dequeFile.h"
#include "stackFile.h"
#include "BSTree.h"
#include "AVLTree.h"
#include "BinHeap.h"
#include "RBTree.h"
#include "Splay.h"
#include "Sets.h"

//Global pointers for the ADT containers
queue* myqueue = new queue(); 
stack* mystack = new stack();
pQueue* mypQueue = new pQueue();
deque* mydeque = new deque();
BST* myBST = new BST();
AVL* myAVL = new AVL();
BinHeap* myBH = new BinHeap();
RBT* myRBT= new RBT();
SplayTree* mySplay = new SplayTree();
Set* setA = new Set();
Set* setB = new Set();
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
        

        void OnAbout(wxCommandEvent& event); 	//handle for About function
        void OnHelp(wxCommandEvent& event); 	//handle for Help function
        
        
        
        //File Events
        void OnOpenFile(wxCommandEvent& event); 	//handle for Quit function
        void OnSaveFile(wxCommandEvent& event);
        void OnSaveAsFile(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event); 	//handle for Quit function
             
        
        //Queue Events
        void OnCreateQueue(wxCommandEvent& event); 	//handle for 'Create Queue' function
        void OnDequeueQ(wxCommandEvent& event);  //handle for 'Dequeue' for Queue function
        void OnAddDataQ(wxCommandEvent& event);  //handle for 'Add Data' Queue function
        void OnDispAllQ(wxCommandEvent& event);  //handle for 'Display All' function
        void OnShowHeadQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowTailQ(wxCommandEvent& event);  //handle for show tail of Queue function
        
        
        //Priority Queue Events
        void OnCreatePQ(wxCommandEvent& event);  //handle for 'Create Priority Queue' function
        void OnAddDataPQ(wxCommandEvent& event);  //handle for 'Add Data' pQueue function
        void OnDispAllPQ(wxCommandEvent& event);  //handle for 'Display All' pQueue function
        void OnShowHeadPQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowTailPQ(wxCommandEvent& event);  //handle for show tail of Queue function
        void OnDequeuePQ(wxCommandEvent& event);  //handle for 'Dequeue' for Dequeue function
        
        
        //Double Ended Queue
        void OnCreateDeque(wxCommandEvent& event);  //handle for 'Create Deque' function
        void OnAddHead(wxCommandEvent& event);  //hanle for 'Add Head' function
        void OnAddTail(wxCommandEvent& event);  //handle for 'Add Tail' function
        void OnDispAllDQ(wxCommandEvent& event);  //handle for 'Display All' function
        void OnShowHeadDQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowTailDQ(wxCommandEvent& event);  //handle for show tail of Queue function
        void OnDequeueH(wxCommandEvent& event);  //handle for 'Dequeue Head' function
        void OnDequeueT(wxCommandEvent& event);  //handle for 'Dequeue Tail' function
        
        
        //Stack Events
        void OnCreateStack(wxCommandEvent& event); 	//handle for 'Create Stack' function
        void OnPush(wxCommandEvent& event);  //handle for 'Push' function
        void OnPop(wxCommandEvent& event);  //handle for 'Pop' function
        void OnDispAllSt(wxCommandEvent& event);  //handle for 'Display All' function for Stack
        
        //BST Events
        void OnCreateBst(wxCommandEvent& event);  //handle for 'Create BST' function
        void OnAddDataBST(wxCommandEvent& event);  //handle for 'Add Data' BST function
        void OnDelDataBST(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnInOrderBST(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnPreOrderBST(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPostOrderBST(wxCommandEvent& event);  //handle for 'Postorder' function
        
        
        
        //AVL Events
        void OnCreateAvl(wxCommandEvent& event);  //handle for 'Create AVL' function
        void OnAddDataAVL(wxCommandEvent& event);  //handle for 'Add Data' AVL function
        void OnDelDataAVL(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnInOrderAVL(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnPreOrderAVL(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPostOrderAVL(wxCommandEvent& event);  //handle for 'Postorder' function
        
        
        //Binary Heap Events
        void OnCreateHeap(wxCommandEvent& event);  //handle for 'Create Heap' function
        void OnAddDataH(wxCommandEvent& event);  //handle for 'Add Data' Heap Tree function
        void OnDispAllH(wxCommandEvent& event);  //handle for 'Display All' function for Heap
        void OnDelDataH(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnHeapSort(wxCommandEvent& event);  //handle for 'Heap Sort' function
        
        
        //RBT Events
        void OnCreateRbt(wxCommandEvent& event); 	//handle for 'Create RBT' function
        void OnAddDataRBT(wxCommandEvent& event);  //handle for 'Add Data' function 
        void OnDelDataRBT(wxCommandEvent& event);  //handle for 'Delete Data' function
        void OnInOrderRBT(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnPreOrderRBT(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPostOrderRBT(wxCommandEvent& event);  //handle for 'Postorder' function
        
        
        //Splay Events
        void OnCreateSplay(wxCommandEvent& event); 	//handle for 'Create Splay' function
        void OnAddDataSp(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnDelDataSp(wxCommandEvent& event);  //Splay 'Delete Data' function  
        void OnInOrderSp(wxCommandEvent& event);  //handle for 'Inorder' function
        void OnPreOrderSp(wxCommandEvent& event);  //handle for 'Preorder' function
        void OnPostOrderSp(wxCommandEvent& event);  //handle for 'Postorder' function
        
        
        //Set
        void OnCreateSet(wxCommandEvent& event); 	//handle for 'Create Set' function
        void OnAddDataSetA(wxCommandEvent& event);  //handle for 'Add Data' function     
        void OnAddDataSetB(wxCommandEvent& event);  //handle for 'Add Data' function     
        void OnDispSetA(wxCommandEvent& event);  //handle for 'Display SetA' function
        void OnDispSetB(wxCommandEvent& event);  //handle for 'Display SetB' function
        void OnDispInter(wxCommandEvent& event);  //handle for 'Display Intersection' function
        void OnDispUnion(wxCommandEvent& event);  //handle for 'Display Union' function
        void OnDelSetA(wxCommandEvent& event);  //handle for 'Delete from Set A' function
        void OnDelSetB(wxCommandEvent& event);  //handle for 'Delete from Set B' function
        
        
        //Public attributes
        wxString CurrentDocPath;
        wxTextCtrl* MainEditBox;
        wxTextCtrl* filenameTextBox;
    };



/************************************************************************************
 *  Step 4. Declare the compiler directives				    
 *************************************************************************************/
DECLARE_APP(MyApp)		// Declare Application class
IMPLEMENT_APP(MyApp)		// Create Application class object


enum
        {
            
            ID_About,
            ID_Help,
            
            //File
            ID_OpenFile,
            ID_SaveFile,
            ID_SaveAsFile,
            ID_Quit = wxID_HIGHEST + 1,
            
            
            //Queue
            ID_CreateQueue,
            ID_AddDataQ,
            ID_DispAllQ,
            ID_DequeueQ,
            ID_ShowHeadQ,
            ID_ShowTailQ,
            
            
            //Priority Queue
            ID_CreatePQ,
            ID_AddDataPQ,
            ID_DispAllPQ,
            ID_ShowHeadPQ,
            ID_ShowTailPQ,
            ID_DequeuePQ,
            
            
            //Double Ended Queue
            ID_CreateDeque,
            ID_AddHead,
            ID_AddTail,
            ID_DispAllDQ,
            ID_ShowHeadDQ,
            ID_ShowTailDQ,
            ID_DequeueH,
            ID_DequeueT,
            
            
            //Stack
            ID_CreateStack,
            ID_Push,
            ID_Pop,
            ID_DispAllSt,
            
            //BST
            ID_CreateBst,
            ID_AddDataBST,
            ID_DelDataBST,
            ID_InOrderBST,
            ID_PreOrderBST,
            ID_PostOrderBST,
            
            //AVLTree
            ID_CreateAvl,
            ID_AddDataAVL,
            ID_DelDataAVL,
            ID_InOrderAVL,
            ID_PreOrderAVL,
            ID_PostOrderAVL,
            
            //Heap
            ID_CreateHeap,
            ID_AddDataH,
            ID_DispAllH,
            ID_DelDataH,
            ID_HeapSort,
            
            //RBT
            ID_CreateRbt,
            ID_AddDataRBT,
            ID_DelDataRBT,
            ID_InOrderRBT,
            ID_PreOrderRBT,
            ID_PostOrderRBT,
            
            //Splay
            ID_CreateSplay,
            ID_AddDataSp,
            ID_DelDataSp,
            ID_InOrderSp,
            ID_PreOrderSp,
            ID_PostOrderSp,
            
            
            //Set
            ID_CreateSet,
            ID_AddDataSetA,
            ID_AddDataSetB,
            ID_DispSetA,
            ID_DispSetB,
            ID_DispInter,
            ID_DispUnion,
            ID_DelSetA,
            ID_DelSetB,
            
        };

BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
        
        EVT_MENU ( ID_About, MyFrame::OnAbout )
        EVT_MENU ( ID_Help, MyFrame::OnHelp )
        
        //File
        EVT_MENU ( ID_OpenFile, MyFrame::OnOpenFile )
        EVT_MENU ( ID_Quit, MyFrame::OnQuit )
        EVT_MENU ( ID_SaveFile, MyFrame::OnSaveFile )
        EVT_MENU ( ID_SaveAsFile, MyFrame::OnSaveAsFile )
        
        
        
        
        //Queue
        EVT_MENU ( ID_CreateQueue, MyFrame::OnCreateQueue )
        EVT_MENU ( ID_AddDataQ, MyFrame::OnAddDataQ )        
        EVT_MENU ( ID_DispAllQ, MyFrame::OnDispAllQ )
        EVT_MENU ( ID_ShowHeadQ, MyFrame::OnShowHeadQ )
        EVT_MENU ( ID_ShowTailQ, MyFrame::OnShowTailQ )
        EVT_MENU ( ID_DequeueQ, MyFrame::OnDequeueQ )
        
        
        //Priority Queue
        EVT_MENU ( ID_CreatePQ, MyFrame::OnCreatePQ )
        EVT_MENU ( ID_AddDataPQ, MyFrame::OnAddDataPQ )
        EVT_MENU ( ID_DispAllPQ, MyFrame::OnDispAllPQ )
        EVT_MENU ( ID_ShowHeadPQ, MyFrame::OnShowHeadPQ )
        EVT_MENU ( ID_ShowTailPQ, MyFrame::OnShowTailPQ )
        EVT_MENU ( ID_DequeuePQ, MyFrame::OnDequeuePQ )
        
        
        //Double Ended Queue
        EVT_MENU ( ID_CreateDeque, MyFrame::OnCreateDeque )
        EVT_MENU ( ID_AddHead, MyFrame::OnAddHead )
        EVT_MENU ( ID_AddTail, MyFrame::OnAddTail )
        EVT_MENU ( ID_DispAllDQ, MyFrame::OnDispAllDQ )
        EVT_MENU ( ID_ShowHeadDQ, MyFrame::OnShowHeadDQ )
        EVT_MENU ( ID_ShowTailDQ, MyFrame::OnShowTailDQ )
        EVT_MENU ( ID_DequeueH, MyFrame::OnDequeueH )
        EVT_MENU ( ID_DequeueT, MyFrame::OnDequeueT )
        
        
        //Stack
        EVT_MENU ( ID_CreateStack, MyFrame::OnCreateStack )
        EVT_MENU ( ID_Push, MyFrame::OnPush )
        EVT_MENU ( ID_Pop, MyFrame::OnPop )
        EVT_MENU ( ID_DispAllSt, MyFrame::OnDispAllSt )
        
        //BST
        EVT_MENU ( ID_CreateBst, MyFrame::OnCreateBst )
        EVT_MENU ( ID_AddDataBST, MyFrame::OnAddDataBST )
        EVT_MENU ( ID_DelDataBST, MyFrame::OnDelDataBST )
        EVT_MENU ( ID_InOrderBST, MyFrame::OnInOrderBST )
        EVT_MENU ( ID_PreOrderBST, MyFrame::OnPreOrderBST )
        EVT_MENU ( ID_PostOrderBST, MyFrame::OnPostOrderBST )
        
        //AVL
        EVT_MENU ( ID_CreateAvl, MyFrame::OnCreateAvl )
        EVT_MENU ( ID_AddDataAVL, MyFrame::OnAddDataAVL )
        EVT_MENU ( ID_DelDataAVL, MyFrame::OnDelDataAVL )
        EVT_MENU ( ID_InOrderAVL, MyFrame::OnInOrderAVL )
        EVT_MENU ( ID_PreOrderAVL, MyFrame::OnPreOrderAVL)
        EVT_MENU ( ID_PostOrderAVL, MyFrame::OnPostOrderAVL )
         
        //Heap
        EVT_MENU ( ID_CreateHeap, MyFrame::OnCreateHeap )
        EVT_MENU ( ID_AddDataH, MyFrame::OnAddDataH )
        EVT_MENU ( ID_DispAllH, MyFrame::OnDispAllH )
        EVT_MENU ( ID_DelDataH, MyFrame::OnDelDataH )
        EVT_MENU ( ID_HeapSort, MyFrame::OnHeapSort )
        
        //RBT
        EVT_MENU ( ID_CreateRbt, MyFrame::OnCreateRbt )
        EVT_MENU ( ID_AddDataRBT, MyFrame::OnAddDataRBT )
        EVT_MENU ( ID_DelDataRBT, MyFrame::OnDelDataRBT )
        EVT_MENU ( ID_InOrderRBT, MyFrame::OnInOrderRBT )
        EVT_MENU ( ID_PreOrderRBT, MyFrame::OnPreOrderRBT )
        EVT_MENU ( ID_PostOrderRBT, MyFrame::OnPostOrderRBT )
        
        //Splay
        EVT_MENU ( ID_CreateSplay, MyFrame::OnCreateSplay )
        EVT_MENU ( ID_AddDataSp, MyFrame::OnAddDataSp )
        EVT_MENU ( ID_DelDataSp, MyFrame::OnDelDataSp )
        EVT_MENU ( ID_InOrderSp, MyFrame::OnInOrderSp )
        EVT_MENU ( ID_PreOrderSp, MyFrame::OnPreOrderSp )
        EVT_MENU ( ID_PostOrderSp, MyFrame::OnPostOrderSp )
        
        //Set
        EVT_MENU ( ID_CreateSet, MyFrame::OnCreateSet )
        EVT_MENU ( ID_AddDataSetA, MyFrame::OnAddDataSetA )
        EVT_MENU ( ID_AddDataSetB, MyFrame::OnAddDataSetB )
        EVT_MENU ( ID_DispSetA, MyFrame::OnDispSetA )
        EVT_MENU ( ID_DispSetB, MyFrame::OnDispSetB )
        EVT_MENU ( ID_DispInter, MyFrame::OnDispInter )
        EVT_MENU ( ID_DispUnion, MyFrame::OnDispUnion )
        EVT_MENU ( ID_DelSetA, MyFrame::OnDelSetA )
        EVT_MENU ( ID_DelSetB, MyFrame::OnDelSetB )
        
        
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
        menuFile->Append( ID_SaveFile, wxT("&Save File") );
        menuFile->Append( ID_SaveAsFile, wxT("&Save As") );
        
        // Create a "Display File" main-menu item
        wxMenu *menuDispFile = new wxMenu;
        
        // Create a "Queue" main-menu item
        wxMenu *menuQueue = new wxMenu;
         menuQueue->Append( ID_CreateQueue, wxT("&Create Queue"), wxT("&Create Queue") );
         menuQueue->Append( ID_AddDataQ, wxT("&Add Data"), wxT("&Add Data") );
         menuQueue->Append( ID_DispAllQ, wxT("&Display All"), wxT("&Display All") );
         menuQueue->Append( ID_ShowHeadQ, wxT("&Show Head"), wxT("&Show Head"));
         menuQueue->Append( ID_ShowTailQ, wxT("&Show Tail"), wxT("&Show Tail"));
         menuQueue->Append( ID_DequeueQ, wxT("&Dequeue"), wxT("&Dequeue"));
         
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
        menuSets->Append( ID_AddDataSetA, wxT("&Add Data A") );
        menuSets->Append( ID_AddDataSetB, wxT("&Add Data B") );
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
        
        
	//Set up the panel for data display


	//Set up the panel for data display

	wxPanel  *panel = new wxPanel(this, -1);
	wxBoxSizer *vbox  = new wxBoxSizer(wxVERTICAL);		//Vertical sizer for main window
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for main window

	//Add two textboxes to the panel for data display
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for filename window
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for display window
	
	wxStaticText *fileLabel 	  = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
	wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));

	//Initialize the filename textbox window
	filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));
	
	//Initialize the display window
	MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."), 
				      wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);
				      

	//Position the labels and textboxes in the panel
	hbox1->Add(fileLabel, 0, wxRIGHT, 8);
	hbox1->Add(filenameTextBox, 1);
	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

	vbox->Add(-1, 10);
	hbox2->Add(displayLabel, 0);
	vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
	vbox->Add(-1, 10);

	hbox3->Add(MainEditBox, 1, wxEXPAND);
	vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

	vbox->Add(-1, 25);
	panel->SetSizer(vbox);

	Centre();
    }	
  
//=====================================================================
//=========== Other Support Functions =================================
//=====================================================================
string strip(string str)
    {
        // Remove preceding blanks and tabs from the string
        while (!isalpha(str[0]))
        {
            for (int x = 0; x < str.length()-1; x++)
                {
                    str[x] = str[x+1];
                }
            str[str.length()-1] = ' ';
        }
        
        // Reset the string width to 20 characters and pad it with blanks
        str.resize(20, ' ');

        return str;
    }

    
  
string makeRecord(int id, string first, string last, string place, string timeOfYear, string bookingType)
    {
        string record = "";
        
        record = to_string(id);
        record.append("\t");
        record.append(first);
        record.append("\t");
        record.append(last);
        record.append("\t");
        record.append(place);
        record.append("\t"); 
	record.append(timeOfYear);
        record.append("\t");
        record.append(bookingType);
        
        return record;
    }
  
  
  
string to_string ( int number )
    {
        string number_string = "";
        char charValue;
        int intValue = 0;
        while ( true )
            {
                intValue = number % 10;
                switch ( intValue )
                    {
                        case 0: charValue = '0'; break;
                        case 1: charValue = '1'; break;
                        case 2: charValue = '2'; break;
                        case 3: charValue = '3'; break;
                        case 4: charValue = '4'; break;
                        case 5: charValue = '5'; break;
                        case 6: charValue = '6'; break;
                        case 7: charValue = '7'; break;
                        case 8: charValue = '8'; break;
                        case 9: charValue = '9'; break;
                    }
                number -= intValue;
                number_string = charValue + number_string;
                if ( number == 0 )
                    {
                        break;
                    }
                number = number/10;
            }
        return number_string;
    }
    


/************************************************************************************
 *  Step 7:  Define member functions for the Frame class
 *************************************************************************************/

//Defining Functions for File Menu
void MyFrame::OnOpenFile ( wxCommandEvent& event) //WXUNUSED ( event ) )
    {
        // Creates a "open file" dialog with 3 file types
    	wxFileDialog *OpenDialog = new wxFileDialog( this, 
		(wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
     		(wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
               	 wxFD_OPEN, wxDefaultPosition);
        
        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
	    {
            	// Sets our current document to the file the user selected
            	CurrentDocPath = OpenDialog->GetPath();

		//Clean up filename textbox and Display file name in filename textbox 
		filenameTextBox->Clear();
		filenameTextBox->AppendText(CurrentDocPath);

        	MainEditBox->LoadFile(CurrentDocPath);   //Opens that file in the MainEditBox

        	// Set the Title
        	SetTitle(wxString(wxT("COMP2611 – Pelican Travels Database")));
	    }

    }
 
    
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))   //
    {
        Close ( TRUE );
    }

void MyFrame::OnSaveFile(wxCommandEvent& WXUNUSED(event))   //
    {
       // Save to the already-set path for the document
	MainEditBox->SaveFile(CurrentDocPath);
    }
    
void MyFrame::OnSaveAsFile(wxCommandEvent& WXUNUSED(event))   //
    {
    wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")), 
						    wxEmptyString, wxEmptyString,
						    (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
						    wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK) 	// If the user clicked "OK"
	    {
		CurrentDocPath = SaveDialog->GetPath();

		// set the path of our current document to the file the user chose to save under
		MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

		// Set the Title to reflect the file open
		SetTitle(wxString(wxT("COMP2611 – Pelican Travels Database")));
	    }
    }
    


void MyFrame::OnAbout ( wxCommandEvent& WXUNUSED ( event ) )
    {
       string str="";
	wxPlatformInfo platInfo = wxPlatformInfo ();
	wxString architecture = platInfo.GetArchName( );
	str.append("Data Structures Assignment\n Program developed by: Alec Gilkes\nID: 415002420\nSystem architecture: ");
	str.append(string(architecture.mb_str()));
	wxString wxstr(str.c_str(), wxConvUTF8);
	
	wxMessageBox(wxstr, wxT("About..."), wxOK | wxICON_INFORMATION, this);
    }


void MyFrame::OnHelp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxMessageBox(wxT("HELP!!!"), wxT("Minimal Help"), 
                     wxOK | wxCANCEL | wxICON_QUESTION, this);
    }
    

//*************************************************************************************
//                      AVL DEFINITIONS DECLARATION  
//*************************************************************************************        
void MyFrame::OnCreateAvl ( wxCommandEvent& WXUNUSED ( event ) )
    {
        // Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
	string place;
	string timeOfYear;
	string bookingType;
	string Fall = "Fall";
	char comma;
	   
        string record, heading;
        
        
	//Empty the AVL
	myAVL->purgeAVL();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
			 
 			 
                if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
			Fall = strip(Fall);
			
			if(timeOfYear == Fall)
			  {
			      record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						      
						      
			      myAVL->insertAVL(id, first, last, place, timeOfYear, bookingType);
			  
			
					      
			      wxString wxRecord(record.c_str(), wxConvUTF8);
			      MainEditBox->AppendText(wxRecord);
			      MainEditBox->AppendText(wxT("\n"));
			      
			      //Reset record variable
			      record = "";
			}
		  }
              }// End while
    }
    
void MyFrame::OnAddDataAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
	Record dataRec;
		string Fall = "Fall";
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for AVL"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Tail:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));
            Fall = strip(Fall);
                if (timeOfYear == Fall)
                {
                    MainEditBox->AppendText(getDataString(dataRec));
                }
                
			if (timeOfYear == Fall)
                {
                    mystack->push(id, first, last, place, timeOfYear, bookingType);                            
                }
                else
                {
                    MainEditBox->AppendText(wxT("Your entry must be Spring"));
                }
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box	//Destroy the dialog box
    }
    
void MyFrame::OnDelDataAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        /*
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for AVL"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			
			// ... Now send the data to the AVL
            
			string deleted = myAVL->remove(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
			}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
       */ 
    }    
    
void MyFrame::OnInOrderAVL ( wxCommandEvent& WXUNUSED ( event ) )      
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	records.append(heading);
	
	records.append(myAVL->inOrderAVL());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in AVL:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }
    
void MyFrame::OnPreOrderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	records.append(heading);
	
	records.append(myAVL->preOrderAVL());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in AVL:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }

void MyFrame::OnPostOrderAVL ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	records.append(heading);
	
	records.append(myAVL->postOrderAVL());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in AVL:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }
    
    
    
//*************************************************************************************
//                      BST DEFINITIONS DECLARATION  
//*************************************************************************************        
void MyFrame::OnCreateBst ( wxCommandEvent& WXUNUSED ( event ) )    //5
    {   // Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  fname;
        string  lname;
        string destination;
        string season;
        string booking;
	
	char comma;
	   
        string record, heading;
        
        
	//Empty the BST
	myBST->purgeBST();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, fname, ',');
                getline(infile, lname, ',');
                getline(infile, destination, ',');
                getline(infile, season, ',');
                getline(infile, booking, '\n');
			 
 			 
                if (!infile.eof())
		  {
			fname = strip(fname);
			lname  = strip(lname);
			destination = strip(destination);
			season = strip(season);
			booking = strip(booking);
			
                   
			record = makeRecord(id, fname, lname, destination, season, booking);
						
			myBST->insert(id, fname, lname, destination, season, booking);
		  
					
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        MainEditBox->AppendText(wxT("\n"));
			
			
                        //Reset record variable
                        record = "";
          }
              }// End while
     
    }
    
void MyFrame::OnAddDataBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
		Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for BST"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(myBST->find(dataRec.idNo) == NULL)//if the ClientID doesn't already exist
			{
			    MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		      
			    // Create a label for the displayed records
			    string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			    heading.append("================================================================================");
			    wxString wxheading(heading.c_str(), wxConvUTF8);
			    MainEditBox->AppendText(wxheading);
			    
			    MainEditBox->AppendText(getDataString(dataRec));

			    //   You need to disaggregate the data from dataRec to
			    //   send them to your ADTs. e.g.:
			    
			    int    id = dataRec.idNo;
			    string first = strip(string(dataRec.fname.mb_str()));
			    string last = strip(string(dataRec.lname.mb_str()));
			    string place = strip(string(dataRec.destination.mb_str()));
			    string timeOfYear = strip(string(dataRec.season.mb_str()));
			    string bookingType = strip(string(dataRec.book.mb_str()));
			    
			    
			    // ... Now send the data to the BST e.g
			    myBST->insert(id, first, last, place, timeOfYear, bookingType); 
			}
			else
			    MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate")); 
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		
        
    }
    
    
void MyFrame::OnDelDataBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for BST"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("===================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int id = dataRec.idNo;
			
			// ... Now send the data to the BST e.g  
			string deleted = myBST->remove(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);	
		    }

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
               
    }
    
void MyFrame::OnInOrderBST ( wxCommandEvent& WXUNUSED ( event ) )      //33
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
    //records.append(myBST->getDataBST());
	records.append(myBST->inOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in BST:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    
    
void MyFrame::OnPreOrderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
	records.append(myBST->preOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in BST:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }

void MyFrame::OnPostOrderBST ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("====================================================================================\n");
	records.append(heading);
	
	records.append(myBST->postOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in BST:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }

    

    
    
//*************************************************************************************
//                      BinaryHeap DEFINITIONS DECLARATION  
//*************************************************************************************        
void MyFrame::OnCreateHeap ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //SUMMER TRAVELS ONLY
      // Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
	string place;
	string timeOfYear;
	string bookingType;
	string Summer = "Summer";
	char comma;
	   
        string record, heading;
        
        
	//Empty the Heap
	myBH->purgeBH();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
			 
 			 
                if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
			Summer = strip(Summer);
			
			if(timeOfYear == Summer )
			  {
			      record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						      
						      
			      myBH->addMinHeap(id, first, last, place, timeOfYear, bookingType);
			  
			
					      
			      wxString wxRecord(record.c_str(), wxConvUTF8);
			      MainEditBox->AppendText(wxRecord);
			      MainEditBox->AppendText(wxT("\n"));
			      
			      //Reset record variable
			      record = "";
			}
		  }
              }// End while
    }
    
void MyFrame::OnAddDataH ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		string Summer = "Summer";
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Stack"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Tail:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));
            Summer = strip(Summer);
                if (timeOfYear == Summer)
                {
                    MainEditBox->AppendText(getDataString(dataRec));
                }
                
			if (timeOfYear == Summer)
                {
                    myBH->addMinHeap(id, first, last, place, timeOfYear, bookingType);                            
                }
                else
                {
                    MainEditBox->AppendText(wxT("Your entry must be Spring"));
                }
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box	//Destroy the dialog box
		
		
        
    }
    
void MyFrame::OnDispAllH ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	records.append(heading);
	
	records.append(myBH->displayHeap());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Heap Tree:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }

void MyFrame::OnDelDataH ( wxCommandEvent& WXUNUSED ( event ) )
    {
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for Heap"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("====================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			
			// ... Now send the data to the Heap e.g   
			string deleted = myBH->deleteMinHeapVal(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
    
        
    }
    
void MyFrame::OnHeapSort ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	records.append(heading);
	
	records.append(myBH->sortMinHeap());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Heap Tree:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }
    
    
//*************************************************************************************
//                      RED BLACK TREE DEFINITIONS DECLARATION  
//*************************************************************************************    
void MyFrame::OnCreateRbt ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //ONLY WINTER SEASONS NECESSARY
        int num;
            string fname;
            string lname;
            string loc;
            string season;
            string book;
            string colour;
            string Winter = "Winter";
        
            char comma;
        
            string record;
            string theRecord;
            string titleLine;
    
            // Clear the edit box
            MainEditBox->Clear();
    
            //Empty the Stack
            myRBT->emptyRBTree();
      
            //Create filename pointer    
            //ifstream inFile;
            ifstream inFile;
        
            inFile.open(CurrentDocPath.mb_str(), ios::in);
    
        if (!inFile)
        {
            MainEditBox->AppendText(wxT("Unable to open file as requested"));
            return;
        }
       
            // Read off the title line and discard it
            getline(inFile, titleLine, '\n');
  
            // Create a label for the displayed records
            titleLine = "Client ID \t\t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

            titleLine.append("==================================================================================================\n");
            record.append(titleLine);
            wxString wxRecords(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxRecords);
        
            while (!inFile.eof())
            {
           
                inFile  >> num >> comma;
                    getline(inFile, fname, ',');
                    getline(inFile, lname, ',');
                    getline(inFile, loc, ',');
                    getline(inFile, season, ',');
                    getline(inFile, book, '\n');
           
                
                if (!inFile.eof())
                {
                    fname = strip(fname);
                    lname  = strip(lname);
                    loc = strip(loc);
                    season = strip(season);
                    book = strip(book);
                    Winter = strip(Winter);
              
                if (season == Winter)
                {
                    record = makeRecord(num, fname, lname, loc, season, book);
                    myRBT->insert(num, fname, lname, loc, season, book);
                    
                    wxString wxRecords(record.c_str(), wxConvUTF8);
                    MainEditBox->AppendText(wxRecords);
                    MainEditBox->AppendText(wxT("\n"));
        
                    record = " ";
                }//end of seasonal if statement
                
                }//end of File If
                
            }//end While
        
    }
    
void MyFrame::OnAddDataRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		string Winter = "Winter";
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for RBT"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Tail:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));
            Winter = strip(Winter);
                if (timeOfYear == Winter)
                {
                    MainEditBox->AppendText(getDataString(dataRec));
                }
                
			if (timeOfYear == Winter)
                {
                    myRBT->insert(id, first, last, place, timeOfYear, bookingType);                            
                }
                else
                {
                    MainEditBox->AppendText(wxT("Your entry must be Spring"));
                }
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box	//Destroy the dialog box
    }
    
void MyFrame::OnDelDataRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
        Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for RBT"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("===================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			
			// ... Now send the data to the RBT e.g  
			string deleted = myRBT->remove(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
        
    }
    
void MyFrame::OnInOrderRBT ( wxCommandEvent& WXUNUSED ( event ) )     
    {
          string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	records.append(heading);
	
	records.append(myRBT->inOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in RBT:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    
void MyFrame::OnPreOrderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
         string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	records.append(heading);
	
	records.append(myRBT->preOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in RBT:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    
void MyFrame::OnPostOrderRBT ( wxCommandEvent& WXUNUSED ( event ) )
    {
         string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
	records.append(myRBT->postOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in RBT:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
 
 
//*************************************************************************************
//                      SET DEFINITIONS DECLARATION  
//*************************************************************************************   
void MyFrame::OnCreateSet ( wxCommandEvent& WXUNUSED ( event ) )
    {// Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
	string place;
	string timeOfYear;
	string bookingType;

	char comma;
	   
        string record, heading;
        
        
	//Empty the sets
	setA->purgeSet();
	setB->purgeSet();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
		string Antigua = "Antigua";
		string Bahamas = "Bahamas";
		string Barbados = "Barbados";
		string Belize = "Belize";
		string Dominica = "Dominica";
		string Grenada = "Grenada";
		string Guyana = "Guyana";
		string Haiti ="Haiti";
		string Jamaica = "Jamaica";
		string Montserrat = "Montserrat";
		string StLucia = "St Lucia";
		string StKitts = "St Kitts";
		string StVincent = "St Vincent";
		string Suriname = "Suriname";
		string Trinidad = "Trinidad";
 			 
                if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
			Antigua = strip(Antigua);
			Bahamas = strip(Bahamas);
			Barbados = strip(Barbados);
			Belize = strip(Belize);
			Dominica = strip(Dominica);
			Grenada = strip(Grenada);
			Guyana = strip(Guyana);
			Haiti = strip(Haiti);
			Jamaica = strip(Jamaica);
			Montserrat = strip(Montserrat);
			StLucia = strip(StLucia);
			StKitts = strip(StKitts);
			StVincent = strip(StVincent);
			Suriname = strip(Suriname);
			Trinidad = strip(Trinidad);
                   
			record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						
			// check if destination is a Caricom country
			if (place == Antigua || place == Bahamas || place ==  Barbados || place ==  Belize || place ==  Dominica || place ==  Grenada || place ==  Guyana || place ==  Haiti || place ==  Jamaica 
			  || place ==  Montserrat || place ==  StLucia || place ==  StKitts || place ==  StVincent || place ==  Suriname || place == Trinidad) 
                            {
                                record.append("\t...Added to Set A\n");
                                setA->add(id, first, last, place, timeOfYear, bookingType);
                            }
					else
						{
						  record.append("\t...Added to Set B\n");
                                setB->add(id, first, last, place, timeOfYear, bookingType);	
						}	
		  }
					
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
			
                        //Reset record variable
                        record = "";
              }// End while
    }
 
void MyFrame::OnAddDataSetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
	Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Set A"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(setA->find(dataRec.idNo) == false)//if the ClientID doesn't already exist
			{
			    MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		      
			    // Create a label for the displayed records
			    string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			    heading.append("=================================================================================");
			    wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			    
			    MainEditBox->AppendText(getDataString(dataRec));

			    //   You need to disaggregate the data from dataRec to
			    //   send them to your ADTs. e.g.:
			    
			    int    id = dataRec.idNo;
			    string first = strip(string(dataRec.fname.mb_str()));
			    string last = strip(string(dataRec.lname.mb_str()));
			    string place = strip(string(dataRec.destination.mb_str()));
			    string timeOfYear = strip(string(dataRec.season.mb_str()));
			    string bookingType = strip(string(dataRec.book.mb_str()));

			    // ... Now send the data to the set
			    setA->add(id, first, last, place, timeOfYear, bookingType);                            
			}
			else
			    MainEditBox->AppendText(wxT("Record already exists within Set")); 
		    }

		else //if (caricomdialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		
    } 
    
void MyFrame::OnAddDataSetB ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
	Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Set B"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			
			    
			    
			    

			    //   You need to disaggregate the data from dataRec to
			    //   send them to your ADTs. e.g.:
			    
			    int    id = dataRec.idNo;
			    string first = strip(string(dataRec.fname.mb_str()));
			    string last = strip(string(dataRec.lname.mb_str()));
			    string place = strip(string(dataRec.destination.mb_str()));
			    string timeOfYear = strip(string(dataRec.season.mb_str()));
			    string bookingType = strip(string(dataRec.book.mb_str()));

			    if((setB->find(dataRec.idNo) == false) &&  place != strip("Antigua") && place != strip("Bahamas") && place !=  strip("Barbados") && place !=  strip("Belize") && place !=  strip("Dominica") 
			  && place !=  strip("Grenada") && place !=  strip("Guyana") && place !=  strip("Haiti") && place !=  strip("Jamaica") && place !=  strip("Montserrat") && place !=  strip("St Lucia") 
			  && place !=  strip("St Kitts") && place !=  strip("St Vincent") && place !=  strip("Suriname") && place != strip("Trinidad") &&  place != strip("antigua") && place != strip("bahamas") 
			  && place !=  strip("barbados") && place !=  strip("belize") && place !=  strip("dominica") && place !=  strip("grenada") && place !=  strip("guyana") && place !=  strip("haiti") 
			  && place !=  strip("jamaica") && place !=  strip("montserrat") && place !=  strip("st lucia") && place !=  strip("st kitts") && place !=  strip("st vincent") && place !=  strip("suriname") 
			  && place != strip("trinidad"))//if the ClientID doesn't already exist and place isn't a Caricom country
			{
			    
			    // ... Now send the data to the set
			    setB->add(id, first, last, place, timeOfYear, bookingType); 
			    MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		      
			    // Create a label for the displayed records
			    string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			    heading.append("===============================================================================");
			    wxString wxheading(heading.c_str(), wxConvUTF8);
			    MainEditBox->AppendText(wxheading);
			    MainEditBox->AppendText(getDataString(dataRec));
			}
			else if(setB->find(dataRec.idNo) == true)
			MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate")); 
			
			else 
			MainEditBox->AppendText(wxT("Sorry, but you can't add Caricom countries to Set B"));
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		
    }

void MyFrame::OnDispSetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
	
	
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
	records.append(setA->displaySet());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Set A:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }
    
void MyFrame::OnDispSetB ( wxCommandEvent& WXUNUSED ( event ) )     
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
	
	
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	records.append(heading);
	
	records.append(setB->displaySet());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Set B:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }
    
void MyFrame::OnDispInter ( wxCommandEvent& WXUNUSED ( event ) )
    {
       string record, heading;
	
	string Internet = "Internet";
	Internet = strip(Internet);
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	record.append(heading);
	
	
	
	Set* C = new Set();
	C->intersectionSet(setA, setB);
	for(int x = 0; x < C->getNumElements(); x++)
	{
	  //if(C->getSetBooking(x) == Internet)
	  record.append(C->getOne(x));
	}
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nThe Intersection of sets A and B:\n\n"));
      MainEditBox->AppendText(wxRecord); 
    }
    
void MyFrame::OnDispUnion ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	// Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=========================================================================================\n");
	record.append(heading);
	
	Set* D = new Set();
	D->unionSet(setA, setB);
	
	record.append(D->displaySet());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nThe Union of Sets A and B:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
void MyFrame::OnDelSetA ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for Set A"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			
			// ... Now send the data to the Set e.g    
			string deleted = setA->remove(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);	
		    }

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
        
    }
    
void MyFrame::OnDelSetB ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for Set B"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			
			// ... Now send the data to the Set e.g  
			string deleted = setB->remove(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		    }

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
    }
 
//*************************************************************************************
//                      SPLAY DEFINITIONS DECLARATION  
//*************************************************************************************   
void MyFrame::OnCreateSplay ( wxCommandEvent& WXUNUSED ( event ) )  //12
    {MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
	string place;
	string timeOfYear;
	string bookingType;
	char comma;
	   
        string record, heading;
        
        
	//Empty the Splay
	mySplay->purgeSplay();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
			 
 			 
                if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
			
			  
            record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						      
						      
            mySplay->Insert(id, first, last, place, timeOfYear, bookingType);
			  
			
					      
            wxString wxRecord(record.c_str(), wxConvUTF8);
            MainEditBox->AppendText(wxRecord);
            MainEditBox->AppendText(wxT("\n"));
			      
			      //Reset record variable
            record = "";
			
		  }
            }// End while
        
    }
    
    
void MyFrame::OnAddDataSp ( wxCommandEvent& WXUNUSED ( event ) )
    {Record dataRec;
		string Spring = "Spring";
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for Deque"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Tail:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));
            /*Spring = strip(Spring);
                if (timeOfYear == Spring)
                {
                    MainEditBox->AppendText(getDataString(dataRec));
                }
                */
			//if (timeOfYear == Spring)
                {
                    mySplay->Insert(id, first, last, place, timeOfYear, bookingType);                            
                }
               
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box	//Destroy the dialog box
		
        
    }
    
void MyFrame::OnDelDataSp ( wxCommandEvent& WXUNUSED ( event ) )
    {        
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for Splay"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->idNoEditBox->GetValue();
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord deleted:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("==================================================================================\n");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			
			// ... Now send the data to the RBT e.g        
			string deleted = mySplay->removeSplay(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
    }
    
void MyFrame::OnInOrderSp ( wxCommandEvent& WXUNUSED ( event ) )   
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=====================================================================================\n");
	records.append(heading);
	
	records.append(mySplay->InOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Splay Tree:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }

void MyFrame::OnPreOrderSp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=====================================================================================\n");
	records.append(heading);
	
	records.append(mySplay->PreOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Splay Tree:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    
void MyFrame::OnPostOrderSp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	records.append(heading);
	
	records.append(mySplay->PostOrder());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Splay Tree:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    
    
    
          
 
 

//***************************************************************************************
//                      QUEUE FUNCTION DEFINITIONS DECLARATION
//***************************************************************************************
void MyFrame::OnCreateQueue ( wxCommandEvent& WXUNUSED ( event ) )
    {// Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
	string place;
	string timeOfYear;
	string bookingType;

	char comma;
	   
        string record, heading;
        
        
	//Empty the Queue
	myqueue->emptyQueue();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("==================================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
			 
 			 
                if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
                   
			record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						
						
			myqueue->enqueue(id, first, last, place, timeOfYear, bookingType);
		  }
					
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        MainEditBox->AppendText(wxT("\n"));
			
                        //Reset record variable
                        record = "";
              }// End while
    
  } 
  
  void MyFrame::OnDequeueQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("==================================================================================================\n");
	record.append(heading);
	record.append(myqueue->dequeue());
		
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord dequeued:\n\n"));
      MainEditBox->AppendText(wxRecord);
    }
    
void MyFrame::OnShowHeadQ ( wxCommandEvent& WXUNUSED ( event ) )
    {string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("==================================================================================================\n");
	record.append(heading);

	record = myqueue->theFront();
		
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
    }
    
void MyFrame::OnShowTailQ ( wxCommandEvent& WXUNUSED ( event ) )
    {string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	// Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("==================================================================================================\n");
	record.append(heading);
	
	record.append(myqueue->theBack());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
void MyFrame::OnDispAllQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
      string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
	
	
	// Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("==================================================================================================\n");
	records.append(heading);
	
	records.append(myqueue->displayQ());
		
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
    }
    
    
void MyFrame::OnAddDataQ ( wxCommandEvent& WXUNUSED ( event ) )
    {Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Queue"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("======================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));

			// ... Now send the data to the Queue
			myqueue->enqueue(id, first, last, place, timeOfYear, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
	
        
    }
    
    
    
    
    
//***************************************************************************************    
//                  PRIORITY QUEUE FUNCTION DEFINITIONS DECLARATIONS
//***************************************************************************************
void MyFrame::OnCreatePQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
 	// Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
        string place;
        string timeOfYear;
        string bookingType;

        char comma;
	   
        string record, heading;
        
	//Empty the Queue
	mypQueue->emptyQueue();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
			 
 			 
                if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
                   
			record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						
						
			mypQueue->enqueue(id, first, last, place, timeOfYear, bookingType);
		  }
					
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        MainEditBox->AppendText(wxT("\n"));
			
                        //Reset record variable
                        record = "";
              } // End while
    }
    
    
void MyFrame::OnAddDataPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for PQ"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("==================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));

			// ... Now send the data to the PQ
			mypQueue->enqueue(id, first, last, place, timeOfYear, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		
        
    }
    
    
void MyFrame::OnDispAllPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
       string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
	records.append(mypQueue->dList());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Priority Queue:\n\n"));
	MainEditBox->AppendText(wxRecords); 
    }
    
        
void MyFrame::OnShowHeadPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string record, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	record.append(heading);
	record.append(mypQueue->theFront());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
    
void MyFrame::OnShowTailPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
         string record, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	record.append(heading);
	record.append(mypQueue->theBack());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
    
void MyFrame::OnDequeuePQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string record, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	record.append(heading);
	record.append(mypQueue->dequeue());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord dequeued:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
   
   
   
   
   
//***************************************************************************************
//              DOUBLE ENDED QUEUE FUNCTION DEFINITIONS DECLARATIONS
//***************************************************************************************
void MyFrame::OnCreateDeque ( wxCommandEvent& WXUNUSED ( event ) )
    {int     id;
        string  first;
        string  last;
        string  place;
        string  timeOfYear;
        string  bookingType;

        char comma = ',';
	   
        string record, heading;
        
        // Clear the edit box
        MainEditBox->Clear();
    
        //Empty the Deque
        mydeque->emptyQueue();
      
        //open the file
        ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("===========================================================================================\n");
        record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
			
 			 
                if (!infile.eof())
                {
					first = strip(first);
					last  = strip(last);
					place = strip(place);
					timeOfYear = strip(timeOfYear);
					bookingType = strip(bookingType);
                   
					record = makeRecord(id, first, last, place, timeOfYear, bookingType);
                    mydeque->inFront(id, first, last, place, timeOfYear, bookingType);
                    
                    wxString wxRecord(record.c_str(), wxConvUTF8);
                    MainEditBox->AppendText(wxRecord);
                    MainEditBox->AppendText(wxT("\n"));
                        //Reset record variable
                    record = " ";
                }
            }  // End while*/
    }
    
void MyFrame::OnAddHead ( wxCommandEvent& WXUNUSED ( event ) )
    {  
	     Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Deque"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Head:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));

			// ... Now send the data to the Head of the Deque
			mydeque->inFront(id, first, last, place, timeOfYear, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		
    }
    
void MyFrame::OnAddTail ( wxCommandEvent& WXUNUSED ( event ) )
    {
        Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for Deque"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Tail:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));

			// ... Now send the data to the Tail of the Deque
			mydeque->inBack(id, first, last, place, timeOfYear, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
    }

   
void MyFrame::OnDispAllDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	records.append(heading);
	
	records.append(mydeque->dList());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Deque:\n\n"));
	MainEditBox->AppendText(wxRecords);

    }
    
void MyFrame::OnShowHeadDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
      string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("===========================================================================================\n");
	record.append(heading);
	record.append(mydeque->theFront());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }

    
void MyFrame::OnShowTailDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	record.append(heading);
	record.append(mydeque->theTail());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }

void MyFrame::OnDequeueH ( wxCommandEvent& WXUNUSED ( event ) )
    {
	string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("==========================================================================================\n");
	record.append(heading);
	record.append(mydeque->outFront());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
void MyFrame::OnDequeueT ( wxCommandEvent& WXUNUSED ( event ) ) //26
    {
       string record, heading;
	
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("======================================================================================\n");
	record.append(heading);
	record.append(mydeque->outBack());
		  
	//Convert to a wxString
	wxString wxRecord(record.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Tail:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
    
    
    
    
   
//***************************************************************************************   
//                  STACK FUNCTION DEFINITION DECLARATIONS
//***************************************************************************************
void MyFrame::OnCreateStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //ONLY THE SPRING RECORDS ARE REQUIRED
        // Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
        string place;
        string timeOfYear;
        string bookingType;
        string Spring = "Spring";
        char comma;
	   
        string record, heading;
        
        
	//Empty the Stack
	mystack->emptyStack();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	  {
	  	MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	  }
	
        // Read off the heading line and discard it
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("========================================================================================\n");
	record.append(heading);
        wxString wxRecord(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecord);
        
        while (!infile.eof())//read all the records in the file
            {
	      
                infile  >> id >> comma;
                getline(infile, first, ',');
                getline(infile, last, ',');
                getline(infile, place, ',');
                getline(infile, timeOfYear, ',');
                getline(infile, bookingType, '\n');
		

		   if (!infile.eof())
		  {
			first = strip(first);
			last  = strip(last);
			place = strip(place);
			timeOfYear = strip(timeOfYear);
			bookingType = strip(bookingType);
            Spring = strip(Spring);
			
		    if(timeOfYear == Spring)
		    {
			  record = makeRecord(id, first, last, place, timeOfYear, bookingType);		  
			  mystack->push(id, first, last, place, timeOfYear, bookingType);	
     	  
					
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        MainEditBox->AppendText(wxT("\n"));
			
                        //Reset record variable
		    record = "";
		    }  
		  }
              }// End while
    }
    
void MyFrame::OnPush ( wxCommandEvent& WXUNUSED ( event ) )
    {
	Record dataRec;
		string Spring = "Spring";
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Stack"), 
							 wxPoint(200,200), wxSize(420,290) );

		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->idNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->fNameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->lNameEditBox->GetValue();
			
			// Grab the Place
			dataRec.destination = datadialog->destinationEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.season 	= datadialog->SeasonCombo->GetValue();
			dataRec.book 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added at the Tail:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("=================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.fname.mb_str()));
			string last = strip(string(dataRec.lname.mb_str()));
			string place = strip(string(dataRec.destination.mb_str()));
			string timeOfYear = strip(string(dataRec.season.mb_str()));
			string bookingType = strip(string(dataRec.book.mb_str()));
            Spring = strip(Spring);
                if (timeOfYear == Spring)
                {
                    MainEditBox->AppendText(getDataString(dataRec));
                }
                
			if (timeOfYear == Spring)
                {
                    mystack->push(id, first, last, place, timeOfYear, bookingType);                            
                }
                else
                {
                    MainEditBox->AppendText(wxT("Your entry must be Spring"));
                }
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box	//Destroy the dialog box
		
        
    }
    
void MyFrame::OnPop ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
	records.append(mystack->pop());
		
	//Convert to a wxString
	wxString wxRecord(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed:\n\n"));
	MainEditBox->AppendText(wxRecord);
    }
    
    
void MyFrame::OnDispAllSt ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, heading;
	// Clear the edit box
	MainEditBox->Clear();
  
	 // Create a label for the displayed records
        heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

        heading.append("=======================================================================================\n");
	records.append(heading);
	
	records.append(mystack->dList());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);
	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Stack:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    

    


    
 

    

    

    
    
    

    

    


    

    

    

    

    
    

//g++ wxExample.cpp -o example `wx-config --libs --cxxflags`
//./example
