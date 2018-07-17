#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requests.h"
#include<QMap>
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

void MainWindow::on_pushButton_clicked()
{

    requests requ;
    QMap<QByteArray,QByteArray>data;
    QMap<QByteArray,QByteArray>headers;
    data["appRoleType"]="0";
    data["loginName"]="18656355357";
    data["password"]="12346";

    headers["Host"]="ztcrm.zotye.com";
    headers["Connection"]="keep-alive";
    headers["User-Agent"]="Mozilla/5.0 (Linux; Android 7.1.2; vivo X9 Build/N2G47H) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Crosswalk/15.44.384.13 Mobile Safari/537.36";
    headers["Accept"]="application/json, text/plain, */*";
    QString url="http://ztcrm.zotye.com/user_loginS.s";
    requ.post(url,headers,data);
}
