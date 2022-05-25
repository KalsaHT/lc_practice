<!--
 * @Author: httermin
 * @Date: 2019-12-23 10:42:45
 -->
### 3 Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:
```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```
Example 2:
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```
Example 3:
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

#### 求解

+ **backstracking 思路**

计算截至每个char下的最大子长度；留一substr存储不重复的substring, 当新入的char之前出现过，则更新substr为去除重复char之前的substr, 并加入新char作为新substr.

```

```

complexity: $O(n + logn)$

+ **hash table**

hash table 存储字符char 最近出现那次的位置
