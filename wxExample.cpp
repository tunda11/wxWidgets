/************************************************************************************
 *  Step 1: Always include the header file wx.h					    
 *************************************************************************************/
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/listbox.h>
#include <wx/numdlg.h>
#include <wx/textdlg.h>
#include <wx/platinfo.h>
#endif


#include <fstream>
#include <sstream>
#include <string>

//Inclusion of all Linked List ADT headers
#include "queueFile.h"
//#include <pQueue.h>
//#include <deque.h>
#include "stackFile.h"

using namespace std;

string to_string(int);
string strip(string);
string makeRecord(int, string, string, string, string, string);



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

string makeRecord(int id, string fname, string lname, string loc, string season, string booking)
    {
        string record = "";
        
        record = to_string(id);
        record.append("\t");
        record.append(fname);
        record.append("\t");
        record.append(lname);
        record.append("\t");
        record.append(loc);
        record.append("\t"); 
        record.append(season);
        record.append("\t");
        record.append(booking);
        
        return record;
    }
    
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

/*string makeRecord(int id, string fName, string lName, string loc, string season, string booking) {
    string str = to_String(id);
    
    while (fName.size() < 20) {
        fName.append(" ");
    }
    
    while (lName.size() < 20) {
        lName.append(" ");
    }
    
    while (loc.size() < 20) {
        loc.append(" ");
    }
    
    while (season.size() < 20) {
        season.append(" ");
    }
    
    while (booking.size() < 20) {
        booking.append(" ");
    }
    
    str.append(" ");
    str.append(fName);
    str.append(lName);
    str.append(loc);
    str.append(season);
    str.append(booking);
    return str;
    
}
    string to_String(int integer) 
    {
    stringstream ss;
    ss << integer;
    return ss.str();
    }*/

