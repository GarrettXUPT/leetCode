#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int ret = 0;
	for (auto& ele : nums) {
		ret = ret ^ ele;
	}
	return ret;
}