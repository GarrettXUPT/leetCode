#include<iostream>
#include<vector>

using namespace std;

/*
	查找数组中目标元素第一个位置和最后一个位置
*/

vector<int> searchRange(vector<int>& nums, int target) {
	int len = nums.size();
	int i = 0;
	int minPos = len;
	int maxPos = 0;
	while (i < len) {
		if (nums[i] == target) {
			if (i < minPos) {
				minPos = i;
			}
			if (i > maxPos) {
				maxPos = i;
			}
		}
		i++;
	}
	if (minPos == len && maxPos == 0) {
		return vector<int>{-1, -1};
	}
	return vector<int>{minPos, maxPos};
}

int main() {

	vector<int> vec{ 5,7,7,8,8,10 };
	auto res = searchRange(vec, 8);


	return 0;
}
