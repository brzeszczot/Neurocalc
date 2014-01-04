#include "olaData.hpp"

olaData::olaData()
{
    file_name = DEFAULT_FILE_NAME;
}

olaData::~olaData()
{

}

bool olaData::add_to_data(DATA *d, string in, size_t pos)
{
    size_t wais_pos = 13;
    if(pos>=wais_pos && pos<(wais_pos+WP1))
        d->wais[pos-wais_pos] = atoi(in.c_str());
    else if(pos>=(wais_pos+WP1) && pos<(wais_pos+WP1+ALL_CLINICAL_TRIALS))
        d->clinical_trials[(pos-(wais_pos+WP1))] = atoi(in.c_str());

    switch(pos)
    {
        case 0: strcpy(d->surname,in.c_str()); break;
        case 1: strcpy(d->name,in.c_str()); break;
        case 2: d->age = atoi(in.c_str()); break;
        case 3: d->age2 = atoi(in.c_str()); break;
        case 4: d->gender = atoi(in.c_str()); break;
        case 5: d->epileptic_focus = atoi(in.c_str()); break;
        case 6: d->education = atoi(in.c_str()); break;
        case 7: d->domination = atoi(in.c_str()); break;
        case 8: d->p_hipokamp = atoi(in.c_str()); break;
        case 9: d->l_hipokamp = atoi(in.c_str()); break;
        case 10: strcpy(d->test_date,in.c_str()); break;
        case 11: strcpy(d->born_date,in.c_str()); break;
        case 12: strcpy(d->update,in.c_str()); break;
        default: return false;
    }
    return true;
}

size_t olaData::srvSend(vector <DATA*> *lp)
{
    char sep = SEP_WORD;
    stringstream sstream;
    string str_curl;
    int jj;

    for(unsigned int ii=0;ii<(unsigned int)lp->size();ii++)
    {
        sstream << (*lp)[ii]->surname << sep;
        sstream << (*lp)[ii]->name << sep;
        sstream << (*lp)[ii]->age << sep;
        sstream << (*lp)[ii]->age2 << sep;
        sstream << (*lp)[ii]->gender << sep;
        sstream << (*lp)[ii]->epileptic_focus << sep;
        sstream << (*lp)[ii]->education << sep;
        sstream << (*lp)[ii]->domination << sep;
        sstream << (*lp)[ii]->p_hipokamp << sep;
        sstream << (*lp)[ii]->l_hipokamp << sep;
        sstream << (*lp)[ii]->test_date << sep;
        sstream << (*lp)[ii]->born_date << sep;
        sstream << (*lp)[ii]->update << sep;
        for(jj=0;jj<WP1;jj++)
            sstream << (*lp)[ii]->wais[jj] << sep;
        for(jj=0;jj<ALL_CLINICAL_TRIALS;jj++)
            sstream << (*lp)[ii]->clinical_trials[jj] << sep;

        sstream << SEP_RECORD;
    }
    str_curl = sstream.str();
    // send data and recive
    str_curl = Go(str_curl);
    return atoi(str_curl.c_str());
}

size_t olaData::srvGet(vector <DATA*> *lp)
{
    string str_curl = "GET";

    str_curl = Go(str_curl);
    // parse data and put to vector
    if(!str_curl.empty())
    {
        if(str_curl[0]=='!' && str_curl[1]=='!')
            return 0;

        size_t found_s, found_h;
        found_h = str_curl.find(SEP_RECORD);
        if(found_h!=string::npos)
        {
            size_t d_counter, it, sub, pos;
            size_t crecords = 0;
            // get quantity of records
            crecords = atoi(str_curl.substr(0,found_h).c_str());
            if(crecords<=0)
                return 0;

            DATA *temp_data;
            temp_data = (DATA*) new DATA;
            string string_temp;
            lp->clear();

            d_counter = pos = 0;
            it = found_h+1;
            do
            {
                found_s = str_curl.find_first_of(SEP_WORD,it);
                sub = found_s-it;
                string_temp = str_curl.substr(it,sub);
                // string limit !!!!!!!!!!!!!!!!!
                string_temp = string_temp.substr(0,NAME_MAX_LEN);
                this->add_to_data(temp_data, string_temp, pos);
                // move iterator to next ';' and structure position
                it+= ++sub;
                pos++;
                // if next char is '#' then begin saving new porcion of data
                if(str_curl[it]==SEP_RECORD)
                {
                    // add to vector
                    lp->push_back(temp_data);
                    // allocate new piece of data
                    temp_data = (DATA*) new DATA;
                    // reset iterator and structure position
                    pos = 0;
                    it++;
                    // increase record data
                    d_counter++;
                }
            } while(d_counter<crecords);
            return crecords;
        }
        else return 0;
    }
    else return 0;
}

