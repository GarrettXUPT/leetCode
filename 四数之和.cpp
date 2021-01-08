#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


vector< vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int> > resVec;
	if (nums.size() < 4) {
		return resVec;
	}
	sort(nums.begin(), nums.end());
	int begin = 0;
	int len = nums.size();
	for (int i = 0; i < len - 3; ++i) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
			break;
		}
		if (nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] <target) {
			continue;
		}
		for (int j = i + 1; j < len - 2; ++j) {
			if ((j > i + 1) && (nums[j] == nums[j - 1])) {
				continue;
			}
			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
				break;
			}
			if (nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) {
				continue;
			}
			begin = j + 1;
			int end = len - 1;
			while (begin < end) {
				int sum = nums[i] + nums[j] + nums[begin] + nums[end];
				if (sum == target) {
					resVec.push_back({ nums[i], nums[j], nums[begin], nums[end] });
					while((begin < end) && (nums[begin] == nums[begin + 1])) {
						begin++;
					}
					while((begin < end) && (nums[end] == nums[end - 1])) {
						end--;
					}
					begin++; end--;
				}
				else if (sum > target) {
					end--;
				}
				else if (sum < target) {
					begin++;
				}
				
			}
		}
	}
	return resVec;
}


int main() {
	vector<int> vec{ 4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5 };
	auto res = fourSum(vec, -13);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}