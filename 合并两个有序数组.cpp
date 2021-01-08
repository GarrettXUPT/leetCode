#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (nums2.empty()) {
		return;
	}
	if (m == 0) {
		nums1 = nums2;
		return;
	}
	int dis = nums1.size() - m;
	for (int i = 0; i < dis; ++i) {
		nums1.pop_back();
	}
	auto begin1 = nums1.begin();
	auto begin2 = nums2.begin();
	int count = 0;
	while (count < n + m) {
		if (*begin1 > * begin2) {
			nums1.insert(begin1, *begin2);
			begin2++;
		}
		begin1++;
		count++;
		if (begin1 == nums1.end() || begin2 == nums2.end()) {
			break;
		}
	}
	while (begin2 != nums2.end()) {
		nums1.insert(begin1, *begin2);
		begin1++; begin2++;
	}
}

int main() {
	vector<int> vec1{  };
	vector<int> vec2{ 2,5,6 };
	merge(vec1, 3, vec2, 3);
	for (auto& ele : vec1) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}