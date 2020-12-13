#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	全排列:基础技术，必须掌握
*/

vector<vector<int> > permute(vector<int>& nums) {
	int len = nums.size();
	if (len == 1) {
		return { nums};
	}
	else if (len == 0) {
		return {};
	}
	sort(nums.begin(), nums.end());
	vector<int> pos = nums;
	vector<vector<int> > ret;
	ret.push_back(pos);
	reverse(pos.begin(), pos.end());
	if (pos == nums) {
		return { nums };
	}
	while (1) {
		int i = len - 1;
		while (i > 0 && nums[i - 1] >= nums[i]) {
			i--;
		}

		int j = len - 1;
		while (j > 0 && nums[j] <= nums[i - 1]) {
			j--;
		}
		swap(nums[i - 1], nums[j]);
		reverse(nums.begin() + i, nums.end());
		ret.push_back(nums);
		for (auto& ele : nums) {
			cout << ele << " ";
		}
		cout << endl;
		if (nums == pos) {
			break;
		}
	}
	return ret;
}

int main() {
	
	vector<int> vec{ 1,1 };
	auto res = permute(vec);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}

