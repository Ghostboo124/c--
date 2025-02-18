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
    code = std::system("start %APPDATA%\\Spotify\\Spotify.exe");
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
        code = std::system("start %LOCALAPPDATA\\Programs\\\"Microsoft VS Code Insiders\"\\\"Code - Insiders.exe\"");
        if (code != 0) {
            code = std::system("code");
            if (code != 0) {
                code = std::system("start %LOCALAPPDATA%\\Programs\\\"Microsoft VS Code\"\\Code.exe");
                if (code != 0) {
                    std::cout << "An error has occured while running Microsoft Visual Studio Code" << std::endl;
                }
            }
        }
    }
}


void MainWindow::on_vsButton_clicked()
{
    int code;
    code = std::system("start %PROGRAMFILES(X86)%\\\"Microsoft Visual Studio\"\\2022\\Preview\\Common7\\IDE\\devenv.exe");
    if (code != 0) {
        code = std::system("start %PROGRAMFILES(X86)%\\\"Microsoft Visual Studio\"\\2022\\Community\\Common7\\IDE\\devenv.exe");
        if (code != 0) {
            code = std::system("start %PROGRAMFILES(X86)%\\\"Microsoft Visual Studio\"\\2019\\Comunity\\Common7\\IDE\\devenv.exe");
            if (code != 0) {
                std::cout << "An error has occured while running Microsoft Visual Studio" << std::endl;
            }
        }
    }
}


void MainWindow::on_discordButton_clicked()
{
    int code;
    code = std::system("start %LOCALAPPDATA%\\DiscordDevelopment\\Update.exe --processStart DiscordDevelopment.exe");
    if (code != 0) {
        code = std::system("start %LOCALAPPDATA%\\DiscordCanary\\Update.exe --processStart DiscordCanary.exe");
        if (code != 0) {
            code = std::system("start %LOCALAPPDATA%\\Discord\\Update.exe --processStart Discord.exe");
            if (code != 0) {
                code = std::system("start %LOCALAPPDATA%\\DiscordPTB\\Update.exe --processStart DiscordPTB.exe");
                if (code != 0) {
                    std::cout << "An error has occured while running Discord" << std::endl;
                }
            }
        }
    }
}


void MainWindow::on_exitButton_clicked()
{
    std::exit(0);
}
