#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 最长回文串
    string longestPalindrome(string s) {
        int strSize = s.length();
        // 状态动态规划
        vector<vector<int>>  stateMatrix(strSize, vector<int>(strSize));
        string res;
        for (int len = 0; len < strSize; ++len) {
            for (int i = 0; i + len < strSize; ++i) {
                int j = i + len;
                if (len == 0) {
                    stateMatrix[i][j] = 1;
                }
                else if (len == 1) {
                    stateMatrix[i][j] = (s[i] == s[j]);
                }
                else {
                    stateMatrix[i][j] = ((s[i] == s[j]) && stateMatrix[i + 1][j - 1]);  // 若s[i + 1][j - 1]是回文串且两端字符相同才是回文
                }
                // 若是出现了更长的回文
                if (stateMatrix[i][j] && len + 1 > res.size()) {
                    res = s.substr(i, len + 1);
                }
            }
        }
        return res;
    }
};