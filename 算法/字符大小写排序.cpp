
// 描述

// 给定一个只包含字母的字符串，按照先小写字母后大写字母的顺序进行排序。

// 小写字母或者大写字母他们之间不一定要保持在原始字符串中的相对位置。
// 您在真实的面试中是否遇到过这个题？  
// 样例

// 给出"abAcD"，一个可能的答案为"acbAD"



//将字符转ascii码，然后对比做排序
#include <algorithm> 
 bool func(char x,char y)
    {
        return (x>y);
    }
class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
   
    void sortLetters(string &chars) {
        // write your code here
        
      sort(chars.begin(),chars.end(),func);
        
        //  int i = 0;
        // int j = chars.size() - 1;
        // while (i < j) {
        //     while (islower(chars[i]) && i < j) {
        //         i++;
        //     }
        //     while (isupper(chars[j]) && j > i) {
        //         j--;
        //     }
        //     swap(chars[i], chars[j]);
        // }
    
    }
};
