'''
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？
都是多少？ 程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组
成所有的排列后再去掉
不满足条件的排列。
'''
li=[]
for i in range(1,10,1):
    for j in range(1,10,1):
        for k in range(1,10,1):
            if i!=j and j!=k and i!=k:
                s=str(i)+str(j)+str(k)
                li.append(s)
                
    
print(li)