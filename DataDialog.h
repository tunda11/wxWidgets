//Programmer: Mellissa Marie 412002117


#ifndef MYDIALOG_H
#define MYDIALOG_H

 
struct record
        {
		int idNo;
		wxString fname;
		wxString lname;
		wxString destination;
		wxString season;
		wxString book;
	};
typedef struct record Record;


   
  
//Define a dialog box class - inheriting from wxDialog
class DataDialog: public wxDialog
  {
	 public:
		DataDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
			  
		wxSpinCtrl* idNoEditBox;
		
		wxTextCtrl* fNameEditBox;
		wxTextCtrl* lNameEditBox;
		wxTextCtrl* destinationEditBox;
		
		wxComboBox* SeasonCombo;	//For a drop-down list
		wxComboBox* BookingCombo;	//For a drop-down list
		
  };

  
  
DataDialog::DataDialog ( const wxString& title, const wxPoint& pos, const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
        {
		//Set up the panel
  		wxPanel    *panel = new wxPanel(this, -1);

		//Define and position the StaticTexts - i.e. the labels
		wxStaticText *idNoLabel   = new wxStaticText(panel, wxID_ANY, wxT("Client ID"),
											    wxPoint(100, 20) );
		wxStaticText *fNameLabel 		= new wxStaticText(panel, wxID_ANY, wxT("Name"),
											    wxPoint(15, 55) );
 		wxStaticText *lNameLabel    = new wxStaticText(panel, wxID_ANY, wxT("Surname"),
											    wxPoint(15, 90) );
 		wxStaticText *destination		= new wxStaticText(panel, wxID_ANY, wxT("Destination"),
											    wxPoint(15, 125) );
		wxStaticText *seasonLabel     = new wxStaticText(panel, wxID_ANY, wxT("Season"), 
											    wxPoint(15, 160) );
		wxStaticText *bookLabel	= new wxStaticText(panel, wxID_ANY, wxT("Booking Type"),
											    wxPoint(200, 160) );		
 		
		

		//Define and position the Data Entry Boxes		
		idNoEditBox 	= new wxSpinCtrl ( panel, wxID_ANY, wxT("0"), wxPoint(160, 16), 
								    wxSize(75, 20), wxSP_ARROW_KEYS, 11111, 99999, 1);	
		
		fNameEditBox  	= new wxTextCtrl ( panel, wxID_ANY, wxT("Name"), wxPoint(55, 53), 
								    wxSize(260, -1) );			
		lNameEditBox	= new wxTextCtrl ( panel, wxID_ANY, wxT("Surname"), wxPoint(80, 88), 
								    wxSize(260, -1) );			
		destinationEditBox	= new wxTextCtrl ( panel, wxID_ANY, wxT("Destination"), wxPoint(95, 123), 
								    wxSize(260, -1) );			

		
		//Define and position a drop-down list for the seasons
		wxArrayString season;
		season.Add(wxT("Spring"));
		season.Add(wxT("Summer"));
		season.Add(wxT("Fall"));
		season.Add(wxT("Winter"));
		SeasonCombo = new wxComboBox( panel, -1, wxT("Summer"), wxPoint(70, 158), wxSize(120, -1), 
								season, wxCB_READONLY);	

		//Define and position a drop-down list for type of booking
		wxArrayString booking;
		booking.Add(wxT("Gifted"));
		booking.Add(wxT("Internet"));
		booking.Add(wxT("Telephone"));
		booking.Add(wxT("Walk-in"));
		BookingCombo = new wxComboBox( panel, -1, wxT("Internet"), wxPoint(295, 158), 
					        wxSize(120, -1), booking, wxCB_READONLY);	



		// Define and position the Response buttons (OK and CANCEL)
		
		// The OK button
		wxButton* ok = new wxButton( panel, wxID_OK, wxT("&OK"), wxPoint(100, 240), 
							    wxDefaultSize, 0);

		// The CANCEL button
		wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
						  wxPoint(240, 240), wxDefaultSize, 0 );
		
  		// Centre the dialog on the parent's window
		Centre();

        	Maximize(); // Maximize the window to full definition size
		
        }
  

// Grab the data to display it in the MainEditBox
wxString getDataString(Record dataRec)
        {
                wxString str = wxT("\n\n");
    
                wxString idNoStr;
			 idNoStr << dataRec.idNo;
         
                str.Append(idNoStr);
                str.Append(wxT("\t"));
                str.Append(dataRec.fname);
                str.Append(wxT("\t"));
                str.Append(dataRec.lname);
                str.Append(wxT("\t"));
                str.Append(dataRec.destination);
                str.Append(wxT("\t"));
                str.Append(dataRec.season);
                str.Append(wxT("\t"));
                str.Append(dataRec.book);

			 str.Append(wxT("\n"));
	
                return str;
        }
        


#endif 
