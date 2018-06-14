//
// Created by meidai on 18-6-14.
//

//描述
//
//        有 n 个硬币排成一条线。两个参赛者轮流从右边依次拿走 1 或 2 个硬币，直到没有硬币为止。拿到最后一枚硬币的人获胜。
//
//请判定 第一个玩家 是输还是赢？

//样例
//
//n = 1, 返回 true.
//
//n = 2, 返回 true.
//
//n = 3, 返回 false.
//
//n = 4, 返回 true.
//
//n = 5, 返回 true.

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        return n%3!=0;
      //根据规律能被3整除的数都会被后手拿到最后一个，根据传递的参数除于3求于，如果余数不为0,不能被3整除，
    }
};
