#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
	vector<vector<int> > resVec;
	if (nums.size() < 3) {
		return resVec;
	}
	// 排序，由小到大
	sort(nums.begin(), nums.end());
	int begin = 0;
	int len = nums.size();
	// 固定一个数，剩下两个数使用双指针进行寻找
	for (int i = 0; i < len; ++i) {
		// 若当前数字大于0，则后面的数字不会再小于0，所以不可能出现合适的解
		if (nums[i] > 0) {
			return resVec;
		}
		// 出现重复解
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		// 双指针声明
		begin = i + 1;
		int end = len - 1;
		// 遍历所有的可能性
		while (begin < end) {
			// 若满足条件
			if (nums[i] + nums[begin] + nums[end] == 0) {
				resVec.push_back(vector<int>{nums[i], nums[begin], nums[end]});
				// 开始指针有重复数字
				while ((begin < end) && (nums[begin] == nums[begin + 1]))
				{
					begin++;
				}
				// 结尾指针有重复数字
				while ((begin < end) && (nums[end] == nums[end - 1])) {
					end--;
				}
				// 开始指针后移，结尾指针后移
				begin++;
				end--;
			}
			// 若大于0，则末尾指针前移，寻找一个比当前更小的数字
			else if (nums[i] + nums[begin] + nums[end] > 0) {
				end--;
			}
			// 若小于0，则开始指针后移，寻找一个比当前更大的数字 
			else if (nums[i] + nums[begin] + nums[end] < 0) {
				begin++;
			}
		}

	}
	return resVec;
}

int main() {
	vector<int> vec{ -1, 0, 1, 2, -1, -4 };
	auto res = threeSum(vec);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}