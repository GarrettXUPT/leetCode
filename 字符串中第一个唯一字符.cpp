#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int firstUniqChar(string s) {
	int len = s.size();
	if (len == 1) {
		return 0;
	}
	else if (len == 0) {
		return -1;
	}
	else if (count(s.begin(), s.end(), s[0]) == len) {
		return -1;
	}
	auto begin = s.begin();
	map<int, int> check;
	set<char> checkSet;
	for (int i = 0; i < s.length(); ++i) {
		if (checkSet.find(s[i]) != checkSet.end()) {
			int pos = find(s.begin(), s.end(), s[i]) - s.begin();
			check[pos]++;
		}
		else {
			checkSet.insert(s[i]);
			check.insert({i, 1});
		}
	}
	int firstPos = INT16_MAX;
	auto resBegin = check.begin();

	while(resBegin != check.end()){
		if (resBegin->second == 1) {
			if (firstPos > resBegin->first) {
				firstPos = resBegin->first;
			}
		}
		resBegin++;
	}
	if (firstPos == INT16_MAX) {
		return -1;
	}
	return firstPos;
}

int main() {
	cout << firstUniqChar("aadadaad") << endl;
	return 0;
}