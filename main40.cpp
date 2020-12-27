#include<iostream>
#include<vector>
#include<map>

using namespace std;

int singleNumber(vector<int>& nums) {
	int len = nums.size();
	
	for (int i = 0; i < len; ++i) {
		if (count(nums.begin(), nums.end(), nums[i]) == 1) {
			return nums[i];
		}
	}
	return -1;
}

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