#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;
/*
	×ÖÄ¸ÒìÎ»´Ê·Ö×é
*/

multiset<char> split(string s) {
	multiset<char> chSet;
	auto begin = s.begin();
	while (*begin != '\0') {
		chSet.insert(*begin);
		begin++;
	}
	
	return chSet;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int len = strs.size();
	if (len == 1) {
		return { strs };
	}
	map<multiset<char>, vector<string>> strmap;
	set<multiset<char>> featureSet;
	auto begin = strs.begin();
	while (begin != strs.end()) {
		multiset<char> tmp = split(*begin);
		if (find(featureSet.begin(), featureSet.end(), tmp) != featureSet.end()) {
			strmap.at(tmp).push_back(*begin);
		}
		else
		{
			featureSet.insert(tmp);
			strmap.insert({ tmp, {*begin} });
		}
		begin++;
	}
	vector<vector<string>> ret;
	for (auto& ele : strmap) {
		ret.push_back(ele.second);
	}
	return ret;
}

int main() {
	multiset<char> set1{ 1,2,1,3 };
	multiset<char> set2{ 1,1,2,3 };
	auto begin = set1.begin();
	/*while (begin != set1.end()) {
		cout << *begin << endl;
	}*/
	cout << (set1 == set2) << endl;
	string s{ "string" };
	cout << s.end() - s.begin() << endl;

	return 0;
}
