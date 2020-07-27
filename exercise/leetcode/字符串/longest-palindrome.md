
给一个字符串，求其字符能够组成的最长的回文串。

统计各个字符出现的数量，
    偶数的直接相加

    奇数的直接相加， 并记录奇数的个数。

最后 sum = sum - oddCount + 1;

对于hash_map的选择。
map
    这样考虑 map.count

unordered_map 
    这样自己计数


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> M;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(M.find(c)!=M.end()){
                M[c] = M[c] + 1;
            }
            else{
                M[c] = 1;
            }
        }
        int all = 0;
        int oddCount = 0;
        for (auto it = M.begin(); it != M.end(); ++it)
        {
            int i = it->second;
            if(i % 2 != 0){
                oddCount += 1;
            }
            all+=i;
        }
        if(oddCount > 0) all = all - oddCount + 1;
        return all;
    }
};


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> count;
        for(char c : s){
            count[c]++;// 还可以这么遍历
        }
        int even = 0, odd = 0, oddCount = 0;
        for(auto i : count){ // 还可以这么遍历！！！
            if(i.second % 2){
                odd += i.second;
                oddCount++;
            }
            else{
                even += i.second;
            }
        }
        if(oddCount >= 1) odd = odd - oddCount + 1;
        return odd + even;
    }
};