
计算 后序算术表达式


遇到数字字符就进栈,  遇到操作符就出栈数字字符。


class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> nums;

        for(string c:tokens){
            if(is_digits(c)){
                nums.push(std::stoi(c));
            }else{
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                int s;
                if(c == "+"){
                    s = a + b;
                }else if(c == "-"){
                    s = a - b;
                }else if(c == "*"){
                    s = a * b;
                }else if(c == "/"){
                    s = a / b;
                }
                nums.push(s);
            }
        }
        return nums.top();
        
    }
    
    
    bool is_digits(const std::string &str)
    {
        return str != "+" && str != "-" && str != "*" && str != "/";
        // return std::all_of(str.begin(), str.end(), ::isdigit); // 注意， 不能这么写， isdigit只是判断字符串是否全部是数字字符。
        // 
        // Check if character is decimal digit
        // Checks whether c is a decimal digit character.
        // Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9
    }
};


递归的解法

后缀表达式的规律, num1 num2 op

num 可能是一个数字也可能是 一个后缀表达式。 也就形成了递归的条件。 

从后往前进行计算， 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size() - 1;
        return subEval(tokens, n);
    }

    int subEval(vector<string>& tokens, int& idx){
        string str = tokens[idx];
        if(is_digits(str)) return stoi(str);

        int b = subEval(tokens, --idx);
        int a = subEval(tokens, --idx);
        int s;

        if(str == "+"){
            s = a + b;
        }else if(str == "-"){
            s = a - b;
        }else if(str == "*"){
            s = a * b;
        }else if(str == "/"){
            s = a / b;
        }

        return s;
    }


    bool is_digits(const std::string &str)
    {
        return str != "+" && str != "-" && str != "*" && str != "/";
    }

};