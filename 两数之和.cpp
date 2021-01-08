#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0) {
		return {};
	}
	else if (len == 1) {
		if (nums[0] != target) {
			return {};
		}
	}
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (nums[i] + nums[j] == target) {
				return { nums[i], nums[j] };
			}
		}
	}
	return {};
}