
取两个下标 i, j ， 开始匹配

s[i] == p[j] || p[j] == '.'
    i++;
    pre = p[j++];
p[j] == '*'
    if(pre == '.')
        pass
    else if(isal(pre))
        int k = j+1;
        while(p[k] == pre && p[i] == pre) {k++;i++;}
        if(p[k] == pre) return false;
        if(p[k] != p[i]) return false;
    else
        return false;

想法超时

递归的解法：

class Solution {
public:
    bool isMatch(string s, string p) {

        if (p.empty()) return s.empty();
        
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }

        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }

        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }

        return isMatch(s, p.substr(2));
    }
};

p 如果为空 s需要为空才匹配

p 如果只有一个字符， s也需要只有一个字符，而且需要匹配。

p 如果>1个字符， 取前两个字符 first, second

如果second 不是 *
    first需要匹配再匹配 second

如果 second 是 *
    xbcdef......
    x*_____
    x 为 first

    *号可以匹配任意数量，需要把数量从0增加依次地探查该适量数量是否匹配。
    
    while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
        if (isMatch(s, p.substr(2))) return true; // 当前字符匹配， 就跳过 p 中 _* 这两个字符， 探查是否匹配。 如果匹配， 则返回。
        s = s.substr(1); // 没有返回， 则需要s往后再+1个字符。 
    }

    跳出上面的循环，
        s 为空， 直叫跳过 _* 这两个字符
        s不为空， 说明 出现了第一个与 first 不匹配的字符,  而且已经探查完毕， 直接跳过这两个字符判断即可。


动态规划的解法

1.  P[i][j] = P[i - 1][j - 1], if j > 0 && p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                    // 前半部分重复0次， 后半部分重复至少1次
                } else {
                    // j=1 或 p[j-1] 为常规字符， 必须匹配
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};