#include "mainwindow.h"
#include <QApplication>
#include<QWebEngineView>
#include<QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QWebEngineView * view = new QWebEngineView();
    view->setUrl(QUrl("file:///home/liupan15/Desktop/database/database/map/map.html"));
    view->show();
    return a.exec();
}
