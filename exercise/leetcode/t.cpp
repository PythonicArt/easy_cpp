

从高位到低位 逐一选择一位sdf, 比如 第i位



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
    for (int i = idx; i < len; ++i)
    {
        nums[idx] = nums[idx + 1];
    }
    nums[len - 1] = t;
}