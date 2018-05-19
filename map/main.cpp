#include "mainwindow.h"
#include <QApplication>
#include<QWebEngineView>
#include<QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //
    QWebEngineView * view = new QWebEngineView();
    view->setUrl(QUrl("file:///home/liupan15/Desktop/database/database/map/test.html"));
    view->show();

    view->setUrl(QUrl("file:///home/liupan15/Desktop/database/database/map/map.html"));
    view->show();
    MainWindow w;
    w.show();


    return a.exec();
}
