#include<map>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	map<int, int> countMap;
	vector<int> flag;
	for (auto& ele : nums) {
		if (find(flag.begin(), flag.end(), ele) == flag.end()) {
			flag.push_back(ele);
			countMap.insert({ ele, count(nums.begin(), nums.end(), ele) });
		}
	}
	for (auto& ele : countMap) {
		if (ele.second > 2) {
			int count = ele.second - 2;
			while (count > 0) {
				nums.erase(find(nums.begin(), nums.end(), ele.first));
				count--;
			}
		}
	}
	return nums.size();
}

int main() {
	vector<int> vec{ 1,1,1,2,2,3 };
	removeDuplicates(vec);
	return 0;
}