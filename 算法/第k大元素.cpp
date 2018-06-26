 
//  描述

// 在数组中找到第k大的元素

// 你可以交换数组中的元素的位置
// 您在真实的面试中是否遇到过这个题？  
// 样例

// 给出数组 [9,3,2,4,8]，第三大的元素是 4

// 给出数组 [1,2,3,4,5]，第一大的元素是 5，第二大的元素是 4，第三大的元素是 3，以此类推
// 挑战



 
 bool sortfunc(int x,int y)
     {
         return (x>y);
     }
    //排序自定义方法，从大到小排序
class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    
    //思路，把这个数组从大到小排序，这样第一个就是最大的，然后根据K取值就可以了
    
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end(),sortfunc); //排序函数
        return nums[n-1]; //K从1开始，数组下标是从0开始，-1
    }
};
 
