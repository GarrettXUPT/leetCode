#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
	int len = nums.size();
	if (len == 0) {
		return;
	}

	// 旋转位数进行降维
	int moveLen = k % len;
	if (moveLen == 0) {
		return;
	}
	while (moveLen > 0) {
		int eleCur = nums.back();
		nums.pop_back();
		nums.insert(nums.begin(), eleCur);
		moveLen--;
	}
}

int main() {
	vector<int> vec{ 1,2,3,4,5,6,7 };
	rotate(vec, 3);
	for (const auto& ele : vec) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}