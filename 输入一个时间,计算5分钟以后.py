'''
 输入一个时间（小时:分钟:秒），输出该时间经过5分30秒后的时间。
'''
iputTime=input("输入一个时间，格式，小时:分钟:秒")
timeSpt=iputTime.split(':')
hour=int(timeSpt[0])
minute=int(timeSpt[1])
second=int(timeSpt[2])
if second+30>60:
    minute+=1
    second=second+30-60
else :
    second+=30
if minute+5>60:
    hour+=1
    minute=minute+5-60
else:
    minute+=5
print('5分钟30秒之后的时间%d：%d：%d'%(hour,minute,second))
