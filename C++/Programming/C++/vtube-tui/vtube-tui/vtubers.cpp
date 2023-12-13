#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<regex>
#include<curl/curl.h>

const std::string TEMP        = "/home/void/.cache/temp.xml";
const std::string CONFIG      = "/home/void/Scripts/config";
const std::string XML_DIR     = "/home/void/.cache/vtuber-xml";
char URL_FILE[]    = "/home/void/.cache/vtuber-urls";
char SEARCH_FILE[] = "/home/void/.cache/vtuber-search";

void help_ () {
    std::string help_text = "Useful information . . .\nmore text on another line";
    std::cout << help_text;
}

void list_ () {

}
void download_ () {

}

void update_ () {
    std::cout << "Do you wish to update the URL cache?\n(y/N) > ";

    std::string line;
    std::getline(std::cin, line);

    if (line == "y"){
        std::ifstream sfile;
        sfile.open(SEARCH_FILE);
        if (sfile) std::remove(SEARCH_FILE);
        sfile.close();

        std::ifstream ufile;
        ufile.open(URL_FILE);
        if (ufile) remove(URL_FILE);
        ufile.close();

        std::ifstream inFile(CONFIG);
        int linecount = std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n');
        std::cout << "Found " << linecount << " entries.\n";

        std::string     line;
        std::regex      comment("^#.*");
        std::regex      chnl(".* .*channel/");
        std::regex      cslsh(" .*");
        std::regex      cslsh2(".* https://www.youtube.com/c/");
        std::ifstream   cfile;

        cfile.open(CONFIG);
        while(getline(cfile, line)){
            if(regex_match(line,comment) == 0){

                std::string url = regex_replace(line, chnl, ""); 
                std::size_t foundUC = url.find("UC");

                if (foundUC != std::string::npos){
                url.replace(24,url.length(),"");
                std::cout << url << "\n";
                } else {
                    url = regex_replace(line, cslsh2, "");
                    url = regex_replace(url, cslsh, "");
                    url = "https://www.youtube.com/c/" + url;
                    std::cout << url << "\n";

                    CURL *curl = curl_easy_init();
                    if (curl){
                        CURLcode res;
                        curl_easy_setopt(curl, CURLOPT_URL, url);
                        res = curl_easy_perform(curl);
                        std::cout << url << " ";
                        if (res != CURLE_OK) std::cout << "failed\n";

                        curl_easy_cleanup(curl);
                    }
                }
            }
        }
    } else std::cout << "continue";
}


int main (int argc, char** argv) {
    for (int i = 1; i <= argc-1; i++) {
        if (strcmp("update",argv[i]) == 0) update_();
        else if (strcmp("list",argv[i]) == 0) list_();
        else if (strcmp("help",argv[i]) == 0) help_();
        else if (strcmp("-d",argv[i]) == 0) download_();
        else if (strcmp("anything",argv[i]) == 0) std::string const tags=".*";
    }
    return 0;
}
