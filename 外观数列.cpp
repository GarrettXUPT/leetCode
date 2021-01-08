#include<iostream>
#include<vector>
#include<string>

using namespace std;

string describe(string pre) {
	string retStr = "";
	int len = pre.size();
	int num = pre[0] - '0';
	int count = 1;
	for (int i = 1; i < len; ++i) {
		if (pre[i] == pre[i - 1]) {
			count++;
		}
		else
		{
			retStr += to_string(count);
			retStr += to_string(num);
			num = pre[i] - '0';
			count = 1;
		}
		if (i == len - 1) {
			retStr += to_string(count);
			retStr += to_string(num);
		}
	}
	return retStr;
}

string countAndSay(int n) {
	if (n <= 0) {
		return "";
	}
	vector<string> dp(n + 1);
	dp[1] = "1";
	dp[2] = "11";
	for (int i = 3; i <= n; ++i) {
		dp[i] = describe(dp[i - 1]);
	}
	return dp[n];
}

int main() {
	cout << countAndSay(4) << endl;
	return 0;
}