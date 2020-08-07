

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.


找到子串中满足括号匹配的 最长子串的长度。有点类似找最长的回文子串。 

1. 用栈。
    和普通的判断匹配的方法唯一的区别是 要记录长度。 
    
    申请一个栈， 记录( 出现时的下标。

    当出现匹配时， 可以更新长度。 
        出现匹配时， 弹出栈顶元素后
        栈为空
            len = i - start; // 用上次记录的开始位置计算长度
        栈不为空
            len = i - st.top(); // 用栈顶元素计算长度， 因为栈顶元素在start的右边。

    不匹配时
        更新 start = i;


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n<2) return 0;

        stack<int> st;
        int start = -1;
        int len = 0;

        for (int i = 0; i < n; ++i)
        {
            if(s[i] == '('){
                st.push(i); // 左侧字符， 压入其下标
            }else{
                if (st.empty()) // 在当前位置不匹配，更新start
                {
                    start = i;
                }else{ // 匹配的情况, 弹出栈顶， 判断更新长度 
                    st.pop();
                    // 考虑多段连续匹配的情况 ()(...)() 
                    if(st.empty()){
                        len = max(len, i - start); // 栈为空，以start为准 
                    }else{
                        len = max(len, i - st.top()); // 栈不为空， 以st.top()为准
                    }
                }
            }
        }
        
        return len;
    }
};




2. 动态规划(超时)
    M[i][j] 表示是否满足条件

        true, match(s, i, j) && ( j == i+1 || validParentheses(s, i, j))
        false, other

class Solution {
public:
    int longestValidParentheses(string s) {
        bool **M;
        int maxLen = 0;
        int n = s.size();
        if(n < 2) return 0;

        M=new bool *[n];
        for(int i=0;i<n;i++){
            M[i]=new bool[n];
            for (int j = 0; j < n; ++j)
            {
                M[i][j] = false;
            }
        }

        for (int j = 1; j < n; ++j)
        {
            M[j][j] = false;
            for (int i = 0; i < j; ++i)
            {
                if(s[i] == '(' && s[j] == ')'){
                    if(j==i+1){
                        M[i][j] = true;
                    }else{
                        stack<char> st;
                        int a;
                        for (a = i; a <=j; ++a)
                        {
                            char c = s[a];
                            if(c == '('){
                                st.push(c);
                            }else{
                                if(st.empty() || st.top()!='('){
                                    break;
                                }
                                st.pop();
                            }
                        }
                        M[i][j] = a>j && st.empty();
                    }
                }else{
                    M[i][j] = false;
                }

                if(M[i][j] && j-i+1 > maxLen){
                    maxLen = j-i+1;
                }
            }
        }

        return maxLen;
    }
};

每次遇到一个新的满足条件的区间， 更新最大值。 
这里忽略了一个问题， 就是 连续两个匹配的区间合一起匹配的情况。 

3. 动态规划(ac)
    用一个数组 记录 位置i能够匹配的长度
    i    m
    ((..))

    求f[i]时， 先找到最右要匹配的值 m = i + f[i+1] + 1 , 即 i+1能够匹配的长度的下一个位置。

    找到m ， 判断 s[i], s[m] 是否匹配。 
        如果匹配， 则 i:m 都是匹配的。 
            f[i] = f[i+1] + 2;
        此时再考虑 m以后的位置的匹配，两个连续匹配合起来也是匹配的，形如 (....)()， 
            f[i] = f[i] + f[m+1];

    判断是否超过当前最大值并更新

    可以看到， 前面的需要依赖后面的，所以 从后往前遍历


class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.size();
        if(n<2) return 0;
        std::vector<int> f(n, 0);
        int result = 0;

        for (int i = n-2; i >= 0; --i)
        {
            int match_i = i + f[i+1] + 1;
            if(s[i] == '(' && s[match_i] == ')'){
                f[i] = f[i+1] + 2;
                if(match_i + 1 < n){
                    f[i] += f[match_i+1];
                }
                result = max(result, f[i]);
            }
        }

        return result;
    }
};




