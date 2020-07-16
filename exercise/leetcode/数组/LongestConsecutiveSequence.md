Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

```cpp
Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

```

有时间复杂度的要求， 不能排序.借助辅助结构， 哈希表

循环一遍存到把每个元素存到hash表中 再对每一个元素计算该元素所在序列的 最长连续序列的长度 从而获得最大值

```cpp

int longestConsecutive(vector<int>& nums) {
    map<int, bool> Signed;
    int longest = 0;
    int tmp;

    for(int i:nums) Signed[i] = false;

    for(int i:nums){
        tmp = 1;
        if(Signed[i]) continue;
        Signed[i] = true;
        int j;

        for(j = i + 1; Signed.find(j) != Signed.end(); j++){
            tmp++;
        }
        for(j = i - 1; Signed.find(j) != Signed.end(); j--){
            tmp++;
        }
        if(tmp > longest) longest = tmp;
    }

    return longest;
}
```
这种方法浪费时间较多， 因为有很多重复计算

## 方法二
同样使用hash表， 但是value记录以key为边界的最长连续序列的长度
1 _ 3
-----
1   1

当加入2时
1 2 3
-----
3 x 3

-------------------
考虑 加入一个元素a, 考虑 big = a+1, small = a-1
这里的big和small应该是产生连续序列的边界，中间的值无需更新

```cpp
int longestConsecutive(vector<int>& nums) {
    map<int, int> Signed;
    int longest = 0;
    for(int i:nums){
        // case unpassed 1: 未考虑出现重复的元素
        if(Signed.find(i) != Signed.end()) continue;
        int RightAtMost = i;
        int LeftAtMost = i;
        int big = i+1;
        int small = i-1;
        Signed[i] = 1;
        // case unpassed 2: 未考虑两边都需要更新的情况, 一开始只考虑了一边
        if(Signed.find(big) != Signed.end() && Signed.find(small) != Signed.end()){
            Signed[i] += Signed[big] + Signed[small];
            RightAtMost = i + Signed[big];
            Signed[RightAtMost] = Signed[i];
            LeftAtMost = i - Signed[small];
            Signed[LeftAtMost] = Signed[i];
        }
        else if(Signed.find(big) != Signed.end()){
            Signed[i] += Signed[big];
            RightAtMost = i + Signed[big];
            Signed[RightAtMost] = Signed[i];
        }
        else if(Signed.find(small) != Signed.end()){
            Signed[i] += Signed[small];
            LeftAtMost = i - Signed[small];
            Signed[LeftAtMost] = Signed[i];
        }
        if(Signed[i] > longest) longest = Signed[i];
    }
    return longest;
}
```
