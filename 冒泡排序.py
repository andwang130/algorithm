# a=[2,3,4,5,6,1,2]
# def maopao(li):#冒泡
#     for i in range(len(li)):
#         for j in range(len(li)-1):
#             if li[i]<li[j]:
#                 li[i],li[j]=li[j],li[i]
#     return li
# print(maopao(a))
a=[1,2,3,4,6,7]
#冒泡排序比较好理解，从第0个元素开始和前面的元素逐一对比，比他小的就冒泡，和他调换位置
#对比完一轮后，下标加一，换下个个元素，对比一轮，这边对比出所有的元素，冒泡法要用到两个循环，时间复杂度比较高，快速排序是冒泡法的升级

