#include<iostream>
#include<vector>

using namespace std;

/*
    һ��������λ��m x n�������Ͻ�
    �����ˣ�ÿ��ֻ�����»��������ƶ�һ������������ͼ�������½�
    ���ܹ��ж�������ͬ��·��

    ��̬�滮
*/

int uniquePaths(int m, int n) {
    //��̬����һ����ά·���𰸱�
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {     //����һ�л�������һ��
                dp[i][j] = 1;
            }
            else {
                // ���һ��������¶����Ե���Ŀ���
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}

