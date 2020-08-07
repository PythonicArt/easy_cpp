

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5


字符串题目做多了， 麻木了。 看上去就想遍历。 


对测试用例的分析

1. 以空格结尾
2. 以单词结尾

class Solution {
public:
    int lengthOfLastWord(string s) {

        int len=0;

        for (int i = 0; i < s.size();)
        {
            len = 0;
            while(i<s.size() && s[i] != ' ') {len++;i++;}
            while(i<s.size() && s[i] == ' ') {i++;}
        }
        
        return len;
    }
};