#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    std::string app;
    int code;

    getline(std::cin, app);
    
    bool isSpotify = std::regex_match(app, std::regex::icase("[S,s]potify"));
    bool isVsCode = std::regex_match(app, std::regex("F"));

    if ( isSpotify ) {
        int code = std::system("start C:\\Users\\perkinsal\\AppData\\Roaming\\Spotify\\Spotify.exe");
    }
    else if ( false == true ) {
        std::cout << "This should be impossible?!?!?!?!";
        return 3;
    }
    else {
        std::cout << "The program " << app << " is unknown?";
        return 1;
    }
    

    // checking if the command was executed successfully
    if ( code == 0 || isSpotify ) {
        cout << "Command executed successfully." << std::endl;
    } else {
        cout << "Command execution failed or returned "
            "non-zero: "
            << code << std::endl;
        return 2;
    }

    return 0;
}