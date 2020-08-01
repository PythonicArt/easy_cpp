
字符串转数字

先判断是否能够转换

允许开头出现多个 空格字符
除去空白字符之后，第一个字符必须是 +，-，数字。否则不能转换， 返回0

第一个字符满足条件之后， 往后找所有数字。 当出现数字以外的字符，中断检索过程. 转换已经检索到的字符串。

只转换32位整数范围内的字符串， 超过的取上下限边界

class Solution {
public:
    int myAtoi(string str) {
        // 去除头部多个空格， 出现其他非数字类字符， 则返回0
        int n = str.size();
        if(n <= 0) return 0;

        string acc;
        for(int i = 0; i<n ; i++){
            if(str[i] == ' ' && acc.empty()){
                continue;
            } 
            else if(str[i] == '+' || str[i] == '-'){
                if(acc.empty()){
                    acc += str[i];
                    continue;
                }else{
                    break; //error: 这里最先返回的是 reurun 0; 为什么要返回呢？
                }
            }
            else if(isdigit(str[i])){
                acc+=str[i];
            }
            else{
                break;
            }
        }

        if(acc.empty()) return 0;

        char sign = acc[0];
        if(!isdigit(sign)&&acc.size()==1) return 0; // 只有一个符号位，返回0

        if(isdigit(sign)){
            sign = '+';
            acc = sign + acc;
        }

        // 关于数值的转换， 从右往左用乘方容易出现很大的值, 而且不好判断是否越界
        // 参考一种方式，从左到右， 每次获得一个数字， 放大10倍加上当前的值。        
        int result = 0;
        for (int i = 1; i < acc.size(); ++i)
        {
            int v = acc[i] - '0';
            // 注意越界的判断
            if(result > INT_MAX / 10 || ( result == INT_MAX / 10 && v > INT_MAX % 10)){
                return sign == '-'?INT_MIN:INT_MAX;
            }
            result = result * 10 + v;
        }
        if(sign=='-') result*=-1;
        return result;
        
    }
};


class Solution {
public:
    int myAtoi(string str) {
        // 去除头部多个空格， 出现其他非数字类字符， 则返回0
        int n = str.size();
        if(n <= 0) return 0;

        string acc;
        int sign = 0;
        for(int i = 0; i<n ; i++){
            if(acc.empty() && sign == 0){ // 这里需要判断符号位是否置位
                if(str[i]== ' '){
                    continue;
                }
                else if(str[i] == '+'){
                    sign = 1;
                    continue;
                }
                else if(str[i] == '-'){
                    sign = -1;
                }
                else if(isdigit(str[i])){
                    sign =1;
                    acc+=str[i];
                }
                else
                    break;
            } 
            else{
                if(isdigit(str[i])){
                    acc+=str[i];
                }
                else{
                    break;
                } 
            }   
        }

        if(acc.empty()) return 0;
        
        // 关于数值的转换， 从右往左用乘方容易出现很大的值。 
        // 参考一种方式，从左到右， 每次获得一个数字， 放大10倍加上当前的值。        
        int result = 0;
        for (int i = 0; i < acc.size(); ++i)
        {
            int v = acc[i] - '0';
            // 注意越界的判断
            if(result > INT_MAX / 10 || ( result == INT_MAX / 10 && v > INT_MAX % 10)){
                return sign < 0?INT_MIN:INT_MAX;
            }
            result = result * 10 + v;
        }

        result *= sign;
        return result;

    }
};