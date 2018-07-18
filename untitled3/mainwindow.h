#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include<iostream>
#include<deom.h>
using namespace std;
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
   Ui::MainWindow *ui;
  ~MainWindow();

private slots:
  void on_pushButton_clicked();
   void UpdateSlot(int num);
private:
  void set_table();
  vector<sper> sper_list;

};

#endif // MAINWINDOW_H
