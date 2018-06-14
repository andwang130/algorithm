/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
      //二叉树的广度遍历，可以使用队列来完成
         vector<vector<int>> vect_order;
         if(root==NULL)
         {
          return vect_order;   
         }
         queue<TreeNode*>que;  //实例一个队列，队列是先进先出的机制
         que.push(root);     // 向队列添加一个TreeNode，添加了二叉树的头
        while(!que.empty())   //判断队列是否未空，如果为空，二叉树遍历完成
        {   int conut=que.size();   //获取二叉树的成员个数;
            vector<int> tor;    
            while(conut--)        //开始遍历队列
            {
                TreeNode* qtree=que.front();   //从队列的头拿一个出来
                que.pop();                    //将刚才拿出来的抛弃
                tor.push_back(qtree->val);    
                if(qtree->left!=NULL) //判断当前节点的left是否为空
                { 
                    que.push(qtree->left); //不为空添加到队列中
                }
                if(qtree->right!=NULL)
                {
                    que.push(qtree->right);
                }
            }//循环结束左右节点，都入队列了  
            vect_order.push_back(tor);
        }
        
        return vect_order;
    }
};
