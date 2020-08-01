

子序列的解法:

from wiki:
In mathematics, a subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

abbbcb => bbbb
abbc => bb

暴力解法
    一个个字符判断, 貌似要循环很多很多次， 删一个， 删两个， 删跳跃的两个... 无法有效跟踪


边界解法

使用一个 map<char, vector<int> > M 记录某个字符C出现的位置
使用 二维数组 p[i][j] 表示区间是否是回文， 默认为false, i=j时为true

maxLen = 0.

每当新加一个字符C = s[i]
    v = M[C]
    tempLen = v.size()+1; // 数量为基础长度

    for idx in v:
        if(isPalindrome(idx, i)){
            v.push(idx);
            M[C] = v;
            p[idx][i] = true;
            t = i-idx+1;
            tempLen = t>tempLen?t:tempLen;
        }

    maxLen = tempLen>maxLen?tempLen:maxLen;

return maxLen;


class Solution {
private:
    unordered_map<char, vector<int> > M;
    bool** p;
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n<2) return n;

        int maxLen = 0;
        p = new bool*[n];
        for (int i = 0; i < n; ++i)
        {
           p[i] = new bool[n]; 
           for (int j = 0; j < n; ++j)
           {
                if(i == j)
                    p[i][j] = true;
                else
                    p[i][j] = false;
           }
        }

        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            int tempLen;
            if(M.find(c)!=M.end()){
                std::vector<int> v = M[c];
                tempLen = v.size() + 1;
                for(auto idx:v){
                    if(idx == i-1 || p[idx+1][i-1]){        
                        p[idx][i] = true;
                        int t = i-idx+1;
                        tempLen = t>=tempLen?t:tempLen;
                        break;
                    }
                }
                v.push_back(i);
                M[c] = v;    
            }else{
                std::vector<int> v;
                v.push_back(i);
                M[c] = v;
                tempLen = 1;
            }   
            maxLen = tempLen>maxLen?tempLen:maxLen;    
        }

        return maxLen;   
    }

};


这个解法存在问题， 就是只考虑了单个相同字符的聚合， 而其他的组合也有可能组成回文串。

参考答案：
动态规划

f[i][j] 表示 范围内 最大的回文串的长度, 从小区间计算到最大的区间

需要从后往前遍历， 只有只有在计算一个大区间时才能保证其所有子区间都被计算完毕了

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        if(n<2) return n;

        int p[n][n];

        for (int i = n-1; i >=0; --i)
        {
            p[i][i] = 1;
            for (int j = i+1; j < n; ++j)
            {
                if(s[i] == s[j]){
                    if(i == j-1)
                        p[i][j] = 2; // c++ 数组不会被初始化为0， 所以没有设置值的需要优先判断
                    else
                        p[i][j] = 2 + p[i+1][j-1];
                }else{
                    p[i][j] = max(p[i+1][j], p[i][j-1]);
                }
            }
        }
        return p[0][n-1];   
    }

};

字符串的题目真是太费时间了， 十分想放弃。


一个边界解法的尝试

low, high, 表示当前的左右边边界
考虑 首字符 str[low] ， 找到字符串中 最右出现的的C 的位置， 
    如果右边没有出现, 则说明以当前字符为开头无法构成一个回文串。
        low++;
    如果找到， 下标为j， 则可以缩小检查范围。 
        sum += 2;
        low = low+1;
        high = j - 1;

循环条件， low < high 

这个版本不能 ac， 首字符在后面会出现， 不代表这就是最大的子回文序列的两端， 并不能缩小范围。
aabaaba
abaccccccccccc （这是一个很明显的反例）

int longestPalindromeSubseq(string s) {
        int low = 0, high = s.size() - 1;
        int sum = 0;

        while(low < high){
            char c = s[low];
            int j = high;
            
            while(j>low && s[j]!=s[low]) j--;

            if(j>low){
                sum+=2;
                low = low+1;
                high = j-1;
                if(low == )
            }else{
                low++;
            }
        }

        if(low == high) sum+=1;
        return sum;
    }




