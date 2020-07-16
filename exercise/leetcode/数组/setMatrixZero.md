

选一行和一列做缓存， 当某行或列 出现0, 则对应的缓存行或列的位置置0
检查缓存行或列， 将对应的行列全部置0
需要先判断首行和首列是否存在0

效率低的问题:
    还没有设计好方案， 没有评估可行性就上手。
    **细节有纰漏**, 没有完全按照预定的计划实现,
    **特别是 条件判断语句和前后对应的关系。 非常容易写错**。
    在原有代码上修改, 特别是复制过来的代码, 容易保留原来的逻辑。没有根据新的想法重新调整代码。

重视代码的审查, 减少
    知道思路写完第一版， 只完成了一半
    检查方案的正确性, 完备性
    检查是否按照方案实现, 重点查找的对象
        赋值语句
        条件判断语句逻辑是否正确
        循环的起始点与终结点
    检查, 探索边界条件

每一次修改都要重新按步骤重新检查一遍

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(m == 0) return;
    int n = (matrix[0]).size();

    int row_has_zero=false, col_has_zero=false;

    for (int i = 0; i < m; ++i)
    {
        if(matrix[i][0] == 0 ){
            col_has_zero = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if(matrix[0][i] == 0 ){
            row_has_zero = true;
        }
    }

    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {

            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i)
    {
        if(matrix[i][0] == 0){
            for (int j = 1; j < n; ++j)
            {
                matrix[i][j] =0;
            }
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if(matrix[0][i] == 0){
            for (int j = 1; j < m; ++j)
            {
                matrix[j][i] = 0;
            }
        }
    }

    if(row_has_zero){
        for (int i = 0; i < n; ++i)
        {
            matrix[0][i] = 0;
        }
    }

    if(col_has_zero){
        for (int i = 0; i < m; ++i)
        {
            matrix[i][0] = 0;
        }
    }

}
