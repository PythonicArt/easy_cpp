
在原有数组上改， 如果最后有进位， 则在首元素上插入一个1

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int inc = 1;
    for (int i = n-1; i >= 0; --i)
    {
        int sum = digits[i] + inc;
        inc = sum / 10;
        digits[i] = sum % 10;
    }

    if (inc == 1)
    {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}


使用vector， 每得到一位就push_back。 变长是在push_back里操作的。 而不出直接按下标赋值也会自动变长
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int inc = 1;
    std::vector<int> v;
    for (int i = n-1; i >= 0; --i)
    {
        int sum = digits[i] + inc;
        inc = sum / 10;
        v.push_back(sum % 10);
    }

    if (inc == 1)
    {
        v.push_back(1);
    }
    reverse(v.bigin(), v.end());
    return v;
}