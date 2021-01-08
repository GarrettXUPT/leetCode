#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool wordPattern(string pattern, string s) {

	string tmp = "";
	vector<string> strVec;
	map<char, string> check;
	auto begin = s.begin();
	while (begin != s.end()) {
		if (*begin == ' ') {
			strVec.push_back(tmp);
			tmp = "";
		}
		else
		{
			tmp += *begin;
		}
		begin++;
		if (begin == s.end()) {
			strVec.push_back(tmp);
		}
	}
	if (strVec.size() != pattern.length()) {
		return false;
	}
	for (int i = 0; i < strVec.size(); ++i) {
		auto iter = check.find(pattern[i]);
		if (iter != check.end()) {
			if (strVec[i] != check.at(pattern[i])) {
				return false;
			}
		}
		
		if (iter == check.end()){
			auto tmpBegin = check.begin();
			bool flag = true;
			while (tmpBegin != check.end()){
				if (tmpBegin->second == strVec[i]) {
					flag = false;
				}
				tmpBegin++;
			}
			if (flag == true) {
				check.insert({ pattern[i], strVec[i] });
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

int main() {
	wordPattern("abba", "dog dog dog dog");
}