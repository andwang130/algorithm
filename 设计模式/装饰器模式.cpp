//
// Created by meidai on 18-6-28.
//

#ifndef SUANFA_BASE64_H
#define SUANFA_BASE64_H

#endif //SUANFA_BASE64_H

#include <iostream>
using namespace std;
class Car
{
public:
    virtual ~Car()
    {
        
    }
    virtual void show()
    {
        cout<<"这是一辆车"<<endl;
    }
};
class WBM:public Car
{
    Car *car;
public:
    ~WBM(){

    }
    WBM(Car *_car )
    {
        car=_car;
    }

    void show()
    {
        car->show();
        cout<<"WBM"<<endl;
    }
};
class  WBM5:public Car
{
    Car *car;
public:
    ~WBM5()
    {

    }
    WBM5(Car *_car)
    {
        car=_car;
    }
    void show()
    {
        car->show();
        cout<<"WBM5"<<endl;
    }

};
int main()
{

    //**********装饰器模式，使用接口类的方式实现，所有对象都继承一个类，
    //实现他的虚函数，并且在自己的构造函数的是时候，传入一个对象，在调用show的时候，同时调用改对象的show
    //这样这个新的对象的show方法，就增加了传入对象的show 方法
    Car *car=new Car;

    car->show();
    cout<<"car***************"<<endl;

    Car *wbmcar=new WBM(car);
    wbmcar->show();
    cout<<"wbm***************"<<endl;

    Car *wbm5car=new WBM5(wbmcar);
    wbm5car->show();


}
