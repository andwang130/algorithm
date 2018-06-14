def twoSum(nums,target):
    while True:
        for i in nums:
            for j in nums:
                if j!=i:
                    if i+j==target:
                        return nums.index(i),nums.index(j)
nums=[1,2,5,6,7,8,10,3]
target=15
s=twoSum(nums,target)
