There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

思路

需要考虑相同的数值
rating 分布 属于山峰形状

初始化最低每人一颗糖
先考虑考虑从左到右的方向
if
    B > A ->
        c[B] = c[A] + 1;
    B == A ->
        c[B] = c[A];
    true ->
        pass
end.

再考虑考虑从右到左的方向
if
    B > A ->
        c[B] = max(c[B], c[A] + 1);
    B == A ->
        c[B] = max(c[B], c[A]);
    true ->
        pass
end.

递归的思路
对任意一个位置B (A, B, C),


```cpp
    一次基本操作只能计算一个 山峰的 值， 需要遍历整个数组, 主操作     
    std::vector<int> t(n);
    for (size_t i = 0; i < n; i++) {
        sum += f(t, i)
    }

    基本操作
    int f(vector<int> rating, vector<int> &t, int i){
        if(t[i] == 0){
            t[i] = 1
            if (i > 0 && rating[i] > rating[i - 1]) {
                t[i] = max(t[i], f(rating, t, i-1) + 1)
            }
            if (i > 0 && rating[i] == rating[i - 1]) {
                t[i] = max(t[i], f(rating, t, i-1))
            }
            if (i < n - 1 && rating[i] > rating[i + 1]) {
                t[i] = max(t[i], f(rating, t, i+1) + 1)
            }
            if (i < n - 1 && rating[i] == rating[i + 1]) {
                t[i] = max(t[i], f(rating, t, i+1))
            }
        }
        return t[i]
    }

```
