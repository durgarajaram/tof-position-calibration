#include "mainwindow.h"
#include <QApplication>
#include "TApplication.h"

int main(int argc, char *argv[])
{
    TApplication* rootapp = new TApplication("a", &argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
