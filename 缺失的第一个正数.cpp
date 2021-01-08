#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	if ((len == 0)|| (nums[0] > 0 && nums[0] != 1) || nums[len - 1] <= 0) {
		return 1;
	}
	int i;
	for (i = 0; i < len; ++i) {
		if (i < len - 1) {
			if (nums[i] > 0 && ((nums[i + 1] != nums[i] + 1) && nums[i + 1] != nums[i])) {
				break;
			}
			else if (nums[i] <= 0 && nums[i + 1] > 0) {
				if (nums[i + 1] != 1) {
					return 1;
				}
			}
		}
		else {
			return nums[i] + 1;
		}
		
	}

	return nums[i] + 1 ;
}

int main() {

	vector<int> vec{ 0,2,2,1,1};
	cout << firstMissingPositive(vec) << endl;

	return 0;
}