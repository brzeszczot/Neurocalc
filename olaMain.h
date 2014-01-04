/***************************************************************
 * Name:      olaMain.h
 * Purpose:   Defines Application Frame
 * Author:    ja (ja)
 * Created:   2011-07-27
 * Copyright: ja (ja)
 * License:
 **************************************************************/

#ifndef OLAMAIN_H
#define OLAMAIN_H

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <time.h>

//(*Headers(olaFrame)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/datectrl.h>
#include <wx/panel.h>
#include <wx/dateevt.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/combobox.h>
#include <wx/statusbr.h>
//*)
#include <wx/regex.h>

#include "olaData.hpp"
#include "wais.hpp"

class olaFrame: public wxFrame
{
    public:

        olaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~olaFrame();

    private:

        //(*Handlers(olaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnCheckListBox1SelectOn(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnGrid1CellChange(wxGridEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnGrid3CellChange(wxGridEvent& event);
        void OnGrid7CellChange(wxGridEvent& event);
        void OnButton6ImportClick(wxCommandEvent& event);
        void OnDatePickerCtrl2Changed(wxDateEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnButton7Click1(wxCommandEvent& event);
        //*)
        void OnCloseWindow(wxCloseEvent& event);

        //(*Identifiers(olaFrame)
        static const long ID_CHECKLISTBOX1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT8;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_STATICTEXT7;
        static const long ID_DATEPICKERCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT26;
        static const long ID_COMBOBOX8;
        static const long ID_STATICTEXT4;
        static const long ID_COMBOBOX2;
        static const long ID_STATICTEXT5;
        static const long ID_COMBOBOX3;
        static const long ID_STATICTEXT23;
        static const long ID_COMBOBOX4;
        static const long ID_STATICTEXT6;
        static const long ID_COMBOBOX5;
        static const long ID_STATICTEXT24;
        static const long ID_COMBOBOX6;
        static const long ID_STATICTEXT25;
        static const long ID_COMBOBOX7;
        static const long ID_BUTTON2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON7;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT27;
        static const long ID_BUTTON6;
        static const long ID_PANEL1;
        static const long ID_GRID1;
        static const long ID_GRID2;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_PANEL2;
        static const long ID_GRID3;
        static const long ID_STATICTEXT22;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT21;
        static const long ID_TEXTCTRL3;
        static const long ID_GRID5;
        static const long ID_GRID7;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK2;
        static const long idSync;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(olaFrame)
        wxStaticText* StaticText10;
        wxStaticText* StaticText22;
        wxStaticText* StaticText9;
        wxStaticText* StaticText20;
        wxTextCtrl* TextCtrl4;
        wxComboBox* ComboBox8;
        wxDatePickerCtrl* DatePickerCtrl2;
        wxButton* Button4;
        wxComboBox* ComboBox6;
        wxDatePickerCtrl* DatePickerCtrl1;
        wxStaticText* StaticText13;
        wxStaticText* StaticText2;
        wxStaticText* StaticText14;
        wxGrid* Grid5;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxStaticText* StaticText26;
        wxStaticText* StaticText19;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxGrid* Grid7;
        wxStaticText* StaticText18;
        wxCheckListBox* CheckListBox1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText27;
        wxStaticText* StaticText3;
        wxGrid* Grid1;
        wxButton* Button2;
        wxPanel* Panel3;
        wxStaticText* StaticText21;
        wxComboBox* ComboBox4;
        wxButton* Button6;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxButton* Button5;
        wxComboBox* ComboBox7;
        wxGrid* Grid2;
        wxMenuItem* MenuItem3;
        wxComboBox* ComboBox3;
        wxButton* Button3;
        wxStaticText* StaticText5;
        wxButton* Button7;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxComboBox* ComboBox5;
        wxTextCtrl* TextCtrl2;
        wxComboBox* ComboBox1;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText15;
        wxStaticText* StaticText12;
        wxPanel* Panel2;
        wxComboBox* ComboBox2;
        wxGrid* Grid3;
        wxStaticText* StaticText25;
        wxNotebook* Notebook2;
        wxStaticText* StaticText17;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl3;
        wxStaticText* StaticText16;
        //*)

        // own stuff:
        wxString reg_string, reg_int;

        vector <olaData::DATA*> *pl;
        olaData *od;

        int pos_selected_id;
        wxArrayString epileptic_focus_tab;  // dictionary with epileptic focus
        wxArrayString education_tab;        // dictionary with educations level
        wxArrayString test_name_tab;        // dictionary with test names
        wxArrayString domination_tab;
        void generate_list_box();
        void read_data_to_textbox();
        void clear_inputs();                // clear all inputs
        void WaisCalculate();               // calculate WAIS and write to grid2
        void AskBeforeExit();

        DECLARE_EVENT_TABLE()
};

#endif // OLAMAIN_H
