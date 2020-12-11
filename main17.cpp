#include<iostream>
#include<vector>

using namespace std;

vector<int> grayCode(int n) {
	vector<int> ret;
	ret.push_back(0);
	for (int i = 0; i < n; ++i) {
		int addValue = 1 << i;  // 需要加的数
		for (int j = ret.size() - 1; j >= 0; --j) {
			ret.push_back(ret[j] + addValue);
		}
	}
	return ret;
}

int main() {
	auto res = grayCode(3);
	for (auto& ele : res) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}