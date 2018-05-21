#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QMessageBox>
#include<fstream>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    view = new QWebEngineView();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<coor> MainWindow::read_file()
{
    vector<coor> ans;
    ifstream fin("../data/road.cnode");

    int tmp;
    double x, y;
    while(!fin.eof())
    {
        fin >> tmp >> x >> y;
        ans.push_back(coor(x, y));
    }

    /*for(int i = 0; i < ans.size(); ++i)
    {
        qDebug() << ans[i].x << " " << ans[i].y << endl;
    }*/
    fin.close();

    return ans;
}
void MainWindow::write_file(vector<coor> points)
{
    QFile file1("html.txt");
    QFile file2("test1.html");

    if(!file1.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", file1.errorString());

    if(!file2.open(QIODevice::ReadWrite))
        QMessageBox::information(0, "error", file2.errorString());

    QTextStream in(&file1);
    QTextStream out(&file2);

    while(!in.atEnd())
    {
        QString line = in.readLine();

        out << line << endl;
    }

    qDebug() << "haipa" << endl;
    for(int i = 0; i < points.size() / 100; ++i)
    {
        QString tmp = "    map.addOverlay(new BMap.Marker(new BMap.Point(" + QString::number(points[i].x, 'f', 5) + ", " + QString::number(points[i].y, 'f', 5) + ")));";

        out << tmp << endl;
        //break;
    }
    out << "</script>";

    file2.close();
    file1.close();
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();

    int num = str.toInt();

    qDebug() << num << endl;

    view->setUrl(QUrl("file:///C:/Users/19420/Desktop/database_bighomework/database/build-map-Desktop_Qt_5_10_1_MSVC2017_64bit-Debug/test1.html"));
    view->show();
}
