Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        int n = strs.size(); if(n<=0) return result;

        if(n==1) return strs[0];

        for (int i = 0; ; ++i)
        {
            char c = '_';
            for(auto s:strs){
                if(i>=s.size()) return result;
                if(c=='_'){
                    c=s[i];
                }else{
                    if(s[i]!=c) return result;
                }
            }
            result +=c;
        }

        return result;

    }
};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";

       for(int idx = 0; idx < strs[0].size(); ++idx) {
           for (int i = 0; i < strs.size(); ++i)
           {
               if(strs[i][idx]!=strs[0][idx])
                    return strs[0].substr(0, idx);
           }
       }
       return strs[0];
    }
};

第二个版本时间减少了 60%,  大概 字符串的拼接是很耗时的方式


从第二串开始找每个串和第一个串的最长匹配前缀的长度, 取最小值

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";

       int maxLen = strs[0].size();
       for (int i = 1; i < strs.size(); ++i)
       {
            int t = 0;
            while(t<maxLen && strs[i][t] == strs[0][t]) t++;
            if(t < maxLen) maxLen = t;
       }
       
       return strs[0].substr(0, maxLen);
    }
};