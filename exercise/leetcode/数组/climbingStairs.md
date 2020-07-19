# 70	[Climbing Stairs](https://leetcode.com/problems/climbing-stairs)	Easy

考虑 要爬到第n阶， 可以从 n-1阶 和 n-2阶 爬上去

即 sum = sum(n-1) + sum(n-2)



递归的解法, 可能会超时， 因为有太多的重复计算
int climbStairs(int n) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;

    return climbStairs(n-1) + climbStairs(n-2);
}


迭代的解法, 循环累积
int climbStairs(int n) {

    int last = 0;
    int sum = 1;

    for (int i = 1; i <= n; ++i)
    {
        int tmp = sum;
        sum = tmp + last;
        last = tmp;
    }

    return sum;
}


通项公式
sqrt(5)
pow(m, n)
