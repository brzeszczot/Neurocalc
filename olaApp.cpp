/***************************************************************
 * Name:      olaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ja (ja)
 * Created:   2011-07-27
 * Copyright: ja (ja)
 * License:
 **************************************************************/

#include "olaApp.h"

//(*AppHeaders
#include "olaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(olaApp);

bool olaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	olaFrame* Frame = new olaFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
