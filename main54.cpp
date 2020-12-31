#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximumGap(vector<int>& nums) {
	int len = nums.size();
	if (len < 2) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	int maxDis = 0;
	for (int i = 0; i < len - 1; ++i) {
		int dis = abs(nums[i] - nums[i + 1]);
		if (dis > maxDis) {
			maxDis = dis;
		}
	}
	return maxDis;
}

int main() {
	vector<int> nums{ 3,6,9,1 };
	cout << maximumGap(nums) << endl;
	return 0;
}