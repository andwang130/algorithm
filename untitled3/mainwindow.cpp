#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requests.h"
#include<QMap>
#include<thread>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void run(sper spe)
{
  qDebug()<<spe.user<<endl;
   //mydemo demos;
   //demos.login(now_spe);
}
void MainWindow::on_pushButton_clicked()
{

    char *url="/home/meidai/桌面/plan";
    get_user(url,sper_list);
    for(int i=0;sper_list.size();i++)
      {
        std::thread t1(run,sper_list[i]);
        t1.detach();
      }
}
