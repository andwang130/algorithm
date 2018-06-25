#include<algorithm>
class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        
        
        //查找一个每个元素，大于另外一个元素的个数
      
        vector<int> req;
        sort(A.begin(),A.end()); 
        for(int i=0;i<queries.size();i++)
        {
              //把A排序,然后找到第一个>=queries[i]的第一个元素，
              //因为A已经是排序过的，找到这个元素的下标-1就是，小于queries[i]的个数
          int num=lower_bound(A.begin(),A.end(),queries[i])-A.begin();
          //lower_bound返回的是一个迭代器，减去A的begin就是int类型
            req.push_back(num);
        }
        return req;
    }
};
