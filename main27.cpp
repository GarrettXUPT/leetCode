#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cmath>
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

/*
	实现步骤
*/
string multiply(string num1, string num2) {

	if (num1 == "0" || num2 == "0") {
		return "0";
	}
	int len1 = num1.length();
	int len2 = num2.length();

	vector<int> nums1, nums2;
	const char* ch1 = num1.c_str();
	const char* ch2 = num2.c_str();
	// 将字符串中数字转化为整形数字数组
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
	for (int i = len1 - 1; i >= 0; i--) {  // 第一项最低位向最高位移动
		int intTmp;
		vector<int> tmpVec;
		for (int j = len2 - 1; j >= 0; j--) {  // 第二项最低位向最高位移动
			int tmp = nums1[i] * nums2[j];  // 最低位相乘
			if (flag != 0) {  // 若有进位，则进行进位操作
				tmp += flag;
				flag = 0;
			}
			if (tmp >= 10) {  // 若两个最低位相乘就有进位，则获取进位数
				flag = (tmp / 10);
			}
			intTmp = tmp % 10;  // 乘积最低位进入临时数组
			tmpVec.insert(tmpVec.begin(), intTmp);
		}
		for (int k = nums1.size() - i - 1; k > 0; k--) {  // 因为第二个乘积结果是错开相加，所以后面要将其填补0
			tmpVec.push_back(0);
		}
		if (flag != 0) {
			tmpVec.insert(tmpVec.begin(), flag);  // 若在最高位还有进位，则将进位增加到更高位
			ret = add(tmpVec, ret);  // 与前一步获得的结果相加，更新当前步骤结果
			flag = 0;
		}
		else {
			ret = add(tmpVec, ret);  // 无进位，则直接相加
		}
	}
	return ret;
}

int main() {
	//cout << add("1368", "9120") << endl;
	cout << multiply("123456789", "987654321") << endl;
	
	return 0;
}

