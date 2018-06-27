

/*描述

设计一个算法，找出只含素因子2，3，5 的第 n 小的数。

符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

我们可以认为1也是一个丑数
您在真实的面试中是否遇到过这个题？  
样例

如果n = 9， 返回 10
挑战

要求时间复杂度为O(nlogn)或者O(n)*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    bool func(int m)  //判断这个数是不是丑数
    { 
 	//判断一个丑数的方法，首先除2，直到不能整除为止，然后除5到不能整除为止，
	//然后除3直到不能整除为止。最终判断剩余的数字是否为1，如果是1则为丑数，否则不是丑数。
        while(m%2==0)  
        {
            m=m/2;
        }
         while(m%5==0)
        {
            m=m/5;
        }
        while(m%3==0)
        {
            m=m/3;
        }
        
        if(m==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int nthUglyNumber(int n) {
        // write your code here
        if(n==1)
        {
            return 1;
        }
        int num=1;
        int flag=0;
        while(true)  //从1开始一直往上增加，判断每个数是否是丑数
        {
            if(func(num))
            {   
                flag++;  
            }
            if(flag==n)
            {
                break;
            }
            num++;
        }
        return num;
    }
};
