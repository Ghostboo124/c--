#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowIcon(QIcon(":/icon.ico"));
    window.show();
    return app.exec();
}
