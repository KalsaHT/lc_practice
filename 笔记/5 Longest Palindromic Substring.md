<!--
 * @Author: httermin
 * @Date: 2019-12-24 11:59:55
 -->
### 5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
```
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```
Example 2:
```
Input: "cbbd"
Output: "bb"
```

### 求解

+ **DP**

起始位置i , 当前位置j， 检查j-i之间是否为palindrom

