#include<iostream>
#include<vector>

using namespace std;
/*
    不同路径问题:动态规划问题

*/
int uniquePaths(int m, int n) {
    //动态创建一个二维路径答案表
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {     //最上一行或者最左一列，只有一个方向到目标点
                dp[i][j] = 1;
            }
            else {  // 一般位置，右一步或下一步
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][m - 1];
}

