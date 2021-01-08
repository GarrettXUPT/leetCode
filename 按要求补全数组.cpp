#include<iostream>
#include<vector>

using namespace std;

int minPatches(vector<int>& nums, int n) {
	int patches = 0;
	long long x = 1;
	int length = nums.size(), index = 0;
	// 由x = 1 ... n
	while (x <= n) {
		// 若是下标还没到最后，且当前值还在该求和中
		if (index < length && nums[index] <= x) {
			x += nums[index];
			index++;
		}
		else  // 若是当前值不在该求和中
		{
			x = 2 * x;
			patches++;
		}
	}
	return patches;
}

int main() {
	vector<int> vec{ 1,5,10 };
	cout << minPatches(vec, 20) << endl;
	return 0;
}