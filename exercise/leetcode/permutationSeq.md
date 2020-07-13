从高位到低位, n趟计算， 每一趟选出一个数。选完之后从集合中去除。
这里使用的vector, 可以使用 Sequence.

遇到的问题：
    人肉debug效率很低， 检查不出问题。 想法是对的， 但是实现的细节有问题。
    
    第一次是在 factorial(n-1), 应该是 factorial(i-1)

    对于代码的修改 没有一个全局的概念， 以偏概全。

    没有检查就提交， 感觉是对了就提交。


string getPermutation(int n, int k) {
    std::vector<int> assister(n);

    string result;
    for (int i = 0; i < n; ++i)
    {
            assister[i] = i+1;
    }
    int len = n;
    for (int i = n; i > 1; --i)
    {
        int idx = max(0, (k-1)/factorial(i-1)); 
        k = max(0, k - idx * factorial(i-1));
        result.push_back(assister[idx] + '0');
        removeElement(assister, len--, idx);
    }
    result.push_back(assister[0] + '0');
    return result;
}


int factorial(int num){
    for (int i = num - 1; i > 1; --i)
    {
        num *= i;
    }
    return num;
}

void removeElement(vector<int>& nums, int len, int idx) {
    int t = nums[idx];
    for (int i = idx; i < len-1; ++i)
    {
        nums[i] = nums[i + 1];
    }
    nums[len - 1] = t;
}