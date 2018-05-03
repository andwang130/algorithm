#include <iostream>
using namespace std;
class long_int
{
private:
   void M_copy(int *a,int *b)
    {
        for(int i=0;i<size;i++)
        {
            a[i]=b[i];
        }
    }

public:
    int *INT_NUM;
    int size;
    long_int(int a)
    {

        INT_NUM=new int[15];
        size=15;
        int i=0;
        while(a)
        {

            int m=a%10;
            a=a/10;
            INT_NUM[i]=m;
            i++;
            if(i>size)
            {   int *INT_NUM_bk=new int[size];
                INT_NUM_bk=INT_NUM;
                size=size+15;
                INT_NUM=new int(size);

                M_copy(INT_NUM,INT_NUM_bk);
                delete INT_NUM_bk;
            }

        }

        size=i;
        int r_i=0;
        int *INT_NUM_BK=new int[size];
        for(int i=size-1;i>=0;i--)
        {
            INT_NUM_BK[r_i]=INT_NUM[i];
            r_i++;
        }
        INT_NUM= new int(size);
        M_copy(INT_NUM,INT_NUM_BK);

        delete INT_NUM_BK;

    }
    long_int operator +(int a)
    {   int i=size-1;
        while(a)
        {
            int m=a%10;
            a=a/10;
            if(m+this->INT_NUM[i]>=10)
            {
                this->INT_NUM[i]=m+this->INT_NUM[i]-10;
                this->INT_NUM[i-1]=this->INT_NUM[i-1]+1;
            }
            else
            {
                this->INT_NUM[i]=this->INT_NUM[i]+m;
            }
            cout<<this->INT_NUM[i]<<endl;
            i--;
        }
        return *this;
    }

    friend ostream & operator <<(ostream &os,const long_int &longInt);


};
ostream &operator <<(ostream &os,const long_int &longInt)
{
    for(int i=0;i<longInt.size;i++)
    {
        os<<longInt.INT_NUM[i];
    }
    return os;
}

int main() {
    long_int num(1220);
    long_int longint=num+10+23;
    cout<<longint<<endl;
    return 0;
}