

括号匹配， 老问题了。

遇到左边的字符就入栈， 

遇到右边的字符就弹出栈顶， 
    此时如果栈为空或是不匹配， 则不匹配。否则继续。


最后如果栈为空则匹配， 否则不匹配


class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }else{
                if(st.empty() || !match(st.top(), c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }

    bool match(char c1, char c2){
        switch(c1){
            case '{':
                return c2 == '}';
            case '[':
                return c2 == ']';
            case '(':
                return c2 == ')';
            default:
                return false;
        }
        return false;
    }

};