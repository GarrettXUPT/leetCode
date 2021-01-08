#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

	auto begin = nums.begin();
	vector<int> retVec;
	int maxValue = *max_element(begin, begin + k);  // 该处求最值时，针对的是左闭右开区间
	retVec.push_back(maxValue);
	while (1) {
		auto endPos = begin + k;
		if (endPos == nums.end()) {
			break;
		}
		if (maxValue == *begin) {
			begin++; endPos++;
			maxValue = *max_element(begin, endPos);   // 该处求最值时，针对的是左闭右开区间
		}
		else if(maxValue < *endPos)
		{
			maxValue = *endPos;
			begin++;
		}
		else
		{
			begin++;
		}
		retVec.push_back(maxValue);
	}
	return retVec;
}

vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
	if (nums.empty() || k > nums.size() || k <= 0) {
		return {};
	}

	vector<int> res;
	deque<int> findMax;

	for (int i = 0; i < nums.size(); ++i) {
		// i 每加一次，代表滑动窗口向右移一个单位。
		// i 指向的是每个滑动窗口的尾部元素（从 i = k - 1 开始）。

		if (i >= k && !findMax.empty()) {
			// i >= k 是为了确保 findMax.front() 至少为第一个完整的滑动窗口的最大值索引。
			// 即至少形成了一个完整的滑动窗口。
			res.push_back(nums[findMax.front()]);
		}

		while (!findMax.empty() && nums[i] >= nums[findMax.back()]) {
			// 如果新进来的 nums[i] 大于等于滑动窗口的尾部元素，
			// 说明该尾部元素肯定不会是任何滑动窗口的最大元素。
			// 就想象公司新来了一个既比你年轻又比你能干（大于等于你）的人，那你就只能被淘汰了，
			// 而且是循环淘汰掉所有不如新员工的老员工。
			findMax.pop_back();
		}

		if (!findMax.empty() && i - findMax.front() >= k) {
			// 虽然 findMax 的头部是最大的元素的索引，但是如果当前滑动窗口已不包括该索引，
			// 那么需要弹出该索引。
			// 就想象即使是公司的骨干成员，但是过了35岁也要被淘汰。
			findMax.pop_front();
		}

		findMax.push_back(i);
	}

	res.push_back(nums[findMax.front()]); // 最后一个滑动窗口还没计算就退出了 for 循环，需补上。

	return res;
}


int main() {
	vector<int> vec{ 1,3,-1,-3,5,3,6,7 };
	auto res = maxSlidingWindow1(vec, 3);
	for (auto& ele : res){
		cout << ele << "	";
	}
	cout << endl;
	return 0;
}