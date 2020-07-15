

先检查行， 列， 分块。

优化的点。 行,列, 分块的检查都可以合并

bool isValidSudoku(vector<vector<char>>& board) {
    map<char, bool> Signs;

    for (int i = 0; i < 9; ++i)
    {
        Signs.clear();
        for (int j = 0; j < 9; ++j)
        {
            char t = board[i][j];
            if(t == '.') continue;
            if(Signs.find(t)!=Signs.end()){
                return false;
            }
            Signs[t] = true;
        }

        Signs.clear();
        for (int j = 0; j < 9; ++j)
        {
            char t = board[j][i];
            if(t == '.') continue;
            if(Signs.find(t)!=Signs.end()){
                return false;
            }
            Signs[t] = true;
        }

        int a = (i/3) * 3;
        int b = (i % 3) * 3;
        Signs.clear();

        for (int k = a; k < a + 3; ++k)
        {
            for (int j = b; j < b + 3; ++j)
            {
                char t = board[k][j];
                if(t == '.') continue;
                if(Signs.find(t)!=Signs.end()){
                    return false;
                }
                Signs[t] = true;
            }
        }
    }

    return true;
        
}