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
    code = std::system("start Spotify");
    if (code != 0) {
        code = std::system("start C:\\Users\\perkinsal\\AppData\\Roaming\\Spotify\\Spotify.exe");
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
                code = std::system("start C:\\Users\\perkinsal\\AppData\\Local\\Programs\\\"Microsoft VS Code\"\\code.exe");
            }
        }
    }
}

