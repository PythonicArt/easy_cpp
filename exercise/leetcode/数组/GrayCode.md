


按顺序求得 格雷码即可

公式法
对于i  格雷码为  i ^ (i>>1)

vector<int> grayCode(int n) {

    int size = 1 << n;
    std::vector<int> v;

    for (int i = 0; i < size; ++i)
    {
        v.push_back(i ^ (i>>1));
    }

    return v;
    
}


迭代法， n位的格雷码 为 (1<<n) | n-1位格雷码

vector<int> grayCode(int n) {

    int size = 1 << n;
    std::vector<int> v;
    v.push_back(0);

    for (int i = 0; i < n; ++i)
    {
        int t = 1<<i;
        for (int j = v.size() - 1; j >= 0; --j)
        {
            v.push_back(v[j]|t);
        }
    }

    return v;
    
}