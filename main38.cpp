#include<iostream>
#include<vector>

using namespace std;

/*
    交叉字符串
*/


bool isInterleave(string s1, string s2, string s3) {
    auto vecTable = vector<vector <int>>(s1.size() + 1, vector<int>(s2.size() + 1, false));

    int n = s1.size(), m = s2.size(), t = s3.size();

    if (n + m != t) {
        return false;
    }

    vecTable[0][0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                vecTable[i][j] |= (vecTable[i - 1][j] && (s1[i - 1] == s3[p]));
            }
            if (j > 0) {
                vecTable[i][j] |= (vecTable[i][j - 1] && (s2[j - 1] == s3[p]));
            }
        }
    }
    return vecTable[n][m];
}

/*
    滚动数组优化代码
*/
bool isInterleave1(string s1, string s2, string s3) {
    auto vecTable = vector <int>(s2.size() + 1, false);

    int n = s1.size(), m = s2.size(), t = s3.size();

    if (n + m != t) {
        return false;
    }
    vecTable[0] = true;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int p = i + j - 1;
            if (i > 0) {
                vecTable[j] &= (s1[i - 1] == s3[p]);                
            }
            if (j > 0) {
                vecTable[j] |= (vecTable[j - 1] && (s2[j - 1] == s3[p]));
            }
        }
    }
    return vecTable[m];
}

int main() {
	string s1 = "aa";
	string s2 = "ab";
	string s3 = "aaba";
	cout << isInterleave1(s1, s2, s3) << endl;
}