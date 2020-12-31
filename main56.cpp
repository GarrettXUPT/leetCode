
#include<iostream>
#include<vector>

using namespace std;

/*
    最短路径和
*/
int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    int rows = grid.size(), columns = grid[0].size();
    auto dp = vector <vector <int>>(rows, vector<int>(columns));
    dp[0][0] = grid[0][0];
    // 从左向右
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // 从上到下
    for (int j = 1; j < columns; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
        
    // 中间的格子，可以从左到达，也可以从上到达
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[rows - 1][columns - 1];
}