bool olaData::readDb(vector <DATA*> *lp)
{
    ifstream file;
    file.open(file_name.c_str(),ios::in|ios::binary);

    if(file.is_open())
    {
        DATA *temp;
        while(!file.eof())
        {
            temp = (DATA*) new DATA;
            if(file.read((char*) temp, sizeof(DATA))!=0)
                lp->push_back(temp);
            /*
            file.read((char*) temp->surname,sizeof(char[30]));
            file.read((char*) temp->name,sizeof(char[30]));
            file.read((char*) &temp->age,sizeof(int));
            file.read((char*) &temp->gender,sizeof(short int));
            file.read((char*) &temp->epileptic_focus,sizeof(short int));
            file.read((char*) &temp->education,sizeof(short int));
            file.read((char*) temp->test_date,sizeof(char[11]));
            file.read((char*) temp->born_date,sizeof(char[11]));
            lp->push_back(temp);
            temp = NULL;
            */
        }
        file.close();
        return true;
    }
    else return false;
}

bool olaData::saveDb(vector <DATA*> *lp)
{
    ofstream file;
    file.open(file_name.c_str(),ios::out|ios::binary);

    if(file.is_open())
    {
        for(unsigned int ii=0;ii<(unsigned int)lp->size();ii++)
        {
            file.write((char*)(*lp)[ii], sizeof(DATA));
            /*
            file.write((char*) (*lp)[ii]->surname,sizeof(char[30]));
            file.write((char*) (*lp)[ii]->name,sizeof(char[30]));
            file.write((char*) &(*lp)[ii]->age,sizeof(int));
            file.write((char*) &(*lp)[ii]->gender,sizeof(short int));
            file.write((char*) &(*lp)[ii]->epileptic_focus,sizeof(short int));
            file.write((char*) &(*lp)[ii]->education,sizeof(short int));
            file.write((char*) (*lp)[ii]->test_date,sizeof(char[11]));
            file.write((char*) (*lp)[ii]->born_date,sizeof(char[11]));
            */
        }
        file.close();
        return true;
    }
    else return false;
}

