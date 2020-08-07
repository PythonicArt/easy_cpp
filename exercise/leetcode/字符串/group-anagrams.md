

Given an array of strings, group anagrams together.

anagram /ˈænəˌɡræm/ |TEM8
N-COUNT An anagram is a word or phrase formed by changing the order of the letters in another word or phrase. For example, "triangle" is an anagram of "integral." 变位词; 由变换某个词或短语的字母顺序而构成的新的词或短语。例如，"triangle"是"integral"的变位词。


有相同字符集 组成的分成一组， 最后返回结果。 

用一个map key是字符集串， value 是其数组。

key 的算法 将 字符串排序

遍历strs， 得到map

再取所有的 values;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        typedef std::unordered_map<string, std::vector<string>> stringmap;
        stringmap M;

        for (auto s:strs)
        {
            string key(s);
            sort(key.begin(), key.end());
            M[key].push_back(s);
        }

        std::vector<std::vector<string>> result;

        for (auto it = M.begin(); it != M.end() ; ++it)
        {
            result.push_back(it->second);
        }

        return result;
    }
};