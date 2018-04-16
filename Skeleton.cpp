//Programmed by: Alec Gilkes ID#415002420

/************************************************************************************
  Step 1: Always include the header file wx.h					    
*************************************************************************************/
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    # include <wx/wx.h>
    # include <wx/spinctrl.h>
    # include <wx/textctrl.h>		
    # include <wx/combobox.h>		
    # include <wx/listbox.h>
    #include <wx/platinfo.h>
#endif

#include <fstream> 
#include <string> 


using namespace std;

// Other miscellaneous functions' protypes
string to_string(int);
string strip(string);
string makeRecord(int, string, string, string, string, string);


// The Data Entry Dialog files
#include "DataDialog.h"
//#include "DeleteDialog.h"
//#include "CaricomDialog.h"

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
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with 
	  the function to execute the program				    
*************************************************************************************
*************************************************************************************/
class ProjectApp: public wxApp
  {
	 virtual bool OnInit();
  };

  
  
  
  
/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class 
	   also will ALL the events handlers be declared    
*************************************************************************************
*************************************************************************************/
class ProjectFrame: public wxFrame
  {
	 private:
		DECLARE_EVENT_TABLE() //To declare events items
    
	 public:
		ProjectFrame(const wxString& title, const wxPoint& pos, 
			const wxSize& size);
		
		//Functions for File Menu Items
		void OnOpenFile(wxCommandEvent& event);
		void OnDisplay(wxCommandEvent& event);
		void OnSave(wxCommandEvent& event);
		void OnSaveAs(wxCommandEvent& event);	
		void OnExit(wxCommandEvent& event); 	//handle for Quit function
		
		
		//Functions for Queue Menu Items
		void OnCreateQueue(wxCommandEvent& event);
		void OnEnqueueQueue(wxCommandEvent& event);
		void OnDisplayQueue(wxCommandEvent& event);
		void OnShowHeadQueue(wxCommandEvent& event);
		void OnShowTailQueue(wxCommandEvent& event);
		void OnDequeueQueue(wxCommandEvent& event);
		
		
		//Functions for Deque Menu Items
		void OnCreateDeque(wxCommandEvent& event);
		void OnEnqueueHeadDeque(wxCommandEvent& event);
		void OnEnqueueTailDeque(wxCommandEvent& event);
		void OnDisplayDeque(wxCommandEvent& event);
		void OnShowHeadDeque(wxCommandEvent& event);
		void OnShowTailDeque(wxCommandEvent& event);
		void OnDequeueHeadDeque(wxCommandEvent& event);
		void OnDequeueTailDeque(wxCommandEvent& event);	
				
				
		//Functions for Priority Queue Menu Items
		void OnCreatePQ(wxCommandEvent& event);
		void OnEnqueuePQ (wxCommandEvent& event);
		void OnDisplayPQ(wxCommandEvent& event);
		void OnShowHeadPQ(wxCommandEvent& event);
		void OnShowTailPQ(wxCommandEvent& event);
		void OnDequeuePQ(wxCommandEvent& event);
		
		
		//Functions for Stack Menu Items
		void OnCreateStack(wxCommandEvent& event);
		void OnPushStack(wxCommandEvent& event);
		void OnPopStack(wxCommandEvent& event);
		void OnDisplayStack(wxCommandEvent& event);

		
		//Functions for Binary search Tree Menu Items
		void OnCreateBST(wxCommandEvent& event);
		void OnAddBST(wxCommandEvent& event);
		void OnDeleteBST(wxCommandEvent& event);
		void OnInorderBST(wxCommandEvent& event);
		void OnPreorderBST(wxCommandEvent& event);
		void OnPostorderBST(wxCommandEvent& event);
		
		
		//Functions for AVL Tree Menu Items
		void OnCreateAVL(wxCommandEvent& event);
		void OnAddAVL(wxCommandEvent& event);
		void OnDeleteAVL(wxCommandEvent& event);
		void OnInorderAVL(wxCommandEvent& event);
		void OnPreorderAVL(wxCommandEvent& event);
		void OnPostorderAVL(wxCommandEvent& event);

		
		//Functions for Heap Menu Items	
		void OnCreateHeap(wxCommandEvent& event);
		void OnAddHeap(wxCommandEvent& event);
		void OnDeleteHeap(wxCommandEvent& event);
		void OnDisplayHeap(wxCommandEvent& event);
		void OnHeapSort(wxCommandEvent& event);
		
		
		//Functions for Red-Black Tree Menu Items
		void OnCreateRBT(wxCommandEvent& event);
		void OnAddRBT(wxCommandEvent& event);
		void OnDeleteRBT(wxCommandEvent& event);
		void OnInorderRBT(wxCommandEvent& event);
		void OnPreorderRBT(wxCommandEvent& event);
		void OnPostorderRBT(wxCommandEvent& event);

		
		//Functions for Splay Tree Menu Items
		void OnCreateSplay(wxCommandEvent& event);
		void OnAddSplay(wxCommandEvent& event);
		void OnDeleteSplay(wxCommandEvent& event);
		void OnInorderSplay(wxCommandEvent& event);
		void OnPreorderSplay(wxCommandEvent& event);
		void OnPostorderSplay(wxCommandEvent& event);

		
		//Functions for Set Menu Items
		void OnCreateSets(wxCommandEvent& event);
		void OnAddSetA(wxCommandEvent& event);
		void OnAddSetB(wxCommandEvent& event);
		void OnDeleteSetA(wxCommandEvent& event);
		void OnDeleteSetB(wxCommandEvent& event);
		void OnIntersection(wxCommandEvent& event);
		void OnUnion(wxCommandEvent& event);
		void OnDisplaySetA(wxCommandEvent& event);
		void OnDisplaySetB(wxCommandEvent& event);
	
		
		//Function for About Menu Item
		void OnAbout(wxCommandEvent& event);
		
		
		//Public attributes
		wxTextCtrl* MainEditBox;
		wxTextCtrl* filenameTextBox;
		wxString CurrentDocPath;	// The Path to the file we have open
		
  };

 
  
/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives				    
*************************************************************************************
*************************************************************************************/
DECLARE_APP(ProjectApp)		// Declare Application class
IMPLEMENT_APP(ProjectApp)		// Create Application class object
  

