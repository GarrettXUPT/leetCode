#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> largeGroupPositions(string s) {
	int len = s.length();
	if (len < 3) {
		return {};
	}
	int count = 1;
	vector<vector<int>> ret;
	for (int i = 1; i < len; ++i) {
		if (s[i - 1] == s[i]) {
			count++;
		}
		else
		{
			if (count >= 3) {
				ret.push_back({ i - count, i - 1 });
			}
			count = 1;
		}
	}
	if (count >= 3) {
		ret.push_back({ len  - count, len - 1 });
	}
	return ret;
}

int main() {
	auto res = largeGroupPositions("aaa");
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}