#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spotifyButton_clicked()
{
    int code;
    code = std::system("start C:\\Users\\perkinsal\\AppData\\Roaming\\Spotify\\Spotify.exe");
    std::cout << code << std::endl;
    if (code != 0) {
        code = std::system("start spotify");
        if (code != 0) {
            std::cout << "An error has occured while running Spotify" << std::endl;
        }
    }
}


void MainWindow::on_vscodeButton_clicked()
{
    int code;
    code = std::system("code-insiders");
    if (code != 0) {
        code = std::system("start C:\\Users\\perkinsal\\AppData\\Local\\Programs\\\"Microsoft VS Code Insiders\"\\\"Code - Insiders.exe\"");
        if (code != 0) {
            code = std::system("code");
            if (code != 0) {
                code = std::system("start C:\\Users\\perkinsal\\AppData\\Local\\Programs\\\"Microsoft VS Code\"\\Code.exe");
                if (code != 0) {
                    std::cout << "An error has occured while running Microsoft Visual Studio Code" << std::endl;
                }
            }
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    int code;
    code = std::system("start C:\\\"Program Files\"\\\"Microsoft Visual Studio\"\\2022\\Preview\\Common7\\IDE\\devenv.exe");
    if (code != 0) {
        code = std::system("start C:\\\"Program Files\"\\\"Microsoft Visual Studio\"\\2022\\Community\\Common7\\IDE\\devenv.exe");
        if (code != 0) {
            code = std::system("start C:\\\"Program Files (x86)\"\\\"Microsoft Visual Studio\"\\2019\\Comunity\\Common7\\IDE\\devenv.exe");
            if (code != 0) {
                std::cout << "An error has occured while running Microsoft Visual Studio" << std::endl;
            }
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int code;
    code = std::system("start %USERPROFILE%\\AppData\\Local\\DiscordDevelopment\\app-1.0.904\\DiscordDevelopment.exe --processStart DiscordDevelopment.exe");
    if (code != 0) {
        code = std::system("start %USERPROFILE%\\AppData\\Local\\DiscordCanary\\Update.exe --processStart DiscordCanary.exe");
        if (code != 0) {
            code = std::system("start %USERPROFILE%\\AppData\\Local\\Discord\\Update.exe --processStart Discord.exe");
            if (code != 0) {
                std::cout << "An error has occured while running Discord" << std::endl;
            }
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    std::exit(0);
}
