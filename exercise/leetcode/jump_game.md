Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:
```cpp

Input: [2,3,1,1,4]
Output: true
Explanation:
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

Example 2:
```cpp
Input: [3,2,1,0,4]
Output: false
Explanation:
    You will always arrive at index 3 no matter what. Its maximum
    jump length is 0, which makes it impossible to reach the last index.
```

分析

1. 从前往后计算, 判断每一个能够到达的位置i, 能够跳跃到的最大位置k, k>=nums.size()-1, 即可
```cpp
bool Solution<T>::canJump(vector<int>& nums){
    int maxReach = 0;
    int n = nums.size();
    for (int i = 0; i <= maxReach; i++) {
        maxReach = max(maxReach, i+nums[i]);
        if(maxReach >= n-1) return true;
    }
    return false;
}
```

2. 从后往前计算
j -> k 可达， 意味着  a[j] >= k-j;
```cpp
bool Solution<T>::canJump(vector<int>& nums){
    int k = nums.size() - 1;
    for (int j = k-1; j >= 0; j--) {
        if(nums[j] >= k - j){
            k=j;
        }
    }
    return k==0;
}
```

3. 动态规划
设状态为 f[i]，表示从第 0 层出发，走到 A[i] 时剩 余的最大步数，则状态转移方程为：
f[i] = max(f[i − 1],A[i − 1]) − 1,i > 0

最后得到 f[n-1] >= 0 即可

```cpp
template <typename T>
bool Solution<T>::canJump(vector<int>& nums){
    int n = nums.size();
    vector<int> f(n);
    f[0] = 0;
    for (int i = 1; i < n; i++) {
        if(f[i-1] < 0) return false; // 前置节点不可达，直接返回false
        f[i] = max(f[i-1], nums[i-1]) - 1;
    }
    return f[n-1] >= 0;
}
```

ac结果
序号  时间 内存占用
1     16   7.8
2     24   7.7
3     12   7.9
