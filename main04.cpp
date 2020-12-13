#include<iostream>
#include<vector>

using namespace std;
/*
    ��ͬ·������:��̬�滮����

*/
int uniquePaths(int m, int n) {
    //��̬����һ����ά·���𰸱�
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {     //����һ�л�������һ�У�ֻ��һ������Ŀ���
                dp[i][j] = 1;
            }
            else {  // һ��λ�ã���һ������һ��
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][m - 1];
}

