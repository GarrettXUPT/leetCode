#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string longestcommPreix(vector<string>& strs) {
	if (strs.empty()) {
		return "";
	}
	vector<int> lenVec;
	for (auto& ele : strs) {
		lenVec.push_back(ele.size());
	}
	string compreix = "";
	int j, count = 0;
	auto minLen = min_element(lenVec.begin(), lenVec.end());
	for (int i = 0; i < *minLen; ++i) {
		for (j = 1; j < strs.size(); ++j) {
			if (strs[j][i] != strs[j - 1][i]) {
				return compreix;
			}
			else {
				continue;
			}
		}
		compreix += strs[j - 1][count++];
	}
	return compreix;
}

int main() {
	vector<string> strs{  };
	cout << longestcommPreix(strs) << endl;
	return 0;
}

