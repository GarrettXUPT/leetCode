#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
	int len = nums.size();
	if (len <= 1) {
		return;
	}
	// 从后向前找,找到非降序的最后他一个元素 5
	int i = len - 1;
	while (i > 0 && nums[i - 1] >= nums[i]) {
		i--;
	}
	// 若该序已经是最大字典序
	if (i == 0) {
		reverse(nums.begin(), nums.end());
		return;
	}
	// 从后向前找，找到大于上步找到位置的元素 4
	int j = len - 1;
	while (j > 0 && nums[i - 1] >= nums[j]) {
		j--;
	}
	// 将换该两个元素
	swap(nums[i - 1], nums[j]);
	// 将i - 1后面的元素进行翻转
	reverse(nums.begin() + i, nums.end());
}

int main() {
	vector<int> vec{ 1, 5, 1};
	vector<int> vec1{ 3,2,1 };
	nextPermutation(vec);
	for (auto& ele : vec) {
		cout << ele << endl;
	}
}