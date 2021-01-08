#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
	if (s.empty()) {
		return 0;
	}
	// 排序
	sort(g.begin(), g.end());	sort(s.begin(), s.end());
	// 进行对比操作
	auto begin1 = g.begin();
	auto begin2 = s.begin();
	int ret = 0;
	while (begin1 != g.end() && begin2 != s.end()) {
		if (*begin1 <= *begin2) {
			ret++;
			begin1++; begin2++;
		}
		else if (*begin1 > *begin2) {
			begin2++;
		}
	}
	return ret;
}

int main() {

	vector<int> g{ 1,2 };
	vector<int> s{ 1,2,3 };
	cout << findContentChildren(g, s) << endl;

	return 0;
}