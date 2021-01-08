#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

string mutiply1(string num1, string num2) {

	if (num1 == "0" || num2 == "0") {
		return "0";
	}

	vector<unsigned long long> nums1, nums2;

	const char* ch1 = num1.c_str();
	const char* ch2 = num2.c_str();
	
	while (*ch1 != '\0') {
		nums1.push_back(*ch1 - '0');
		ch1++;
	}
	while (*ch2 != '\0') {
		nums2.push_back(*ch2 - '0');
		ch2++;
	}

	unsigned long long intNum1 = 0;
	for (int i = 0; i < nums1.size(); ++i) {
		intNum1 += nums1[i] * pow(10, nums1.size() - i - 1);
	}

	unsigned long long intNum2 = 0;
	for (int i = 0; i < nums2.size(); ++i) {
		intNum2 += nums2[i] * pow(10, nums2.size() - i - 1);
	}

	return to_string(intNum1 * intNum2);
}


string add(vector<int> nums1, string num2) {

	vector<int> nums2;
	const char* ch = num2.c_str();
	while (*ch != '\0') {
		nums2.push_back(*ch - '0');
		ch++;
	}

	int len1 = nums1.size();
	int len2 = nums2.size();
	int len = len1 > len2 ? len1 : len2;
	if (len1 >len2) {
		for (int i = len2; i <len1; i++) {
			nums2.insert(nums2.begin(), 0);
		}
	}
	else {
		for (int i = len1; i < len2; i++) {
			nums1.insert(nums1.begin(), 0);
		}
	}

	int flag = 0;
	string tmpStr;
	for (int i = len - 1; i >= 0; i--) {
		int tmp = nums1[i] + nums2[i];
		if (flag != 0) {
			tmp += flag;
			flag = 0;
		}
		if (tmp >= 10) {
			flag += 1;
		}
		tmpStr = to_string(tmp % 10) + tmpStr;
	}
	if (flag != 0) {
		tmpStr = to_string(flag) + tmpStr;
		flag = 0;
	}
	return tmpStr;
}


string multiply(string num1, string num2) {

	if (num1 == "0" || num2 == "0") {
		return "0";
	}
	int len1 = num1.length();
	int len2 = num2.length();

	vector<int> nums1, nums2;
	const char* ch1 = num1.c_str();
	const char* ch2 = num2.c_str();

	while (*ch1 != '\0') {
		nums1.push_back(*ch1 - '0');
		ch1++;
	}
	while (*ch2 != '\0') {
		nums2.push_back(*ch2 - '0');
		ch2++;
	}


	int flag = 0;
	string ret = "0";
	for (int i = len1 - 1; i >= 0; i--) {
		int intTmp;
		vector<int> tmpVec;
		for (int j = len2 - 1; j >= 0; j--) {
			int tmp = nums1[i] * nums2[j];
			if (flag != 0) {
				tmp += flag;
				flag = 0;
			}
			if (tmp >= 10) {
				flag = (tmp / 10);
			}
			intTmp = tmp % 10;
			tmpVec.insert(tmpVec.begin(), intTmp);
		}
		for (int k = nums1.size() - i - 1; k > 0; k--) {
			tmpVec.push_back(0);
		}
		if (flag != 0) {
			tmpVec.insert(tmpVec.begin(),flag);
			ret = add(tmpVec, ret);
			flag = 0;
		}
		else {
			ret = add(tmpVec, ret);
		}
	}
	return ret;
}

int main() {
	//cout << add("1368", "9120") << endl;
	cout << multiply("123456789", "987654321") << endl;
	
	return 0;
}

