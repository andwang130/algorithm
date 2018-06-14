//
// Created by meidai on 18-6-14.
//

//单例模式，将构造函数设置成私有的，使的外部不能调用，只能使用一个静态方法来获得一个对象
//懒汉模式1  //懒汉模式在调用方法的时候才生成这个对象，懒汉模式不是线程安全的，如果要线程需要加锁

class Solution1 {
private:
    Solution1()
    {

    };
public:
    static Solution1* getInstance(){
        static Solution1 s;
        return &s;
    }
};




//懒汉模式2
class Solution2{
private:
    Solution2()
    {

    };
    static Solution2* s;
public:
    static Solution2* getInstance();
};
Solution2* Solution2::s= nullptr;
Solution2* Solution2::getInstance()
{
    // write your code here
    if(s== nullptr)
    {
        s=new Solution2();
        return s;
    }
    else
    {
        return s;
    }

}


//饿汉模式，饿汉模式合懒汉模式的区别在于，饿汉在调用方法之前对象就已经生成了，而且是线程安全的，
class Solution3
{
private:
    Solution3()
    {

    };
    
    static Solution3* s;
public:
    static Solution3* getInstance()
    {
        return s;
    }
};
Solution3* Solution3::s=new Solution3();