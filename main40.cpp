#include<iostream>
#include<vector>
#include<map>
#include <algorithm>

using namespace std;

/*
	只出现一次的数字
*/
int singleNumber(vector<int>& nums) {
	int len = nums.size();
	
	for (int i = 0; i < len; ++i) {
		if (count(nums.begin(), nums.end(), nums[i]) == 1) {
			return nums[i];
		}
	}
	return -1;
}

/*
	遇到该种问题，应该可以考虑到使用哈希表来提高效率
	若是可以使用库函数的就一定要使用库函数，因为那些函数都是经过优化的
*/
int singleNumber1(vector<int>& nums) {
	int len = nums.size();
	map<int, int> check;
	for (int i = 0; i < len; i++) {
		if (check.find(nums[i]) != check.end()) {
			check[nums[i]]++;
		}
		else
		{
			check.insert({ nums[i], 1 });
		}
	}
	auto iter = find_if(check.begin(), check.end(), [](const map<int, int>::value_type p1) {return p1.second == 1; });
	return iter->first;
}

int main() {
	vector<int> vec{ 2,2,3,2 };
	cout << singleNumber1(vec) << endl;
	return 0;
}