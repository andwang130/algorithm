'''
一个数如果恰好等于它的因子之和，这个数就称为“完数”。
如，6的因子为1、2、3，而6=1+2+3，因此6是完数。编程，找出1000之内的所有完数，
并输出该完数及对应的因子。（枚举法）
'''
for i in range(2,1001):
    factor=0
    factorList=[]
    for x in range(1,i):
        if i%x==0 and i!=x:
            factor+=x
            factorList.append(str(x))
    if factor==i:
        print('%s是完数'%i,'因子：',' '.join(factorList))