bool olaData::saveCsv(vector <DATA*> *lp,vector <string> string_epileptic_focus_tab,vector <string> string_education_tab,vector <string> string_domination_tab)
{
    ofstream file;

    csv_file_name = DEFAULT_CSV_NAME;
    csv_file_name.append(this->getCurrentDate(false));
    csv_file_name.append(".txt");

    file.open(csv_file_name.c_str(),ios::out);
    char nl[3] = "\n";
    char sep = ';';
    unsigned int ii,jj;

    if(file.is_open())
    {
        file    << "Nazwisko" << sep
                << "Imię" << sep
                << "Wiek" << sep
                << "Wiek zachorowania" << sep
                << "Płeć" << sep
                << "Płat" << sep
                << "Wykształcenie" << sep
                << "Dominacja dla mowy" << sep
                << "Prawy hipokamp" << sep
                << "Lewy hipokamp" << sep
                << "Data testu" << sep
                << "Data urodzenia" << sep
                << "S1"<<sep<<"S2"<<sep<<"S3"<<sep<<"S4"<<sep<<"S5"<<sep<<"S6"<<sep<<"S7"<<sep<<"S8"<<sep<<"S9"<<sep<<"S10"<<sep<<"S11"<<sep
                << "P1"<<sep<<"P2"<<sep<<"P3"<<sep<<"P4"<<sep<<"P5"<<sep<<"P6"<<sep<<"P7"<<sep<<"P8"<<sep<<"P9"<<sep<<"P10"<<sep<<"P11"<<sep
                << "Skala słowna"<<sep<<"Skala bezsłowna"<<sep<<"Skala pełna"<<sep<<"Rozumienie werbalne"<<sep<<"Organizacja percepcyjna"<<sep<<"Pamięć i odporność"<<sep
                << "10 słów (SUMA)"<<sep<<"10 słów (odroczenie)"<<sep<<"100-7 (Liczba błędów)"<<sep<<"Kopia"<<sep<<"Reprodukcja"<<sep<<"Zwierzęta"<<sep<<"Słowo na K"<<sep<<"Przedmioty ostre"<<sep<<"Słowo na F"<<sep
                << nl;
        for(ii=0;ii<(unsigned int)lp->size();ii++)
        {
            //file.write((char*)(*lp)[ii], sizeof(DATA));

            file << (*lp)[ii]->surname << sep;
            file << (*lp)[ii]->name << sep;
            file << (*lp)[ii]->age << sep;
            file << (*lp)[ii]->age2 << sep;
            if((*lp)[ii]->gender) file << 'M' << sep;
            else file << 'K' << sep;
            file << string_epileptic_focus_tab[(*lp)[ii]->epileptic_focus] << sep;
            file << string_education_tab[(*lp)[ii]->education] << sep;
            file << string_domination_tab[(*lp)[ii]->domination] << sep;
            if((*lp)[ii]->p_hipokamp==0)
                file << "brak" << sep;
            else
                file << (((*lp)[ii]->p_hipokamp)-1) << "%" << sep;
            if((*lp)[ii]->l_hipokamp==0)
                file << "brak" << sep;
            else
                file << (((*lp)[ii]->l_hipokamp)-1) << "%" << sep;
            file << (*lp)[ii]->test_date << sep;
            file << (*lp)[ii]->born_date << sep;
            for(jj=0;jj<WP1;jj++)
                file << (*lp)[ii]->wais[jj] << sep;

            // wartosci przeliczone, oraz 3xIQ i 3xczyniki
            short int *wais_res, *wc_res;
            wais_res = Calculate((*lp)[ii]->wais, (*lp)[ii]->age);
            wc_res = Calculate2(wais_res);
            for(jj=0;jj<WP1;jj++)
                file << wais_res[jj] << sep;
            for(jj=0;jj<WC_RES;jj++)
                file << wc_res[jj] << sep;

            // some choicen data from clinical trials
            file << (*lp)[ii]->clinical_trials[10] << sep;
            file << (*lp)[ii]->clinical_trials[11] << sep;
            file << (*lp)[ii]->clinical_trials[12] << sep;
            file << (*lp)[ii]->clinical_trials[14] << sep;
            file << (*lp)[ii]->clinical_trials[16] << sep;
            file << (*lp)[ii]->clinical_trials[22] << sep;
            file << (*lp)[ii]->clinical_trials[27] << sep;
            file << (*lp)[ii]->clinical_trials[32] << sep;
            file << (*lp)[ii]->clinical_trials[37] << sep;

            file << nl;
            file.flush();
        }
        file.close();
        return true;
    }
    else return false;
}

