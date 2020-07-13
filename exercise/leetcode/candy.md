# [Candy](https://leetcode.com/problems/candy/)

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

#  思路

ratings 分布 属于山峰形状, 可以看做由多个 凸起的山峰连接在一起
比如这样的形状
                4
     3       3
    2  2    2
  1      1 1

 对于相同的rating的处理， ratings[i] = ratings[i-1] 根据题目给的例子, 不需要糖果数量相同, 也就是后者可以从1开始

初始化最低每人一颗糖
考虑从左到右的方向, 每当右边元素大于自己， 右边的糖果数目为自己的数目+1, 否则为1
考虑从右到左的方向, 每当左边元素小于自己， max(左边的糖果数目为自己的数目+1, 已分配的数目), 否则为 已分配数目

```cpp
int candy(vector<int>& ratings) {
    int size = ratings.size()
    if(size == 1 || size == 0) return size;
    vector<int> c(size);
    c[0] = 1;
    // 从左往右    
    for (size_t i = 1; i < size; i++) {
        if(ratings[i] > ratings[i-1]){
            c[i] = c[i-1] + 1;
        }
        else if(ratings[i] == ratings[i-1]){
            c[i] = c[i-1];
        }
        else{
            c[i] = 1
        }
    }
    // 从右往左
    for (size_t i = size - 2; i > 0; i--) {
        if(ratings[i] > ratings[i+1]){
            c[i] = max(c[i+1] + 1, c[i]);
        }
        else if(ratings[i] == ratings[i+1]){
            c[i] = max(c[i+1], c[i]);
        }
        else{
            c[i] = 1
        }
    }
}

// ac版本
int candy(vector<int>& ratings) {
    int size = ratings.size();
    if(size == 1 || size == 0) return size;
    vector<int> c(size);
    c[0] = 1;
    // 从左往右
    for (int i = 1; i < size; i++) {
        if(ratings[i] > ratings[i-1]){
            c[i] = c[i-1] + 1;
        }
        // else if(ratings[i] == ratings[i-1]){
        //     c[i] = c[i-1];
        // }
        else{
            c[i] = 1;
        }
        // cout<< i <<" " << c[i] <<endl;
    }
    // 从右往左
    for (int i = size - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]){
            c[i] = max(c[i+1] + 1, c[i]);
        }
        // else if(ratings[i] == ratings[i+1]){
        //     c[i] = max(c[i+1], c[i]);
        // }
        // cout<< i <<" " << c[i] <<endl;
        // else{
        //     c[i] = 1;
        // }
    }
    int sum = accumulate(c.begin() , c.end() , 0);
    return sum;
}

问题
1. 没有考虑相等rating的情况的处理
2. 从有往左 第一遍写的是  i > 0, 判断错误

需要以测试驱动编码

```

# 递归的思路

每一个位置的最小糖果数目依赖于与其相邻的位置的糖果数目, 相邻位置用递归求解, 一次遍历累加即可

```cpp
int minCandy(vector<int> &ratings, vector<int> &t, int i){
    int n = ratings.size();
    if(t[i] == 0){
        t[i] = 1;
        if(i > 0){
            if (ratings[i] > ratings[i - 1]) {
                t[i] = max(t[i], minCandy(ratings, t, i-1) + 1);
            }
            else {
                t[i] = max(t[i], 1);
            }

        }
        if(i < n - 1){
            if (ratings[i] > ratings[i + 1]) {
                t[i] = max(t[i], minCandy(ratings, t, i+1) + 1);
            }
            else {
                t[i] = max(t[i], 1);
            }
        }
    }
    return t[i];
}

int candy(vector<int>& ratings) {
    int n = ratings.size();
    std::vector<int> t(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += minCandy(ratings, t, i);
    }
    return sum;
}
```
