

构建一个 字符串与 数值 的map ， 包含所有单字符和双字符

每次取两个字符， 不够长的就去取一个字符。 
优先取 带个字符组成的字符串查询数值， 如果查到， 则加上sum, 
否则取单字符的值。



class Solution {
public:
    int romanToInt(string s) {

        typedef std::unordered_map<std::string, int> stringmap;

        stringmap M({{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, 
                     {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
                    {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4},
                    {"I", 1}});

        int result = 0;

        for (int i = 0; i < s.size();)
        {
            string single = s.substr(i, 1);
            string doub = i == s.size() - 1 ? single:s.substr(i, 2); 

            if(M.find(doub)!=M.end()){
                result+=M[doub];
                i+=2;
            }else{
                result+=M[single];
                i++;
            }
        }

        return result;
        
    }
};

这个解法很慢， 原因是用了很多 substr


class Solution {
public:
    int romanToInt(string s) {

        typedef std::unordered_map<char, int> stringmap;

        stringmap m({{'M', 1000},  {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10},  {'V', 5}, {'I', 1}});

        int res = 0;

        for (int i = 0; i < s.size();i++)
        {
            if (i == 0 || m[s[i]] <= m[s[i - 1]]) res += m[s[i]];
            else res += m[s[i]] - 2 * m[s[i - 1]];
        }

        return res;
        
    }
};


这个解法有提升， 关键是有抓住规律才能写出答案。


class Solution {
public:
    inline int m(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:return 0;
        }
    }

    int romanToInt(string s) {

        // typedef std::unordered_map<char, int> stringmap;
        // stringmap m({{'M', 1000},  {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10},  {'V', 5}, {'I', 1}});

        int res = 0;

        for (int i = 0; i < s.size();i++)
        {
            if (i == 0 || m(s[i]) <= m(s[i - 1])) res += m(s[i]);
            else res += m(s[i]) - 2 * m(s[i - 1]);
        }

        return res;
        
    }
};


把 map改成  case 语句， 真香。 超过全球 98%的C++用户。
