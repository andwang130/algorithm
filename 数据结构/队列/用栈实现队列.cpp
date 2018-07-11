class MyQueue {
    private:
    std::stack<int> st1;
    std::stack<int> st2;
    //实例两个栈
    
    //思路：栈是后进先出的机制
    //队列是先进先出的机制，
    //把一个栈的数据，压到另外一个栈，实现先进先出，数据入栈到st1，出从st2，
public:
    
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        
        st1.push(element);
        
    }

    /*
     * @return: An integer
     */
     void st1_to_st2()
     {
         //判断st2这个栈是否为空，为空就从第一个栈的数据压到st2
         if(st2.empty())
         {
         while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
             
         }
     }
    int pop() {
        
       st1_to_st2();
        int num= st2.top();
        st2.pop();
        return num;
        // write your code here
    }

    /*
     * @return: An integer
     */
    int top() {
        st1_to_st2();
        return st2.top();
        // write your code here
    }
};
