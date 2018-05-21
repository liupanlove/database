#include "mainwindow.h"
#include <QApplication>

#include<QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    vector<coor> test;

    //view->setUrl(QUrl("file:///C:/Users/19420/Desktop/database_bighomework/database/map/test.html"));
    //view->show();

    //view->setUrl(QUrl("file:///C:/Users/19420/Desktop/database_bighomework/database/map/map.html"));
    //view->show();
    MainWindow w;
    //test = w.read_file();
   // w.write_file(test);
    w.show();


    return a.exec();
}
