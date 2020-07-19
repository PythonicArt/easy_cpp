# 45 | [Jump Game II]( https://leetcode.com/problems/jump-game-ii ) | Hard
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

思路

从前到后

假设n0 = k
第一轮考虑 [1, k]
从i-k, 获取该位置能够到达的最远距离, 循环得到 maxRight
下一轮考虑
[k+1, maxRight]
直到maxRight>=n

```cpp

template <typename T>
int Solution<T>::jump(vector<int>& nums){
    int n = nums.size();
    if(n<=1) return 0;
    int minReach = 0;
    int maxReach = nums[0];
    int step = 1;
    if(maxReach>=n-1) return step;
    int t = maxReach;
    while(step < n){
        for (int i = minReach + 1; i <= maxReach; i++) {
            if(i + nums[i] >= t){
                // 更新最远位置
                t = i + nums[i];
            }
            if(t >= n-1) return ++step;
        }
        if(t > maxReach){
            // 下一轮从 [maxReach+1, t] 内判断
            minReach = maxReach;
            maxReach = t;
            step++;
        }
        else
        // 无法跳跃当前范围, 终点不可达
            return 0;
    }
    return 0;
}

```

AC记录
1. 边界情况的考虑
   [0], 直接就能到的 0
   [1, 2] 一步就能到的 1

另一种解法

```cpp

int fun(std::vector<int> nums){
    int n = nums.size();
    if(n<=1) return 0;
    int step = 0;
    int cur = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (i > last) {
            // 当i刚好超过上一轮的边界, step+1, 新的边界已从上一轮计算出来, 计入新一轮边界
            last = cur;
            ++step;
        }
        cur = max(cur, i + A[i]);
        if(cur >= n-1) return ++step;
    }
    return step;
}

```
