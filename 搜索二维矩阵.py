
# 写出一个高效的算法来搜索 m × n矩阵中的值。
#
# 这个矩阵具有以下特性：
#
# 每行中的整数从左到右是排序的。
# 每行的第一个数大于上一行的最后一个整数。
# 样例
# 考虑下列矩阵：
#
# [
#   [1, 3, 5, 7],
#   [10, 11, 16, 20],
#   [23, 30, 34, 50]
# ]
# 给出 target = 3，返回 true
class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        # for i in matrix:
        #     for j in i:
        #         if j ==target:
        #             return True
        # return False
        for i in matrix:
            if target<i[-1]:
                for j in i:
                    if j ==target:
                        return True
            elif target==i[-1]:
                return True
            else:
                continue
        return False

matrix=[
  [1, 3, 5, 7],   [10, 11, 16, 20],
  [23, 30, 34, 50]
]

target=20
solu=Solution()
print(solu.searchMatrix(matrix,target))