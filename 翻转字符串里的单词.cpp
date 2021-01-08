#include<iostream>
#include<vector>

using namespace std;

string reverseWords(string s) {
	vector<string> strVec;
	int Len = s.length();
	string strTmp = "";
	for (int i = 0; i < Len; ++i) {
		if (s[i] == ' ') {
			if (!strTmp.empty()) {
				strVec.push_back(strTmp);
			}
			strTmp = "";
		}
		else if(isalnum(s[i]))
		{
			strTmp += s[i];
		}
	}
	if (!strTmp.empty()) {
		strVec.push_back(strTmp);
	}
	string retStr = "";
	auto rBegin = strVec.rbegin();
	while (rBegin != strVec.rend()) {
		retStr = retStr + " " + *rBegin;
		rBegin++;
	}
	retStr.erase(retStr.begin());
	return retStr;
}

int main() {
	cout << reverseWords("  hello world!  ") << "*"<< endl;
	return 0;
}