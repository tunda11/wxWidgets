//Programmer: Alec Gilkes 415002420


#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H
 
//Define a dialog box class - inheriting from wxDialog  
class DeleteDialog: public wxDialog
  {
	 public:
		DeleteDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
			  
		wxSpinCtrl* idNoEditBox;
		
  };
        
        
        
DeleteDialog::DeleteDialog ( const wxString& title, const wxPoint& pos, 
		         const wxSize& size): wxDialog((wxDialog *)NULL, -1, 
                         title, pos, size)
        {
		//Set up the panel
  		wxPanel    *panel = new wxPanel(this, -1);

		//Define and position the StaticText - i.e. the label
		wxStaticText *ClientIDLabel   = new wxStaticText(panel, wxID_ANY, wxT("Client ID"),
											    wxPoint(150, 70) );
		

		//Define and position the Data Entry Box		
		idNoEditBox 	= new wxSpinCtrl ( panel, wxID_ANY, wxT("0"), wxPoint(210, 66), 
								    wxSize(75, 20), wxSP_ARROW_KEYS, 11111, 99999, 1);	
		// Define and position the Response buttons (OK and CANCEL)
		
		// The OK button
		wxButton* ok = new wxButton( panel, wxID_OK, wxT("&OK"), wxPoint(100, 140), 
							    wxDefaultSize, 0);

		// The CANCEL button
		wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
						  wxPoint(240, 140), wxDefaultSize, 0 );
		
  		// Centre the dialog on the parent's window
		Centre();

        	Maximize(); // Maximize the window to full definition size
		
        }

#endif
