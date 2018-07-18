// 描述

// 给定一个字符串所表示的括号序列，包含以下字符： '(', ')', '{', '}', '[' and ']'， 判定是否是有效的括号序列。
// 您在真实的面试中是否遇到过这个题？  
// 样例

// 括号必须依照 "()" 顺序表示， "()[]{}" 是有效的括号，但 "([)]"则是无效的括号。

class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code 
        //解题思路：使用栈的后入先出的机制，把(,{,[这几个括号入到栈中，在遍历的时候，和),},]做对比,
        //在后面进入栈的括号肯定对应的括号也是最近的，
       
        int size=s.size();
        bool falg=true;
        if(size<2)
        {
            return false;
        }
        if(size%2!=0)
        {
            return false;
        }
        std::stack<char> sta ;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                sta.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!sta.empty()&&sta.top()=='(')
                {
                    sta.pop();
                }
                else
                {
                    falg=false;
                    break;
                }
            }
            else if(s[i]==']')
            {
                if(!sta.empty()&&sta.top()=='[')
                {
                    sta.pop();
                }
                else
                {
                    falg=false;
                    break;
                }
            }
             else if(s[i]=='}')
            {
                if(!sta.empty()&&sta.top()=='{')
                {
                    sta.pop();
                }
                else
                {
                    falg=false;
                    break;
                }
            }
         
        }
        if(!falg)
        {
            return falg;
        }
        else
        {
            if(!sta.empty())
            {
                falg=false;
            }
        }
        return falg;
           
            
        
    }
};
