#include <stdio.h>
#include <curl/curl.h>

int main(void){
     CURL *pCurl;
     CURLcode rsp;
     pCurl = curl_easy_init();
     if(pCurl) {
          curl_easy_setopt(pCurl, CURLOPT_URL, "https://localhost:8080/");

          rsp = curl_easy_perform(pCurl);
          if(pCurl != CURLE_OK){
               fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(rsp));
          }
          fprintf(stdout, "OK");
          curl_easy_cleanup(pCurl);
     }
     return 0;
}
