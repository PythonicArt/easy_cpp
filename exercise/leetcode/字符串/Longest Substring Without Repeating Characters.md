20210602 好久没有写代码了， 连数组都不会用了。 

Given a string s, find the length of the longest substring without repeating characters.

题目比较简单

从后往前的解法

使用一个辅助的数组 a, 记录该位置字符开始的最长的无重复子串长度。a[len-1] = 1 
用从右往左的方式遍历，int i = len - 2,  假设当前遍历到 i, 则从i+1开始, 从左右往依次检查， 由于前一轮已经计算得到 a[i+1], 这个数字表示以i+1开始的字符，的最长无重复重复的子串的长度， 所以一轮检查的右边界就是 last = i+a[i+1]  

提交的时候没有注意 边界检查。 注意长度为0和1的情况


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    	int len = s.length();
        if (len == 0 ) return 0;
        if (len == 1) return 1;
    	int max = 0;
    	int *a = new int[len];
    	a[len-1]=1;
    	for (int i = len-2; i >=0; --i)
    	{
    		int t = 1;
    		for (int j = i+1; j <= i+a[i+1]; ++j)
    		{
    			if (s[i]==s[j]) break;
    			t++;
    		}
    		a[i]=t;
    		max = t>max?t:max; 
    	}
    	return max;
    }
};

从前往后 滑动窗口的解法

维护一个窗口， 记录当面扫描到的无重复字符的子串

i = 0->n-1, 从左到右扫描
left 为窗口的左边界-1， left = -1

res 为累计的最长长度。

使用一个map , 记录当前字符s[i]上一次出现的位置。 如果上次已经出现而且在窗口内， 则窗口需要调整为 map[s[i]]

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
    int ans=0, left=-1;
    unordered_map<int, int> m;

    for (int i = 0; i < s.size(); ++i)
    {
        if(m.count(s[i])>0&&m[s[i]]>left){
            left = m[s[i]];
        }
        m[s[i]]=i;
        ans = max(ans, i-left);
    }
    	return ans;
    }
};