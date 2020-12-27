#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0) {
		nums.push_back(target);
	}
	int i = 0;
	while (i < len && nums[i] != target && nums[i] < target) {
		i++;
	}
	if (i == len) {
		nums.insert(nums.end(), target);
	}
	if (nums[i] != target) {
		nums.insert(nums.begin() + i, target);
	}
	return i;
}

int main() {
	vector<int>vec{1, 2, 5, 6};
	cout << searchInsert(vec, 7) << endl;
	return 0;
}