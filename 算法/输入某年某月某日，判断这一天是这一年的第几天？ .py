'''程序分析：以3月5日为例，应该先把前两个月的加起来，
然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。 
'''
while True:
    try:
        year=int(input("输入年份"))
        month=int(input("输入月份"))
        day=int(input("输入日期"))
        break
    except:
        print('输入的格式不正确，请重新输入')
da={1:0,2:31,3:59,4:90,5:120,6:151,
    7:181,8:212,9:243,
    10:273,11:304,12:334}
def fx(mt):
    return da.get(mt)
sum=fx(month)+day
if year%100==0 and year%400==0 and day>3:
    sum+=1
print(sum)
    
    
