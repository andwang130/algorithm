
// 给定一个单词序列，检查它是否构成一个有效单词广场。
// 一个有效的单词广场满足：如果第k行和第k列读取相同的字符串,并且0≤k<max(numRows numColumns)。
// 样例

// 给定
// [
//   "abcd",
//   "bnrt",
//   "crmy",
//   "dtye"
// ]
// 返回 true

// 解释:
// 第一行和第一列都是“abcd”。
// 第二行和第二列都是“bnrt”。
// 第三行和第三列都是“crmy”。
// 第四行和第四列都是“dtye”。

// 因此，这是一个有效的单词广场.

// 给定
// [
//   "abcd",
//   "bnrt",
//   "crm",
//   "dt"
// ]
// 返回 true

// 解释:
// 第一行和第一列都是“abcd”。
// 第二行和第二列都是“bnrt”。
// 第三行和第三列都是“crm”。
// 第四行和第四列都是“dt”。

// 因此，这是一个有效的单词广场.

// 给定
// [
//   "ball",
//   "area",
//   "read",
//   "lady"
// ]
// 返回 false

// 解释:
// 第三行是 "read" 但是第三列是 "lead".

// 因此，这不是一个有效的单词广场.


class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
        //思路，遍历这个数组，先到行的坐标，取出行
        //然后在遍历，用行的下标取列，组成新的字符串，和行做对比
        for(int i=0;i<words.size();i++)
        {
            string str="";
            for(int j=0;j<words.size();j++)
            {
                str+=words[j][i];
            }
            if(str!=words[i])
            {
                return false;
            }
        }
        return true;
    }
};
