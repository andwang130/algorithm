#include "deom.h"
#include <iostream>
#include <fstream>
#include<requests.h>
#include<regex>
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
 vector<QMap<QString, QString>>mydemo::get_clue(sper &spe)
 {
     vector<QMap<QString, QString>> data_list;
     QString url="http://ztcrm.zotye.com/saleClue_queryExtPageS.s";
     QMap<QByteArray,QByteArray>headers;
     headers["Host"]="ztcrm.zotye.com";
     headers["Connection"]="keep-alive";
     headers["User-Agent"]="Mozilla/5.0 (Linux; Android 7.1.2; vivo X9 Build/N2G47H) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Crosswalk/15.44.384.13 Mobile Safari/537.36";
     headers["Accept"]="application/json, text/plain, */*";
      QMap<QByteArray,QByteArray>data;
      data["ztcrmAppToken"]=spe.token.toLocal8Bit();
      data["currentPage"]="1";
      data["queryParam"]="";
      data["saleCluePublicType"]="0";
      requests requ;
      response resp=requ.post(url,headers,data);

      QMap<QString, QVariant> rseult=resp.json().toVariant().toMap();
      QString flag=QString::fromUtf8(rseult["successFlag"].toByteArray());
      if(flag!="true")
        {
          return data_list;
        }
      QMap<QString, QVariant>message =rseult["message"].toMap();
      QList<QVariant> data_QV=message["data"].toList();
      for(int i=0;i<data_QV.size();i++)
      {
        QMap<QString, QVariant> data_info=data_QV.at(i).toMap();
        QMap<QString,QString> qmap;
        qmap["ztcrmAppToken"]=spe.token;
        qmap["clueType"]=QString::fromUtf8(data_info["clueType"].toByteArray());
        qmap["agePeriodId"]=QString::fromUtf8(data_info["agePeriodId"].toByteArray());
        qmap["agePeriodName"]=QString::fromUtf8(data_info["agePeriodName"].toByteArray());
        qmap["areaId"]=QString::fromUtf8(data_info["areaId"].toByteArray());
        qmap["areaName"]=QString::fromUtf8(data_info["areaName"].toByteArray());
        qmap["auditor"]=QString::fromUtf8(data_info["auditor"].toByteArray());
        qmap["auditordate"]=QString::fromUtf8(data_info["auditordate"].toByteArray());
        qmap["auditorId"]=QString::fromUtf8(data_info["auditorId"].toByteArray());

        qmap["auditorStatus"]="0";//0

        qmap["auditorStatusNot"]=QString::fromUtf8(data_info["auditorStatusNot"].toByteArray());
        qmap["back"]=QString::fromUtf8(data_info["back"].toByteArray());
        qmap["birthday"]=QString::fromUtf8(data_info["birthday"].toByteArray());
        qmap["birthdayStr"]=QString::fromUtf8(data_info["birthdayStr"].toByteArray());
        qmap["buyCarReason"]=QString::fromUtf8(data_info["buyCarReason"].toByteArray());

        qmap["carSeriesId"]=QString::fromUtf8(data_info["carSeriesId"].toByteArray());//查询中取

        qmap["carTypeColorId"]=QString::fromUtf8(data_info["carTypeColorId"].toByteArray());
        qmap["carTypeColorName"]=QString::fromUtf8(data_info["carTypeColorName"].toByteArray());

        //qmap["carTypeId"]=QString::fromUtf8(data_info["carTypeId"].toByteArray()); //8e619987-776a-44a5-84a5-c99fc29c4433
        qmap["carTypeId"]=QString::fromUtf8("8e619987-776a-44a5-84a5-c99fc29c4433");


        cmatch st;
        regex remark_re("关注车型:(.*?)\\(关注度");
        regex_match(QString::fromUtf8(data_info["remark"].toByteArray()).toStdString().c_str(),st,remark_re);
        string str=st[1];
        qmap["carTypeName"]=QString::fromUtf8(str.c_str()); //T3001.5L-MT国V豪华型


        qmap["channelType"]=QString::fromUtf8(data_info["channelType"].toByteArray());//直接取

        qmap["clueId"]=QString::fromUtf8(data_info["clueId"].toByteArray());
        qmap["clueType"]=QString::fromUtf8(data_info["clueType"].toByteArray());
        qmap["clueTypeName"]=QString::fromUtf8(data_info["clueTypeName"].toByteArray());
        qmap["clueTypeNotIn"]=QString::fromUtf8(data_info["clueTypeNotIn"].toByteArray());
        qmap["clueId"]=QString::fromUtf8(data_info["clueId"].toByteArray());
        qmap["compareCarType"]=QString::fromUtf8(data_info["compareCarType"].toByteArray());
        qmap["createDate"]=QString::fromUtf8(data_info["createDate"].toByteArray()); //直接取

        qmap["creater"]=QString::fromUtf8(data_info["creater"].toByteArray());//直接取

        qmap["createrId"]=QString::fromUtf8(data_info["createrId"].toByteArray());//直接取

        qmap["customServiceAuditor"]=QString::fromUtf8(data_info["customServiceAuditor"].toByteArray());
        qmap["customServiceAuditorId"]=QString::fromUtf8(data_info["customServiceAuditorId"].toByteArray());

        qmap["customServiceAuditorStatus"]=QString::fromUtf8(data_info["customServiceAuditorStatus"].toByteArray());
        qmap["customerAddress"]=QString::fromUtf8(data_info["customerAddress"].toByteArray());
        qmap["customerBudget"]=QString::fromUtf8(data_info["customerBudget"].toByteArray());

        qmap["customerSourceId"]=QString::fromUtf8("a66d8415-ecee-470f-b89d-1df779375931");//a66d8415-ecee-470f-b89d-1df779375931

        qmap["customerSourceIdAndNull"]=QString::fromUtf8(data_info["customerSourceIdAndNull"].toByteArray());
        qmap["customerSourceName"]=QString::fromUtf8(data_info["customerSourceName"].toByteArray());

        qmap["customerType"]=QString::fromUtf8("0");//0

        qmap["customerTypeNotEqual"]=QString::fromUtf8(data_info["customerTypeNotEqual"].toByteArray());
        qmap["defeatReasonId"]=QString::fromUtf8(data_info["defeatReasonId"].toByteArray());
        qmap["defeatReasonName"]=QString::fromUtf8(data_info["defeatReasonName"].toByteArray());
        qmap["defeatReasonOther"]=QString::fromUtf8(data_info["defeatReasonOther"].toByteArray());

        qmap["delFlag"]=QString::fromUtf8(data_info["delFlag"].toByteArray());//直接取
        qmap["deposit"]=QString::fromUtf8("0");//0

        qmap["dir"]=QString::fromUtf8(data_info["dir"].toByteArray());
        qmap["dmsDealerNo"]=QString::fromUtf8(data_info["dmsDealerNo"].toByteArray());
        qmap["dmsSynStatus"]=QString::fromUtf8(data_info["dmsSynStatus"].toByteArray());

        qmap["documentDate"]=QString::fromUtf8(data_info["documentDate"].toByteArray());//直接取

        qmap["endDate"]=QString::fromUtf8(data_info["endDate"].toByteArray());
        qmap["endDate1"]=QString::fromUtf8(data_info["endDate1"].toByteArray());

        qmap["endDate2"]=QString::fromUtf8(data_info["endDate2"].toByteArray());
        qmap["endDate22"]=QString::fromUtf8(data_info["endDate22"].toByteArray());
        qmap["endDate3"]=QString::fromUtf8(data_info["endDate3"].toByteArray());
        qmap["endDateStr"]=QString::fromUtf8(data_info["endDateStr"].toByteArray());
        qmap["engineNo"]=QString::fromUtf8(data_info["engineNo"].toByteArray());
        qmap["estimatClinchcarDate"]=QString::fromUtf8(data_info["estimatClinchcarDate"].toByteArray());
        qmap["fineDecoration"]=QString::fromUtf8(data_info["fineDecoration"].toByteArray());

        qmap["gender"]=QString::fromUtf8("0"); //0

        qmap["id"]=QString::fromUtf8(data_info["id"].toByteArray());//直接取

        qmap["idCardNumber"]=QString::fromUtf8(data_info["idCardNumber"].toByteArray());
        qmap["idNotEqual"]=QString::fromUtf8(data_info["idNotEqual"].toByteArray());
        qmap["instruction"]=QString::fromUtf8(data_info["instruction"].toByteArray());

        qmap["intentionGradeId"]=QString::fromUtf8("41385ed4-2ce1-41d3-882e-6995bc0d13fe");//41385ed4-2ce1-41d3-882e-6995bc0d13fe

        qmap["intentionGradeId1"]=QString::fromUtf8(data_info["intentionGradeId1"].toByteArray());


        qmap["intentionGradeName"]=QString::fromUtf8("H"); //H

        qmap["isFailedResult"]=QString::fromUtf8(data_info["isFailedResult"].toByteArray());
        qmap["lastAuditorContext"]=QString::fromUtf8(data_info["lastAuditorContext"].toByteArray());
        qmap["lastTalksContext"]=QString::fromUtf8(data_info["lastTalksContext"].toByteArray());

        qmap["limit"]=QString::fromUtf8(data_info["limit"].toByteArray());//0

        qmap["loanTimeLimit"]=QString::fromUtf8(data_info["loanTimeLimit"].toByteArray());
        qmap["loanType"]=QString::fromUtf8(data_info["loanType"].toByteArray());
        qmap["loanTypeName"]=QString::fromUtf8(data_info["loanTypeName"].toByteArray());
        qmap["modifieId"]=QString::fromUtf8(data_info["modifieId"].toByteArray());

        qmap["modifier"]=QString::fromUtf8(data_info["modifier"].toByteArray());

        qmap["name"]=QString::fromUtf8(data_info["name"].toByteArray());//直接取

        qmap["nameOther"]=QString::fromUtf8(data_info["nameOther"].toByteArray());
        qmap["noExistTask"]=QString::fromUtf8(data_info["noExistTask"].toByteArray());
        qmap["orderCarTypeColorId"]=QString::fromUtf8(data_info["orderCarTypeColorId"].toByteArray());
        qmap["orderDate1"]=QString::fromUtf8(data_info["orderDate1"].toByteArray());
        qmap["orderType"]=QString::fromUtf8(data_info["orderType"].toByteArray());


        qmap["orgId"]=QString::fromUtf8(data_info["orgId"].toByteArray()); //直接取

        qmap["orgName"]=QString::fromUtf8(data_info["orgName"].toByteArray()); //直接取

        qmap["ownCarRecord"]=QString::fromUtf8(data_info["ownCarRecord"].toByteArray());

        qmap["phoneNum"]=QString::fromUtf8(data_info["phoneNum"].toByteArray());//直接取

        qmap["phoneNum1"]=QString::fromUtf8(data_info["phoneNum1"].toByteArray());
        qmap["phoneNumOther"]=QString::fromUtf8(data_info["phoneNumOther"].toByteArray());

        qmap["preferentialPrice"]=QString::fromUtf8(data_info["preferentialPrice"].toByteArray()); //

        qmap["professional"]=QString::fromUtf8(data_info["professional"].toByteArray());
        qmap["professionalName"]=QString::fromUtf8(data_info["professionalName"].toByteArray());
        qmap["provinceName"]=QString::fromUtf8(data_info["provinceName"].toByteArray());
        qmap["queryParam"]=QString::fromUtf8(data_info["queryParam"].toByteArray());

        qmap["replacementFlag"]=QString::fromUtf8(data_info["replacementFlag"].toByteArray());
        qmap["saleClueID"]=QString::fromUtf8("0b2c3cc0-365d-43fe-ba51-5ba8fd5ddcee"); //0b2c3cc0-365d-43fe-ba51-5ba8fd5ddcee

        qmap["saleConsultantId"]=QString::fromUtf8(data_info["saleConsultantId"].toByteArray());//直接取

        qmap["saleConsultantId1"]=QString::fromUtf8(data_info["saleConsultantId1"].toByteArray());

        qmap["saleConsultantName"]=QString::fromUtf8(data_info["saleConsultantName"].toByteArray());//直接取

        qmap["secondaryId"]=QString::fromUtf8(data_info["secondaryId"].toByteArray());
        qmap["serviceBackDealDealer"]=QString::fromUtf8(data_info["serviceBackDealDealer"].toByteArray());
        qmap["serviceBackDealDealerId"]=QString::fromUtf8(data_info["serviceBackDealDealerId"].toByteArray());
        qmap["serviceBackDealerStatus"]=QString::fromUtf8(data_info["serviceBackDealerStatus"].toByteArray());
        qmap["sort"]=QString::fromUtf8(data_info["sort"].toByteArray());

        qmap["start"]=QString::fromUtf8(data_info["start"].toByteArray()); //直接取

        qmap["startDate"]=QString::fromUtf8(data_info["startDate"].toByteArray());

        qmap["startDate1"]=QString::fromUtf8(data_info["startDate1"].toByteArray());
        qmap["startDate2"]=QString::fromUtf8(data_info["startDate2"].toByteArray());
        qmap["startDate22"]=QString::fromUtf8(data_info["startDate22"].toByteArray());
        qmap["startDate3"]=QString::fromUtf8(data_info["startDate3"].toByteArray());
        qmap["startDateStr"]=QString::fromUtf8(data_info["startDateStr"].toByteArray());
        qmap["successdate1"]=QString::fromUtf8(data_info["successdate1"].toByteArray());
        qmap["talksCount"]=QString::fromUtf8(data_info["talksCount"].toByteArray());
        qmap["talksPhaseId"]=QString::fromUtf8(data_info["talksPhaseId"].toByteArray());


        qmap["taskGenerateLastDate"]=QString::fromUtf8(data_info["taskGenerateLastDate"].toByteArray());
        qmap["taskGenerateLastDateStr"]=QString::fromUtf8(data_info["taskGenerateLastDateStr"].toByteArray());
        qmap["tryDrivingFlag"]=QString::fromUtf8(data_info["tryDrivingFlag"].toByteArray());
        qmap["vin"]=QString::fromUtf8(data_info["vin"].toByteArray());
        qmap["x"]=QString::fromUtf8(data_info["x"].toByteArray());
        qmap["y"]=QString::fromUtf8(data_info["y"].toByteArray());
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy-MM-dd'T'HH:mm:ss.SSS Z");
        QString new_data=current_date_time.toString("yyyy-MM-dd");
        QString talks=QString("{\"talksPhaseId\":\"\",\"marketingActivityId\":\"\",\"tryDrivingCarTypeId\":\"\",\"talksPhaseDetailIds\":\"\",\"nextCallDate"
                              "\":\"%1\",\"talksType\":\"0\",\"talksContext\":\"hhhhhh\",\"nextCallDateStr\":\"%2\"}").arg(current_date,new_data);
        //{"talksPhaseId":"","marketingActivityId":"","tryDrivingCarTypeId":"","talksPhaseDetailIds":"","nextCallDate":"2018-07-19T16:00:00.000Z","talksType":"0","talksContext":"hhhhh","nextCallDateStr":"2018-07-20"}
        qmap["talksRecordList"]=QString::fromUtf8(talks.toStdString().c_str());
        data_list.push_back(qmap);
      }
       qDebug()<<to_gbk(resp.str())<<endl;
        return data_list;
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
