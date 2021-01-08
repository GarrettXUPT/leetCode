#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	if (numRows == 0) {
		return {};
	}
	vector<vector<int>> vec(numRows, {1,1});
	vec[0].pop_back();
	for (int i = 1; i < numRows; ++i) {
		if (vec[i].size() == i + 1) {
			continue;
		}
		for (int j = 0; j < i - 1; ++j) {
			int tmp = vec[i - 1][j] + vec[i - 1][j + 1];
			vec[i].insert(vec[i].begin() + j + 1, tmp);
		}
	}
	return vec;
}

int main() {
	auto res = generate(1);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}