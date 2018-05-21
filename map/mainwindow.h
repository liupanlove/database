#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <vector>
#include<QWebEngineView>
using namespace std;


namespace Ui {
class MainWindow;
}

struct coor{coor(double a=0.0,double b=0.0):x(a),y(b){}double x,y;};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void write_file(vector<coor> points);
    vector<coor> read_file();

    QWebEngineView * view; //  = new QWebEngineView();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
