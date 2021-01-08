#include<iostream>
#include<unordered_set>

using namespace std;

bool isAnagram(string s, string t) {
	unordered_multiset<char> sSet;
	unordered_multiset<char> tSet;
	const char* chs = s.c_str();
	const char* cht = t.c_str();
	while (*chs != '\0') {
		sSet.insert(*chs);
		chs++;
	}

	while (*cht != '\0') {
		tSet.insert(*cht);
		cht++;
	}

	return sSet == tSet;
}