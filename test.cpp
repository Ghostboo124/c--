#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string app;
    int code;

    std::cout << "Please enter the program that you want to open:\x20";
    getline(std::cin, app);
    std::cout << std::endl;
    std::cout << "Test!" << std::endl;
    bool isSpotify = std::regex_match(app, std::regex("spotify"));
    // bool isVsCode = std::regex_match(app, std::regex("vscode"));

    if (isSpotify) {
    // if (app == "spotify") {
		code = std::system("start Spotify");
		if (code != 0) {
			code = std::system("start C:\\Users\\perkinsal\\AppData\\Roaming\\Spotify\\Spotify.exe");
		}
    }
    else if (app == "vscode") {
        code = std::system("start C:\\Users\\perkinsal\\AppData\\Local\\Programs\\\"Microsoft VS Code Insiders\"\\\"Code - Insiders.exe\"");
    }
    else if (app == "" || app == "\x20") {
        std::cout << "Uhh, that isn't a valid input";
    } 
    else {
        std::cout << "The program " << app << " is unknown?";
        std::system("pause");
        return 1;
    }


    // checking if the command was executed successfully
    if (code == 0) {
        cout << "Command executed successfully." << std::endl;
    }
    else {
        cout << "Command execution failed or returned "
            "non-zero: "
            << code << std::endl;
        std::system("pause");
        return 2;
    }
    std::system("pause");
    return 0;
}