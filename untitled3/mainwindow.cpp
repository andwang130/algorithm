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
void MainWindow::UpdateSlot(int num)
{

}


void get_login(sper spe,MainWindow *window)
{

   mydemo demos;
   QTableWidgetItem *user_itme = new QTableWidgetItem(spe.user);
   window->ui->my_tab->setItem(spe.falg,0,user_itme);
   QTableWidgetItem *pswd_itme = new QTableWidgetItem("************");
   window->ui->my_tab->setItem(spe.falg,1,pswd_itme);
   if(demos.login(spe))
   {
      QTableWidgetItem *token_time= new QTableWidgetItem(spe.token);
      window->ui->my_tab->setItem(spe.falg,2,token_time);
   }
   else
   {
       QTableWidgetItem *fall= new QTableWidgetItem("失败");
     window->ui->my_tab->setItem(spe.falg,2,fall);

   }
//   void UpdateSignal(int num);
//   emit UpdateSignal(1);


   //delete item;
}
void run(sper spe,MainWindow *window)
{

}
void MainWindow::on_pushButton_clicked()
{

    char url[29]="C:\\Users\\me\\Desktop\\plan.txt";
    get_user(url,sper_list);
    set_table();
   for(int i=0;i<sper_list.size();i++)
     {
       get_login(sper_list[i],this);
     }
    for(int i=0;i<sper_list.size();i++)
      {

       std::thread t1(run,sper_list[i],this);
        t1.detach();
      }
}
void MainWindow::set_table()
{
  ui->my_tab->setColumnCount(5);
  ui->my_tab->setRowCount(sper_list.size()+1);
  ui->my_tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
