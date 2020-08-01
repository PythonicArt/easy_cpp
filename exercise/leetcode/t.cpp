



取两个下标 i, j ， 开始匹配

s[i] == p[j] || p[j] == '.'
    i++;
    pre = p[j++];
p[j] == '*'
    if(pre == '.')
        pass
    else if(isal(pre))
        int k = j+1;
        while(p[k] == pre && p[i] == pre) {k++;i++;}
        if(p[k] == pre) return false;
        if(p[k] != p[i]) return false;
    else
        return false;

想法超时


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }

        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }

        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }

        return isMatch(s, p.substr(2));
    }
};
