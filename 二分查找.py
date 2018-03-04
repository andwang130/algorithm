#二分查找就是将查找的值和数组的中间键作比较，如果被查找的键小于中间键，就在左子数组继续查找；如果大于中间键，就在右子数组中查找，否则中间键就是要找的元素。
#二分查找的数组必须为有序排列的
def binarySearch(li,num):
    low,higo=0,len(li)
    while low<higo:
        mid=(low+higo)//2
        if li[mid]>num:#如果目标值小于中间值，从左边开始找，中间值下标赋值给higo
            higo=mid
        elif li[mid]<num:#如果大于，说明目标在左侧，下标赋值给low
            low=mid+1
        else:
            return mid  #不满足，大于和小于的条件，等于目标值，返回下标
    return mid if li[mid]==num else False
a=[1,2,4,6,10,22,33,56,66]
print(binarySearch(a,66)) #66在列表的第八个