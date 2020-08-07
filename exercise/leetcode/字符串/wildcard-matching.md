简单地正则表达式匹配算法

只实现 * ? 的功能。 

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.

取 i, j分别从 s, p的开头往后匹配



class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchSub(s, 0, p, 0);
    }

    bool isMatchSub(string &s, int i, string &p, int j){
        int m = s.size();
        int n = p.size();
        
         if(i>=m){
            while(j<n){
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }

        while(true){
            if(p[j] == '?' || s[i] == p[j]){
                i++;
                j++;
                if(i >= m){
                    if(j >= n){
                        return true;
                    }else if(p[j]=='*')
                    {
                        while(++j < n && p[j] != '*') return false;
                        return true;
                    }else{
                        return false;
                    }
                }else{
                    if (j >= n)
                    {
                        return false;
                    }
                }
            }
            else if(p[j] == '*'){
                if(j==n-1) return true;
                // 剔除返回情况之后， 选p中的下一个字符 c ， 这个时候， s 从 i开始到最后的每个c 都可能是可选项。 如果没有出现c则不匹配。
                char c = p[++j];
                if(c == '*'){
                    continue;
                }else if( c == '?'){
                    while(i<m){
                        if(isMatchSub(s, i, p, j)){
                            return true;
                        }
                        i++;
                    }
                    return false;
                }else{
                    while(i<m){
                        if(s[i] == c && isMatchSub(s, i, p, j)){
                            return true;
                        }
                        i++;
                    }
                    return false;
                }
            }
            else
                return false;
        }
    }

};

思路是对的， 就是非常难debug， 应该拒绝这样的写法。


class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                ++i; ++j;
            } else if (j < n && p[j] == '*') {
                iStar = i;
                jStar = j++;
            } else if (iStar >= 0) {
                i = ++iStar;
                j = jStar + 1;
            } else 
                return false;
        }
        while (j < n && p[j] == '*') ++j;
        return j == n;
    }
};
https://www.cnblogs.com/grandyang/p/4401196.html

说到底还是思路不够清晰， 导致无法处理各个条件分之下的所有情况。

s[i] == p[j] || p[j] == '?', 两个指针同时前进。

如果出现*， 记录i的位置， 和*号的位置，
    iStar = i;
    jStart = j;
    j = jStart + 1;

当出现不匹配的情况， 但是前面出现过*, iStart++, 做新一轮尝试。
    iStar++;
    j = jStar + 1;

当出现不匹配， 前面又没有星号， 返回不匹配。


跳出循环之后， j如果没到结尾， 则判断其后面是否都是*， 是的话就匹配， 否则不匹配。


这里被一个情况卡住了， 就是后面出现的*， 后改变前面的*的位置， 以为这是错误的。
其实只要后面再出现*， 前面缓存的位置已经不重要了， 可以更新缓存位置 iStar, jStar


动态规划的解法

二维数组 dp[m+1][n+1] 

d[i][j] 表示 
s(0, i-1) 与 p(0, j-1) 是否匹配

如果 s, m都为空， 也是匹配的， 所以 d[0][0] = true;

dp[i][j] =>
    dp[i-1][j] || dp[i][j-1] , p[j-1] == '*', 这要任何一部分匹配即可
    dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')， 前部分匹配， 且当前字符匹配


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?') ;
                }
            }
        }
        return dp[m][n];
    }
};


