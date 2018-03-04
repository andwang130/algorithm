'''
今有雉兔同笼，上有三十五头，下有九十四足，问雉兔各几何？
'''
head=35
foot=94
for i in range(1,head+1):
    for j in range(1,head+1):
        if i+j==head and foot-i*2==j*4:
            print('鸡有%d,兔子有%d'%(i,j))
