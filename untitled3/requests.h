
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<iostream>
#include<QDebug>
#include<QString>
#include<QMap>
#include<QJsonDocument>
#include<QTextCodec>
using namespace std;
QByteArray to_gbk(QString bytes);
QString to_gbk(QByteArray bytes);
QString to_uft_8(QByteArray bytes);

class response
{
  QByteArray data;
public:
  response(QByteArray str);
  QByteArray str();
  QJsonDocument json();


};

class requests
{

  QNetworkAccessManager *m_accessManager;
  void set_headers(QNetworkRequest &Request,QMap<QByteArray,QByteArray>&headers);
  QByteArray set_data(QMap<QByteArray,QByteArray>&data);
public:
  requests();
  ~requests();
  response get(QString url,QMap<QByteArray,QByteArray>headers);
  response post(QString url,QMap<QByteArray,QByteArray>headers,QMap<QByteArray,QByteArray>data);
};

