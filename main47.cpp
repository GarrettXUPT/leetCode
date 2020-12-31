#include<iostream>
#include<vector>

using namespace std;

/*
	搜索插入位置
	若向量中不存在该元素，则将该元素插入到排序位置，返回插入位置，若是存在，直接返回所在位置
*/

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