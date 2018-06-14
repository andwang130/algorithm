def testfun():
    '''
这是一行注释
    '''
    pass
testfun.__doc__#可以查看方法中的注释
###__getitem__
class zoo():
    def __getitem__(self,key):#对类取值的时候会调用
        if key>=0 and key<=5:
            return key*key
        raise IndexError
        return None
    def __call__(self,*arg):#使类变成可调用函数
        for i in arg:
            print(i)
    def __delitem__(self,key):#在对类使用del的时候调用
        print('deltiem测试%s'%key)
    def __setitem__(self,key,value): #模拟obj['key']=value时调用
        print('setitem %s,%s'%(key,value))
a=zoo()
for i in a:
    print(i)
a('人生苦短','我用python')#调用__call__函数
del a['s']#模拟del 调用delitem函数
a['s']='b' #调用setitem函数
'''
用类的来实现斐波那契数列
'''
class Fbl():
    def __call__(self,key):
        a=0
        b=1
        print(a,b,end=',')
        for i in range(key):
            a+=b
            b+=a
            print(a,b,end=',')
b=Fbl()#实例类
b(10)#调用__call__函数
