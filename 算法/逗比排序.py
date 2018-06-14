from threading import Thread
import time
def sort(a):
    time.sleep(a)
    print(a)
a=[8,6,3,5,6,7]
t1=Thread(target=sort,args=(a[0],))
t2=Thread(target=sort,args=(a[1],))
t3=Thread(target=sort,args=(a[2],))
t4=Thread(target=sort,args=(a[3],))
t5=Thread(target=sort,args=(a[4],))
t6=Thread(target=sort,args=(a[5],))
t1.start(),t2.start(),t3.start(),t4.start(),t5.start(),t6.start()