/***************************************************************
 * Name:      olaMain.cpp
 * Purpose:   Code for Application Frame
 * Purpose:   Code for Application Frame
 * Author:    ja (ja)
 * Created:   2011-07-27
 * Copyright: ja (ja)
 * License:
 **************************************************************/

#include "olaMain.h"

#include <wx/msgdlg.h>

//(*InternalHeaders(olaFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(olaFrame)
const long olaFrame::ID_CHECKLISTBOX1 = wxNewId();
const long olaFrame::ID_STATICTEXT1 = wxNewId();
const long olaFrame::ID_TEXTCTRL1 = wxNewId();
const long olaFrame::ID_STATICTEXT2 = wxNewId();
const long olaFrame::ID_TEXTCTRL2 = wxNewId();
const long olaFrame::ID_STATICTEXT8 = wxNewId();
const long olaFrame::ID_DATEPICKERCTRL1 = wxNewId();
const long olaFrame::ID_STATICTEXT7 = wxNewId();
const long olaFrame::ID_DATEPICKERCTRL2 = wxNewId();
const long olaFrame::ID_STATICTEXT3 = wxNewId();
const long olaFrame::ID_COMBOBOX1 = wxNewId();
const long olaFrame::ID_STATICTEXT26 = wxNewId();
const long olaFrame::ID_COMBOBOX8 = wxNewId();
const long olaFrame::ID_STATICTEXT4 = wxNewId();
const long olaFrame::ID_COMBOBOX2 = wxNewId();
const long olaFrame::ID_STATICTEXT5 = wxNewId();
const long olaFrame::ID_COMBOBOX3 = wxNewId();
const long olaFrame::ID_STATICTEXT23 = wxNewId();
const long olaFrame::ID_COMBOBOX4 = wxNewId();
const long olaFrame::ID_STATICTEXT6 = wxNewId();
const long olaFrame::ID_COMBOBOX5 = wxNewId();
const long olaFrame::ID_STATICTEXT24 = wxNewId();
const long olaFrame::ID_COMBOBOX6 = wxNewId();
const long olaFrame::ID_STATICTEXT25 = wxNewId();
const long olaFrame::ID_COMBOBOX7 = wxNewId();
const long olaFrame::ID_BUTTON2 = wxNewId();
const long olaFrame::ID_BUTTON1 = wxNewId();
const long olaFrame::ID_BUTTON7 = wxNewId();
const long olaFrame::ID_BUTTON3 = wxNewId();
const long olaFrame::ID_BUTTON4 = wxNewId();
const long olaFrame::ID_BUTTON5 = wxNewId();
const long olaFrame::ID_STATICTEXT27 = wxNewId();
const long olaFrame::ID_BUTTON6 = wxNewId();
const long olaFrame::ID_PANEL1 = wxNewId();
const long olaFrame::ID_GRID1 = wxNewId();
const long olaFrame::ID_GRID2 = wxNewId();
const long olaFrame::ID_STATICTEXT15 = wxNewId();
const long olaFrame::ID_STATICTEXT16 = wxNewId();
const long olaFrame::ID_STATICTEXT17 = wxNewId();
const long olaFrame::ID_STATICTEXT9 = wxNewId();
const long olaFrame::ID_STATICTEXT10 = wxNewId();
const long olaFrame::ID_STATICTEXT11 = wxNewId();
const long olaFrame::ID_STATICTEXT18 = wxNewId();
const long olaFrame::ID_STATICTEXT19 = wxNewId();
const long olaFrame::ID_STATICTEXT20 = wxNewId();
const long olaFrame::ID_STATICTEXT12 = wxNewId();
const long olaFrame::ID_STATICTEXT13 = wxNewId();
const long olaFrame::ID_STATICTEXT14 = wxNewId();
const long olaFrame::ID_PANEL2 = wxNewId();
const long olaFrame::ID_GRID3 = wxNewId();
const long olaFrame::ID_STATICTEXT22 = wxNewId();
const long olaFrame::ID_TEXTCTRL4 = wxNewId();
const long olaFrame::ID_STATICTEXT21 = wxNewId();
const long olaFrame::ID_TEXTCTRL3 = wxNewId();
const long olaFrame::ID_GRID5 = wxNewId();
const long olaFrame::ID_GRID7 = wxNewId();
const long olaFrame::ID_PANEL3 = wxNewId();
const long olaFrame::ID_NOTEBOOK2 = wxNewId();
const long olaFrame::idSync = wxNewId();
const long olaFrame::idMenuQuit = wxNewId();
const long olaFrame::idMenuAbout = wxNewId();
const long olaFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(olaFrame,wxFrame)
    //(*EventTable(olaFrame)
    //*)
    EVT_CLOSE(olaFrame::OnCloseWindow)
END_EVENT_TABLE()