bool olaData::savePdf(DATA* patient,vector <string> string_epileptic_focus_tab,vector <string> string_education_tab, vector <string> string_test_name_tab,vector <string> string_domination_tab)
{
    string page_title = "NeuroCalc ";
    page_title.append(this->getCurrentDate(true));
    page_title.append(" (ostatnia aktualizacja: ");
    page_title.append(patient->update);
    page_title.append(")");
    unsigned short int y_space = 12;
    unsigned short int x_space = 170;
    unsigned short int x_space_small = 75;
    unsigned int jj;
    HPDF_Doc    pdf;
    HPDF_Page   page;
    HPDF_Font   def_font,def_font_bold;
    HPDF_REAL   tw;
    HPDF_REAL   height;
    HPDF_REAL   width;
    //HPDF_UINT i;

    pdf = HPDF_New (NULL, NULL);
    if(!pdf)    return false;
    try {
        page = HPDF_AddPage (pdf);
        height = HPDF_Page_GetHeight (page);
        width = HPDF_Page_GetWidth (page);

        HPDF_Page_SetLineWidth (page, 1);
        HPDF_Page_Rectangle (page, 50, 50, width - 100, height - 110);
        HPDF_Page_Stroke (page);

        def_font = HPDF_GetFont (pdf, "Helvetica", "ISO8859-2");
        def_font_bold = HPDF_GetFont (pdf, "Helvetica-Bold", "ISO8859-2");
        HPDF_Page_SetFontAndSize (page, def_font, 12);

        tw = HPDF_Page_TextWidth (page, page_title.c_str());
        HPDF_Page_BeginText (page);
        HPDF_Page_MoveTextPos (page, (width - tw) / 2, height - 50);
        HPDF_Page_ShowText (page, page_title.c_str());
        HPDF_Page_EndText (page);

        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_BeginText (page);

        // print data
        HPDF_Page_MoveTextPos (page, 60, height - 80);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        char *temp = new char[MAX_STR_CONV];
        strcpy(temp,"Imię i nazwisko: ");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        strcpy(temp,patient->surname);
        strcat(temp," ");
        strcat(temp,patient->name);
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page,temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "Wiek: ");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->age, temp, 10);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "Wiek zachorowania: ");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->age2, temp, 10);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        strcpy(temp,"Płeć: ");
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        if(patient->gender)
        {
            strcpy(temp,"Mężczyzna");
            this->utf_to_iso2(temp);
            HPDF_Page_ShowText (page, temp);
        }
        else    HPDF_Page_ShowText (page, "Kobieta");

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        strcpy(temp,"Płat: ");
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        strcpy(temp,string_epileptic_focus_tab[patient->epileptic_focus].c_str());
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        strcpy(temp,"Wykształcenie: ");
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        strcpy(temp,string_education_tab[patient->education].c_str());
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        strcpy(temp,"Dominacja dla mowy: ");
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        strcpy(temp,string_domination_tab[patient->domination].c_str());
        this->utf_to_iso2(temp);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "Prawy hipokamp: ");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        if(patient->p_hipokamp==0)
            strcpy(temp,"- brak danych");
        else
        {
            itoa(patient->p_hipokamp-1, temp, 10);
            strcat(temp,"%");
        }
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "Lewy hipokamp: ");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        if(patient->l_hipokamp==0)
            strcpy(temp,"- brak danych");
        else
        {
            itoa(patient->l_hipokamp-1, temp, 10);
            strcat(temp,"%");
        }
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, temp);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "Data urodzenia: ");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, patient->born_date);

        HPDF_Page_MoveTextPos (page, -x_space, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "Data badania: ");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_ShowText (page, patient->test_date);

        // counted values and 3xIQ i 3x factor
        short int *wais_res, *wc_res;
        wais_res = Calculate(patient->wais, patient->age);
        wc_res = Calculate2(wais_res);

        HPDF_Page_MoveTextPos (page, -x_space, -(y_space*2));
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "WAIS-R");
        HPDF_Page_MoveTextPos (page, x_space, 0);
        HPDF_Page_ShowText (page, "surowe");
        HPDF_Page_MoveTextPos (page, x_space_small, 0);
        HPDF_Page_ShowText (page, "przeliczone");
        HPDF_Page_MoveTextPos (page, -(x_space+x_space_small), -y_space);
        HPDF_Page_SetFontAndSize (page, def_font, 10);

        char cht[3];
        for(jj=0;jj<WP1;jj++)
        {
            strcpy(temp,string_test_name_tab[jj].c_str());
            strcat(temp,":");
            this->utf_to_iso2(temp);
            HPDF_Page_ShowText (page, temp);

            HPDF_Page_MoveTextPos (page, x_space, 0);
            itoa(patient->wais[jj],cht,10);
            HPDF_Page_ShowText (page, cht);

            HPDF_Page_MoveTextPos (page, x_space_small, 0);
            itoa(wais_res[jj],cht,10);
            HPDF_Page_ShowText (page, cht);

            HPDF_Page_MoveTextPos (page, -(x_space+x_space_small), -y_space);
        }

        HPDF_Page_MoveTextPos (page, 0, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        HPDF_Page_ShowText (page, "IQ");
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_MoveTextPos (page, 0, -y_space);
        for(jj=0;jj<WC_RES;jj++)
        {
            // i know that is not good solution :)
            switch(jj)
            {
                case 0: strcpy(temp,"Skala słowna: "); break;
                case 1: strcpy(temp,"Skala bezsłowna:"); break;
                case 2: strcpy(temp,"Skala pełna:"); break;
                case 3: strcpy(temp,"Rozumienie werbalne:"); break;
                case 4: strcpy(temp,"Organizacja percepcyjna:"); break;
                case 5: strcpy(temp,"Pamięć i odporność..:"); break;
            }
            this->utf_to_iso2(temp);
            HPDF_Page_ShowText (page, temp);

            HPDF_Page_MoveTextPos (page, x_space, 0);
            itoa(wc_res[jj],cht,10);
            HPDF_Page_ShowText (page, cht);
            HPDF_Page_MoveTextPos (page, -x_space, -y_space);
            if(jj==2)
            {
                HPDF_Page_MoveTextPos (page, 0, -y_space);
                HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
                HPDF_Page_ShowText (page, "Wyniki czynnikowe");
                HPDF_Page_SetFontAndSize (page, def_font, 10);
                HPDF_Page_MoveTextPos (page, 0, -y_space);
            }
        }

        HPDF_Page_MoveTextPos (page, 0, -y_space);
        HPDF_Page_SetFontAndSize (page, def_font_bold, 10);
        strcpy(temp,"Próby kliniczne");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_SetFontAndSize (page, def_font, 10);
        HPDF_Page_MoveTextPos (page, 0, -y_space);

        strcpy(temp,"10 słów: ");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        for(jj=0;jj<10;jj++)
        {
            itoa(patient->clinical_trials[jj],cht,10);
            HPDF_Page_ShowText (page, cht);
            HPDF_Page_ShowText (page, ", ");
        }
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);


        strcpy(temp,"10 słów (SUMA):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[10],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"10 słów (odroczenie):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[11],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"100-7 (Liczba błędów):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[12],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"100-7 (Czas):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[13],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Figura REY'A (kopia):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[14],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Figura REY'A (typ - kopia):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[15],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Figura REY'A (reprodukcja):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[16],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Figura REY'A (typ - reprodukcja):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        itoa(patient->clinical_trials[17],cht,10);
        HPDF_Page_ShowText (page, cht);
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Fluencja słowna (zwierzęta):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        for(jj=18;jj<=22;jj++)
        {
            itoa(patient->clinical_trials[jj],cht,10);
            HPDF_Page_ShowText (page, cht);
            HPDF_Page_ShowText (page, ", ");
            if(jj==21)  {HPDF_Page_SetFontAndSize (page, def_font_bold, 10); HPDF_Page_ShowText (page, "SUMA: "); HPDF_Page_SetFontAndSize (page, def_font, 10);}
        }
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Fluencja słowna (słowo na K):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        for(jj=23;jj<=27;jj++)
        {
            itoa(patient->clinical_trials[jj],cht,10);
            HPDF_Page_ShowText (page, cht);
            HPDF_Page_ShowText (page, ", ");
            if(jj==26)  {HPDF_Page_SetFontAndSize (page, def_font_bold, 10); HPDF_Page_ShowText (page, "SUMA: "); HPDF_Page_SetFontAndSize (page, def_font, 10);}
        }
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Fluencja słowna (przedmioty ostre):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        for(jj=28;jj<=32;jj++)
        {
            itoa(patient->clinical_trials[jj],cht,10);
            HPDF_Page_ShowText (page, cht);
            HPDF_Page_ShowText (page, ", ");
            if(jj==31)  {HPDF_Page_SetFontAndSize (page, def_font_bold, 10); HPDF_Page_ShowText (page, "SUMA: "); HPDF_Page_SetFontAndSize (page, def_font, 10);}
        }
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        strcpy(temp,"Fluencja słowna (słowo na F):");
        this->utf_to_iso2(temp);
        HPDF_Page_ShowText (page, temp);
        HPDF_Page_MoveTextPos (page, x_space, 0);
        for(jj=33;jj<=37;jj++)
        {
            itoa(patient->clinical_trials[jj],cht,10);
            HPDF_Page_ShowText (page, cht);
            HPDF_Page_ShowText (page, ", ");
            if(jj==36)  {HPDF_Page_SetFontAndSize (page, def_font_bold, 10); HPDF_Page_ShowText (page, "SUMA: "); HPDF_Page_SetFontAndSize (page, def_font, 10);}
        }
        HPDF_Page_MoveTextPos (page, -x_space, -y_space);

        HPDF_Page_EndText (page);
        //HPDF_Page_TextOut (page, 50, i*20, samp_text);

        pdf_file_name = DEFAULT_PDF_NAME;
        pdf_file_name.append(this->getCurrentDate(false));
        //pdf_file_name.append("_");
       // pdf_file_name.append(patient->surname);
        pdf_file_name.append(".pdf");
        HPDF_SaveToFile (pdf, pdf_file_name.c_str());
    }
    catch (...)
    {
        HPDF_Free (pdf);
        return 1;
    }
    HPDF_Free (pdf);

    return true;
}

