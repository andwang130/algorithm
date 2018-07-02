 
// 描述
// 翻转链表中第m个节点到第n个节点的部分

// m，n满足1 ≤ m ≤ n ≤ 链表长度

// 您在真实的面试中是否遇到过这个题？  
// 样例
// 给出链表1->2->3->4->5->null， m = 2 和n = 4，返回1->4->3->2->5->null
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
     //思路：
     //1先找到m,n这两个位置的节点，然后取出来，
     //2在把这两个节点中间的节点添加到vector当中，
     //3 m和n两个节点的元素调换。将vector当中的节点倒叙取出来，连接起来
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        ListNode * m_list=NULL;
        ListNode * n_list=NULL;
        ListNode * now=head;
        if(head->next==NULL||m==n)
        {
            return head;
        }
        int i=1;
         std::vector<ListNode *> vect_List ;
        while(head!=NULL)
        {
            
            if(i==m&&m_list==NULL)
            {
                m_list=head;
            }
            if(i>m&&i<n)
            {
                vect_List.push_back(head);
            }
            if(i==n)
            {
                n_list=head;
                break;
            }
         head=head->next;
         i++;
        }
        i=vect_List.size()-1;
        int _int_new=m_list->val;
        m_list->val=n_list->val;
        n_list->val=_int_new;
        while(i>=0)
        {
        m_list->next=vect_List[i];
           cout<<vect_List[i]->val<<"->";
        
        m_list=m_list->next;
        i--;
        }
        m_list->next=n_list;
       
        return now;
    }
};