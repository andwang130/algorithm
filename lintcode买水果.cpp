/*
题目：
小明要帮公司买水果，给了一个codeList，里面装的是他买的水果，给了一个shoppingCart,里面装的是target水果，目标是检查codelist里的水果顺序是否和shoppingCart里的顺序匹配。注意的是只有codelist中的所有链表的item之后加起来小于等于shoppingcart里item之和才可能返回1，另外在codelist中有可能出现item时"anything"，它可以和任意的水果匹配。
给出codeList = [["apple", "apple"],["orange", "banana", "orange"]]，shoppingCart = ["orange", "apple", "apple", "orange", "banana", "orange"]，返回1。

解释：
因为codelist 里的顺序和 shoppingcart 里除了第一个 orange 之后的水果匹配。

给出codeList = [["orange", "banana", "orange"],["apple", "apple"]],shoppingCart = ["orange", "apple", "apple", "orange", "banana", "orange"],返回 0。

解释：
因为codeList里的顺序和shoppingcart没法匹配。

*/
class Solution {
public:
    /**
     * @param codeList: The codeList
     * @param shoppingCart: The shoppingCart
     * @return: The answer
     */
    int buyFruits(vector<vector<string>> &codeList, vector<string> &shoppingCart) {
        // Write your code here
        int shopi=0;
        bool flag=false;
        
        //两个循环遍历codelist
        //和shoppingcart的对比
        for(int i=0;i<codeList.size();i++)
        {
            vector<string> vec_str;
            vec_str=codeList[i];
           
            for(int j=0;j<vec_str.size();j++)
        {
            if(shopi>shoppingCart.size()-1)  //codeList未差完，shoppingCart已经完了，不匹配
            {
                return 0;
            }
            if(flag==false &&vec_str[j]==shoppingCart[shopi] &&shoppingCart[shopi]!="anything" &&vec_str[j]!="anything")  //没有找到对应的，codelist回到头，直到找到对应的顺序
            { 
                if(i==codeList.size()-1 &&j==vec_str.size()-1)
                {
                    return 1;
                }
                flag=true;
                i=-1;
                //shopi++;
                break;
            }
            else if(flag==true&&vec_str[j]!=shoppingCart[shopi] &&shoppingCart[shopi]!="anything" &&vec_str[j]!="anything") //顺序已经找到的情况下，不相等，返回0
            {   cout<<j<<endl;
           
                std::cout << vec_str[j] << std::endl;
                return 0;
               
            }
             shopi++;
        }
        }
        return 1;
    }
};
