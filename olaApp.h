/***************************************************************
 * Name:      olaApp.h
 * Purpose:   Defines Application Class
 * Author:    ja (ja)
 * Created:   2011-07-27
 * Copyright: ja (ja)
 * License:
 **************************************************************/

#ifndef OLAAPP_H
#define OLAAPP_H

#include <wx/app.h>
#include <windows.h>

class olaApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // OLAAPP_H