enum
    {
      	// File menu items
	ID_OpenFile	= wxID_HIGHEST + 1,		//File menu item
	ID_Display,
	ID_Save,
	ID_SaveAs,
	ID_Exit,
      	
	//Queue menu items
	ID_CreateQueue,
	ID_EnqueueQueue, 
	ID_DisplayQueue,
	ID_ShowHeadQueue,
	ID_ShowTailQueue,
	ID_DequeueQueue,
		
	//Deque menu items
	ID_CreateDeque,
	ID_EnqueueHeadDeque,
	ID_EnqueueTailDeque,
	ID_DisplayDeque,
	ID_ShowHeadDeque,
	ID_ShowTailDeque,
	ID_DequeueHeadDeque,
	ID_DequeueTailDeque,
		
	// Priority Queue menu items
	ID_CreatePQ,
	ID_EnqueuePQ,
	ID_DisplayPQ,
	ID_ShowHeadPQ,
	ID_ShowTailPQ,
	ID_DequeuePQ,
	
	//Stack menu items
	ID_CreateStack,
	ID_PushStack,
	ID_PopStack,
	ID_DisplayStack,
	
	// BST menu items
	ID_CreateBST,
	ID_AddBST,
	ID_DeleteBST,
	ID_InorderBST,
	ID_PreorderBST,
	ID_PostorderBST,
	
	// AVL Tree menu items		
	ID_CreateAVL,
	ID_AddAVL,
	ID_DeleteAVL,
	ID_InorderAVL,
	ID_PreorderAVL,
	ID_PostorderAVL,
		
	// Heap menu items
	ID_CreateHeap,
	ID_AddHeap,
	ID_DeleteHeap,
	ID_DisplayHeap,
	ID_HeapSort,	
	
	// Red-Black Tree Menu items	
	ID_CreateRBT,
	ID_AddRBT,
	ID_DeleteRBT,
	ID_InorderRBT,
	ID_PreorderRBT,
	ID_PostorderRBT,
		
	// Splay Tree menu items
	ID_CreateSplay,
	ID_AddSplay,
	ID_DeleteSplay,
	ID_InorderSplay,
	ID_PreorderSplay,
	ID_PostorderSplay,
		
	// Set menu items
	ID_CreateSets,
	ID_AddSetA,
	ID_AddSetB,
	ID_DeleteSetA,
	ID_DeleteSetB,
	ID_Intersection,
	ID_Union,
	ID_DisplaySetA,
	ID_DisplaySetB, 
		
	// About menu items
	ID_About,
	
    };

    
    
BEGIN_EVENT_TABLE ( ProjectFrame, wxFrame )
      // Events for the "File" menu items
      EVT_MENU ( ID_OpenFile, 	ProjectFrame::OnOpenFile)		//File Menu 
      EVT_MENU ( ID_Display, 	ProjectFrame::OnDisplay)
      EVT_MENU ( ID_Save, 	ProjectFrame::OnSave)
      EVT_MENU ( ID_SaveAs, 	ProjectFrame::OnSaveAs)
      EVT_MENU ( ID_Exit, 	ProjectFrame::OnExit)
	 
      // Events for the "Queue" menu items
      EVT_MENU ( ID_CreateQueue,		ProjectFrame::OnCreateQueue)
      EVT_MENU ( ID_EnqueueQueue, 		ProjectFrame::OnEnqueueQueue)
      EVT_MENU ( ID_DisplayQueue,		ProjectFrame::OnDisplayQueue)
      EVT_MENU ( ID_ShowHeadQueue,		ProjectFrame::OnShowHeadQueue)
      EVT_MENU ( ID_ShowTailQueue,		ProjectFrame::OnShowTailQueue)
      EVT_MENU ( ID_DequeueQueue,		ProjectFrame::OnDequeueQueue)
	  
      // Events for the "Deque" menu items
      EVT_MENU ( ID_CreateDeque,		ProjectFrame::OnCreateDeque)
      EVT_MENU ( ID_EnqueueHeadDeque,		ProjectFrame::OnEnqueueHeadDeque)
      EVT_MENU ( ID_EnqueueTailDeque,		ProjectFrame::OnEnqueueTailDeque)
      EVT_MENU ( ID_DisplayDeque,		ProjectFrame::OnDisplayDeque)
      EVT_MENU ( ID_ShowHeadDeque,		ProjectFrame::OnShowHeadDeque)
      EVT_MENU ( ID_ShowTailDeque,		ProjectFrame::OnShowTailDeque)
      EVT_MENU ( ID_DequeueHeadDeque,		ProjectFrame::OnDequeueHeadDeque)
      EVT_MENU ( ID_DequeueTailDeque,		ProjectFrame::OnDequeueTailDeque)
	  
      // Events for the "Priority Queue" menu items
      EVT_MENU ( ID_CreatePQ,			ProjectFrame::OnCreatePQ)
      EVT_MENU ( ID_EnqueuePQ,			ProjectFrame::OnEnqueuePQ)
      EVT_MENU ( ID_DisplayPQ,			ProjectFrame::OnDisplayPQ)
      EVT_MENU ( ID_ShowHeadPQ,			ProjectFrame::OnShowHeadPQ)
      EVT_MENU ( ID_ShowTailPQ,			ProjectFrame::OnShowTailPQ)
      EVT_MENU ( ID_DequeuePQ,			ProjectFrame::OnDequeuePQ)
      
      // Events for the "Stack" menu items
      EVT_MENU ( ID_CreateStack,	ProjectFrame::OnCreateStack)
      EVT_MENU ( ID_PushStack,		ProjectFrame::OnPushStack)
      EVT_MENU ( ID_PopStack,		ProjectFrame::OnPopStack)
      EVT_MENU ( ID_DisplayStack,	ProjectFrame::OnDisplayStack)
	  
      // Events for the "BST" menu items
      EVT_MENU ( ID_CreateBST,		ProjectFrame::OnCreateBST)
      EVT_MENU ( ID_AddBST,		ProjectFrame::OnAddBST)
      EVT_MENU ( ID_DeleteBST,		ProjectFrame::OnDeleteBST)
      EVT_MENU ( ID_InorderBST,		ProjectFrame::OnInorderBST)
      EVT_MENU ( ID_PreorderBST,	ProjectFrame::OnPreorderBST)
      EVT_MENU ( ID_PostorderBST,	ProjectFrame::OnPostorderBST) 
	   
	  
      // Events for the "AVL Tree" menu items
      EVT_MENU ( ID_CreateAVL,		ProjectFrame::OnCreateAVL)
      EVT_MENU ( ID_AddAVL,		ProjectFrame::OnAddAVL)
      EVT_MENU ( ID_DeleteAVL,		ProjectFrame::OnDeleteAVL)
      EVT_MENU ( ID_InorderAVL,		ProjectFrame::OnInorderAVL)
      EVT_MENU ( ID_PreorderAVL,	ProjectFrame::OnPreorderAVL)
      EVT_MENU ( ID_PostorderAVL,	ProjectFrame::OnPostorderAVL)
     
      // Events for the "Heap" menu items
      EVT_MENU ( ID_CreateHeap,		ProjectFrame::OnCreateHeap)
      EVT_MENU ( ID_AddHeap,		ProjectFrame::OnAddHeap)
      EVT_MENU ( ID_DeleteHeap,		ProjectFrame::OnDeleteHeap)
      EVT_MENU ( ID_DisplayHeap,	ProjectFrame::OnDisplayHeap)
      EVT_MENU ( ID_HeapSort,		ProjectFrame::OnHeapSort)
     
      // Events for the "Red-Black Tree" menu items
      EVT_MENU ( ID_CreateRBT,		ProjectFrame::OnCreateRBT)
      EVT_MENU ( ID_AddRBT,		ProjectFrame::OnAddRBT)
      EVT_MENU ( ID_DeleteRBT,		ProjectFrame::OnDeleteRBT)
      EVT_MENU ( ID_InorderRBT,		ProjectFrame::OnInorderRBT)
      EVT_MENU ( ID_PreorderRBT,	ProjectFrame::OnPreorderRBT)
      EVT_MENU ( ID_PostorderRBT,	ProjectFrame::OnPostorderRBT)
     
      // Events for the "Splay Tree" menu items
      EVT_MENU ( ID_CreateSplay,	ProjectFrame::OnCreateSplay)
      EVT_MENU ( ID_AddSplay,		ProjectFrame::OnAddSplay)
      EVT_MENU ( ID_DeleteSplay,	ProjectFrame::OnDeleteSplay)
      EVT_MENU ( ID_InorderSplay,	ProjectFrame::OnInorderSplay)
      EVT_MENU ( ID_PreorderSplay,	ProjectFrame::OnPreorderSplay)
      EVT_MENU ( ID_PostorderSplay,	ProjectFrame::OnPostorderSplay)
     
      // Events for the "Set" menu items
      EVT_MENU ( ID_CreateSets,		ProjectFrame::OnCreateSets)
      EVT_MENU ( ID_AddSetA,		ProjectFrame::OnAddSetA)
      EVT_MENU ( ID_AddSetB,		ProjectFrame::OnAddSetB)
      EVT_MENU ( ID_DeleteSetA,		ProjectFrame::OnDeleteSetA)
      EVT_MENU ( ID_DeleteSetB,		ProjectFrame::OnDeleteSetB)
      EVT_MENU ( ID_Intersection,	ProjectFrame::OnIntersection)
      EVT_MENU ( ID_Union,		ProjectFrame::OnUnion)
      EVT_MENU ( ID_DisplaySetA,	ProjectFrame::OnDisplaySetA)
      EVT_MENU ( ID_DisplaySetB, 	ProjectFrame::OnDisplaySetB)
   
      // Events for the "About" menu items
      EVT_MENU ( ID_About, ProjectFrame::OnAbout)

