#include<iostream>
#include<vector>
#include<map>

using namespace std;

char findTheDifference(string s, string t) {
	auto sBegin = s.begin();
	auto tBegin = t.begin();
	map<char, int>sMap;
	map<char, int>tMap;
	while (sBegin != s.end()) {
		if (sMap.find(*sBegin) != sMap.end()) {
			sMap[*sBegin]++;
		}
		else
		{
			sMap.insert({ *sBegin, 1 });
		}
		sBegin++;
	}

	while (tBegin != t.end()) {
		if (tMap.find(*tBegin) != tMap.end()) {
			tMap[*tBegin]++;
			if (tMap[*tBegin] > sMap[*tBegin]) {
				return *tBegin;
			}
		}
		else{
			tMap.insert({ *tBegin, 1 });
			if (sMap.find(*tBegin) == sMap.end()) {
				return *tBegin;
			}
		}
		tBegin++;
	}
	return ' ';
}

int main() {
	cout << findTheDifference("abcd", "abcde") << endl;
	return 0;
}
