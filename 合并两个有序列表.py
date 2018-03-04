def merge_list(l1,l2):
    tim=[]
    while len(l1)>0 and len(l2)>0:#当有一个列表的长度不大于0了就停止循环
        if l1[0]<l2[0]: #l1和l2的一个元素对比，谁小，谁加入新的列表里面，然后删除这个元素
            tim.append(l1[0])
            del l1[0]
        else:
            tim.append(l2[0])
            del l2[0]
    #从小到大，排完了一个列表，剩下的都是有个列表是大的。还没有取完，把这个列表从末尾添加
    #有一个列表是空的，有个有数据，不知道是哪个，都插入
    tim.extend(l1)
    tim.extend(l2)
    return tim
a=[3,3,4,6,7,8,9]
b=[1,2,3]
print(merge_list(a,b))
