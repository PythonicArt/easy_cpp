


又是一道阅读理解题。 代码没学好， 英语学好了。

输入一个数i 需要找到第i个表达序列

第一个表达序列是 1

从第二个开始， 每个表达序列都是前一个的读法。 

i=1 => 1 初始值

i=2 =>  1 的读法  即 one 1 => 11
i=3 => 11 的读法 即  two 1s => 21
i=4 => 21 的读法 即  one 2 one 1 => 1211
....

i 在范围 {1, 30} 中


从1->n 一个个计算。

把连续出现的字符进行分组， 最后的结果就是

num Char num Char ... num Char

class Solution {
public:
    string countAndSay(int n) {

        string result = "1";

        for (int i = 2; i <= n; ++i)
        {
            string tmp;
            char c = result[0];
            for (int j = 0; j < result.size();)
            {
                int count = 0;
                while(j<result.size() && result[j] == c) {count++;j++;};

                tmp += std::to_string(count);
                tmp += c;

                if(j<result.size()){
                    c = result[j];
                }
            }
            result = tmp;
        }

        return result;
        
    }
};


40分钟， 一次过， 爽歪歪。
还有一种利用stl的解法， 这样就很c++了。



