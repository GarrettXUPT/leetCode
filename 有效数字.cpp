#include<iostream>
#include<vector>

using namespace std;

bool isNumber(string s) {
	
	vector<char> chVec;
	const char* ch = s.c_str();
	while (*ch != '\0') {
		chVec.push_back(*ch);
	}

	if ((chVec[0] != '-' && chVec[0] != '+') ||( chVec[0] < '0' && chVec[0] > '9') || chVec[0] == '.') {
		return false;
	}

	bool exFlag = false;
	for(int i = 1; i < s.length(); ++i) {
		if ((chVec[i] < '0' && chVec[i] > '9') && (chVec[i - 1])) {
			
		}
	}
	return false;
}

int main() {
	cout << int('e') << endl;
	return 0;
}