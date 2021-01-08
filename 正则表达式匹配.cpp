#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 动态规划

bool isMatch(string s, string p) {
    int sLen = s.length();
    int pLen = p.length();
    vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1));
    for (int i = 0; i <= sLen; ++i) {
        for (int j = 0; j <= pLen; ++j) {
            // 分为正则表达为空和非空两种情况
            if (j == 0) {
                dp[i][j] = i == 0;  // 边界条件
            }
            else
            {
                if (p[j - 1] != '*') {
                    if (i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else  // 若存在'*',分为考虑及不考虑两种情况
                {
                    if (j >= 2) {  // 不考虑
                        dp[i][j] = dp[i][j] | dp[i][j - 2];
                    }                    
                    if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }                    
                }
            }
        }
    }
    return dp[sLen][pLen];
}