void olaData::utf_to_iso2(char *src)
{
    char dst[MAX_STR_CONV];
    size_t srclen = MAX_STR_CONV;
    size_t dstlen = MAX_STR_CONV*2;
    const char *in = src;
    char *out = dst;
    iconv_t conv = iconv_open("ISO-8859-2","UTF-8");
    iconv(conv, &in, &srclen, &out, &dstlen);
    iconv_close(conv);

    strcpy(src,dst);
}

string olaData::getCurrentDate(bool dots)
{
    time_t curtime = time(0);
    tm *now=localtime(&curtime);
    char dest[BUFSIZ]={0};

    const char dot_format[]="%Y.%m.%d";
    const char underbar_format[]="%Y_%m_%d";
    if(dots)    strftime(dest, sizeof(dest)-1, dot_format, now);
    else        strftime(dest, sizeof(dest)-1, underbar_format, now);

    stringstream ss;
    string temp;
    ss << dest;
    ss >> temp;

    return temp;
}

string olaData::getCurrentTime()
{
    time_t curtime = time(0);
    tm *now=localtime(&curtime);
    char dest[BUFSIZ]={0};

    const char format[]="%X";
    strftime(dest, sizeof(dest)-1, format, now);

    stringstream ss;
    string temp;
    ss << dest;
    ss >> temp;

    return temp;
}

int olaData::getAge(char year[4])
{
    time_t curtime = time(0);
    tm *now=localtime(&curtime);
    char dest[BUFSIZ]={0};
    const char format[]="%Y";

    strftime(dest, sizeof(dest)-1, format, now);
    int year_int = atoi(year);
    int year_now = atoi(dest);
    return year_now-year_int;
}
