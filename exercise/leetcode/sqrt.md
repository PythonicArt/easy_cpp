Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.

思路
    基于一个事实, sqrt(n) 属于范围 [1, n/2]
    可以在这个范围内进行二分查找
    当  j^2 < n < (j+1)^2 时, j就是所查到的结果

```cpp
class Solution{
    public:
         int mySqrt(int x) {
             int a = 1;
             int b = x/2;
             int last;
             if(x < 2) return x;
             while(a<=b){
                 int mid = a + (b - a) / 2;
                 if(x / mid > mid){
                     a = mid + 1;
                     last = mid;
                 }
                 else if(x / mid < mid){
                     b = mid - 1;
                 }
                 else
                    return mid;
             }
             return last;
    }
};
// vector<int> inputs = { 0, 4, 8 };
// vector<int> expects = { 0, 2, 2 };
```
