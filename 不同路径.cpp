#include<iostream>
#include<vector>

using namespace std;

/*
    一个机器人位于m x n网格左上角
    机器人，每次只能向下或者向右移动一步，机器人试图到达右下角
    问总共有多少条不同的路径

    动态规划
*/

int uniquePaths(int m, int n) {
    //动态创建一个二维路径答案表
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {     //最上一行或者最左一列
                dp[i][j] = 1;
            }
            else {
                // 向右或者是向下都可以到达目标点
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}

