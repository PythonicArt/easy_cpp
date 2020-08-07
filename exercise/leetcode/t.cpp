Given n non-negative integers representing the histogram''s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.




1. 暴力解法
    每个元素从两边扩展，计算.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(n<1) return 0;

        int result = 0;
 
        for (int i = 0; i < n; ++i)
        {
            int tmp = heights[i];
            
            int j = i-1;
            while(j>=0 && heights[j--]>=heights[i]) tmp+= heights[i];

            j = i+1;
            while(j<n && heights[j++]>=heights[i]) tmp+= heights[i];

            result = max(result, tmp);
        }

        return result;
    }
};


不出意外超时了， 有一个测试用例竟然是 6万个1..


优化的方向， 减少每个位置向左右两边扩展的次数。
由于矩形连续的特点， 最大的面积一定是某个区间内的最大矩形面积， 

M[i][j] 为 区间[i:j] 的面积， 逐一求获得最大值即可。 妥妥的动态规划。

面积 = minHeight * (j-i+1) , 存储 minHeight 即可。故

M[i][j] => 
    heights[i], i==j;

    min(heights[i], heights[j]), i+1 == j;

    min(min(heights[i], heights[j), M[i+1][j-1]), other

每计算一个 m[i][j], 面积也就得到计算。 


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int **M;
        int result = 0;
        int n = heights.size();
        if(n < 1) return 0;
        if(n == 1) return heights[0];

        M=new int *[n];
        for(int i=0;i<n;i++){
            M[i]=new int[n];
            for (int j = 0; j < n; ++j)
            {
                if(i == j){
                    M[i][j] = heights[i];
                    result = max(result, heights[i]);
                }else{
                    M[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                int tmp = min(heights[i], heights[j]);
                if(i+1 == j){
                    M[i][j] = tmp;
                }else{
                    M[i][j] = min(tmp, M[i+1][j-1]);
                }

                int area = M[i][j] * (j-i+1);
                result = max(result, area);
            }
        }
        return result;
    }
};


还是会超时， 平方级别的复杂度应该都会超时。