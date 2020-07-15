


对于每一个位置高度为 h， 求得左边界柱子高度 a , 右边界柱子高度 b

该位置能够蓄水  min(a, b) - h

对于边界的界定
左边界： 左边所有大于自己的柱子的最高值
右边界： 右边所有大于自己的柱子的最高值

left[i] = max(h[i-1], left[i-1])
right[i] = max(h[i+1], right[i+1])

int trap(vector<int>& height) {
    int size = height.size();

    std::vector<int> left(size);
    std::vector<int> right(size);

    for (int i = 1; i < size; ++i)
    {
        left[i] = max(left[i-1], height[i-1]);
        int j = size - 1 - i;
        right[j] = max(right[j+1], height[j+1]);
    }

    int sum = 0;
    for (int i = 1; i < size-1; ++i)
    {
        int devotion = min(left[i], right[i]) - height[i];
        sum += max(0, devotion);
    }

    return sum;

}



找到最高的柱子， 这个柱子将数组分成两边，
对于左边，只要有左边界， 就一定能蓄水。 右边同理。 具体看代码。

int trap(vector<int>& height) {
    int size = height.size();

    if(size == 0) retrun 0;

    int max = 0;
    for (int i = 1; i < size; ++i)
    {
        if(height[i] > height[max])  max = i;
    }

    int sum = 0;
    for (int i = 0, left = 0; i < max; ++i)
    {
        if(height[i] > left) left = height[i];
        else{
            sum += left - height[i];
        }
    }
    for (int i = size - 1, right = 0; i > max; --i)
    {
        if(height[i] > right) right = height[i];
        else{
            sum += right - height[i];
        }
    }

    return sum;

}

使用辅助栈, 主要的思想是按层计算蓄水值。

当前元素 i, 高度 height(i)
当前元素小于栈顶， 则进栈， 等待计算。
使用一个变量 h 计算 累积的层高。 对于h的计算,

当前元素大于栈顶， 逐一弹出栈顶， 直到当前元素小于或等于栈顶。
    每弹出一个元素(height[j], j)， 则计算该栈顶与当前元素组成的凹槽的蓄水值。
    water = (min(height[i], height[j]) - h) * (j - i - 1)

    这里实际上计算的一个区间内的某一层， 而且是从下往上计算。
    每计算一层， 栈顶会留下该层的右边界，其高度为h， 下一轮计算的时候， 由于h以下的都已经计算过， 所以上面的公式要去掉h



int trap(vector<int>& height) {
    int size = height.size();

    if(size == 0) retrun 0;

    stack<pair<int, int>> s;


    for (int i = 0; i < size; ++i)
    {
        int h = 0;

        while(!s.empty()){
            int leftHeght = s.pop().first;
            int j = s.pop().second;

            sum += (min(leftHeght, height[i]) - h) * (i-pos-1);
            h = leftHeght;

            if(height[i] < leftHeght){
                break;
            }
            else{
                s.pop();
            }

        }

        s.push(make_pair(height[i], i));
    }

    return sum;

}


三维的情况。
按照第一种解法， 再考虑竖向一个维度

int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    if(m == 0) return 0;
    vector<vector<int>> waterMap(m);
    for(int i = 0; i<m; i++){
        waterMap[i] = trap(heightMap[i]);
    }

    int n = (heightMap[0]).size();

    int sum = 0;
    for (int col = 0; col < n; ++col)
    {
        std::vector<int> tmp(m);
        for (int row = 0; row < m; ++row)
        {
            tmp[row] = heightMap[row][col];
        }

        std::vector<int> tmpResult = trap(tmp);
        for (int row = 0; row < m; ++row)
        {
            int water = min(waterMap[row][col], tmpResult[row]);
            sum += water;
        }

    }

    return sum;

}


vector<int> trap(vector<int>& height) {
    int size = height.size();
    std::vector<int> result(size);
    if(size == 0) return result;

    std::vector<int> left(size);
    std::vector<int> right(size);


    for (int i = 1; i < size; ++i)
    {
        left[i] = max(left[i-1], height[i-1]);
        int j = size - 1 - i;
        right[j] = max(right[j+1], height[j+1]);
    }


    for (int i = 1; i < size-1; ++i)
    {
        int devotion = min(left[i], right[i]) - height[i];
        result[i] = max(0, devotion);
    }

    return result;

}
