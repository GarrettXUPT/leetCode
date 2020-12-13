#include<iostream>
#include<vector>

using namespace std;

// ??????ù?????????????????
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

int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
    if (obstacleGrid.size() == 0) {
        return 0;
    }

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
        dp[0][j] = 1;
    }

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


 
