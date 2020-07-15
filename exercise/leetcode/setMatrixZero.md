

选一行和一列做缓存， 当某行或列 出现0, 则对应的缓存行或列的位置置0
检查缓存行或列， 将对应的行列全部置0
需要先判断首行和首列是否存在0

效率低的问题: 没有完全按照预定的计划实现, 特别是 条件判断语句和前后对应的关系。 容易写错。 在原有代码上修改, 容易保留原来的逻辑。没有根据新的想法重新调整代码。

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