olaFrame::olaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(olaFrame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer12;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer21;
    wxMenuItem* MenuItem2;
    wxBoxSizer* BoxSizer13;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer23;
    wxStaticBoxSizer* StaticBoxSizer9;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer16;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer18;
    wxStaticBoxSizer* StaticBoxSizer10;
    wxBoxSizer* BoxSizer14;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxGridSizer* GridSizer1;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxBoxSizer* BoxSizer31;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer24;
    wxStaticBoxSizer* StaticBoxSizer11;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer22;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxGridSizer* GridSizer2;
    wxBoxSizer* BoxSizer25;

    Create(parent, wxID_ANY, _("NeuroCalc"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(756,521));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("ico.ico"))));
    	SetIcon(FrameIcon);
    }
    Notebook2 = new wxNotebook(this, ID_NOTEBOOK2, wxDefaultPosition, wxSize(768,406), 0, _T("ID_NOTEBOOK2"));
    Panel1 = new wxPanel(Notebook2, ID_PANEL1, wxPoint(-1,-1), wxSize(646,380), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Lista pacjentów"));
    CheckListBox1 = new wxCheckListBox(Panel1, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(250,300), 0, 0, wxLB_SORT, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    StaticBoxSizer1->Add(CheckListBox1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer3->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Dodawanie, edycja pacjentów"));
    FlexGridSizer1 = new wxFlexGridSizer(8, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Nazwisko:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMaxLength(100);
    FlexGridSizer1->Add(TextCtrl1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Imię:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetMaxLength(29);
    FlexGridSizer1->Add(TextCtrl2, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Data badania:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer1->Add(StaticText8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    DatePickerCtrl1 = new wxDatePickerCtrl(Panel1, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    FlexGridSizer1->Add(DatePickerCtrl1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Data urodzenia:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    DatePickerCtrl2 = new wxDatePickerCtrl(Panel1, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    FlexGridSizer1->Add(DatePickerCtrl2, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Wiek:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox1 = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox1->Disable();
    FlexGridSizer1->Add(ComboBox1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText26 = new wxStaticText(Panel1, ID_STATICTEXT26, _("Wiek zachorowania:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    FlexGridSizer1->Add(StaticText26, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox8 = new wxComboBox(Panel1, ID_COMBOBOX8, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX8"));
    FlexGridSizer1->Add(ComboBox8, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Płeć:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox2 = new wxComboBox(Panel1, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX2"));
    ComboBox2->Append(_("K"));
    ComboBox2->Append(_("M"));
    FlexGridSizer1->Add(ComboBox2, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Płat:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox3 = new wxComboBox(Panel1, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX3"));
    FlexGridSizer1->Add(ComboBox3, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText23 = new wxStaticText(Panel1, ID_STATICTEXT23, _("Wykształcenie:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    FlexGridSizer1->Add(StaticText23, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox4 = new wxComboBox(Panel1, ID_COMBOBOX4, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX4"));
    FlexGridSizer1->Add(ComboBox4, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Dominacja dla mowy:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer1->Add(StaticText6, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox5 = new wxComboBox(Panel1, ID_COMBOBOX5, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX5"));
    FlexGridSizer1->Add(ComboBox5, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText24 = new wxStaticText(Panel1, ID_STATICTEXT24, _("Prawy hipokamp:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    FlexGridSizer1->Add(StaticText24, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox6 = new wxComboBox(Panel1, ID_COMBOBOX6, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX6"));
    FlexGridSizer1->Add(ComboBox6, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticText25 = new wxStaticText(Panel1, ID_STATICTEXT25, _("Lewy hipokamp:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    FlexGridSizer1->Add(StaticText25, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    ComboBox7 = new wxComboBox(Panel1, ID_COMBOBOX7, wxEmptyString, wxDefaultPosition, wxSize(256,21), 0, 0, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX7"));
    FlexGridSizer1->Add(ComboBox7, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
    StaticBoxSizer2->Add(FlexGridSizer1, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer4->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Panel1, wxEmptyString);
    GridSizer1 = new wxGridSizer(1, 3, 0, 0);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Dodaj pacjenta"), wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GridSizer1->Add(Button2, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Zaktualizuj pacjenta"), wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->Disable();
    GridSizer1->Add(Button1, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    Button7 = new wxButton(Panel1, ID_BUTTON7, _("Usuń pacjenta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button7->Disable();
    GridSizer1->Add(Button7, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticBoxSizer3->Add(GridSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2 = new wxGridSizer(1, 3, 0, 0);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Zapisz bazę"), wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    GridSizer2->Add(Button3, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Eksport pacjentów EXCEL"), wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    GridSizer2->Add(Button4, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Wydruk pacjenta PDF"), wxDefaultPosition, wxSize(140,-1), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->Disable();
    GridSizer2->Add(Button5, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticBoxSizer3->Add(GridSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    StaticText27 = new wxStaticText(Panel1, ID_STATICTEXT27, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    BoxSizer13->Add(StaticText27, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    Button6 = new wxButton(Panel1, ID_BUTTON6, _("IMPORTUJ..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    BoxSizer13->Add(Button6, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer2->Add(BoxSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook2, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Wyniki surowe"));
    Grid1 = new wxGrid(Panel2, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid1->CreateGrid(11,1);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetRowLabelSize(155);
    Grid1->SetDefaultColSize(70, true);
    Grid1->SetColLabelValue(0, _("Wartości"));
    Grid1->SetRowLabelValue(0, _("wiadomości"));
    Grid1->SetRowLabelValue(1, _("powtarzanie cyfr"));
    Grid1->SetRowLabelValue(2, _("słownik"));
    Grid1->SetRowLabelValue(3, _("arytmetyka"));
    Grid1->SetRowLabelValue(4, _("rozumienie"));
    Grid1->SetRowLabelValue(5, _("podobieństwa"));
    Grid1->SetRowLabelValue(6, _("braki w obrazkach"));
    Grid1->SetRowLabelValue(7, _("porządkowanie obrazków"));
    Grid1->SetRowLabelValue(8, _("klocki"));
    Grid1->SetRowLabelValue(9, _("układanki"));
    Grid1->SetRowLabelValue(10, _("symbole cyfr"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    StaticBoxSizer4->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12->Add(BoxSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Wyniki przeliczone"));
    Grid2 = new wxGrid(Panel2, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
    Grid2->CreateGrid(11,1);
    Grid2->EnableEditing(false);
    Grid2->EnableGridLines(true);
    Grid2->SetRowLabelSize(155);
    Grid2->SetDefaultColSize(70, true);
    Grid2->SetColLabelValue(0, _("Wartości"));
    Grid2->SetRowLabelValue(0, _("wiadomości"));
    Grid2->SetRowLabelValue(1, _("powtarzanie cyfr"));
    Grid2->SetRowLabelValue(2, _("słownik"));
    Grid2->SetRowLabelValue(3, _("arytmetyka"));
    Grid2->SetRowLabelValue(4, _("rozumienie"));
    Grid2->SetRowLabelValue(5, _("podobieństwa"));
    Grid2->SetRowLabelValue(6, _("braki w obrazkach"));
    Grid2->SetRowLabelValue(7, _("porządkowanie obrazków"));
    Grid2->SetRowLabelValue(8, _("klocki"));
    Grid2->SetRowLabelValue(9, _("układanki"));
    Grid2->SetRowLabelValue(10, _("symbole cyfr"));
    Grid2->SetDefaultCellFont( Grid2->GetFont() );
    Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
    StaticBoxSizer5->Add(Grid2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12->Add(BoxSizer8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer9 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("IQ"));
    BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    StaticText15 = new wxStaticText(Panel2, ID_STATICTEXT15, _("Skala słowna: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    BoxSizer14->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel2, ID_STATICTEXT16, _("Skala bezsłowna:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    BoxSizer14->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel2, ID_STATICTEXT17, _("Skala pełna:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    BoxSizer14->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer15 = new wxBoxSizer(wxVERTICAL);
    StaticText9 = new wxStaticText(Panel2, ID_STATICTEXT9, _("brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer15->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel2, ID_STATICTEXT10, _("brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer15->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(Panel2, ID_STATICTEXT11, _("brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    BoxSizer15->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer18->Add(BoxSizer15, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticBoxSizer9->Add(BoxSizer18, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer10->Add(StaticBoxSizer9, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer9->Add(BoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer10 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Wyniki czynnikowe"));
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer16 = new wxBoxSizer(wxVERTICAL);
    StaticText18 = new wxStaticText(Panel2, ID_STATICTEXT18, _("Rozumienie werbalne:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    BoxSizer16->Add(StaticText18, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(Panel2, ID_STATICTEXT19, _("Organizacja percepcyjna:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    BoxSizer16->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(Panel2, ID_STATICTEXT20, _("Pamięć i odporność na dystraktory:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    BoxSizer16->Add(StaticText20, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer19->Add(BoxSizer16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer17 = new wxBoxSizer(wxVERTICAL);
    StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _("brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer17->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel2, ID_STATICTEXT13, _("brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer17->Add(StaticText13, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT14, _("brak"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    BoxSizer17->Add(StaticText14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer19->Add(BoxSizer17, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticBoxSizer10->Add(BoxSizer19, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer11->Add(StaticBoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer9->Add(BoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer12->Add(BoxSizer9, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    BoxSizer6->Add(BoxSizer12, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel2->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel2);
    BoxSizer6->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook2, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer20 = new wxBoxSizer(wxVERTICAL);
    BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("10 słów"));
    Grid3 = new wxGrid(Panel3, ID_GRID3, wxDefaultPosition, wxSize(230,-1), 0, _T("ID_GRID3"));
    Grid3->CreateGrid(12,1);
    Grid3->EnableEditing(true);
    Grid3->EnableGridLines(true);
    Grid3->SetRowLabelSize(155);
    Grid3->SetDefaultColSize(70, true);
    Grid3->SetColLabelValue(0, _("Wartości"));
    Grid3->SetRowLabelValue(0, _("1"));
    Grid3->SetRowLabelValue(1, _("2"));
    Grid3->SetRowLabelValue(2, _("3"));
    Grid3->SetRowLabelValue(3, _("4"));
    Grid3->SetRowLabelValue(4, _("5"));
    Grid3->SetRowLabelValue(5, _("6"));
    Grid3->SetRowLabelValue(6, _("7"));
    Grid3->SetRowLabelValue(7, _("8"));
    Grid3->SetRowLabelValue(8, _("9"));
    Grid3->SetRowLabelValue(9, _("10"));
    Grid3->SetRowLabelValue(10, _("SUMA"));
    Grid3->SetRowLabelValue(11, _("Odroczenie"));
    Grid3->SetDefaultCellFont( Grid3->GetFont() );
    Grid3->SetDefaultCellTextColour( Grid3->GetForegroundColour() );
    StaticBoxSizer6->Add(Grid3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer22->Add(StaticBoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer21->Add(BoxSizer22, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("100 - 7"));
    BoxSizer25 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    StaticText22 = new wxStaticText(Panel3, ID_STATICTEXT22, _("Liczba błędów: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    FlexGridSizer2->Add(StaticText22, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(Panel3, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer2->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    StaticText21 = new wxStaticText(Panel3, ID_STATICTEXT21, _("Czas: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    FlexGridSizer2->Add(StaticText21, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(Panel3, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer2->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer25->Add(FlexGridSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticBoxSizer7->Add(BoxSizer25, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer23->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer21->Add(BoxSizer23, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer11 = new wxStaticBoxSizer(wxVERTICAL, Panel3, _("Figura REY\'A"));
    Grid5 = new wxGrid(Panel3, ID_GRID5, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID5"));
    Grid5->CreateGrid(4,1);
    Grid5->EnableEditing(true);
    Grid5->EnableGridLines(true);
    Grid5->SetRowLabelSize(155);
    Grid5->SetDefaultColSize(70, true);
    Grid5->SetColLabelValue(0, _("Wartości"));
    Grid5->SetRowLabelValue(0, _("Kopia"));
    Grid5->SetRowLabelValue(1, _("Typ (kopia)"));
    Grid5->SetRowLabelValue(2, _("Reprodukcja"));
    Grid5->SetRowLabelValue(3, _("Typ (reprodukcja)"));
    Grid5->SetDefaultCellFont( Grid5->GetFont() );
    Grid5->SetDefaultCellTextColour( Grid5->GetForegroundColour() );
    StaticBoxSizer11->Add(Grid5, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer24->Add(StaticBoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
    BoxSizer21->Add(BoxSizer24, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    BoxSizer20->Add(BoxSizer21, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Fluencja słowna"));
    Grid7 = new wxGrid(Panel3, ID_GRID7, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID7"));
    Grid7->CreateGrid(4,5);
    Grid7->EnableEditing(true);
    Grid7->EnableGridLines(true);
    Grid7->SetRowLabelSize(150);
    Grid7->SetColLabelValue(0, _("15"));
    Grid7->SetColLabelValue(1, _("30"));
    Grid7->SetColLabelValue(2, _("45"));
    Grid7->SetColLabelValue(3, _("60"));
    Grid7->SetColLabelValue(4, _("SUMA"));
    Grid7->SetRowLabelValue(0, _("Zwierzęta"));
    Grid7->SetRowLabelValue(1, _("Słowa na \"K\""));
    Grid7->SetRowLabelValue(2, _("Przedmioty ostre"));
    Grid7->SetRowLabelValue(3, _("Słowa na \"F\""));
    Grid7->SetDefaultCellFont( Grid7->GetFont() );
    Grid7->SetDefaultCellTextColour( Grid7->GetForegroundColour() );
    StaticBoxSizer12->Add(Grid7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer31->Add(StaticBoxSizer12, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer20->Add(BoxSizer31, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
    Panel3->SetSizer(BoxSizer20);
    BoxSizer20->Fit(Panel3);
    BoxSizer20->SetSizeHints(Panel3);
    Notebook2->AddPage(Panel1, _("Pacjenci"), false);
    Notebook2->AddPage(Panel2, _("Test WAIS-R"), false);
    Notebook2->AddPage(Panel3, _("Próby kliniczne"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idSync, _("Synchronizacja\tF9"), _("Synchronizacja z serwerem"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Wyjście\tAlt-F4"), _("Wyjście z programu"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Program"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("O Programie\tF1"), _("Informacje o programie"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Pomoc"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&olaFrame::OnCheckListBox1SelectOn);
    Connect(ID_DATEPICKERCTRL2,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&olaFrame::OnDatePickerCtrl2Changed);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton2Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton1Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton7Click1);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&olaFrame::OnButton6ImportClick);
    Connect(ID_GRID1,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&olaFrame::OnGrid1CellChange);
    Connect(ID_GRID3,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&olaFrame::OnGrid3CellChange);
    Connect(ID_GRID5,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&olaFrame::OnGrid1CellChange);
    Connect(ID_GRID7,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&olaFrame::OnGrid7CellChange);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&olaFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&olaFrame::OnAbout);
    //*)
    //Connect(idMenuQuit,wxCLOSE_WINDOW,(wxObjectEventFunction)&olaFrame::OnCloseWindow);
    //// moje linijki!!!!!!!!!!!

    Connect(idSync,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&olaFrame::OnButton7Click);

    Grid3->SetCellBackgroundColour(10,0, *wxLIGHT_GREY);
    Grid3->SetReadOnly(10,0);

    // panel disable
    Panel2->Disable();
    Panel3->Disable();

    Grid7->SetCellBackgroundColour(0,4, *wxLIGHT_GREY);
    Grid7->SetCellBackgroundColour(1,4, *wxLIGHT_GREY);
    Grid7->SetCellBackgroundColour(2,4, *wxLIGHT_GREY);
    Grid7->SetCellBackgroundColour(3,4, *wxLIGHT_GREY);
    Grid7->SetReadOnly(0,4);
    Grid7->SetReadOnly(1,4);
    Grid7->SetReadOnly(2,4);
    Grid7->SetReadOnly(3,4);

    reg_string = wxT("^([a-zA-ZżółćęśąźńŻÓŁĆĘŚĄŹŃ]{3,29})$");
    reg_int = wxT("^([0-9]{1,3})$");

    unsigned int wx_c;

    test_name_tab.Add(_("wiadomości"));
    test_name_tab.Add(_("powtarzanie cyfr"));
    test_name_tab.Add(_("słownik"));
    test_name_tab.Add(_("arytmetyka"));
    test_name_tab.Add(_("rozumienie"));
    test_name_tab.Add(_("podobieństwa"));
    test_name_tab.Add(_("braki w obrazkach"));
    test_name_tab.Add(_("porządkowanie obrazków"));
    test_name_tab.Add(_("klocki"));
    test_name_tab.Add(_("układanki"));
    test_name_tab.Add(_("symbole cyfr"));

    for(wx_c = 0;wx_c<test_name_tab.Count();wx_c++)
    {
        Grid1->SetRowLabelValue(wx_c,test_name_tab[wx_c]);
        Grid2->SetRowLabelValue(wx_c,test_name_tab[wx_c]);
    }

    education_tab.Add(_("podstawowe"));
    education_tab.Add(_("zawodowe"));
    education_tab.Add(_("średnie"));
    education_tab.Add(_("wyższe"));
    for(wx_c = 0;wx_c<education_tab.Count();wx_c++)
        ComboBox4->Append(education_tab[wx_c]);

    epileptic_focus_tab.Add(_("prawa skroń"));
    epileptic_focus_tab.Add(_("lewa skroń"));
    epileptic_focus_tab.Add(_("prawe czoło"));
    epileptic_focus_tab.Add(_("lewe czoło"));
    epileptic_focus_tab.Add(_("zmiany uogólnione"));
    epileptic_focus_tab.Add(_("prawa potylica"));
    epileptic_focus_tab.Add(_("lewa potylica"));
    epileptic_focus_tab.Add(_("prawe ciemię"));
    epileptic_focus_tab.Add(_("lewe ciemię"));
    epileptic_focus_tab.Add(_("inne"));
    for(wx_c = 0;wx_c<epileptic_focus_tab.Count();wx_c++)
        ComboBox3->Append(epileptic_focus_tab[wx_c]);

    domination_tab.Add(_("- brak danych"));
    domination_tab.Add(_("prawopółkulowa"));
    domination_tab.Add(_("lewopółkulowa"));
    domination_tab.Add(_("obupółkulowa"));
    for(wx_c = 0;wx_c<domination_tab.Count();wx_c++)
        ComboBox5->Append(domination_tab[wx_c]);

    ComboBox6->Append(_("- brak danych"));
    ComboBox7->Append(_("- brak danych"));
    wxString wx_str_temp;
    for(wx_c = 1;wx_c<=101;wx_c++)
    {
        wx_str_temp << wx_c-1;
        wx_str_temp.Append(_("%"));
        ComboBox6->Append(wx_str_temp);
        ComboBox7->Append(wx_str_temp);
        wx_str_temp.Clear();
    }

    // check if import file exist
    ifstream file;
    file.open(DEFAULT_IMPORT_FILE_NAME,ios::in|ios::binary);
    file.close();
    if(file.fail())
        Button6->Hide();
    else
        Button6->Show();

    // set age combobox
    wxString wx_combo_values;
    for(unsigned int counter = 1;counter<=130;counter++)
    {
        wx_combo_values.Clear();
        wx_combo_values << counter;
        ComboBox1->Append(wx_combo_values);
        ComboBox8->Append(wx_combo_values);
    }

    pl = new vector <olaData::DATA*>;
    od = new olaData;
    od->readDb(pl);
    this->generate_list_box();
}

olaFrame::~olaFrame()
{
    //(*Destroy(olaFrame)
    //*)
}

void olaFrame::OnCloseWindow(wxCloseEvent& event)
{
    this->AskBeforeExit();
}


void olaFrame::OnQuit(wxCommandEvent& event)
{
    this->AskBeforeExit();
}

void olaFrame::AskBeforeExit()
{
    wxMessageDialog dialog(NULL, wxT("Czy na pewno chcesz wyjść z programu? \nUpewnij się że dane zostały zapisane!!!"), wxT("Pytanie"),wxOK|wxCANCEL);
    switch(dialog.ShowModal())
    {
        case wxID_OK: exit(EXIT_SUCCESS); break;
        case wxID_CANCEL: break;
        default: break;
    }
    //Close();
}

void olaFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(_("NeuroCalc v1.44\nbrzeszczot@gmail.com"), _("Informacje o programie"));
}

// record selected on listbox
void olaFrame::OnCheckListBox1SelectOn(wxCommandEvent& event)
{
    wxString text;
    int sel = CheckListBox1->GetSelection();
    if(sel!=-1)
    {
        text = CheckListBox1->GetString(sel);
        string str = string(text.mb_str(wxConvUTF8));

        size_t pos_tag_a = str.find("(");
        //if(pos_tag_a!=string::npos)
        size_t pos_tag_b = str.find(")");
        pos_tag_a++;
        str = str.substr(pos_tag_a,pos_tag_b-pos_tag_a);
        pos_selected_id = atoi(str.c_str());

        this->read_data_to_textbox();

        Button1->Enable(true);
        Button5->Enable(true);
        Button7->Enable(true);

        Panel2->Enable(true);
        Panel3->Enable(true);
    }
}

// update record
void olaFrame::OnButton1Click(wxCommandEvent& event)
{
    if(pos_selected_id>=0)
    {
        olaData::DATA *data_temp = new olaData::DATA;

        // prepare regular expression
        wxRegEx name_reg, integer_reg;
        name_reg.Compile(reg_string);
        integer_reg.Compile(reg_int);

        wxString wx_surname = TextCtrl1->GetValue();
        wxString wx_name = TextCtrl2->GetValue();
        strcpy(data_temp->surname, (const char*)wx_surname.mb_str(wxConvUTF8));
        strcpy(data_temp->name, (const char*)wx_name.mb_str(wxConvUTF8));
        data_temp->age = (int)ComboBox1->GetCurrentSelection()+1;
        data_temp->age2 = (int)ComboBox8->GetCurrentSelection()+1;
        data_temp->gender = (int)ComboBox2->GetCurrentSelection();
        data_temp->epileptic_focus = (int)ComboBox3->GetCurrentSelection();
        data_temp->education = (int)ComboBox4->GetCurrentSelection();
        data_temp->domination = (int)ComboBox5->GetCurrentSelection();
        data_temp->p_hipokamp = (int)ComboBox6->GetCurrentSelection();
        data_temp->l_hipokamp = (int)ComboBox7->GetCurrentSelection();

        if(data_temp->domination<0) data_temp->domination=0;
        if(data_temp->p_hipokamp<0) data_temp->p_hipokamp=0;
        if(data_temp->l_hipokamp<0) data_temp->l_hipokamp=0;

        wxDateTime wxdDate1= DatePickerCtrl1->GetValue();
        wxString wxStr1 = wxdDate1.FormatISODate();
        strcpy(data_temp->test_date, (const char*)wxStr1.mb_str(wxConvUTF8));
        wxDateTime wxdDate2= DatePickerCtrl2->GetValue();
        wxString wxStr2 = wxdDate2.FormatISODate();
        strcpy(data_temp->born_date, (const char*)wxStr2.mb_str(wxConvUTF8));

        string date_time = od->getCurrentDate(true)+" ";
        date_time += od->getCurrentTime();
        strcpy(data_temp->update, (const char*)date_time.c_str());

        for(unsigned short int ii=0;ii<11;ii++)
            data_temp->wais[ii] = wxAtoi(Grid1->GetCellValue(ii,0).SubString(0,1));

        // save clinical_trials !!!!!!!
        unsigned short int ct,row,xx,yy;
        ct = row = xx = yy = 0;
        while(ct<18)
        {
            if(ct<=11)   data_temp->clinical_trials[ct] = wxAtoi(Grid3->GetCellValue(ct,0).SubString(0,2));
            else if(ct==12)  data_temp->clinical_trials[ct] = wxAtoi(TextCtrl4->GetValue().SubString(0,2));
            else if(ct==13)  data_temp->clinical_trials[ct] = wxAtoi(TextCtrl3->GetValue().SubString(0,2));
            else if(ct>=14 && ct<=17) data_temp->clinical_trials[ct] = wxAtoi(Grid5->GetCellValue(ct-14,0).SubString(0,2));
            ct++;
        }
        for(yy=0;yy<4;yy++)
            for(xx=0;xx<5;xx++)
            {
                data_temp->clinical_trials[ct] = wxAtoi(Grid7->GetCellValue(yy,xx).SubString(0,2));
                ct++;
            }
        // end of clinical trials

        if(name_reg.Matches(wx_surname) && name_reg.Matches(wx_name) && strlen(data_temp->surname)<30 && strlen(data_temp->name)<30 && strlen(data_temp->surname)>=3 && strlen(data_temp->name)>=3 && (data_temp->age>0 && data_temp->age<999) && (data_temp->age2>0 && data_temp->age2<999) && (data_temp->gender==0 || data_temp->gender==1) && (data_temp->epileptic_focus>=0 && data_temp->epileptic_focus<10) && (data_temp->education>=0 && data_temp->education<4) && strlen(data_temp->test_date)==10 && strlen(data_temp->born_date)==10)
        {
            (*pl)[pos_selected_id] = data_temp;
            this->generate_list_box();
            Button1->Enable(false);
            Button7->Enable(false);
            this->clear_inputs();
            this->WaisCalculate();
        }
        else
        {
            delete data_temp;
            wxMessageBox(_("Dane nie zostały zaktualizowane (są niepoprawne lub ich brak) :(\nUpewnij się, że w imieniu i nazwisku używasz wyłącznie liter (min 3 litery, max 29 liter)"), _("Informacja"));
            this->read_data_to_textbox();
        }
    }

    //this->WaisCalculate();
}

// add new record
void olaFrame::OnButton2Click(wxCommandEvent& event)
{
    olaData::DATA *d = new olaData::DATA;

    // prepare regular expression
    wxRegEx name_reg, integer_reg;
    name_reg.Compile(reg_string);
    integer_reg.Compile(reg_int);

    wxString wx_surname = TextCtrl1->GetValue();
    strcpy(d->surname, (const char*)wx_surname.mb_str(wxConvUTF8));
    wxString wx_name = TextCtrl2->GetValue();
    strcpy(d->name, (const char*)wx_name.mb_str(wxConvUTF8));
    d->age = (int)ComboBox1->GetCurrentSelection()+1;
    d->age2 = (int)ComboBox8->GetCurrentSelection()+1;
    d->gender = (int)ComboBox2->GetCurrentSelection();
    d->epileptic_focus = (int)ComboBox3->GetCurrentSelection();
    d->education = (int)ComboBox4->GetCurrentSelection();
    d->domination = (int)ComboBox5->GetCurrentSelection();
    d->p_hipokamp = (int)ComboBox6->GetCurrentSelection();
    d->l_hipokamp = (int)ComboBox7->GetCurrentSelection();

    if(d->domination<0) d->domination=0;
    if(d->p_hipokamp<0) d->p_hipokamp=0;
    if(d->l_hipokamp<0) d->l_hipokamp=0;

    wxDateTime wxdDate1= DatePickerCtrl1->GetValue();
    wxString wxStr1 = wxdDate1.FormatISODate();
    strcpy(d->test_date, (const char*)wxStr1.mb_str(wxConvUTF8));
    wxDateTime wxdDate2= DatePickerCtrl2->GetValue();
    wxString wxStr2 = wxdDate2.FormatISODate();
    strcpy(d->born_date, (const char*)wxStr2.mb_str(wxConvUTF8));

    string date_time = od->getCurrentDate(true)+" ";
    date_time += od->getCurrentTime();
    strcpy(d->update, (const char*)date_time.c_str());

    // read WAIS values to vector
    for(unsigned short int ii=0;ii<11;ii++)
        d->wais[ii] = wxAtoi(Grid1->GetCellValue(ii,0).SubString(0,1));

    // save clinical_trials !!!!!!!
    unsigned short int ct,row,xx,yy;
    ct = row = xx = yy = 0;
    while(ct<18)
    {
        if(ct<=11)   d->clinical_trials[ct] = wxAtoi(Grid3->GetCellValue(ct,0).SubString(0,2));
        else if(ct==12)  d->clinical_trials[ct] = wxAtoi(TextCtrl4->GetValue().SubString(0,2));
        else if(ct==13)  d->clinical_trials[ct] = wxAtoi(TextCtrl3->GetValue().SubString(0,2));
        else if(ct>=14 && ct<=17) d->clinical_trials[ct] = wxAtoi(Grid5->GetCellValue(ct-14,0).SubString(0,2));
        ct++;
    }
    for(yy=0;yy<4;yy++)
        for(xx=0;xx<5;xx++)
        {
            d->clinical_trials[ct] = wxAtoi(Grid7->GetCellValue(yy,xx).SubString(0,2));
            ct++;
        }
    // end of clinical trials

    bool patient_exist = false;
    for(unsigned int ii=0;ii<(unsigned int)pl->size();ii++)
    {
        if(strcmp(d->name,(*pl)[ii]->name)==0 && strcmp(d->surname,(*pl)[ii]->surname)==0 && d->age==(*pl)[ii]->age)
        {
            patient_exist = true;
            break;
        }
    }

    if(!patient_exist && strlen(d->surname)<30 && strlen(d->name)<30 && strlen(d->surname)>=3 && strlen(d->name)>=3 && name_reg.Matches(wx_surname) && name_reg.Matches(wx_name) && (d->age>0 && d->age<999) && (d->age2>0 && d->age2<999) && (d->gender==0 || d->gender==1) && (d->epileptic_focus>=0 && d->epileptic_focus<10) && (d->education>=0 && d->education<4) && strlen(d->test_date)==10 && strlen(d->born_date)==10)
    {
        pl->push_back(d);
        this->generate_list_box();
        this->clear_inputs();
        Button7->Enable(false);
    }
    else
    {
        if(patient_exist)
            wxMessageBox(_("Dane nie zostały dodane!\nPacjent o takim imieniu, nazwisku i liczbie lat już istnieje!\n\nZmodyfikuj imię, nazwisko lub wiek..."), _("Informacja"));
        else
            wxMessageBox(_("Dane nie zostały dodane (są niepoprawne lub ich brak) :(\nUpewnij się, że w imieniu i nazwisku używasz wyłącznie liter (min 3 litery, max 29 liter)"), _("Informacja"));
    }
}

// delete record
void olaFrame::OnButton7Click1(wxCommandEvent& event)
{
    //(*pl)[pos_selected_id] = data_temp;
    if(pos_selected_id>=0)
    {
        pl->erase (pl->begin()+pos_selected_id);
        this->generate_list_box();
        Button7->Enable(false);
    }
}

void olaFrame::generate_list_box()
{
    CheckListBox1->Clear();
    for(unsigned int ii=0;ii<pl->size();ii++)
    {
        ostringstream ss;
        string str_temp;
        ss << (*pl)[ii]->surname;
        ss << " ";
        ss << (*pl)[ii]->name;
        ss << " (";
        ss << ii;
        str_temp = ss.str() + ")";
        wxString full_name(str_temp.c_str(), wxConvUTF8);
        CheckListBox1->Append(full_name);
    }
    wxString txt;
    txt.Append(_("Ilość pacjentów: "));
    txt << pl->size();
    StaticText27->SetLabel(txt);
}

// read from vector to items
void olaFrame::read_data_to_textbox()
{
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    wxString wx_surname((*pl)[pos_selected_id]->surname, wxConvUTF8);
    TextCtrl1->AppendText(wx_surname);
    wxString wx_name((*pl)[pos_selected_id]->name, wxConvUTF8);
    TextCtrl2->AppendText(wx_name);
    wxString wx_age;
    wx_age << (*pl)[pos_selected_id]->age;
    ComboBox1->SetValue(wx_age);
    wx_age.Clear();
    wx_age << (*pl)[pos_selected_id]->age2;
    ComboBox8->SetValue(wx_age);
    //ComboBox1->SetInsertionPoint((*pl)[pos_selected_id]->age);
    (*pl)[pos_selected_id]->gender?ComboBox2->SetValue(_T("M")):ComboBox2->SetValue(_T("K"));
    ComboBox3->SetValue(epileptic_focus_tab[(*pl)[pos_selected_id]->epileptic_focus]);
    ComboBox4->SetValue(education_tab[(*pl)[pos_selected_id]->education]);
    ComboBox5->SetValue(domination_tab[(*pl)[pos_selected_id]->domination]);

    wxString wx_str_temp;
    if((*pl)[pos_selected_id]->p_hipokamp==0) wx_str_temp.Append(_("- brak danych"));
    else
    {
        wx_str_temp << ((*pl)[pos_selected_id]->p_hipokamp)-1;
        wx_str_temp.Append(_("%"));
    }
    ComboBox6->SetValue(wx_str_temp);
    wx_str_temp.Clear();

    if((*pl)[pos_selected_id]->l_hipokamp==0) wx_str_temp.Append(_("- brak danych"));
    else
    {
        wx_str_temp << ((*pl)[pos_selected_id]->l_hipokamp)-1;
        wx_str_temp.Append(_("%"));
    }
    ComboBox7->SetValue(wx_str_temp);
    wx_str_temp.Clear();

    wxString wx_test_date((*pl)[pos_selected_id]->test_date, wxConvUTF8);
    wxString wx_born_date((*pl)[pos_selected_id]->born_date, wxConvUTF8);
    wxDateTime wx_d_test_date, wx_d_born_date;
    wx_d_test_date.ParseDate(wx_test_date);
    wx_d_born_date.ParseDate(wx_born_date);
    DatePickerCtrl1->SetValue(wx_d_test_date);
    DatePickerCtrl2->SetValue(wx_d_born_date);

    wxString wx_wais;
    for(unsigned short int ii=0;ii<11;ii++)
    {
        wx_wais << (*pl)[pos_selected_id]->wais[ii];
        Grid1->SetCellValue(ii,0,wx_wais);
        wx_wais.Clear();
    }

    // save clinical_trials !!!!!!!
    wxString wx_int_temp;
    unsigned short int ct,row,xx,yy;
    ct = row = xx = yy = 0;
    while(ct<18)
    {
        if(ct<=11)
        {
            wx_int_temp << (*pl)[pos_selected_id]->clinical_trials[ct];
            Grid3->SetCellValue(ct,0,wx_int_temp);
            wx_int_temp.Clear();
        }
        else if(ct==12)
        {
            TextCtrl4->Clear();
            wx_int_temp << (*pl)[pos_selected_id]->clinical_trials[ct];
            TextCtrl4->AppendText(wx_int_temp);
            wx_int_temp.Clear();
        }
        else if(ct==13)
        {
            TextCtrl3->Clear();
            wx_int_temp << (*pl)[pos_selected_id]->clinical_trials[ct];
            TextCtrl3->AppendText(wx_int_temp);
            wx_int_temp.Clear();
        }
        else if(ct>=14 && ct<=17)
        {
            wx_int_temp << (*pl)[pos_selected_id]->clinical_trials[ct];
            Grid5->SetCellValue(ct-14,0,wx_int_temp);
            wx_int_temp.Clear();
        }
        ct++;
    }
    for(yy=0;yy<4;yy++)
        for(xx=0;xx<5;xx++)
        {
            wx_int_temp << (*pl)[pos_selected_id]->clinical_trials[ct];
            Grid7->SetCellValue(yy,xx,wx_int_temp);
            wx_int_temp.Clear();

            ct++;
        }
        // end of clinical trials

    // calculate WAIS and write to Grid2
    this->WaisCalculate();
}

// set current date
void olaFrame::clear_inputs()
{
    TextCtrl1->Clear();
    TextCtrl2->Clear();
//    ComboBox1->Clear();
//    ComboBox2->Clear();
//    ComboBox3->Clear();
//    ComboBox4->Clear();
    wxDateTime current_date = wxDateTime::Now();
    DatePickerCtrl1->SetValue(current_date);
    DatePickerCtrl2->SetValue(current_date);
    Grid1->ClearGrid();
    Grid2->ClearGrid();
}

// save records to file
void olaFrame::OnButton3Click(wxCommandEvent& event)
{
    if(od->saveDb(pl))
        wxMessageBox(_("Dane zostały pomyślnie zapisane :)"), _("Informacja"));
}

//save csv
void olaFrame::OnButton4Click(wxCommandEvent& event)
{
    vector <string> string_epileptic_focus_tab;
    vector <string> string_education_tab;
    vector <string> string_domination_tab;

    size_t wx_c;
    for(wx_c = 0;wx_c<epileptic_focus_tab.Count();wx_c++)
        string_epileptic_focus_tab.push_back(string(epileptic_focus_tab[wx_c].mb_str(wxConvUTF8)));
    for(wx_c = 0;wx_c<education_tab.Count();wx_c++)
        string_education_tab.push_back(string(education_tab[wx_c].mb_str(wxConvUTF8)));
    for(wx_c = 0;wx_c<domination_tab.Count();wx_c++)
        string_domination_tab.push_back(string(domination_tab[wx_c].mb_str(wxConvUTF8)));


    if(od->saveCsv(pl, string_epileptic_focus_tab, string_education_tab, string_domination_tab))
        wxMessageBox(_("Plik Excel został pomyślnie wygenerowany!"), _("Informacja"));
    else
        wxMessageBox(_("Plik Excel nie został wygenerowany!"), _("Informacja"));
}

// save pdf
void olaFrame::OnButton5Click(wxCommandEvent& event)
{
    vector <string> string_epileptic_focus_tab;
    vector <string> string_education_tab;
    vector <string> string_test_name_tab;
    vector <string> string_domination_tab;

    size_t wx_c;
    for(wx_c = 0;wx_c<epileptic_focus_tab.Count();wx_c++)
        string_epileptic_focus_tab.push_back(string(epileptic_focus_tab[wx_c].mb_str(wxConvUTF8)));
    for(wx_c = 0;wx_c<education_tab.Count();wx_c++)
        string_education_tab.push_back(string(education_tab[wx_c].mb_str(wxConvUTF8)));
    for(wx_c = 0;wx_c<test_name_tab.Count();wx_c++)
        string_test_name_tab.push_back(string(test_name_tab[wx_c].mb_str(wxConvUTF8)));
   for(wx_c = 0;wx_c<domination_tab.Count();wx_c++)
        string_domination_tab.push_back(string(domination_tab[wx_c].mb_str(wxConvUTF8)));

    if(od->savePdf((*pl)[pos_selected_id], string_epileptic_focus_tab, string_education_tab, string_test_name_tab, string_domination_tab))
        wxMessageBox(_("Plik PDF został pomyślnie wygenerowany!"), _("Informacja"));
    else
        wxMessageBox(_("Plik PDF nie został wygenerowany!"), _("Informacja"));
}

void olaFrame::WaisCalculate()
{
    // calculate WP and insert to grid2
    wxString wx_wais;
    short int *wais_res, *wc_res;
    wais_res = Calculate((*pl)[pos_selected_id]->wais, (*pl)[pos_selected_id]->age);
    wx_wais.Clear();

    for(unsigned short int ii=0;ii<WP1;ii++)
    {
        wx_wais << wais_res[ii];
        Grid2->SetCellValue(ii,0,wx_wais);
        wx_wais.Clear();
    }

    wc_res = Calculate2(wais_res);
    wx_wais.Clear();
    if(wc_res[0]<45)    wx_wais = _("< 45");
    else if(wc_res[0]>=45 && wc_res[0]<=150)   wx_wais << wc_res[0];
    else    wx_wais = _("> 150");
    StaticText9->SetLabel(wx_wais);
    wx_wais.Clear();
    if(wc_res[1]<45)    wx_wais = _("< 45");
    else if(wc_res[1]>=45 && wc_res[1]<=150) wx_wais << wc_res[1];
    else    wx_wais = _("> 150");
    StaticText10->SetLabel(wx_wais);
    wx_wais.Clear();
    if(wc_res[2]<45)    wx_wais = _("< 45");
    else if(wc_res[2]>=45 && wc_res[2]<=150) wx_wais << wc_res[2];
    else    wx_wais = _("> 150");
    StaticText11->SetLabel(wx_wais);
    wx_wais.Clear();
    if(wc_res[3]<45)    wx_wais = _("< 45");
    else if(wc_res[3]>=45 && wc_res[3]<=150) wx_wais << wc_res[3];
    else    wx_wais = _("> 150");
    StaticText12->SetLabel(wx_wais);
    wx_wais.Clear();
    if(wc_res[4]<45)    wx_wais = _("< 45");
    else if(wc_res[4]>=45 && wc_res[4]<=150) wx_wais << wc_res[4];
    else    wx_wais = _("> 150");
    StaticText13->SetLabel(wx_wais);
    wx_wais.Clear();
    if(wc_res[5]<45)    wx_wais = _("< 45");
    else if(wc_res[5]>=45 && wc_res[5]<=150) wx_wais << wc_res[5];
    else    wx_wais = _("> 150");
    StaticText14->SetLabel(wx_wais);
    wx_wais.Clear();
}

// correct data mask
void olaFrame::OnGrid1CellChange(wxGridEvent& event)
{
    for(unsigned short int ii=0;ii<WP1;ii++)
    {
        Grid1->SetCellValue(ii,0,Grid1->GetCellValue(ii,0).SubString(0,1));
        (*pl)[pos_selected_id]->wais[ii] = wxAtoi(Grid1->GetCellValue(ii,0).SubString(0,1));
    }
    this->WaisCalculate();
}

// AUTO SUMMARY
void olaFrame::OnGrid3CellChange(wxGridEvent& event)
{
    wxString wx_int_temp;
    int sum = 0;
    for(unsigned short int ii=0;ii<10;ii++)
    {
         sum += wxAtoi(Grid3->GetCellValue(ii,0).SubString(0,2));
    }
    wx_int_temp << sum;
    Grid3->SetCellValue(10,0,wx_int_temp);
    wx_int_temp.Clear();
}

// AUTO SUMMARY
void olaFrame::OnGrid7CellChange(wxGridEvent& event)
{
    wxString wx_int_temp;
    int sum,yy,xx;
    for(yy=0;yy<4;yy++)
    {
        for(sum=xx=0;xx<4;xx++)
        {
            sum += wxAtoi(Grid7->GetCellValue(yy,xx).SubString(0,2));
        }
        wx_int_temp << sum;
        Grid7->SetCellValue(yy,4,wx_int_temp);
        wx_int_temp.Clear();
    }
}

// local import from file
void olaFrame::OnButton6ImportClick(wxCommandEvent& event)
{
    ifstream file;
    unsigned int ii;
    bool patient_exist = false;
    unsigned int import_counter = 0;

    file.open(DEFAULT_IMPORT_FILE_NAME,ios::in|ios::binary);

    if(file.is_open())
    {
        olaData::DATA *temp;
        while(!file.eof())
        {
            temp = (olaData::DATA*) new olaData::DATA;
            if(file.read((char*) temp, sizeof(olaData::DATA))!=0)
            {
                patient_exist = false;
                for(ii=0;ii<(unsigned int)pl->size();ii++)
                {
                    if(strcmp(temp->name,(*pl)[ii]->name)==0 && strcmp(temp->surname,(*pl)[ii]->surname)==0)
                    {
                        patient_exist = true;
                        break;
                    }
                }
                if(!patient_exist)
                {
                    pl->push_back(temp);
                    import_counter++;
                }
            }
        }
        file.close();
        wxString import_text = _("Import został zakończony\nLiczba zainportowanych: ");
        import_text << import_counter;
        wxMessageBox(import_text, _("Informacja"));
    }
    else    wxMessageBox(_("Błąd podczas importu"), _("Informacja"));

    this->generate_list_box();
}

// dynamic age set
void olaFrame::OnDatePickerCtrl2Changed(wxDateEvent& event)
{
    char str_date[11];
    char str_dest[5];
    int age;

    wxDateTime wxdDate= DatePickerCtrl2->GetValue();
    wxString wxStr = wxdDate.FormatISODate();
    strcpy(str_date, (const char*)wxStr.mb_str(wxConvUTF8));
    strncpy(str_dest,str_date,4);
    str_dest[4]='\0';

    age = od->getAge(str_dest);
    wxString wx_age;
    wx_age << age;
    ComboBox1->SetValue(wx_age);
    wx_age.Clear();
}

// synchronization
void olaFrame::OnButton7Click(wxCommandEvent& event)
{
    od->srvSend(pl);
    size_t ret_get = od->srvGet(pl);

    if(ret_get>0)
    {
        this->generate_list_box();
        //wxString import_text(ret, wxConvUTF8);
        wxString import_text;
        import_text = _("Zsynchronizowanych pacjentów: ");
        import_text << ret_get;
        import_text << _(" ");
        wxMessageBox(import_text, _("Informacja"));
    }
    else
    {
        wxMessageBox(_("Błąd podczas synchronizacji!"), _("Informacja"));
    }
    /*
    progressbar
    Gauge1->SetValue(0);
    Gauge1->SetRange((int)pl->size());
    for(unsigned int ii=0;ii<(unsigned int)pl->size();ii++)
    {
        od->srv((*pl)[ii]);
        Gauge1->SetValue(ii+1);
    }
    */
}

