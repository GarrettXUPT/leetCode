#include<iostream>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	if (rowIndex == 0) {
		return {};
	}
	vector<vector<int>> vec(rowIndex + 1, { 1,1 });
	vec[0].pop_back();
	for (int i = 1; i <= rowIndex; ++i) {
		if (vec[i].size() == i + 1) {
			continue;
		}
		for (int j = 0; j < i - 1; ++j) {
			int tmp = vec[i - 1][j] + vec[i - 1][j + 1];
			vec[i].insert(vec[i].begin() + j + 1, tmp);
		}
	}
	return vec[vec.size() - 1];
}