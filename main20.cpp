#include<iostream>
#include<vector>

using namespace std;

// 只出现一次的数字

int singleNumber(vector<int>& nums) {
	int ret = 0;
	for (auto& ele : nums) {
		ret = ret ^ ele;
	}
	return ret;
}