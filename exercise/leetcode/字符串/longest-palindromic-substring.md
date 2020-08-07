做字符串相关的题很考验阅读理解。 

最大回文子序列串(sequence)，子字符串(sbstr)。


暴力解法
    以每个字符为中心两边扩展到最大的回文子串。 

边界解法
    可以把问题看成， 以字符 str[i] 开头的子回文序列的 最大值, i from 0 to n-1, 也就是区间 low, high

对于一个区间 low, high

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        int low = 0, high = n-1;
        if(n<=1) return s;
        string subStr;
        calc(s, low, high, subStr);
        return subStr;
    }

    bool calc(string s, int low, int high, string& subStr){
        if(low > high) return false;

        bool sign = false;

        if(low == high){
            if(subStr.size()<1) 
                subStr = s[low];
            return true;
        } 
                                                                                                                                                                                                                                       
        if(s[low] == s[high]){
            if(low+1 == high||calc(s, low+1, high-1, subStr)){
                if(subStr.size() < high - low + 1)
                    subStr = s.substr(low, high - low + 1);
                return true;
            }else{
                calc(s, low, high-1, subStr) || calc(s, low+1, high, subStr);
                return false;
            }
        }else{
           calc(s, low, high-1, subStr) || calc(s, low+1, high, subStr) || calc(s, low+1, high-1, subStr);
           return false;
        }
        
        return false;
        
    }
};

这个版本会超时，从外到内， 重复计算太多了。

动态规划的解法， 从里到外， 先计算小区间， 大区间通过小区间的值直接获得。

xxxxxxxx
i...j

M[i][j] => 
    true, i=j;
    s[j]==s[i] && (i - j < 2 || M[j+1][i-1]);

循环的写法
    i: 0 -> n
    j: 0 -> i

    在一个新的i加入， 0-i-1 的所有子区间都得到计算

由于要计算子串, 在每次计算一个新值的时候, 判断最大长度, 如果更新则记录最新的长度和起点。 


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool **M;

        M=new bool *[n];
        for(int i=0;i<n;i++){
            M[i]=new bool[n];
            for (int j = 0; j < n; ++j)
            {
                M[i][j] = false;
            }
        }

        int maxLen = 1, start = 0; // maxLen 需要从1开始。 单个字符也是回文
        for (int i = 0; i < n; ++i)
        {
            M[i][i] = true;
            for (int j = 0; j < i; ++j)
            {
                M[j][i] = (s[j]==s[i] && (i - j < 2 || M[j+1][i-1]));
                if(M[j][i] && (i-j+1 > maxLen)){
                    maxLen = i-j+1;
                    start = j;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};


马拉车算法：

预处理, 获得字符串 T
abba => ^#a#b#b#a#$

预处理的作用： 
    统一奇数和偶数个数，将字符数量全部转化为奇数, 减少边界条件的判断。

使用一个数组 P[n]， 标记以i为下标的字符 能够构成回文串的半径， 不包括当前位置。

abba
^#a#b#b#a#$
0010131000

数组的构建
for (int i = 1; i < t.size() - 1; ++i)
{
    while(t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
    // 这里不需要考虑边界问题， 因为 边界值 t[0] t[size-1] 注定是不相等的。
}

当这个数组构建完毕之后, 就找到数组的最大值 i, P[i]。 要求得子串， 就需要知道原字符串的位置和长度。

字符串T的位置 i 和原字符串 j 的位置关系

i = 1(字符^) + (j+1)(字符#) + j(前面的字符) = 2 * (j+1) 
j = i/2 - 1

P[i]是i左右侧组成回文串的长度， 有一半是 # 所以实际的长度为 (P[i]/2) * 2 = p[i]

子串为 s.substr((i/2) - 1, P[i]/2)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;

        string t="^";
        for (int i = 0; i < s.size(); ++i)
        {   
            t+="#";
            t+=s[i];
        }
        t+="#$";  // error : 不要再用单引号了， 好浪费时间。
        
        std::vector<int> p(t.size(), 0);
        int maxCenter = 0;
        int maxRadius = 0;

        for (int i = 1; i < t.size() - 1; ++i)
        {
            while(t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
            if(p[i] > maxRadius){
                maxCenter = i;
                maxRadius = p[i];
            }
        }
        
        int tStart = maxCenter - maxRadius;
        int start = ((tStart+1)/2) - 1;
        int len = maxRadius;
        return s.substr(start, len);
        
    }
};

可以优化的地方， 上述p[i]都是从0开始算起的，其实可以不从0算起， 这种处理方式有点像 kmp, 减少判断的次数。

什么时候不需要从0算起？

在位置 j 已求得 maxCenter, maxRadius 
  j i j
xxmxCxmxx

当求 j在 (maxCenter+1, maxCenter + maxRadius) 范围内时, 由于回文串的对称性， 

找到j 相对于 maxCenter 的对称位置 sj maxCenter - (j - maxCenter)， 该对称位置的 回文半径已经得到计算。

由对称性可以得到 p[j] = p[sj]， 

但是由于在maxCenter点只拓展到了  maxCenter + maxRadius 的位置，j + p[j] 不能超出这个范围，所以修正为

p[j] = min(p[mirror_j], maxCenter+maxRadius - j)， 从这个数值开始判断。 

如果j超出 (maxCenter+1, maxCenter + maxRadius) 范围， 则取0

整理如下
p[j]
    min(p[mirror_j], maxCenter + maxRadius - j), j>maxCenter && j<= maxCenter + maxRadius;
    0, other


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;

        string t="^";
        for (int i = 0; i < s.size(); ++i)
        {   
            t+="#";
            t+=s[i];
        }
        t+="#$";  // error : 不要再用单引号了， 好浪费时间。
        
        std::vector<int> p(t.size(), 0);
        int maxCenter = 0;
        int maxRadius = 0;

        for (int i = 1; i < t.size() - 1; ++i)
        {
            int rightMost = maxCenter+maxRadius
            if(rightMost > i){
                int mirror_i = maxCenter - (i - maxCenter);
                p[i] = min(p[mirror_i], rightMost - i);
            }
            while(t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
            if(p[i] > maxRadius){
                maxCenter = i;
                maxRadius = p[i];
            }
        }
        
        int tStart = maxCenter - maxRadius;
        int start = ((tStart+1)/2) - 1;
        int len = maxRadius;
        return s.substr(start, len);
        
    }
};

第一种复杂度 是平方， 其实就是暴力解法，预处理还使长度变成了2n,  每个位置都探查 O(n) 次， 即 n*n

优化后的嘛，只要右侧即rightMost拓展得越宽, 就几乎只是查表即可， 约等于 n


总结：

0. 暴力解法
1. 动态规划的解法
2. 马拉车算法