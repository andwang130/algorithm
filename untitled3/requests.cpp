#include "requests.h"
#include<QMap>
#include <QEventLoop>

requests::requests()
{
  m_accessManager=new QNetworkAccessManager();
}
requests::~requests()
{
  delete m_accessManager;
}
void requests::set_headers(QNetworkRequest &Request,QMap<QByteArray,QByteArray>&headers)
{
  QMap<QByteArray,QByteArray>::iterator ite;
  for(ite=headers.begin();ite!=headers.end();ite++)
    {
      Request.setRawHeader(ite.key(),ite.value());
    }
}
QByteArray requests::set_data(QMap<QByteArray,QByteArray>&data)
{
  QByteArray data_str;
  QMap<QByteArray,QByteArray>::iterator ite;
  for(ite=data.begin();ite!=data.end();ite++)
    {
      data_str+=ite.key()+"="+ite.value()+"&";

    }
  return data_str;
}
response requests::get(QString url,QMap<QByteArray,QByteArray>headers)
{
  QNetworkRequest requtst;
  requtst.setUrl(QUrl(url));
  set_headers(requtst,headers);
  QNetworkReply* reply = m_accessManager->get(requtst);
  QEventLoop eventLoop;
  QObject::connect(m_accessManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
  eventLoop.exec();
  QByteArray  bytes = reply->readAll();
  response req(bytes);
  return req;
}
response requests::post(QString url,QMap<QByteArray,QByteArray>headers,QMap<QByteArray,QByteArray>data)
{

    QNetworkAccessManager *m_accessManager=new QNetworkAccessManager();
    QNetworkRequest requtst;
    requtst.setUrl(QUrl(url));
    set_headers(requtst,headers);
    QByteArray data_str=set_data(data);
    //data_str[data_str.size()-1]="";
    qDebug()<<data_str<<endl;
    requtst.setHeader(QNetworkRequest::UserAgentHeader, QVariant("Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.76 Mobile Safari/537.36"));
    QNetworkReply* reply = m_accessManager->post(requtst,data_str);
    QEventLoop eventLoop;
    QObject::connect(m_accessManager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
     QByteArray  bytes = reply->readAll();

    response req(bytes);
    return req;
   
}
QString to_gbk(QByteArray bytes)
{
  QTextCodec *qtext=QTextCodec::codecForName("GBK");
  QString str=qtext->toUnicode(bytes);
  return str;
}
QByteArray to_gbk(QString bytes)
{
  QTextCodec *qtext=QTextCodec::codecForName("UTF-8");
  QByteArray str=qtext->fromUnicode(bytes);
  return str;
}
QString to_uft_8(QByteArray bytes)
{
  QTextCodec *qtext=QTextCodec::codecForName("UTF-8");
  QString str=qtext->toUnicode(bytes);
  return str;
}
//******
response::response(QByteArray str)
{
  data=str;
}
QByteArray response::str()
{
  return data;
}
QJsonDocument response::json()
{
  QJsonParseError error;
   //qDebug()<<to_uft_8(data)<<endl;

  QString str=to_gbk(data);
  QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8(), &error);
  qDebug()<<error.error<<endl;
  return jsonDocument;

}
