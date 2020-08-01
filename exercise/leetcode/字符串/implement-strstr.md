

寻找子串的位置， 存在则返回下标， 不存在则返回-1.如果needle为空， 则返回0

普通人只能想到 暴力解法。

由于难度是easy， 解法也应该是easy的。 

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;

        int n = haystack.size() - needle.size() + 1; // error1: 这里计数算错了
        for (int i = 0; i < n; ++i)
        {
            int j = 0, k = i; // error0: 第一次没有使用k做标记， 竟然有一个用例还过了
            while(j < needle.size() && haystack[k] == needle[j]) {++j;++k;}; // ++k后面漏了一个; compile error
            if(j>=needle.size()) return i;
        }
        return -1;
    }
};



kmp算法--重复多遍的理解吧， 楞想是想不出来的
分两步， 第一步计算 前后缀表 map
第二步，查表匹配。 匹配和暴力解法类似， 只是j 不再从头开始，而取的是 map[j-1]




class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }

    int kmp(string haystack, string needle){
        if(needle.empty()) return 0;

        std::vector<int> offsets = calckmp(needle);

        int n = haystack.size();
        int m = needle.size();
        int i = 0, j=0;
        while(i < n){
            // 匹配的情况
            if(haystack[i] == needle[j]){
                if(j == m - 1)// j已到结尾
                {
                    return i - m + 1; // 此时已经完全匹配, 因为在匹配过程中i是跟着前进的, 所以首次出现的位置将i前移 m - 1 个位置
                }
                else{
                    i++;
                    j++;
                }                    
            }
            // 第一个字符就不匹配
            else if(j == 0){
                i++;
            }
            else{
                // 不匹配的情况， 考虑P中新的需要匹配的位置
                // ......xxaabP....
                // aabm..xxaabQ...
                //         aabm........
                /// 此时P,Q出现不匹配, 找到Q前面的b, 根据前后缀的关系, 只需从m位置开始比较即可, 即 offsets[j-1]
                int Offset = offsets[j-1];
                j = Offset;
            } 
        }
        return -1;
    }

    vector<int> calckmp(string needle){
        std::vector<int> v(needle.size());
        v[0] = 0;
        int i = 0, j=1;
        while(j<needle.size()){
            if(needle[i] == needle[j]){
                // v[j] = v[j-1]+1; // error: 想当然了， 和前一个字符的最长前后缀是没有关系的。
                v[j] = i+1;
                j++;
                i++;
            }
            else if(i==0){
                v[j]=0;
                j++;
            }else{ // i!=0;
                i = v[i-1];
            }
        }
        return v;
    }
    
};