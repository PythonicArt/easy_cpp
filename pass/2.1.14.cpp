#include <iostream>
#include <vector>

using namespace std;

bool check(char c, bool used[9]){
    if (c == '.') {
        return true;
    }
    if (used[c - '1'] == true) {
        return false;
    }
    else{
        used[c - '1'] = true;
        return true;
    }
}

bool fun(std::vector<std::vector<char> > board) {
    bool used[9];
    for (size_t i = 0; i < 9; i++) {
        fill(used, used + 9, false);
        // 检查第i行
        for (size_t j = 0; j < 9; j++) {
            if (check(board[i][j], used) == false) {
                return false;
            }
        }
        fill(used, used + 9, false);
        // 检查第i列
        for (size_t j = 0; j < 9; j++) {
            if (check(board[j][i], used) == false) {
                return false;
            }
        }
        fill(used, used + 9, false);
        // 检查第i个格子
        size_t lhead = i/3 * 3;
        size_t rhead = i%3 * 3;
        for (size_t j = lhead; j < lhead + 3; j++) {
            for (size_t k = rhead; k < rhead + 3; k++) {
                if (check(board[j][k], used) == false) {
                    return false;
                }
            }
        }
    }
    return true;
}
