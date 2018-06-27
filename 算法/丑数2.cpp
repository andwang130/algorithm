#include<algorithm>
class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
   
    //使用空间复杂度换事件复杂度
   //先生成丑数列表，然后从里面直接拿，速度快很多
  //从丑数1,乘以2,乘以3,乘以5,都是丑数，然后新的丑数X2,X3,X5也是丑数
   
    int my_min(int x,int y,int z) 
    {
       int num=x;
        if(y<num)
        {
            num=y;
        }
        if(z<num)
        {
            num=z;
        }
        return num;
    }
    int nthUglyNumber(int n)
    {
    std::vector<int> nths;
    nths.push_back(1);
     int index=1;
     int r2=0;  
     int r3=0;
     int r5=0;
        while(index<n)
         {
             nths.push_back(my_min(2*nths[r2],3*nths[r3],5*nths[r5]));//比较乘以2,3,5之后，最小的插入向量当中
              
             if(*(nths.end()-1)==2*nths[r2])     //如果是插入的×2的丑数，X2的下标加一
             {
                 r2++;
             }
             if(*(nths.end()-1)==3*nths[r3])
             {
                 r3++;
             }
             if(*(nths.end()-1)==5*nths[r5])
             {
                 r5++;
             }
            index++;
         }
     return *(nths.end()-1);
     }
};
