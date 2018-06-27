/*如果一个矩阵的每一条斜对角线（左上到右下）上的元素都相等，则我们称它为托普利兹矩阵。
现在输入一个M*N大小的矩阵，如果它是一个托普利兹矩阵，则返回true，如果不是，返回false。*/
class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // Write your code here
        if(matrix[0].size()==1)
        {
            return true;
        }
       for(int i=1;i<matrix.size();i++)  //遍历这个矩阵， 上一行，和一下行做对比
					//下一行的位置相对上一行要向后移动一位
       {
           for(int x=i;x<matrix[i].size();x++)
           {
               if(matrix[i][x]!=matrix[i-1][x-1]) 
               {
                  
                   cout<<matrix[i][x]<<endl;
                   return false;
               }
           }
       }
       return true;
    }
};
