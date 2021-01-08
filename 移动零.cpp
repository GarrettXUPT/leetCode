#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int len = nums.size();
	auto begin = nums.begin();
	int count = 0;
	while (1) {
		auto pos = find(nums.begin(), nums.end(), 0);
		if (pos == nums.end()) {
			break;
		}
		else {
			count++;
			nums.erase(pos);
		}
	}
	for(int i = 0; i < count; ++i){
		nums.push_back(0);
	}
}

int main() {
	vector<int> vec{ 0,1,0,3,12 };
	moveZeroes(vec);
	for (auto& ele : vec)
	{
		cout << ele << endl;
	}
}