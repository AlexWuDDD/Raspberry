
#include "libcurl.h"
#include <string>
#include <wchar.h>

size_t WriteGetResp(void *buffer, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)buffer, 0, size*nmemb);
    return size*nmemb;
}

size_t WritePostBodyResp(void *buffer, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)buffer, 0, size*nmemb);
    return size*nmemb;
}
size_t WritePostHeaderResp(void *buffer, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)buffer, 0, size*nmemb);
    return size*nmemb;
}

int HttpGet(const char* url, std::string &respData)
{
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl == NULL)
    {
        return 1;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteGetResp);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &respData);
//      curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 5000); //libcurl存在毫秒超时bug,如果设备小于1000ms立即返回失败
//      curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 5000); //设置超时时间
    bool bCA = false;
    if (!bCA)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);//设定为不验证证书和HOST
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    }
    else
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "");
    }
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        cout << curl_easy_strerror(res) << endl;
    }
    curl_easy_cleanup(curl);
    cout << respData << endl;
    return 0;
}


int HttpPost(char* url, char* body)
{
    string respBodyData;
    string respHeadData;
    CURL* curl;
    CURLcode res;
    //设置头
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type:application/json;charset=UTF-8");
    curl = curl_easy_init();
    if (curl == NULL)
    {
        return 1;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, WritePostHeaderResp);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WritePostBodyResp);
    curl_easy_setopt(curl, CURLOPT_WRITEHEADER, &respHeadData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &respBodyData);
    //      curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 5000); //libcurl存在毫秒超时bug,如果设备小于1000ms立即返回失败
    //      curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 5000); //设置超时时间
    bool bCA = false;
    if (!bCA)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);//设定为不验证证书和HOST
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    }
    else
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "");
    }
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        cout << curl_easy_strerror(res) << endl;
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    cout << respHeadData << endl;
    cout << respBodyData << endl;
    return 0;
}

using namespace std;




