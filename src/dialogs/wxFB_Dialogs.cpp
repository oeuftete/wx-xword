///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 11 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxFB_Dialogs.h"

///////////////////////////////////////////////////////////////////////////

wxFB_PropertiesDialog::wxFB_PropertiesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* sizer;
	sizer = new wxBoxSizer( wxVERTICAL );
	
	wxNotebook* notebook;
	notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	wxPanel* solvePanel;
	solvePanel = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( solvePanel, wxID_ANY, wxT("Cursor Movement") ), wxVERTICAL );
	
	wxString m_afterLetterChoices[] = { wxT("Do not move"), wxT("Move to next square"), wxT("Move to next blank") };
	int m_afterLetterNChoices = sizeof( m_afterLetterChoices ) / sizeof( wxString );
	m_afterLetter = new wxRadioBox( solvePanel, wxID_ANY, wxT("After entering a letter"), wxDefaultPosition, wxDefaultSize, m_afterLetterNChoices, m_afterLetterChoices, 1, wxRA_SPECIFY_COLS );
	m_afterLetter->SetSelection( 0 );
	sbSizer3->Add( m_afterLetter, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( solvePanel, wxID_ANY, wxT("Move to a blank square") ), wxVERTICAL );
	
	m_blankOnDirection = new wxCheckBox( solvePanel, wxID_ANY, wxT("After switching directions"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_blankOnDirection, 0, wxALL, 5 );
	
	m_blankOnNewWord = new wxCheckBox( solvePanel, wxID_ANY, wxT("After moving to a new word"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_blankOnNewWord, 0, wxALL, 5 );
	
	sbSizer3->Add( sbSizer5, 1, wxALL|wxEXPAND, 5 );
	
	wxString m_pauseOnSwitchChoices[] = { wxT("Move cursor"), wxT("Keep cursor on current square") };
	int m_pauseOnSwitchNChoices = sizeof( m_pauseOnSwitchChoices ) / sizeof( wxString );
	m_pauseOnSwitch = new wxRadioBox( solvePanel, wxID_ANY, wxT("When switching with arrow keys"), wxDefaultPosition, wxDefaultSize, m_pauseOnSwitchNChoices, m_pauseOnSwitchChoices, 1, wxRA_SPECIFY_COLS );
	m_pauseOnSwitch->SetSelection( 0 );
	sbSizer3->Add( m_pauseOnSwitch, 0, wxALL|wxEXPAND, 5 );
	
	bSizer4->Add( sbSizer3, 0, wxALL|wxEXPAND, 5 );
	
	bSizer3->Add( bSizer4, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( solvePanel, wxID_ANY, wxT("Right mouse button") ), wxVERTICAL );
	
	m_moveOnRightClick = new wxCheckBox( solvePanel, wxID_ANY, wxT("Move to mouse position"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_moveOnRightClick, 0, wxALL, 5 );
	
	bSizer5->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( solvePanel, wxID_ANY, wxT("Misc") ), wxVERTICAL );
	
	m_checkWhileTyping = new wxCheckBox( solvePanel, wxID_ANY, wxT("Check solution while typing"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer41->Add( m_checkWhileTyping, 0, wxALL, 5 );
	
	bSizer5->Add( sbSizer41, 0, wxALL|wxEXPAND, 5 );
	
	bSizer3->Add( bSizer5, 1, wxALL|wxEXPAND, 5 );
	
	solvePanel->SetSizer( bSizer3 );
	solvePanel->Layout();
	bSizer3->Fit( solvePanel );
	notebook->AddPage( solvePanel, wxT("Solving"), true );
	wxPanel* colorPanel;
	colorPanel = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	sbSizer36 = new wxStaticBoxSizer( new wxStaticBox( colorPanel, wxID_ANY, wxT("Grid") ), wxVERTICAL );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_selectedLetterColor = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer61->Add( m_selectedLetterColor, 0, 0, 5 );
	
	wxStaticText* m_staticText1;
	m_staticText1 = new wxStaticText( colorPanel, wxID_ANY, wxT("Selected square"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer61->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer36->Add( bSizer61, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxHORIZONTAL );
	
	m_selectedWordColor = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer611->Add( m_selectedWordColor, 0, 0, 5 );
	
	wxStaticText* m_staticText11;
	m_staticText11 = new wxStaticText( colorPanel, wxID_ANY, wxT("Selected word"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer611->Add( m_staticText11, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer36->Add( bSizer611, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer612;
	bSizer612 = new wxBoxSizer( wxHORIZONTAL );
	
	m_penColor = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer612->Add( m_penColor, 0, 0, 5 );
	
	wxStaticText* m_staticText12;
	m_staticText12 = new wxStaticText( colorPanel, wxID_ANY, wxT("Pen"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer612->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer36->Add( bSizer612, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer613;
	bSizer613 = new wxBoxSizer( wxHORIZONTAL );
	
	m_pencilColor = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	m_pencilColor->Hide();
	
	bSizer613->Add( m_pencilColor, 0, 0, 5 );
	
	wxStaticText* m_staticText13;
	m_staticText13 = new wxStaticText( colorPanel, wxID_ANY, wxT("Pencil"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->Hide();
	
	bSizer613->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer36->Add( bSizer613, 0, wxEXPAND, 5 );
	
	bSizer33->Add( sbSizer36, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( colorPanel, wxID_ANY, wxT("Clue Prompt") ), wxVERTICAL );
	
	wxBoxSizer* bSizer613511;
	bSizer613511 = new wxBoxSizer( wxHORIZONTAL );
	
	m_cluePromptBackground = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer613511->Add( m_cluePromptBackground, 0, 0, 5 );
	
	wxStaticText* m_staticText13511;
	m_staticText13511 = new wxStaticText( colorPanel, wxID_ANY, wxT("Background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13511->Wrap( -1 );
	bSizer613511->Add( m_staticText13511, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer7->Add( bSizer613511, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer613512;
	bSizer613512 = new wxBoxSizer( wxHORIZONTAL );
	
	m_cluePromptText = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer613512->Add( m_cluePromptText, 0, 0, 5 );
	
	wxStaticText* m_staticText13512;
	m_staticText13512 = new wxStaticText( colorPanel, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13512->Wrap( -1 );
	bSizer613512->Add( m_staticText13512, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer7->Add( bSizer613512, 0, wxEXPAND, 5 );
	
	bSizer33->Add( sbSizer7, 0, wxALL|wxEXPAND, 5 );
	
	bSizer35->Add( bSizer33, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( colorPanel, wxID_ANY, wxT("Clue List") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6131;
	bSizer6131 = new wxBoxSizer( wxHORIZONTAL );
	
	m_clueBackground = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer6131->Add( m_clueBackground, 0, 0, 5 );
	
	wxStaticText* m_staticText131;
	m_staticText131 = new wxStaticText( colorPanel, wxID_ANY, wxT("Background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	bSizer6131->Add( m_staticText131, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer6131, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6132;
	bSizer6132 = new wxBoxSizer( wxHORIZONTAL );
	
	m_clueText = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer6132->Add( m_clueText, 0, 0, 5 );
	
	wxStaticText* m_staticText132;
	m_staticText132 = new wxStaticText( colorPanel, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText132->Wrap( -1 );
	bSizer6132->Add( m_staticText132, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer6132, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6133;
	bSizer6133 = new wxBoxSizer( wxHORIZONTAL );
	
	m_selectedClueBackground = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer6133->Add( m_selectedClueBackground, 0, 0, 5 );
	
	wxStaticText* m_staticText133;
	m_staticText133 = new wxStaticText( colorPanel, wxID_ANY, wxT("Current clue background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText133->Wrap( -1 );
	bSizer6133->Add( m_staticText133, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer6133, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6134;
	bSizer6134 = new wxBoxSizer( wxHORIZONTAL );
	
	m_selectedClueText = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer6134->Add( m_selectedClueText, 0, 0, 5 );
	
	wxStaticText* m_staticText134;
	m_staticText134 = new wxStaticText( colorPanel, wxID_ANY, wxT("Current clue text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134->Wrap( -1 );
	bSizer6134->Add( m_staticText134, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer6134, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6135;
	bSizer6135 = new wxBoxSizer( wxHORIZONTAL );
	
	m_crossingClueBackground = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer6135->Add( m_crossingClueBackground, 0, 0, 5 );
	
	wxStaticText* m_staticText135;
	m_staticText135 = new wxStaticText( colorPanel, wxID_ANY, wxT("Crossing clue background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText135->Wrap( -1 );
	bSizer6135->Add( m_staticText135, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer6135, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61351;
	bSizer61351 = new wxBoxSizer( wxHORIZONTAL );
	
	m_crossingClueText = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer61351->Add( m_crossingClueText, 0, 0, 5 );
	
	wxStaticText* m_staticText1351;
	m_staticText1351 = new wxStaticText( colorPanel, wxID_ANY, wxT("Crossing clue text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1351->Wrap( -1 );
	bSizer61351->Add( m_staticText1351, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer61351, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer613513;
	bSizer613513 = new wxBoxSizer( wxHORIZONTAL );
	
	m_clueHeadingBackground = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer613513->Add( m_clueHeadingBackground, 0, 0, 5 );
	
	wxStaticText* m_staticText13513;
	m_staticText13513 = new wxStaticText( colorPanel, wxID_ANY, wxT("Heading background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13513->Wrap( -1 );
	bSizer613513->Add( m_staticText13513, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer613513, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6135131;
	bSizer6135131 = new wxBoxSizer( wxHORIZONTAL );
	
	m_clueHeadingText = new wxColourPickerCtrl( colorPanel, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer6135131->Add( m_clueHeadingText, 0, 0, 5 );
	
	wxStaticText* m_staticText135131;
	m_staticText135131 = new wxStaticText( colorPanel, wxID_ANY, wxT("Heading text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText135131->Wrap( -1 );
	bSizer6135131->Add( m_staticText135131, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	sbSizer6->Add( bSizer6135131, 0, wxEXPAND, 5 );
	
	bSizer37->Add( sbSizer6, 0, wxALL|wxEXPAND, 5 );
	
	bSizer35->Add( bSizer37, 1, wxEXPAND, 5 );
	
	colorPanel->SetSizer( bSizer35 );
	colorPanel->Layout();
	bSizer35->Fit( colorPanel );
	notebook->AddPage( colorPanel, wxT("Colors"), false );
	wxPanel* fontPanel;
	fontPanel = new wxPanel( notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer614;
	bSizer614 = new wxBoxSizer( wxHORIZONTAL );
	
	m_gridFont = new wxFontPickerCtrl( fontPanel, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	m_gridFont->SetMaxPointSize( 100 ); 
	bSizer614->Add( m_gridFont, 0, wxALL, 5 );
	
	wxStaticText* m_staticText14;
	m_staticText14 = new wxStaticText( fontPanel, wxID_ANY, wxT("Grid (font size is ignored)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer614->Add( m_staticText14, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	bSizer20->Add( bSizer614, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6142;
	bSizer6142 = new wxBoxSizer( wxHORIZONTAL );
	
	m_cluePromptFont = new wxFontPickerCtrl( fontPanel, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	m_cluePromptFont->SetMaxPointSize( 100 ); 
	bSizer6142->Add( m_cluePromptFont, 0, wxALL, 5 );
	
	wxStaticText* m_staticText142;
	m_staticText142 = new wxStaticText( fontPanel, wxID_ANY, wxT("Clue prompt (font size is ignored)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText142->Wrap( -1 );
	bSizer6142->Add( m_staticText142, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	bSizer20->Add( bSizer6142, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6141;
	bSizer6141 = new wxBoxSizer( wxHORIZONTAL );
	
	m_clueFont = new wxFontPickerCtrl( fontPanel, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	m_clueFont->SetMaxPointSize( 100 ); 
	bSizer6141->Add( m_clueFont, 0, wxALL, 5 );
	
	wxStaticText* m_staticText141;
	m_staticText141 = new wxStaticText( fontPanel, wxID_ANY, wxT("Clue list"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	bSizer6141->Add( m_staticText141, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	bSizer20->Add( bSizer6141, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61411;
	bSizer61411 = new wxBoxSizer( wxHORIZONTAL );
	
	m_clueHeadingFont = new wxFontPickerCtrl( fontPanel, wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	m_clueHeadingFont->SetMaxPointSize( 100 ); 
	bSizer61411->Add( m_clueHeadingFont, 0, wxALL, 5 );
	
	wxStaticText* m_staticText1411;
	m_staticText1411 = new wxStaticText( fontPanel, wxID_ANY, wxT("Clue list heading"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1411->Wrap( -1 );
	bSizer61411->Add( m_staticText1411, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	bSizer20->Add( bSizer61411, 0, wxEXPAND, 5 );
	
	bSizer30->Add( bSizer20, 1, wxALL|wxEXPAND, 5 );
	
	fontPanel->SetSizer( bSizer30 );
	fontPanel->Layout();
	bSizer30->Fit( fontPanel );
	notebook->AddPage( fontPanel, wxT("Fonts"), false );
	
	sizer->Add( notebook, 1, wxEXPAND | wxALL, 5 );
	
	wxStdDialogButtonSizer* buttons;
	wxButton* buttonsOK;
	wxButton* buttonsCancel;
	buttons = new wxStdDialogButtonSizer();
	buttonsOK = new wxButton( this, wxID_OK );
	buttons->AddButton( buttonsOK );
	buttonsCancel = new wxButton( this, wxID_CANCEL );
	buttons->AddButton( buttonsCancel );
	buttons->Realize();
	sizer->Add( buttons, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( sizer );
	this->Layout();
	sizer->Fit( this );
	
	// Connect Events
	m_afterLetter->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( wxFB_PropertiesDialog::OnAfterLetter ), NULL, this );
	m_blankOnDirection->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnBlankOnDirection ), NULL, this );
	m_blankOnNewWord->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnBlankOnNewWord ), NULL, this );
	m_pauseOnSwitch->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( wxFB_PropertiesDialog::OnPauseOnSwitch ), NULL, this );
	m_moveOnRightClick->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnMoveOnRightClick ), NULL, this );
	m_checkWhileTyping->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnCheckWhileTyping ), NULL, this );
	m_selectedLetterColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedLetterColor ), NULL, this );
	m_selectedWordColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedWordColor ), NULL, this );
	m_penColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPenColor ), NULL, this );
	m_pencilColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPencilColor ), NULL, this );
	m_cluePromptBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPromptBackgroundColor ), NULL, this );
	m_cluePromptText->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPromptTextColor ), NULL, this );
	m_clueBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueBackgroundColor ), NULL, this );
	m_clueText->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueTextColor ), NULL, this );
	m_selectedClueBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedClueBackgroundColor ), NULL, this );
	m_selectedClueText->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedClueTextColor ), NULL, this );
	m_crossingClueBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnCrossingClueBackgroundColor ), NULL, this );
	m_crossingClueText->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnCrossingClueTextColor ), NULL, this );
	m_clueHeadingBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueHeadingBackgroundColor ), NULL, this );
	m_clueHeadingText->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueHeadingTextColor ), NULL, this );
	m_gridFont->Connect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnGridFont ), NULL, this );
	m_cluePromptFont->Connect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnCluePromptFont ), NULL, this );
	m_clueFont->Connect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnClueFont ), NULL, this );
	m_clueHeadingFont->Connect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnClueHeadingFont ), NULL, this );
}

wxFB_PropertiesDialog::~wxFB_PropertiesDialog()
{
	// Disconnect Events
	m_afterLetter->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( wxFB_PropertiesDialog::OnAfterLetter ), NULL, this );
	m_blankOnDirection->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnBlankOnDirection ), NULL, this );
	m_blankOnNewWord->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnBlankOnNewWord ), NULL, this );
	m_pauseOnSwitch->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( wxFB_PropertiesDialog::OnPauseOnSwitch ), NULL, this );
	m_moveOnRightClick->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnMoveOnRightClick ), NULL, this );
	m_checkWhileTyping->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_PropertiesDialog::OnCheckWhileTyping ), NULL, this );
	m_selectedLetterColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedLetterColor ), NULL, this );
	m_selectedWordColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedWordColor ), NULL, this );
	m_penColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPenColor ), NULL, this );
	m_pencilColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPencilColor ), NULL, this );
	m_cluePromptBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPromptBackgroundColor ), NULL, this );
	m_cluePromptText->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnPromptTextColor ), NULL, this );
	m_clueBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueBackgroundColor ), NULL, this );
	m_clueText->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueTextColor ), NULL, this );
	m_selectedClueBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedClueBackgroundColor ), NULL, this );
	m_selectedClueText->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnSelectedClueTextColor ), NULL, this );
	m_crossingClueBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnCrossingClueBackgroundColor ), NULL, this );
	m_crossingClueText->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnCrossingClueTextColor ), NULL, this );
	m_clueHeadingBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueHeadingBackgroundColor ), NULL, this );
	m_clueHeadingText->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( wxFB_PropertiesDialog::OnClueHeadingTextColor ), NULL, this );
	m_gridFont->Disconnect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnGridFont ), NULL, this );
	m_cluePromptFont->Disconnect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnCluePromptFont ), NULL, this );
	m_clueFont->Disconnect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnClueFont ), NULL, this );
	m_clueHeadingFont->Disconnect( wxEVT_COMMAND_FONTPICKER_CHANGED, wxFontPickerEventHandler( wxFB_PropertiesDialog::OnClueHeadingFont ), NULL, this );
}

