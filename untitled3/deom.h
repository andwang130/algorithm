#ifndef DEOM_H
#define DEOM_H

#endif // DEOM_H
#include<QString>
#include<iostream>
#include<vector>
using namespace std;
struct sper
{
 QString user;
 QString passwd;
 QString token;
 int falg;
};
int get_user(char *path,vector<sper> &sper_list);
class mydemo
{
public:
  bool login(sper &spe);
  vector<QMap<QString, QString>>get_clue(sper &spe);

};