queue* myqueue = new queue(); 
stack* mystack = new stack();
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
        void OnCreateAvl(wxCommandEvent& event);  //handle for 'Create AVL' function
        void OnCreateBst(wxCommandEvent& event);  //handle for 'Create BST' function
        void OnCreateDeque(wxCommandEvent& event);  //handle for 'Create Deque' function
        void OnCreateHeap(wxCommandEvent& event);  //handle for 'Create Heap' function
        void OnCreatePQ(wxCommandEvent& event);  //handle for 'Create Priority Queue' function
        
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
        
        //Stack Events
        void OnCreateStack(wxCommandEvent& event); 	//handle for 'Create Stack' function
        void OnPush(wxCommandEvent& event);  //handle for 'Push' function
        void OnPop(wxCommandEvent& event);  //handle for 'Pop' function
        void OnDispAllSt(wxCommandEvent& event);  //handle for 'Display All' function for Stack
        
        void OnCreateRbt(wxCommandEvent& event); 	//handle for 'Create RBT' function
        void OnCreateSet(wxCommandEvent& event); 	//handle for 'Create Set' function
        void OnCreateSplay(wxCommandEvent& event); 	//handle for 'Create Splay' function
        
        void OnAddDataPQ(wxCommandEvent& event);  //handle for 'Add Data' pQueue function
        void OnAddDataBST(wxCommandEvent& event);  //handle for 'Add Data' BST function
        void OnAddDataAVL(wxCommandEvent& event);  //handle for 'Add Data' AVL function
        void OnAddDataH(wxCommandEvent& event);  //handle for 'Add Data' Heap Tree function
        void OnAddDataRBT(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnAddDataSp(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnAddDataSet(wxCommandEvent& event);  //handle for 'Add Data' function
        void OnAddHead(wxCommandEvent& event);  //hanle for 'Add Head' function
        void OnAddTail(wxCommandEvent& event);  //handle for 'Add Tail' function
        void OnDispAllDQ(wxCommandEvent& event);  //handle for 'Display All' function
        void OnDispAllPQ(wxCommandEvent& event);  //handle for 'Display All' function
        
        void OnDispAllH(wxCommandEvent& event);  //handle for 'Display All' function for Heap
        void OnDispSetA(wxCommandEvent& event);  //handle for 'Display SetA' function
        void OnDispSetB(wxCommandEvent& event);  //handle for 'Display SetB' function
        void OnDispInter(wxCommandEvent& event);  //handle for 'Display Intersection' function
        void OnDispUnion(wxCommandEvent& event);  //handle for 'Display Union' function
        void OnShowHeadDQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowHeadPQ(wxCommandEvent& event);  //handle for show head of Queue function
        void OnShowTailDQ(wxCommandEvent& event);  //handle for show tail of Queue function
        void OnShowTailPQ(wxCommandEvent& event);  //handle for show tail of Queue function
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
            
            ID_CreateAvl,
            ID_CreateBst,
            ID_CreateDeque,
            ID_CreateHeap,
            ID_CreatePQ,
            //Queue
            ID_CreateQueue,
            ID_AddDataQ,
            ID_DispAllQ,
            ID_DequeueQ,
            ID_ShowHeadQ,
            ID_ShowTailQ,
            
            //Stack
            ID_CreateStack,
            ID_Push,
            ID_Pop,
            ID_DispAllSt,
            
            ID_CreateRbt,
            ID_CreateSet,
            ID_CreateSplay,
            ID_AddDataPQ,
            ID_AddDataBST,
            ID_AddDataAVL,
            ID_AddDataH,
            ID_AddDataRBT,
            ID_AddDataSp,
            ID_AddDataSet,
            ID_AddHead,
            ID_AddTail,
            ID_DispAllDQ,
            ID_DispAllPQ,
            ID_DispAllH,
            ID_DispSetA,
            ID_DispSetB,
            ID_DispInter,
            ID_DispUnion,
            ID_ShowHeadDQ,
            ID_ShowHeadPQ,
            ID_ShowTailDQ,
            ID_ShowTailPQ,
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
        
        EVT_MENU ( ID_About, MyFrame::OnAbout )
        EVT_MENU ( ID_Help, MyFrame::OnHelp )
        //File
        EVT_MENU ( ID_OpenFile, MyFrame::OnOpenFile )
        EVT_MENU ( ID_Quit, MyFrame::OnQuit )
        EVT_MENU ( ID_SaveFile, MyFrame::OnSaveFile )
        EVT_MENU ( ID_SaveAsFile, MyFrame::OnSaveAsFile )
        
        EVT_MENU ( ID_CreateAvl, MyFrame::OnCreateAvl )
        EVT_MENU ( ID_CreateBst, MyFrame::OnCreateBst )
        EVT_MENU ( ID_CreateDeque, MyFrame::OnCreateDeque )
        EVT_MENU ( ID_CreateHeap, MyFrame::OnCreateHeap )
        EVT_MENU ( ID_CreatePQ, MyFrame::OnCreatePQ )
        
        //Queue
        EVT_MENU ( ID_CreateQueue, MyFrame::OnCreateQueue )
        EVT_MENU ( ID_AddDataQ, MyFrame::OnAddDataQ )        
        EVT_MENU ( ID_DispAllQ, MyFrame::OnDispAllQ )
        EVT_MENU ( ID_ShowHeadQ, MyFrame::OnShowHeadQ )
        EVT_MENU ( ID_ShowTailQ, MyFrame::OnShowTailQ )
        EVT_MENU ( ID_DequeueQ, MyFrame::OnDequeueQ )
        
        //Stack
        EVT_MENU ( ID_CreateStack, MyFrame::OnCreateStack )
        EVT_MENU ( ID_Push, MyFrame::OnPush )
        EVT_MENU ( ID_Pop, MyFrame::OnPop )
        EVT_MENU ( ID_DispAllSt, MyFrame::OnDispAllSt )
        
        EVT_MENU ( ID_CreateRbt, MyFrame::OnCreateRbt )
        EVT_MENU ( ID_CreateSet, MyFrame::OnCreateSet )
        EVT_MENU ( ID_CreateSplay, MyFrame::OnCreateSplay )
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
        EVT_MENU ( ID_DispAllDQ, MyFrame::OnDispAllDQ )
        EVT_MENU ( ID_DispAllPQ, MyFrame::OnDispAllPQ )
        EVT_MENU ( ID_DispAllH, MyFrame::OnDispAllH )
        EVT_MENU ( ID_ShowHeadDQ, MyFrame::OnShowHeadDQ )
        EVT_MENU ( ID_ShowHeadPQ, MyFrame::OnShowHeadPQ )
        EVT_MENU ( ID_ShowTailDQ, MyFrame::OnShowTailDQ )
        EVT_MENU ( ID_ShowTailPQ, MyFrame::OnShowTailPQ )
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
        menuFile->Append( ID_SaveFile, wxT("&Save File") );
        menuFile->Append( ID_SaveAsFile, wxT("&Save As") );
        
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
        
        
	//Set up the panel for data display


	wxPanel 	*panel 	= new wxPanel(this, -1);
	wxBoxSizer 	*vbox 	= new wxBoxSizer(wxVERTICAL);		//Vertical sizer for main window
	wxBoxSizer 	*hbox1 	= new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for main window

	//Add two textboxes to the panel for data display
	wxBoxSizer 	*hbox2 	= new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for filename window
	wxBoxSizer 	*hbox3 	= new wxBoxSizer(wxHORIZONTAL);		//Horizontal sizer for display window
	
	wxStaticText 	*fileLabel 	= new wxStaticText(panel, wxID_ANY, wxT("File Name"));
	wxStaticText 	*displayLabel 	= new wxStaticText(panel, wxID_ANY, wxT("Display"));

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
        wxString msg;
    
        msg.Printf(wxT("Hello and welcome to %s"), wxVERSION_STRING);
    
        wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
    }


void MyFrame::OnHelp ( wxCommandEvent& WXUNUSED ( event ) )
    {
        wxMessageBox(wxT("HELP!!!"), wxT("Minimal Help"), 
                     wxOK | wxCANCEL | wxICON_QUESTION, this);
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
    

    int num;
        string fname;
        string lname;
        string loc;
        string season;
        string book;
        
        char comma;// = ',';
        
    string record;
    string theRecord;
    string titleLine;
    
    // Clear the edit box
        MainEditBox->Clear();
    //myqueue ->~queue();
    
	//Empty the Queue
	myqueue->emptyQueue();
      
	//Create filename pointer    
    //ifstream inFile;
    //open the file
    ifstream inFile(CurrentDocPath.mb_str(), ios::in);
    
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
            //test->enqueue(num, a, b, c, d, e);
            inFile  >> num >> comma;
                getline(inFile, fname, ',');
                getline(inFile, lname, ',');
                getline(inFile, loc, ',');
                getline(inFile, season, ',');
                getline(inFile, book, '\n');
           
                
                if (!inFile.eof())
		  {
			fname = strip(fname);
			lname = strip(lname);
			loc = strip(loc);
			season = strip(season);
			book = strip(book);
                   
			record = makeRecord(num, fname, lname, loc, season, book);
						
						
			myqueue->enqueue(num, fname, lname, loc, season, book);
		  }//endif
		  
		  wxString wxRecords(record.c_str(), wxConvUTF8);
        MainEditBox->AppendText(wxRecords);
        MainEditBox->AppendText(wxT("\n"));
			
        //Reset record variable
        record = " ";
        }//endWhile
        
       
    
  } 
  
  void MyFrame::OnDequeueQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string record;
        
        //Clear the main edit box
        MainEditBox->Clear();
    
        record = myqueue->dequeue();
        
        //Converts record data to a string
        wxString wxRecords(record.c_str(), wxConvUTF8);
        
        //display information in Edit box
        MainEditBox->AppendText(wxRecords);
    
    
    }
    
