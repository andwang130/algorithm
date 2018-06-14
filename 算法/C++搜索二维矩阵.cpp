class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        for(int i=0;i<matrix.size();i++)  //vector是一个容器，和python的列表类似
        {
            if(matrix[i].back()>target)   //back方法返回最后一个元素，size长度，和python len差不多
										//这个二维数组是有序的，先找最后一个，对比一下，如果比他小。就进这个数组，在去对比，
										//如果比他大，直接跳过循环，进入下个数组
            {
                for(int j=0;j<matrix[i].size();j++)
                {
                    if (matrix[i][j]==target)  
                    {
                        return true;
                    }
                }
            }
            else if (matrix[i].back()==target)   //直接等于目标，那直接返回了
            {
                return true;
            }
            else
            {
                continue;
            }
            
        }
        return false;
    }
};