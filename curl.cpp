#include "curl.hpp"

string Go(string var)
{
    CURL *curl;
    CURLcode res;
    string buffer;
    string url = "curl=";
    string str = var;
    string str_encode;
    string str_md5 = "";
    char errorBuffer[CURL_ERROR_SIZE];
    struct curl_slist *headers=NULL;

    str_encode = base64::encode((char*)str.c_str(), str.length());
    url += str_encode;
    url += "&sid=";
    url += SEED;
    url += "&crc=";
    str_md5 += str_encode;
    str_md5 += SEED;
    str_md5 += "Alamakotaakotmacostamwzebach759823728375";
    str_md5 = md5(str_md5);
    url += str_md5;

    curl_slist_append(headers, "Content-Type: text/html");
    curl_slist_append(headers, "charsets: utf-8");

    curl = curl_easy_init();
    if(curl)
    {
        //  curl_easy_setopt(curl, CURLOPT_HTTPHEADER,headers);
        curl_easy_setopt(curl, CURLOPT_ENCODING,"UTF-8");
        curl_easy_setopt(curl, CURLOPT_URL, "brzeszczot.net/curl");
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, url.c_str());
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT , 10);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer );
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res!=0)
        {
            //cout << errorBuffer << endl;
            string tmp;
            tmp.append("!!");
            tmp.append(errorBuffer);
            return tmp;
        }
        str = base64::decode(buffer);
        if(!str.empty())
            return str;
        else
            return "!!string is empty";
        //   cout << "1:" << str << endl;
        //   cout << "MD5:" << str_md5 << endl;
        /*
        ofstream file;
        file.open("outttttttt",ios::out);
        file << str;
        file.close();
        */
    }
    else return "!!curl error";
}

int writer(char *data, size_t size, size_t nmemb, string *buffer)
{
    int result = 0;
    if(buffer != NULL)
    {
        buffer -> append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}

