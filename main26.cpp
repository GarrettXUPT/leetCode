#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

/*
	字母异位词分组
*/

vector<vector<string>> groupanagrams(vector<string>& strs) {
	int len = strs.size();
	if (len == 1) {
		return { strs };
	}
	vector<vector<string> >retVec;
	vector<int> check;
	for (int i = 0; i < len; ++i) {
		auto re = find(check.begin(), check.end(), i);
		if (re != check.end()) {
			continue;
		}
		vector<string> tmpVec;
		tmpVec.push_back(strs[i]);
		unordered_multiset<char> chset;
		const char* ch = strs[i].c_str();
		while (*ch != '\0') {
			chset.insert(*ch);
			ch++;
		}

		for (int j = 0; j < len; ++j) {
			if (i == j) {
				continue;
			}
			unordered_multiset<char> tmpset;
			auto begin = strs[j].begin();
			while (begin != strs[j].end())
			{
				tmpset.insert(*begin);
				begin++;
			}
			if (chset == tmpset) {
				tmpVec.push_back(strs[j]);
				check.push_back(j);
			}
		}

		retVec.push_back(tmpVec);
	}
	return  retVec;
}

int main() {
	vector<string> strs{ "ddddddddddg","dgggggggggg" };
	auto res = groupanagrams(strs);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}