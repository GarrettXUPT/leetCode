#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int strSize = s.length();
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
                    stateMatrix[i][j] = ((s[i] == s[j]) && stateMatrix[i + 1][j - 1]);
                }
                if (stateMatrix[i][j] && len + 1 > res.size()) {
                    res = s.substr(i, len + 1);
                }
            }
        }
        return res;
    }
};