
def change(a):
    Capital_LIST=['零','壹','贰','叁','肆','伍','陆','柒','捌','玖']
    danw_LIST=['仟','佰','拾','']

    str_t=[]
    print(len(a))
    i=0
    while True:
        if i==0 and len(a)%4!=0:
            s=a[i:len(a)%4]
            i+=len(a)%4
        else:
            s=a[i:i+4]
            i+=4
        # s=s[::-1]
        num_flag=0
        for num in s:
            if num_flag<3:
                if int(num)==0:
                    try:
                        if  s[int(num_flag)+1]!='0':
                            str_t.append(Capital_LIST[0])
                    except:
                        pass
                else:
                    if i<4:
                        str_t.append(Capital_LIST[int(num)] + danw_LIST[-i+num_flag])
                    else:
                        str_t.append(Capital_LIST[int(num)] + danw_LIST[num_flag])

            else:
                str_t.append(Capital_LIST[int(num)])
            num_flag += 1
        # if len(a[i:i+4])>3:
        #     str_t+='万'
        # else:len(a[4:9])>4:
        if i>len(a):
            break
    if len(str_t) > 4:
        str_t.insert(-4,'万')
    if len(str_t)>8:
        str_t.insert(-9,'亿')
    return ''.join(str_t)
a='123123'
print(change(a))