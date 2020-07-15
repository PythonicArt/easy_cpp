

两次调整模拟 顺时针旋转

先沿着副对角线翻转一次， 再沿着水平中线翻转一次. 反之亦可

考虑副对角线 左一侧的 元素， 
    i: 0->n-2; j: 0->n-i-2
    
    对于副对角线上的元素： 
        i + j = n-1;

    其对称的位置  
        row: 与当前点同一列的对角线上的点 同一行
            a = n-1-j;
        col: j +  当前点与同列对角线上的点的竖向距离, 即横坐标的差值。
            b = j + (a - i) = j + (n - 1 - j - i) = n - 1 - i;

考虑水平中线 上半部分元素
    i: 0->(n/2); j: 0->n-1

    其对称的位置
        row = n-1-i;
        col = j;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if( n<= 1) return 0;

    for (int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j < n-1-i; ++j)
        {
            int a = n-1-j;
            int b = n-1-i;
            swap(matrix[i][j], matrix[a][b]);
        }
    }

    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a = n-1-i;
            int b = j;
            swap(matrix[i][j], matrix[a][b]);
        }
    }
}



关于矩阵对称的一些坐标转换


关于副对角线对称
i: 0->n-2; j: 0->n-i-2
a[i][j] => a[n-j-1][n-i-1]


主对角线对称, 行列互换
i: 0-> n-1, j: 0->i
a[i][j] => a[j][i]

水平中心线
i: 0->n/2; j: 0<n
a[i][j] => a[n-1-i][j]


竖直中心线
i: 0->n; j: 0<n/2
a[i][j] => a[i][n-1-j]