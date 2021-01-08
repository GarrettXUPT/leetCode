#include<vector>
#include<iostream>

using namespace std;

int jump(vector<int>& nums) {
	vector<int> times;
	auto begin = nums.begin();
	int time = 0;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 1; j <= *begin; ++j) {
			begin += j;
			time++;
			if (begin == nums.end()) {
				times.push_back(time);
			}
		}
	}
	return 0;
}

int main() {
	vector<int> vec{ 2,3,1,1,4 };
	cout << jump(vec) << endl;
	return 0;
}

