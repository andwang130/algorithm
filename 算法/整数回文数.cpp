/*描述
判断一个正整数是不是回文数。
回文数的定义是，将这个数反转之后，得到的数仍然是同一个数。

给的数一定保证是32位正整数，但是反转之后的数就未必了。
您在真实的面试中是否遇到过这个题？  
样例
11, 121, 1, 12321 这些是回文数。
23, 32, 1232 这些不是回文数。*/
class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        int new_num=num;
        int Reversal=0;
        while(num!=0)  //把这个整型倒序
        {
            Reversal=Reversal*10+num%10;  //从个位对这个整型取证，然后添加到新的整型当中
            num=num/10;                     //除于10向前移动一位

        }
        std::cout << Reversal << std::endl;
        if(Reversal==new_num)  //倒序之后的值合这个数对比，如果是相等表示是回文数
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
