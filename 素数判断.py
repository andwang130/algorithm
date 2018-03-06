'''
8. 输入一个数，判断这个数是否为素数，并输出判断结果。
（所谓素数，是指除了1和该数本身之外，
不能被其它任何整数整除的数。
'''
while True:
    a=int(input('输入一个数字'))
    for i in range(1,a+1):
        if a%i==0 and a!=i and i!=1:
            print('该数不是素数')
            break
    else:
        print('该数是素数')
    
        
