#include<iostream>
#include<vector>

using namespace std;

/*
	dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
*/

int minCostClimbingStairs(vector<int>& cost) {
	int len = cost.size();
	vector<int> dp(len + 1, 0);
	dp[0] = dp[1] = 0;  // ±ß½çÌõ¼þ
	for (int i = 2; i <= len; ++i) {
		dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
	}
	return dp[len];
}