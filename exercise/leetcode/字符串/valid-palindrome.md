

palindrome  emmmmmmmm， 不说连题目的看不懂。

回文串检查， 只考虑数字和字母， 其他忽略

第一版， 主要熟悉字符串的操作。
遍历
转换大小写
判断是否是 数字-字母


class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), tolower);
        auto left = s.begin(), right = s.end()-1;

        while(left < right){
            if(!isalnum(*left)){
                left++;
            }else if(!isalnum(*right)){
                right--;
            }else if(*left!=*right){
                return false
            }else{
                left++;
                right--;
            }
        }
        return true;
    }
};

最多去掉一个字符， 判断是否是回文。
暴力解应该不是期望的答案， 还是用两个指针， left, right

如果没有出现不相同的， 则是回文

当遇到第一个不相同的， 记录当前left, right的位置。分别跳过其中一个进行判断。 如果跳过其中一个还是回文则得解。否则不能成为回文。


class Solution {
public:
    bool validPalindrome(string s) {
        auto left = s.begin(), right = s.end()-1;

        if(validPalindromeWithIterator(left, right)){
            return true;
        }

        auto p = left, q=right;

        if(validPalindromeWithIterator(++left, right)){
            return true;
        }

        return validPalindromeWithIterator(p, --q);

    }

    bool validPalindromeWithIterator(string::iterator &left, string::iterator &right){ // error0：auto类型不能作为函数参数
        while(left < right){
             if(*left!=*right){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;
    }
};