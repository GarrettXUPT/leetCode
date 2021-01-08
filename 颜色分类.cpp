#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums) {
	int len = nums.size();
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (nums[i] > nums[j]) {
				swap(nums[i], nums[j]);
			}
		}
	}
}

int main() {
	vector<int> vec{ 0,1,2,0,1 };
	sortColors(vec);
	for (auto& ele : vec) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}