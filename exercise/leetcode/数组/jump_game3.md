Given an array of non-negative integers arr, you are initially positioned at start index of the array.
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Example 1:
```cpp
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3
```

Example 2:
```cpp
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
Explanation:
One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3
```

Example 3:
```cpp
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
```

Constraints:
1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length

# 思路
从出发点开始， 两个方向的下一个值 A,B
任何一个越界都不考虑
先考虑A, 再考虑B
都不可达则为false
但是递归会爆栈, 不可取
只能自己申请栈, 然后使用迭代的方式. 同时, 已经入栈的index不能重复入栈

```cpp
template <typename T>
bool Solution<T>::canReach(vector<int>& arr, int start) {
    // int n = arr.size();
    // if(start<0 && start >= n) return false;
    // if(arr[start] == 0) return true;
    // int left = start - arr[start];
    // int right = start + arr[start];
    // return canReach(arr, left) || canReach(arr, right);
    //
    int n = arr.size();
    std::stack<int> s;
    std::vector<bool> sign(n, false);
    s.push(start);
    sign[start] = true;
    while(!s.empty()){
        int t = s.top();
        s.pop();
        if(arr[t] == 0) return true;
        int left = t - arr[t];
        int right = t + arr[t];
        //
        if(right>=0 && right < n && sign[right]!=true) {
            s.push(right);
            sign[right]=true;
        }
        if(left>=0 && left < n && sign[left]!=true) {
            s.push(left);
            sign[left]=true;
        }
    }
    return false;
}
```
