There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

两个已排序数组的 中位数, 时间复杂度要求 O(log(m+n))

中位数的定义
    当总数n为 奇数， 为中间的一个数
    当总数n为 偶数， 为中间的两个数的平均值

也就是找 第 k = (m+n)/2 个大的数， 两个数组的 topk 问题

s = m+n
s为奇数
    则计算 两个数组第  s/2 大的数

s为偶数
    则计算 两个数组第  s/2 大的数 a, 第  (s/2) + 1 大的数 b
    结果为 (a+b)/2

分别取两个数组 A, B 的 第 i = k/2 个数
if(A[i] < B[i])
    那么A中前 i 个数都可以去掉, 继续寻找后面得到 k-i个数
if(A[i] == B[i])
    第k个数就是A[i]
if(A[i] > B[i])
    同第一种情况是对称的


```cpp

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

double findMedianSortedArrays_(vector<int>::iterator it1, int m, vector<int>::iterator it2, int n, int k){
    if(m > n) return findMedianSortedArrays_(it2, n, it1, m, k);
    if(m == 0) return *(it2 + k - 1);
    if(k == 1) return min(*it1, *it2);
    int mid = min(k/2, m);
    int vA = *(it1 + mid - 1);
    int vB = *(it2 + mid - 1);
    if(vA == vB){
        if(mid * 2 == k) return vA;
        return findMedianSortedArrays_(it1 + mid, m - mid, it2 + mid, n - mid, k - mid * 2);
    }
    else if(vA < vB){
        return findMedianSortedArrays_(it1 + mid, m - mid, it2, n, k - mid);
    }
    else{
        return findMedianSortedArrays_(it1, m, it2 + mid, n - mid, k - mid);
    }
}

template <typename T>
double Solution<T>::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    int all = m + n;
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();
    if(all % 2 != 0){
        return findMedianSortedArrays_(it1, m, it2, n, (all/2) + 1);
    }
    else{
        double a = findMedianSortedArrays_(it1, m, it2, n, (all/2));
        double b = findMedianSortedArrays_(it1, m, it2, n, (all/2) + 1);
        return (a+b)/2.0;
    }
}
```
