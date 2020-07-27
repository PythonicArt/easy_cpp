
两个 表示二进制数的 字符串地相加

从右往左遍历。i, j 分别指向两个字符串的位置。

去一个进位数值, 
结果为 result  从左到右存储， 最后将字符串反转一遍

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size()-1, j = b.size() -1;
        int inc = 0;
        while(i>=0 || j>=0){
            int left = i>=0?a[i] - '0':0;
            int right = j>=0?b[j] - '0':0;
            int sum = (left + right + inc)%2;
            inc = (left + right + inc)/2;
            result += ('0' + sum);
            i--; // error： 第一次没有修改i, j，死循环了
            j--;
        }
        if(inc > 0) result += ('0' + inc);
        reverse(result.begin(), result.end());
        return result;
    }
    
};


c++ 实现了 += 运算符重载， 右侧操作数可以为 c-string, string, char 类型， 相当于 string.append(Str)

但是无法使用 result = result + char, 字符串与字符类型相加， 会编译报错。

string.insert, 在此题中也可以解。 insert append效率是相同的

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size()-1, j = b.size() -1;
        int inc = 0;
        while(i>=0 || j>=0){
            int left = i>=0?a[i] - '0':0;
            int right = j>=0?b[j] - '0':0;
            int sum = (left + right + inc)%2;
            inc = (left + right + inc)/2;
            result.insert(result.begin(), '0' + sum);
            i--; // error： 第一次没有修改i, j，死循环了
            j--;
        }
        if(inc > 0) result.insert(result.begin(), '0' + inc);
        // reverse(result.begin(), result.end());
        return result;
    }
    
};