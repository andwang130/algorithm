def qosort(li):#快速排序
   if not li:
      return li
   pivot=li[0]
   lenr=qosort([i for i in li[1:] if i>pivot])
   genr=qosort([i for i in li[1:] if i<=pivot])
   return  lenr+[pivot]+genr
   
  #快速排序，使用递归的方式，先取下标为0的元素，然后将所有的元素和他对比。大于他的放到一个列表，小于他的放到一个列表
  #然后将这两个列表在执行这个方法，最后将这些列表。想加起来，组成一个从大到小，或者从小到的列表