void MyFrame::OnShowHeadQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, titleLine;
	
	// Clear the edit box
	MainEditBox->Clear();
    
    // Create a label for the displayed records
        titleLine = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tPayment \t\tBooking\n";

        titleLine.append("==================================================================================================\n");
	records.append(titleLine);
    
	//Go grab the data
	records.append(myqueue->theFront());
      
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
    MainEditBox->AppendText(wxT("\t\t\t\t\nAt the front of the queue is:\n\n"));
	MainEditBox->AppendText(wxRecords); 
    }
    
void MyFrame::OnShowTailQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
         string records, titleLine;
	
	// Clear the edit box
	MainEditBox->Clear();
    
    // Create a label for the displayed records
        titleLine = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tPayment \t\tBooking\n";

        titleLine.append("==================================================================================================\n");
	records.append(titleLine);
  
	//Go grab the data
	records.append(myqueue->theBack());
   
      
	//Convert to a wxString
	wxString wxRecord(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
    MainEditBox->AppendText(wxT("\t\t\t\t\nAt the back of the queue is:\n\n"));
	MainEditBox->AppendText(wxRecord); 
    MainEditBox->AppendText(wxT("\n"));
    }
    
void MyFrame::OnDispAllQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
      string records, titleLine;
	
	// Clear the edit box
	MainEditBox->Clear();
    
    // Create a label for the displayed records
        titleLine = "Client ID \t FirstName \t\tSurname \t\tDestination \t\tSeason \t\tPayment \t\tBooking\n";

        titleLine.append("==================================================================================================\n");
	records.append(titleLine);
  
	//Go grab the data
	records = myqueue->displayQ();
      
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
    MainEditBox->AppendText(wxT("\t\t\t\t\nAll current records:\n\n"));
	MainEditBox->AppendText(wxRecords); 
    }
    
    