wxFB_ConvertDialog::wxFB_ConvertDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_mainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Files") ), wxVERTICAL );
	
	m_list = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 400,150 ), wxLC_REPORT );
	sbSizer2->Add( m_list, 1, wxALL|wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_optionsButton = new wxButton( this, wxID_ANY, wxT("Options <<<"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( m_optionsButton, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_add = new wxButton( this, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( m_add, 0, wxALL, 5 );
	
	m_remove = new wxButton( this, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( m_remove, 0, wxALL, 5 );
	
	m_runButton = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( m_runButton, 0, wxALL, 5 );
	
	bSizer35->Add( bSizer32, 0, wxALIGN_RIGHT, 5 );
	
	bSizer34->Add( bSizer35, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer34, 1, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer33, 0, wxEXPAND, 5 );
	
	m_mainSizer->Add( bSizer1, 1, wxEXPAND, 5 );
	
	m_optionsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	wxBoxSizer* bSizer351;
	bSizer351 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_overwriteChoices[] = { wxT("Rename"), wxT("Overwrite") };
	int m_overwriteNChoices = sizeof( m_overwriteChoices ) / sizeof( wxString );
	m_overwrite = new wxRadioBox( this, wxID_ANY, wxT("Name Collisions"), wxDefaultPosition, wxDefaultSize, m_overwriteNChoices, m_overwriteChoices, 1, wxRA_SPECIFY_ROWS );
	m_overwrite->SetSelection( 0 );
	bSizer351->Add( m_overwrite, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_errorHandlingChoices[] = { wxT("Ignore if possible"), wxT("Always fail") };
	int m_errorHandlingNChoices = sizeof( m_errorHandlingChoices ) / sizeof( wxString );
	m_errorHandling = new wxRadioBox( this, wxID_ANY, wxT("Error Handling"), wxDefaultPosition, wxDefaultSize, m_errorHandlingNChoices, m_errorHandlingChoices, 1, wxRA_SPECIFY_ROWS );
	m_errorHandling->SetSelection( 1 );
	bSizer351->Add( m_errorHandling, 0, wxALL|wxEXPAND, 5 );
	
	m_optionsSizer->Add( bSizer351, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output Directory") ), wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_useInput = new wxRadioButton( this, wxID_ANY, wxT("Use input folder"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_useInput->SetValue( true ); 
	bSizer3->Add( m_useInput, 0, wxALL, 5 );
	
	m_specifyDirectory = new wxRadioButton( this, wxID_ANY, wxT("Specify a directory"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_specifyDirectory, 0, wxALL, 5 );
	
	sbSizer4->Add( bSizer3, 0, 0, 5 );
	
	m_outputDirectory = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Default output folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	m_outputDirectory->Enable( false );
	
	sbSizer4->Add( m_outputDirectory, 1, wxALL|wxEXPAND, 5 );
	
	m_optionsSizer->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Log") ), wxHORIZONTAL );
	
	m_useLog = new wxCheckBox( this, wxID_ANY, wxT("Use log"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_useLog, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_logfile = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	m_logfile->Enable( false );
	
	sbSizer5->Add( m_logfile, 1, wxALL|wxEXPAND, 5 );
	
	m_optionsSizer->Add( sbSizer5, 0, wxEXPAND|wxALL, 5 );
	
	m_mainSizer->Add( m_optionsSizer, 0, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( m_mainSizer );
	this->Layout();
	m_mainSizer->Fit( this );
	
	// Connect Events
	m_list->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( wxFB_ConvertDialog::OnDoubleClick ), NULL, this );
	m_optionsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnShowOptions ), NULL, this );
	m_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnAdd ), NULL, this );
	m_remove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnRemove ), NULL, this );
	m_runButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnRunButton ), NULL, this );
	m_specifyDirectory->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ConvertDialog::OnSpecifyDirectory ), NULL, this );
	m_useLog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnUseLog ), NULL, this );
}

wxFB_ConvertDialog::~wxFB_ConvertDialog()
{
	// Disconnect Events
	m_list->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( wxFB_ConvertDialog::OnDoubleClick ), NULL, this );
	m_optionsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnShowOptions ), NULL, this );
	m_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnAdd ), NULL, this );
	m_remove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnRemove ), NULL, this );
	m_runButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnRunButton ), NULL, this );
	m_specifyDirectory->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ConvertDialog::OnSpecifyDirectory ), NULL, this );
	m_useLog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_ConvertDialog::OnUseLog ), NULL, this );
}