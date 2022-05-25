<!--
 * @Author: httermin
 * @Date: 2019-12-22 16:21:46
 -->
### 2 add two numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

#### 求解

+ **反转linklist 再求和**

若linklist是逆序，则不需要翻转。留一个指针指向初始位置，注意每次进位的情况
```
```
complexity: $O(n)$