void MyFrame::OnAddDataQ ( wxCommandEvent& WXUNUSED ( event ) )
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
    
    
//STACK FUNCTION DEFINITION DECLARATIONS
void MyFrame::OnCreateStack ( wxCommandEvent& WXUNUSED ( event ) )
    {
        //ONLY THE SPRING RECORDS ARE REQUIRED
            
            int num;
            string fname;
            string lname;
            string loc;
            string season;
            string book;
            string Spring = "Spring";
        
            char comma = ',';
        
            string record;
            string theRecord;
            string titleLine;
    
            // Clear the edit box
            MainEditBox->Clear();
    
            //Empty the Stack
            mystack->emptyStack();
      
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
                    Spring = strip(Spring);
              
                if (season == Spring)
                {
                    record = makeRecord(num, fname, lname, loc, season, book);
                    mystack->push(num, fname, lname, loc, season, book);
                    
                    wxString wxRecords(record.c_str(), wxConvUTF8);
                    MainEditBox->AppendText(wxRecords);
                    MainEditBox->AppendText(wxT("\n"));
        
                    record = " ";
                }//end of seasonal if statement
                
                }//end of File If
                
            }//end While
        
    }
    
void MyFrame::OnPush ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnPop ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, titleLine;
        // Clear the edit box
        MainEditBox->Clear();
  
        // Create a label for the displayed records
        titleLine = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tPayment \t\tBooking\n";

        titleLine.append("==================================================================================================\n");
	records.append(titleLine);
	
	records.append(mystack->pop());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);
	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Stack:\n\n"));
	MainEditBox->AppendText(wxRecords);
    }
    
    
void MyFrame::OnDispAllSt ( wxCommandEvent& WXUNUSED ( event ) )
    {
        string records, titleLine;
        // Clear the edit box
        MainEditBox->Clear();
  
        // Create a label for the displayed records
        titleLine = "Client ID \t\tFirstName \t\tSurname \t\tDestination \t\tSeason \t\tPayment \t\tBooking\n";

        titleLine.append("==================================================================================================\n");
	records.append(titleLine);
	
	records.append(mystack->dList());
		
	//Convert to a wxString
	wxString wxRecords(records.c_str(), wxConvUTF8);
	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Stack:\n\n"));
	MainEditBox->AppendText(wxRecords);
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
    

void MyFrame::OnDispAllDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnDispAllPQ ( wxCommandEvent& WXUNUSED ( event ) )
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
    

    
void MyFrame::OnShowHeadDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowHeadPQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    

    
void MyFrame::OnShowTailDQ ( wxCommandEvent& WXUNUSED ( event ) )
    {
        
    }
    
void MyFrame::OnShowTailPQ ( wxCommandEvent& WXUNUSED ( event ) )
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
