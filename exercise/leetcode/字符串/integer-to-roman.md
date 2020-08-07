Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two ones added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.


致命的错误不能再犯了， 没完全理解题目就开始做了，浪费了很多时间， 真亏。

class Solution {
public:
    string intToRoman(int num) {
        int n[] = {1000, 500, 100, 50, 10, 5, 1};
        char c[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        string result;

        int left = num;

        for (int i = 0; left > 0 && i < 7; i+=2)
        {   
            int rem = left % n[i];
            int count = left / n[i];

            if(count == 9){
                result += c[i];
                result += c[i-2];  // error1:  不能写成 result += c[i] + c[i-2]
            } 
            else if(count >= 5){
                result += c[i-1];
                count -= 5;
                while(count-- > 0)
                    result += c[i];
            }
            else if(count == 4) {
                result += c[i];
                result += c[i-1];
            }
            else
                 while(count-- > 0) 
                    result += c[i];

            left = rem;
        }

        return result;
        
    }
};
