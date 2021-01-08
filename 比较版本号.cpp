#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int strCompare(string s1, string s2) {
	if (s1.length() > s2.length()) {
		return 1;
	}
	else if (s1.length() < s2.length()) {
		return -1;
	}
	const char* ch1 = s1.c_str();
	const char* ch2 = s2.c_str();
	while (ch1 != '\0') {
		if (*ch1 > * ch2) {
			return 1;
		}
		else if (*ch1 < *ch2) {
			return -1;
		}
		ch1++; ch2++;
	}
	return 0;
}

int compareVersion(string version1, string version2) {

	auto begin1 = version1.begin();
	auto begin2 = version2.begin();
	string tmpStr = "";
	vector<string> strVec1;
	vector<string> strVec2;
	while (begin1 != version1.end()) {
		if (*begin1 != '.') {
			tmpStr += *begin1;
		}
		if (*begin1 == '.') {
			bool flag = false;
			string str = "";
			if (count(tmpStr.begin(), tmpStr.end(), '0') == tmpStr.size()) {
				strVec1.push_back("0");
			}
			else {
				for (int i = 0; i < tmpStr.size(); ++i) {
					if (tmpStr[i] > '0') {
						flag = true;
						str += tmpStr[i];
					}
					else if (flag == true) {
						str += tmpStr[i];
					}
				}
				strVec1.push_back(str);
			}
			tmpStr = "";
		}
		begin1++;
	}
	if (!tmpStr.empty()) {
		strVec1.push_back(tmpStr);
	}
	tmpStr = "";
	while (begin2 != version2.end()) {
		if (*begin2 != '.') {
			tmpStr += *begin2;
		}
		if (*begin2 == '.') {
			bool flag = false;
			string str = "";
			if (count(tmpStr.begin(), tmpStr.end(), '0') == tmpStr.size()) {
				strVec2.push_back("0");
			}
			else {
				for (int i = 0; i < tmpStr.size(); ++i) {
					if (tmpStr[i] > '0') {
						flag = true;
						str += tmpStr[i];
					}
					else if (flag == true) {
						str += tmpStr[i];
					}
				}
				strVec2.push_back(str);
			}
			tmpStr = "";
		}
		begin2++;
	}
	if (!tmpStr.empty()) {
		strVec2.push_back(tmpStr);
	}
	
	auto vec1Begin = strVec1.begin();
	auto vec2Begin = strVec2.begin();

	while (vec1Begin != strVec1.end() && vec2Begin != strVec2.end()) {
		if (strCompare(*vec1Begin, *vec2Begin) > 0) {
			return 1;
		}
		else if (strCompare(*vec1Begin, *vec2Begin) < 0) {
			return -1;
		}
		vec1Begin++; vec2Begin++;
	}
	if (vec1Begin != strVec1.end()) {
		if (count(vec1Begin, strVec1.end(), "0") != (strVec1.end() - vec1Begin)) {
			return 1;
		}
	}
	else if (vec2Begin != strVec2.end()) {
		if (count(vec2Begin, strVec2.end(), "0") != (strVec2.end() - vec2Begin)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	cout << compareVersion("01.1.10.0.1", "01.1.10.0.1") << endl;
	cout << ("11" > "10") << endl;
	return 0;
}