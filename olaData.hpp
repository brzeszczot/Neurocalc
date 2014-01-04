#ifndef OLADATA_HPP_INCLUDED
#define OLADATA_HPP_INCLUDED

#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>

#include <iconv.h>
#include "curl.hpp"
#include "wais.hpp"
#include "hpdf.h"
#define DEFAULT_IMPORT_FILE_NAME "import/neurocalcdb"
#define DEFAULT_FILE_NAME "export/neurocalcdb"
#define DEFAULT_CSV_NAME "export/excel_export_"
#define DEFAULT_PDF_NAME "export/pdf_export_"
#define NAME_MAX_LEN 30
#define MAX_STR_CONV 100
#define ALL_CLINICAL_TRIALS 38
#define SEP_WORD ';'
#define SEP_RECORD '#'

using namespace std;

class olaData
{
    public:
         struct DATA
        {
            char surname[NAME_MAX_LEN];
            char name[NAME_MAX_LEN];
            int age;                // 1-130
            int age2;               // sick age
            short int gender;           // 1: M, 0: K
            short int epileptic_focus;  // 0-9
            short int education;        // 0: low, 1: medium, 2: high, 3: vhigh
            short int domination;       // 0 - 2
            int p_hipokamp;       // 0 - 100
            int l_hipokamp;       // 0 - 100
            char test_date[WP1];
            char born_date[WP1];
            char update[20];
            short int wais[WP1];
            short int clinical_trials[ALL_CLINICAL_TRIALS];
        };
        string file_name;
        string csv_file_name;
        string pdf_file_name;
        olaData();
        ~olaData();
        bool readDb(vector <DATA*> *lp);
        bool saveDb(vector <DATA*> *lp);
        bool saveCsv(vector <DATA*> *lp,vector <string> string_epileptic_focus_tab,vector <string> string_education_tab,vector <string> string_domination_tab);
        bool savePdf(DATA* patient,vector <string> string_epileptic_focus_tab,vector <string> string_education_tab, vector <string> string_test_name_tab, vector <string> string_domination_tab);
        size_t srvSend(vector <DATA*> *lp);
        size_t srvGet(vector <DATA*> *lp);
        bool add_to_data(DATA *d, string in, size_t pos);
        string getCurrentDate(bool dots);
        string getCurrentTime();
        int getAge(char year[4]);
        void utf_to_iso2(char *src);
};

#endif // OLADATA_HPP_INCLUDED

