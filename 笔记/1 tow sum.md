<!--
 * @Author: httermin
 * @Date: 2019-12-22 15:32:17
 -->
### 1. two sum


Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

#### 解法

+ **循环 全搜索**

对每个数值两两求和计算是否等于解，复杂度$O(n^2)$

```

```

+ **hash table**

put every number into hash table, the key is number, and position as value. Then loop the array, target minus number as m. the hash table is searched for  m, if it gets the key, then return the positions. 
complexity $O(n+log(n))$

the lookup complexity of hash table is $log(n)$

```

```

