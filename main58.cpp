#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int distance(int dst, int src) {
	return abs(dst - src);
}


int threeSum(vector<int>& nums, int target) {
	if (nums.size() < 3) {
		return EXIT_FAILURE;
	}
	// 排序，由小到大
	sort(nums.begin(), nums.end());
	int minDistan = 9999;
	int begin = 0;
	int len = nums.size();
	int res = 0;
	// 固定一个数，剩下两个数使用双指针进行寻找
	for (int i = 0; i < len; ++i) {
		// 双指针声明
		begin = i + 1;
		int end = len - 1;
		// 遍历所有的可能性
		while (begin < end) {
			// 若满足条件
			int tmp = nums[i] + nums[begin] + nums[end];
			if (tmp == target) {
				return target;
			}
			// 若大于target，则末尾指针前移，寻找一个比当前更小的数字
			else if (tmp > target) {
				int dis = distance(target, tmp);
				if (dis < minDistan) {
					minDistan = dis;
					res = tmp;
				}
				end--;
			}
			// 若小于target，则开始指针后移，寻找一个比当前更大的数字 
			else if (tmp < target) {
				int dis = distance(target, tmp);
				if (dis < minDistan) {
					minDistan = dis;
					res = tmp;
				}
				begin++;
			}
		}
	}
	return res;
}

int main() {
	vector<int> vec{-1,0,1,1,55 };
	auto res = threeSum(vec, 3);
	cout << res << endl;
	cout << distance(-100, 2) << endl;
	cout << distance(-100, 3) << endl;

	return 0;
}