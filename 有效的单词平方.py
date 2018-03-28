class Solution:
    """
    @param words: a list of string
    @return: a boolean
    """

    def validWordSquare(self, words):
        # Write your code ere
        for i in range(500):  # 字符长度是500，所有循环就500次了
            st = ''
            for j in words:  # 遍历这个列表

                try:
                    st += j[i]  # 把列拼起来和行对比
                except:
                    return False

            if st == words[i]:  # 和行对比
                return True

# #题目给定一个单词序列，检查它是否构成一个有效的单词平方。
#
# 如果第k行和列读取完全相同的字符串，则字序列形成有效的字平方，其中0 ≤ k < max(numRows, numColumns)。
#
#  注意事项
# 给出的字数至少为1，不超过500。
# 字长度至少为1且不超过500。
# 每个单词只包含小写英文字母a-z。
# 样例
# Given
# [
#   "abcd",
#   "bnrt",
#   "crmy",
#   "dtye"
# ]
# return true