END_EVENT_TABLE () 
  




/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool ProjectApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("COMP2115 – Pelican Travels Database"), 
				
				    wxPoint(0,0), 
				    wxSize(1920,1080));
      
					      

      // Display the window
      frame->Show(TRUE);
    
      SetTopWindow(frame);

      return TRUE;

  }
  
  
  

/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame ( const wxString& title, const wxPoint& pos, const wxSize& size)
		    : wxFrame((wxFrame *)NULL, -1, title, pos, size)
  {
	// Set the frame icon
	SetIcon(wxIcon(wxT("uwiIcon.xpm")));

	
	
	// Create the main-menu items
	wxMenu *menuFile  	   =   new wxMenu;
	wxMenu *menuDisplayFile	   =   new wxMenu;
	wxMenu *menuQueue	   =   new wxMenu;
	wxMenu *menuDeque	   =   new wxMenu;
	wxMenu *menuPQ		   =   new wxMenu;
	wxMenu *menuStack	   =   new wxMenu;
	wxMenu *menuBST		   =   new wxMenu;
	wxMenu *menuAVL		   =   new wxMenu;
	wxMenu *menuHeap       	   =   new wxMenu;
	wxMenu *menuRBT		   =   new wxMenu;
	wxMenu *menuSplay	   =   new wxMenu;
	wxMenu *menuSet		   =   new wxMenu;
	wxMenu *menuExit	   =   new wxMenu;
	wxMenu *menuAbout  	   =   new wxMenu;

	//Create a Main menu bar
	wxMenuBar *menuBar = new wxMenuBar;
		
	
	//Append the main menu items to the Menu Bar
	menuBar->Append( menuFile, 		wxT("File") );
	menuBar->Append( menuDisplayFile,  	wxT("&Display File"));
	menuBar->Append( menuQueue, 		wxT("Queue") );
	menuBar->Append( menuDeque, 		wxT("Deque") );
	menuBar->Append( menuPQ, 		wxT("Priority Queue") );
	menuBar->Append( menuStack, 		wxT("Stack") );
	menuBar->Append( menuBST, 		wxT("BST") );
	menuBar->Append( menuAVL, 		wxT("AVL Tree") );
	menuBar->Append( menuHeap, 		wxT("Heap") );
	menuBar->Append( menuRBT, 		wxT("RB Tree ") );
	menuBar->Append( menuSplay, 		wxT("Splay") );
	menuBar->Append( menuSet, 		wxT("Set") );
	menuBar->Append( menuExit, 		wxT("Exit") );
	menuBar->Append( menuAbout,             wxT("About") );

	
	
	//Append the sub-menu items to the File Main Menu item
	menuFile->Append( ID_OpenFile, wxT("&Open File..."), 	wxT("Open an Existing file") );
	menuFile->Append( ID_Display,  wxT("&Display File..."),wxT("Display contents of opened file") );
	menuFile->Append( ID_Save, 	 wxT("&Save"), 		wxT("Save opened file") );
	menuFile->Append( ID_SaveAs, 	 wxT("Save &As..."), 	wxT("Save display as a new file") );
	menuFile->Append( ID_Exit, 	 wxT("E&xit"), 		wxT("Close and EXIT Program") );
	
	
	//Append the sub-menu items to the Display Main Menu item
	menuDisplayFile->Append( ID_Display,  wxT("&Display File..."),wxT("Display contents of opened file") );
	
	
	
	//Append the sub-menu items to the Queue Main Menu item
	menuQueue->Append( ID_CreateQueue,	wxT("Create Queue"),wxT("Create Queue") );
	menuQueue->Append( ID_EnqueueQueue, 	wxT("Enqueue"),wxT("Enqueue") );
	menuQueue->Append( ID_DisplayQueue,	wxT("Display All"),wxT("Display All") );
	menuQueue->Append( ID_ShowHeadQueue,	wxT("Show Head"),wxT("Show Head") );
	menuQueue->Append( ID_ShowTailQueue,	wxT("Show Tail"),wxT("Show Tail") );
	menuQueue->Append( ID_DequeueQueue,	wxT("Dequeue"),wxT("Dequeue") );
	
	
	
	//Append the sub-menu items to the Deque Main Menu item
	menuDeque->Append( ID_CreateDeque,	wxT("Create Deque"),wxT("Create Deque") ); 
	menuDeque->Append( ID_EnqueueHeadDeque,	wxT("Enqueue Head"),wxT("Enqueue Head") );
	menuDeque->Append( ID_EnqueueTailDeque,	wxT("Enqueue Tail"),wxT("Enqueue Tail") );
	menuDeque->Append( ID_DisplayDeque,	wxT("Display All"),wxT("Display All") );	
	menuDeque->Append( ID_ShowHeadDeque,	wxT("Show Head"), wxT("Show Head") );
	menuDeque->Append( ID_ShowTailDeque,	wxT("Show Tail"),wxT("Show Tail") );
	menuDeque->Append( ID_DequeueHeadDeque,	wxT("Dequeue Head"),wxT("Dequeue Head") );
	menuDeque->Append( ID_DequeueTailDeque,	wxT("Dequeue Tail"),wxT("Dequeue Tail") );
	
	
	//Append the sub-menu items to the Priority Queue Main Menu item
	menuPQ->Append( ID_CreatePQ,	wxT("Create Priority Queue"),wxT("Create Priority Queue") );
	menuPQ->Append( ID_EnqueuePQ, 	wxT("Enqueue"),wxT("Enqueue") );
	menuPQ->Append( ID_DisplayPQ,	wxT("Display All"),wxT("Display All") );
	menuPQ->Append( ID_ShowHeadPQ,	wxT("Show Head"),wxT("Show Head") );
	menuPQ->Append( ID_ShowTailPQ,	wxT("Show Tail"),wxT("Show Tail") );
	menuPQ->Append( ID_DequeuePQ,	wxT("Dequeue"),wxT("Dequeue") );
	
	
	
	//Append the sub-menu items to the Stack Main Menu item
	menuStack->Append( ID_CreateStack,	wxT("Create Stack"),wxT("Create Stack") );
	menuStack->Append( ID_PushStack,	wxT("Push"),wxT("Push") );
	menuStack->Append( ID_DisplayStack,	wxT("Display All"),wxT("Display All") );
	menuStack->Append( ID_PopStack,		wxT("Pop"),wxT("Pop") );
	
	
	
	//Append the sub-menu items to the BST Main Menu item
	menuBST->Append( ID_CreateBST,		wxT("Create BST"),wxT("Create Binary Stack Tree") );
	menuBST->Append( ID_AddBST, 		wxT("Add Data"),wxT("Add Data") );
	menuBST->Append( ID_DeleteBST,		wxT("Delete Data"),wxT("Delete Data") );
	menuBST->Append( ID_InorderBST,		wxT("Inorder"),wxT("Inorder") );
	menuBST->Append( ID_PreorderBST,	wxT("Preorder"),wxT("Preorder") );
	menuBST->Append( ID_PostorderBST,	wxT("Postorder"),wxT("Postorder") );
	
	
	
	
	//Append the sub-menu items to the AVL Main Menu item
	menuAVL->Append( ID_CreateAVL,		wxT("Create AVL Tree"),wxT("Create AVL Tree") );
	menuAVL->Append( ID_AddAVL, 		wxT("Add Data"),wxT("Add Data") );
	menuAVL->Append( ID_DeleteAVL,		wxT("Delete Data"),wxT("Delete Data") );
	menuAVL->Append( ID_InorderAVL,		wxT("Inorder"),wxT("Inorder") );
	menuAVL->Append( ID_PreorderAVL,	wxT("Preorder"),wxT("Preorder") );
	menuAVL->Append( ID_PostorderAVL,	wxT("Postorder"),wxT("Postorder") );
	
	
	
	
	//Append the sub-menu items to the Heap Main Menu item
	menuHeap->Append( ID_CreateHeap,	wxT("Create Heap"),wxT("Create Heap") );
	menuHeap->Append( ID_AddHeap,		wxT("Add Data"),wxT("Add Data") );
	menuHeap->Append( ID_DeleteHeap,	wxT("Delete Data"),wxT("Delete Data") );
	menuHeap->Append( ID_DisplayHeap,	wxT("Display All"),wxT("Display All") );
	menuHeap->Append( ID_HeapSort,		wxT("Heap Sort"),wxT("Heap Sort") );
	
	
	
	//Append the sub-menu items to the rbt Main Menu item
	menuRBT->Append( ID_CreateRBT,		wxT("Create RBT"),wxT("Create RB Tree") );
	menuRBT->Append( ID_AddRBT, 		wxT("Add Data"),wxT("Add Data") );
	menuRBT->Append( ID_DeleteRBT,		wxT("Delete Data"),wxT("Delete Data") );
	menuRBT->Append( ID_InorderRBT,		wxT("Inorder"),wxT("Inorder") );
	menuRBT->Append( ID_PreorderRBT,	wxT("Preorder"),wxT("Preorder") );
	menuRBT->Append( ID_PostorderRBT,	wxT("Postorder"),wxT("Postorder") );
	
	
	
	
	//Append the sub-menu items to the Splay Main Menu item
	menuSplay->Append( ID_CreateSplay,		wxT("Create Splay"),wxT("Create Splay") );
	menuSplay->Append( ID_AddSplay, 		wxT("Add Data"),wxT("Add Data") );
	menuSplay->Append( ID_DeleteSplay,		wxT("Delete Data"),wxT("Delete Data") );
	menuSplay->Append( ID_InorderSplay,		wxT("Inorder"),wxT("Inorder") );
	menuSplay->Append( ID_PreorderSplay,		wxT("Preorder"),wxT("Preorder") );
	menuSplay->Append( ID_PostorderSplay,		wxT("Postorder"),wxT("Postorder") );
	
	
	
	
	//Append the sub-menu items to the Set Main Menu item
	menuSet->Append( ID_CreateSets,		wxT("Create Sets"),wxT("Create Sets") );
	menuSet->Append( ID_Union,		wxT("Display Union"),wxT("Display Union") );
	menuSet->Append( ID_DisplaySetA,	wxT("Display Set A"),wxT("Display Set A") );
	menuSet->Append( ID_DisplaySetB,	wxT("Display Set B"),wxT("Display Set B") ); 
	menuSet->Append( ID_Intersection,	wxT("Intersection"),wxT("Display Intersection") );
	menuSet->Append( ID_DeleteSetA,		wxT("Delete Data from Set A"),wxT("Delete Data from Set A") );
	menuSet->Append( ID_DeleteSetB,		wxT("Delete Data from Set B"),wxT("Delete Data from Set B") );
	menuSet->Append( ID_AddSetA,		wxT("Add Data to Set A"),wxT("Add Data to Set A") );
	menuSet->Append( ID_AddSetB,		wxT("Add Data to Set B"),wxT("Add Data to Set B") );
	
	
	
	//Append the sub-menu items to the Exit Main Menu item
	menuExit->Append( ID_Exit,  wxT("E&xit"), wxT("Close and EXIT Program") );
	
	
	
	//Append the sub-menu items to the About Main Menu item
	menuAbout->Append( ID_About, wxT("About"), wxT("About this program") );
	
	
	
	// ... and now... attach this main menu bar to the frame
	SetMenuBar( menuBar );
		
	// Create a status bar just for fun
	CreateStatusBar(3);
		
	//Put something in the first section of the status bar
	SetStatusText( wxT("Ready...") );
	
	//Put something in the Second section of the status bar
	SetStatusText( wxT(" Assignment: Alec Gilkes"), 1 );
	
	//Put something in the Third section of the status bar
	SetStatusText( wxT("415002420"), 2 );
	
	
	
	
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
*************************************************************************************
  Step 7:  Define member functions for the Frame class
*************************************************************************************
*************************************************************************************/

//===================================================================================
//=========== Definition for the File Functions =====================================
//===================================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent& event )
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
 

 

void ProjectFrame::OnSave(wxCommandEvent& event )
    {
	// Save to the already-set path for the document
	MainEditBox->SaveFile(CurrentDocPath);
    }
  
  
  
void ProjectFrame::OnSaveAs(wxCommandEvent& event)
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
  
 
 
 
void ProjectFrame::OnDisplay(wxCommandEvent& event )
    {
	// Creates a "open file" dialog with 4 file types
	wxFileDialog *OpenDialog = new wxFileDialog( this, (wxT("Choose a file to open")), 
				wxEmptyString, wxEmptyString,
				(wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
				wxFD_OPEN, wxDefaultPosition);

	MainEditBox->Clear();

	MainEditBox->LoadFile(CurrentDocPath); 
    }
   
void ProjectFrame::OnExit(wxCommandEvent& event)
    {
	wxMessageBox(wxT("A+ Quality!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
	Close(TRUE); // Close the window//
    }



    
void ProjectFrame::OnAbout(wxCommandEvent& event )
    {
	string str="";
	wxPlatformInfo platInfo = wxPlatformInfo ();
	wxString architecture = platInfo.GetArchName( );
	str.append("Data Structures Assignment\n Program developed by: Alec Gilkes\nID: 415002420\nSystem architecture: ");
	str.append(string(architecture.mb_str()));
	wxString wxstr(str.c_str(), wxConvUTF8);
	
	wxMessageBox(wxstr, wxT("About..."), wxOK | wxICON_INFORMATION, this);
    }
  

    
  
  
//=======================================================================================
//==================== Definition for the Queue Functions ==========================
//=======================================================================================
void ProjectFrame::OnCreateQueue(wxCommandEvent& event)
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
  
  
  
void ProjectFrame::OnDisplayQueue(wxCommandEvent& event)
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
  
  
  
void ProjectFrame::OnShowHeadQueue(wxCommandEvent& event)
  {
	string record, heading;
	
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


void ProjectFrame::OnShowTailQueue(wxCommandEvent& event)
  {
	string record, heading;
	
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


void ProjectFrame::OnDequeueQueue(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnEnqueueQueue(wxCommandEvent& event)
  {
	Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Queue"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.fname = datadialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.lname = datadialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.loc = datadialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= datadialog->SeasonCombo->GetValue();
			dataRec.bookType 	= datadialog->BookingCombo->GetValue();
			//dataRec.payMethod   = datadialog->PaymentCombo->GetValue();

			
			
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
			string first = strip(string(dataRec.first.mb_str()));
			string last = strip(string(dataRec.last.mb_str()));
			string place = strip(string(dataRec.place.mb_str()));
			string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			string bookingType = strip(string(dataRec.bookType.mb_str()));

			// ... Now send the data to the Queue
			queue->enqueue(id, first, last, place, timeOfYear, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		 
  }  
  
 
//=======================================================================================
//==================== Definition for the Deque Functions ==========================
//=======================================================================================  

void ProjectFrame::OnCreateDeque(wxCommandEvent& event)
  {
 	
	
        int     id;
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


void ProjectFrame::OnDisplayDeque(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnShowHeadDeque(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnShowTailDeque(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnDequeueHeadDeque(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnDequeueTailDeque(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnEnqueueHeadDeque(wxCommandEvent& event)
  {
 
	/*Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for Deque"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = datadialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = datadialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = datadialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= datadialog->SeasonCombo->GetValue();
			dataRec.bookType 	= datadialog->BookingCombo->GetValue();
			dataRec.payMethod   = datadialog->PaymentCombo->GetValue();

			
			
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
			string first = strip(string(dataRec.first.mb_str()));
			string last = strip(string(dataRec.last.mb_str()));
			string place = strip(string(dataRec.place.mb_str()));
			string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			string payType = strip(string(dataRec.payMethod.mb_str()));
			string bookingType = strip(string(dataRec.bookType.mb_str()));

			// ... Now send the data to the Head of the Deque
			deque->enqueueHead(id, first, last, place, timeOfYear, payType, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		*/
	
  }  
  
void ProjectFrame::OnEnqueueTailDeque(wxCommandEvent& event)
  {
	/*Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for Deque"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = datadialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = datadialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = datadialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= datadialog->SeasonCombo->GetValue();
			dataRec.bookType 	= datadialog->BookingCombo->GetValue();
			dataRec.payMethod   = datadialog->PaymentCombo->GetValue();

			
			
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
			string first = strip(string(dataRec.first.mb_str()));
			string last = strip(string(dataRec.last.mb_str()));
			string place = strip(string(dataRec.place.mb_str()));
			string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			string bookingType = strip(string(dataRec.bookType.mb_str()));

			// ... Now send the data to the Tail of the Deque
			deque->enqueueTail(id, first, last, place, timeOfYear, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box*/
  }  
  
  
  
//=======================================================================================
//                   PRIORITY QUEUE DEFINITION DECLARATIONS 
//=======================================================================================  

void ProjectFrame::OnCreatePQ(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnDisplayPQ(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnShowHeadPQ(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnShowTailPQ(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnDequeuePQ(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnEnqueuePQ(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for PQ"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = datadialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = datadialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = datadialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= datadialog->SeasonCombo->GetValue();
			dataRec.bookType 	= datadialog->BookingCombo->GetValue();
			dataRec.payMethod   = datadialog->PaymentCombo->GetValue();

			
			
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
			string first = strip(string(dataRec.first.mb_str()));
			string last = strip(string(dataRec.last.mb_str()));
			string place = strip(string(dataRec.place.mb_str()));
			string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			string payType = strip(string(dataRec.payMethod.mb_str()));
			string bookingType = strip(string(dataRec.bookType.mb_str()));

			// ... Now send the data to the PQ
			PQ->enqueue(id, first, last, place, timeOfYear, payType, bookingType);                            
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		*/
  }    
  
  
  
//=======================================================================================
//==================== Definition for the Stack Functions ==========================
//=======================================================================================

void ProjectFrame::OnCreateStack(wxCommandEvent& event)
  {
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
  
  
void ProjectFrame::OnDisplayStack(wxCommandEvent& event)
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
  

void ProjectFrame::OnPopStack(wxCommandEvent& event)
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
 
  
void ProjectFrame::OnPushStack(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		SpringDialog *springdialog = new SpringDialog( wxT("COMP2115 - Data Entry for Stack"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (springdialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = springdialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = springdialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = springdialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = springdialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= springdialog->SeasonCombo->GetValue();
			dataRec.bookType 	= springdialog->BookingCombo->GetValue();
			dataRec.payMethod   = springdialog->PaymentCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		  
			// Create a label for the displayed records
			string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			heading.append("===================================================================================");
			wxString wxheading(heading.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxheading);
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			
			int    id = dataRec.idNo;
			string first = strip(string(dataRec.first.mb_str()));
			string last = strip(string(dataRec.last.mb_str()));
			string place = strip(string(dataRec.place.mb_str()));
			string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			string payType = strip(string(dataRec.payMethod.mb_str()));
			string bookingType = strip(string(dataRec.bookType.mb_str()));

			// ... Now send the data to the Stack
			stack->push(id, first, last, place, timeOfYear, payType, bookingType);                            
			
		    }

		else //if (springdialog->ShowModal() == wxID_CANCEL)
			 springdialog->Close();
			    
 
		springdialog->Destroy();			//Destroy the dialog box
		*/
  }  
  
  
  
//=======================================================================================
//                     BINARY SEARCH TREE DEFINITION DECLARATIONS 
//***************************************************************************************
void ProjectFrame::OnCreateBST(wxCommandEvent& event)
  {
 	// Clear the edit box
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
  
  
void ProjectFrame::OnInorderBST(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPreorderBST(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPostorderBST(wxCommandEvent& event)
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
  
  

  
void ProjectFrame::OnDeleteBST(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for BST"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
			
			// ... Now send the data to the BST e.g  
			string deleted = bst->removeBST(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);	
		    }

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
        */
  }  
  
  
void ProjectFrame::OnAddBST(wxCommandEvent& event)
  {/*
		Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2115 - Data Entry for BST"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = datadialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = datadialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = datadialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= datadialog->SeasonCombo->GetValue();
			dataRec.bookType 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(bst->find(dataRec.idNo) == NULL)//if the ClientID doesn't already exist
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
			    string first = strip(string(dataRec.first.mb_str()));
			    string last = strip(string(dataRec.last.mb_str()));
			    string place = strip(string(dataRec.place.mb_str()));
			    string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			    string payType = strip(string(dataRec.payMethod.mb_str()));
			    string bookingType = strip(string(dataRec.bookType.mb_str()));
			    
			    
			    // ... Now send the data to the BST e.g
			    bst->insertBST(id, first, last, place, timeOfYear, payType, bookingType); 
			}
			else
			    MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate")); 
			
		    }

		else //if (datadialog->ShowModal() == wxID_CANCEL)
			 datadialog->Close();
			    
 
		datadialog->Destroy();			//Destroy the dialog box
		*/
  }  
  
  
//=======================================================================================
//==================== Definition for the AVL Functions ==========================
//=======================================================================================
void ProjectFrame::OnCreateAVL(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnInorderAVL(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPreorderAVL(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPostorderAVL(wxCommandEvent& event)
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
  
  

  
void ProjectFrame::OnDeleteAVL(wxCommandEvent& event)
  {/*
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for AVL"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
			string deleted = avl->removeAVL(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
			}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
        */
  }  
  
  
void ProjectFrame::OnAddAVL(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		FallDialog *falldialog = new FallDialog( wxT("COMP2115 - Data Entry for AVL"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (falldialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = falldialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = falldialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = falldialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = falldialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= falldialog->SeasonCombo->GetValue();
			dataRec.bookType 	= falldialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(avl->find(dataRec.idNo) == NULL)//if the ClientID doesn't already exist
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
			    string first = strip(string(dataRec.first.mb_str()));
			    string last = strip(string(dataRec.last.mb_str()));
			    string place = strip(string(dataRec.place.mb_str()));
			    string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			    string bookingType = strip(string(dataRec.bookType.mb_str()));

			    // ... Now send the data to the AVL
			    avl->insertAVL(id, first, last, place, timeOfYear, payType, bookingType);                            
			}
			else
			    MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate"));
		    }

		else //if (falldialog->ShowModal() == wxID_CANCEL)
			 falldialog->Close();
			    
 
		falldialog->Destroy();			//Destroy the dialog box
	*/	
  }  
  
//=======================================================================================
//==================== Definition for the Heap Functions ==========================
//=======================================================================================
void ProjectFrame::OnCreateHeap(wxCommandEvent& event)
  {
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
  
  
void ProjectFrame::OnDisplayHeap(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnHeapSort(wxCommandEvent& event)
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
  

  
void ProjectFrame::OnDeleteHeap(wxCommandEvent& event)
  {/*
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for Heap"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
			string deleted = heap->deleteMinHeapVal(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
    */
  }  
  
  
void ProjectFrame::OnAddHeap(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		SummerDialog *summerdialog = new SummerDialog( wxT("COMP2115 - Data Entry for Heap"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (summerdialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = summerdialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = summerdialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = summerdialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = summerdialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= summerdialog->SeasonCombo->GetValue();
			dataRec.bookType 	= summerdialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(heap->find(dataRec.idNo) == false)//if the ClientID doesn't already exist
			{
			    MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		      
			    // Create a label for the displayed records
			    string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			    heading.append("===============================================================================");
			    wxString wxheading(heading.c_str(), wxConvUTF8);
			    MainEditBox->AppendText(wxheading);
			    
			    MainEditBox->AppendText(getDataString(dataRec));

			    //   You need to disaggregate the data from dataRec to
			    //   send them to your ADTs. e.g.:
			    
			    int    id = dataRec.idNo;
			    string first = strip(string(dataRec.first.mb_str()));
			    string last = strip(string(dataRec.last.mb_str()));
			    string place = strip(string(dataRec.place.mb_str()));
			    string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			    string payType = strip(string(dataRec.payMethod.mb_str()));
			    string bookingType = strip(string(dataRec.bookType.mb_str()));

			    // ... Now send the data to the Heap
			    heap->addMinHeap(id, first, last, place, timeOfYear, payType, bookingType);  
			}
			else
			    MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate"));
			
		    }

		else //if (summerdialog->ShowModal() == wxID_CANCEL)
			 summerdialog->Close();
			    
 
		summerdialog->Destroy();			//Destroy the dialog box
		*/
  } 
		
		
		
//=======================================================================================
//==================== Definition for the RBT Functions ==========================
//=======================================================================================
void ProjectFrame::OnCreateRBT(wxCommandEvent& event)
  {
      //ONLY WINTER SEASONS NECESSARY
 	// Clear the edit box
	MainEditBox->Clear();
	
        int     id;
        string  first;
        string  last;
	string place;
	string timeOfYear;
	string bookingType;
	string Winter = "Winter";
	char comma;
	   
        string record, heading;
        
        
	//Empty the RBT
	myRBT->emptyRBTree();
      
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

        heading.append("=========================================================================================\n");
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
			Winter = strip(Winter);
			
			if(timeOfYear == Winter)
			  {
			      record = makeRecord(id, first, last, place, timeOfYear, bookingType);
						      
			      myRBT->insert(id, first, last, place, timeOfYear, bookingType);
			  
			
					      
			      wxString wxRecord(record.c_str(), wxConvUTF8);
			      MainEditBox->AppendText(wxRecord);
			      MainEditBox->AppendText(wxT("\n"));
			      
			      //Reset record variable
			      record = "";
			}
		  }
              }// End while
  }  
  
  
void ProjectFrame::OnInorderRBT(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPreorderRBT(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPostorderRBT(wxCommandEvent& event)
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
  
  

  
void ProjectFrame::OnDeleteRBT(wxCommandEvent& event)
  {/*
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for RBT"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
			string deleted = rbt->removeRBT(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
        */
  }  
  
  
void ProjectFrame::OnAddRBT(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		WinterDialog *winterdialog = new WinterDialog( wxT("COMP2115 - Data Entry for RBT"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (winterdialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = winterdialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = winterdialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = winterdialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = winterdialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= winterdialog->SeasonCombo->GetValue();
			dataRec.bookType 	= winterdialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(rbt->findNode(dataRec.idNo) == NULL)//if the ClientID doesn't already exist
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
			    string first = strip(string(dataRec.first.mb_str()));
			    string last = strip(string(dataRec.last.mb_str()));
			    string place = strip(string(dataRec.place.mb_str()));
			    string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			    string bookingType = strip(string(dataRec.bookType.mb_str()));

			    // ... Now send the data to the RBT
			    rbt->insertRBT(id, first, last, place, timeOfYear, payType, bookingType);                            
			}
			else
			    MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate")); 
		    }

		else //if (winterdialog->ShowModal() == wxID_CANCEL)
			 winterdialog->Close();
			    
 
		winterdialog->Destroy();			//Destroy the dialog box
		*/
  }  
  
  
//=======================================================================================
//==================== Definition for the Splay Functions ==========================
//=======================================================================================
void ProjectFrame::OnCreateSplay(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnInorderSplay(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPreorderSplay(wxCommandEvent& event)
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
  
  
void ProjectFrame::OnPostorderSplay(wxCommandEvent& event)
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
  
  

  
void ProjectFrame::OnDeleteSplay(wxCommandEvent& event)
  {/*
    Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2115 - Data Deletion for Splay"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
			string deleted = splay->removeSplay(id);
			wxString wxdeleted(deleted.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxdeleted);
		}

		else //if (deletedialog->ShowModal() == wxID_CANCEL)
			 deletedialog->Close();
			    
 
		deletedialog->Destroy();			//Destroy the dialog box
		*/
  }  
  
  
void ProjectFrame::OnAddSplay(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		SpringDialog *springdialog = new SpringDialog( wxT("COMP2115 - Data Entry for Splay"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (springdialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = springdialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = springdialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = springdialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = springdialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= springdialog->SeasonCombo->GetValue();
			dataRec.bookType 	= springdialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			if(splay->find(dataRec.idNo) == NULL)//if the ClientID doesn't already exist
			{
			  MainEditBox->AppendText(wxT("\t\t\t\t\nRecord added:\n\n"));
		    
			  // Create a label for the displayed records
			  string heading = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tBooking\n";

			  heading.append("====================================================================================");
			  wxString wxheading(heading.c_str(), wxConvUTF8);
			  MainEditBox->AppendText(wxheading);
			  
			  MainEditBox->AppendText(getDataString(dataRec));

			  //   You need to disaggregate the data from dataRec to
			  //   send them to your ADTs. e.g.:
			  
			  int    id = dataRec.idNo;
			  string first = strip(string(dataRec.first.mb_str()));
			  string last = strip(string(dataRec.last.mb_str()));
			  string place = strip(string(dataRec.place.mb_str()));
			  string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			  string bookingType = strip(string(dataRec.bookType.mb_str()));
			  
			  
			  // ... Now send the data to the Splay e.g
			  splay->insertSplay(id, first, last, place, timeOfYear, payType, bookingType); 
			}
			else
			    MainEditBox->AppendText(wxT("Sorry, but that would create a duplicate")); 
			
		    }

		else //if (springdialog->ShowModal() == wxID_CANCEL)
			 springdialog->Close();
			    
 
		springdialog->Destroy();			//Destroy the dialog box
		
        */
  } 
  
 
//***************************************************************************************
//                       Definition for the Set Functions 
//***************************************************************************************
void ProjectFrame::OnCreateSets(wxCommandEvent& event)
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
  
  
  
void ProjectFrame::OnDisplaySetA(wxCommandEvent& event)
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
  
 
 void ProjectFrame::OnDisplaySetB(wxCommandEvent& event)
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
  
void ProjectFrame::OnIntersection(wxCommandEvent& event)
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


void ProjectFrame::OnUnion(wxCommandEvent& event)
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


void ProjectFrame::OnDeleteSetA(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for Set A"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
        */
  }  

  
void ProjectFrame::OnDeleteSetB(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		DeleteDialog *deletedialog = new DeleteDialog( wxT("COMP2611 - Data Deletion for Set B"), 
							 wxPoint(200,200), wxSize(420,180) );

		// If the OK button is clicked...
		if (deletedialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = deletedialog->IdNoEditBox->GetValue();
			
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
        */
  } 
  
  
void ProjectFrame::OnAddSetA(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		CaricomDialog *caricomdialog = new CaricomDialog( wxT("COMP2611 - Data Entry for Set A"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (caricomdialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = caricomdialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = caricomdialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = caricomdialog->SurnameEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.place = caricomdialog->PlaceCombo->GetValue();
			dataRec.timeOfYear 	= caricomdialog->SeasonCombo->GetValue();
			dataRec.bookType 	= caricomdialog->BookingCombo->GetValue();

			
			
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
			    string first = strip(string(dataRec.first.mb_str()));
			    string last = strip(string(dataRec.last.mb_str()));
			    string place = strip(string(dataRec.place.mb_str()));
			    string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			    string bookingType = strip(string(dataRec.bookType.mb_str()));

			    // ... Now send the data to the set
			    setA->add(id, first, last, place, timeOfYear, bookingType);                            
			}
			else
			    MainEditBox->AppendText(wxT("Record already exists within Set")); 
		    }

		else //if (caricomdialog->ShowModal() == wxID_CANCEL)
			 caricomdialog->Close();
			    
 
		caricomdialog->Destroy();			//Destroy the dialog box
		*/
  }  
  
  
  void ProjectFrame::OnAddSetB(wxCommandEvent& event)
  {/*
	Record dataRec;
		
		DataDialog *datadialog = new DataDialog( wxT("COMP2611 - Data Entry for Set B"), 
							 wxPoint(200,200), wxSize(420,290) );

		// If the OK button is clicked...
		if (datadialog->ShowModal() == wxID_OK )
		    {
			// Grab the Client ID
			dataRec.idNo = datadialog->IdNoEditBox->GetValue();
			
			//Grab value from the NameTextBox.
			dataRec.first = datadialog->NameEditBox->GetValue();
					
			//Grab value from the SurnameTextBox
			dataRec.last = datadialog->SurnameEditBox->GetValue();
			
			// Grab the Place
			dataRec.place = datadialog->PlaceEditBox->GetValue();
			
			
			//Grab the list item selected
			dataRec.timeOfYear 	= datadialog->SeasonCombo->GetValue();
			dataRec.bookType 	= datadialog->BookingCombo->GetValue();

			
			
			// Clear the edit box
			MainEditBox->Clear();
			
			
			    
			    
			    

			    //   You need to disaggregate the data from dataRec to
			    //   send them to your ADTs. e.g.:
			    
			    int    id = dataRec.idNo;
			    string first = strip(string(dataRec.first.mb_str()));
			    string last = strip(string(dataRec.last.mb_str()));
			    string place = strip(string(dataRec.place.mb_str()));
			    string timeOfYear = strip(string(dataRec.timeOfYear.mb_str()));
			    string bookingType = strip(string(dataRec.bookType.mb_str()));

			    if((setB->find(dataRec.idNo) == false) &&  place != strip("Antigua") && place != strip("Bahamas") && place !=  strip("Barbados") && place !=  strip("Belize") && place !=  strip("Dominica") 
			  && place !=  strip("Grenada") && place !=  strip("Guyana") && place !=  strip("Haiti") && place !=  strip("Jamaica") && place !=  strip("Montserrat") && place !=  strip("St Lucia") 
			  && place !=  strip("St Kitts") && place !=  strip("St Vincent") && place !=  strip("Suriname") && place != strip("Trinidad") &&  place != strip("antigua") && place != strip("bahamas") 
			  && place !=  strip("barbados") && place !=  strip("belize") && place !=  strip("dominica") && place !=  strip("grenada") && place !=  strip("guyana") && place !=  strip("haiti") 
			  && place !=  strip("jamaica") && place !=  strip("montserrat") && place !=  strip("st lucia") && place !=  strip("st kitts") && place !=  strip("st vincent") && place !=  strip("suriname") 
			  && place != strip("trinidad"))//if the ClientID doesn't already exist and place isn't a Caricom country
			{
			    
			    // ... Now send the data to the set
			    setB->add(id, first, last, place, timeOfYear, payType, bookingType); 
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
	*/	
  }  
  
  

  
