#include<iostream>
#include<vector>

using namespace std;

// 搜索元素所在位置

int search(vector<int>& nums, int target) {
	int len = nums.size();
	int i = 0;
	while (i < len && nums[i] != target) {
		i++;
	}
	if (i == len) {
		return -1;
	}
	return i;
}

int main() {
	vector<int> vec{ 4,5,6,7,0,1,2 };
	cout << search(vec, 0) << endl;
}