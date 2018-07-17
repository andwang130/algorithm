
#include <QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<iostream>
#include<QDebug>
#include<QString>
#include<QMap>
using namespace std;
class requests
{

  QNetworkAccessManager *m_accessManager;
  void set_headers(QNetworkRequest &Request,QMap<QByteArray,QByteArray>&headers);
  QByteArray set_data(QMap<QByteArray,QByteArray>&data);
public:
  requests();
  ~requests();
  QString get(QString url,QMap<QByteArray,QByteArray>headers);
  QString post(QString url,QMap<QByteArray,QByteArray>headers,QMap<QByteArray,QByteArray>data);

};

