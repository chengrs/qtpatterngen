#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.showMaximized();
//    w.showFullScreen();
    w.setFixedSize(1280, 800);
    w.show();

    return a.exec();
}
