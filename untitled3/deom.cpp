#include "deom.h"
#include <iostream>
#include <fstream>
#include<requests.h>
using namespace std;
 bool mydemo::login(sper &spe)
 {
   requests requ;
   QMap<QByteArray,QByteArray>data;
   QMap<QByteArray,QByteArray>headers;
   data["appRoleType"]="0";
   data["loginName"]=spe.user.toLocal8Bit();
   data["password"]=spe.passwd.toLocal8Bit();
   headers["Host"]="ztcrm.zotye.com";
   headers["Connection"]="keep-alive";
   headers["User-Agent"]="Mozilla/5.0 (Linux; Android 7.1.2; vivo X9 Build/N2G47H) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Crosswalk/15.44.384.13 Mobile Safari/537.36";
   headers["Accept"]="application/json, text/plain, */*";
   QString url="http://ztcrm.zotye.com/user_loginS.s";
   response req=requ.post(url,headers,data);
   qDebug()<<to_gbk(req.str())<<endl;
   QMap<QString, QVariant> rseult=req.json().toVariant().toMap();
   QString flag=QString::fromUtf8(rseult["successFlag"].toByteArray());
   if(flag!="true")
     {
       return false;
     }

      QMap<QString, QVariant> message=rseult["message"].toMap();
       spe.token=QString::fromUtf8(message["token"].toByteArray());


 }
 int get_user(char *path,vector<sper> &sper_list)
 {

   //**eero code
   // 0 that is not files
   // 1
   ifstream fs(path);
   if(!fs.is_open())
     {
       return 0;
     }
   char buff[1024];
   string str;
   while(!fs.eof())
      {

          memset(buff,0,1024);
          fs.read(buff,1024);
          str+=buff;
      }
      fs.close();

    vector<string> lis;
    int flag=0;
    for(int i=0;i<str.size();i++)
      {
       if(str[i]=='\n'||str[i]=='\r')
         {
           lis.push_back(string(str,flag,i-flag));
           flag=i+1;
         }
      }
    lis.push_back(string(str,flag,str.size()-flag));
    for(int i=0;i<lis.size();i++)
      {
        for(int x=0;x<lis[i].size();x++)
          {
            if(lis[i][x]==':')
              {
                string user=string(lis[i],0,x);
                string paswd=string(lis[i],x+1,lis[i].size()-x);
                sper user_sp;
                user_sp.user=QString::fromStdString(user);
                user_sp.passwd=QString::fromStdString(paswd);
                user_sp.falg=i+1;
                sper_list.push_back(user_sp);
                break;
              }
          }
      }
    return 1;

 }
