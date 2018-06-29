

// 描述

// 翻转游戏：给定一个只包含两种字符的字符串：+和-，你和你的小伙伴轮流翻转"++"变成"--"。当一个人无法采取行动时游戏结束，另一个人将是赢家。

// 编写一个函数，计算字符串在一次有效移动后的所有可能状态。
// 您在真实的面试中是否遇到过这个题？  
// 样例

// 给定 s = "++++", 在一次有效移动后，它会变成下列状态之一：

// [
//   "--++",
//   "+--+",
//   "++--"
// ]

// 如果无法移动，则返回一个空列表[].

class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        // write your code here
        
        vector<string> str_li;
        if(s=="")
        {
         return str_li;   
        }
        //思路遍历这个字符串，一次因为需要翻两个，判断当前下标和下一个字符是否是加号，如果都是加号
        //就可以反转他，生成新的字符串到vector当中
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='+'&&s[i+1]=='+')
            {
                string new_str=s;
                new_str[i]='-';
                new_str[i+1]='-';
                str_li.push_back(new_str);
            }
            
        }
        return str_li;
    }
};
