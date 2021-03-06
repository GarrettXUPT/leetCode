#include<iostream>
#include<vector>

using namespace std;

// 此为利用滚动数组思想优化过的
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
    vector <int> vec(m);

    vec[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[i][j] == 1) {
                vec[j] = 0;
                continue;
            }
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                vec[j] += vec[j - 1];
            }
        }
    }

    return vec.back();
}

/*
    此时网格中有障碍物，实用动态规划
*/
int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
    if (obstacleGrid.size() == 0) {
        return 0;
    }
    // 定义 dp 数组并初始化第 1 行和第 1 列。
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化边界条件，将最左和最上初始化为1，但是初始化为1的是无障碍的点
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
        dp[0][j] = 1;
    }

    // 根据状态转移方程 dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 进行递推。
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}


int main(int argc, char const* argv[])
{   
    vector<int> vec;
    
    cout << isalpha('a') << endl;
    cout << isdigit('1') << endl;
    return 0;
}


 