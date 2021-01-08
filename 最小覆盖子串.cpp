#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

/*
	���longStr�Ƿ����Ӵ�subStr
	Ҫע��subStr�п��ܻ���ֵ��ظ��ַ��������б�ʱ���Ӱ��
*/
bool check(string longStr, string subStr) {
	if (longStr.size() < subStr.size()) {
		return false;
	}
	int flag = 0;
	for (int i = 0; i < subStr.size(); ++i) {
		auto findflag = find(longStr.begin(), longStr.end(), subStr[i]);
		if (findflag != longStr.end()) {
			longStr.erase(findflag);
			flag++;
		}
		else {
			return false;
		}
	}
	if (flag == subStr.size()) {
		return true;
	}
	else {
		return false;
	}
}

string minWindow(string s, string t) {
	auto fast = s.begin();
	string ret = "";
	int minLength = 9999;
	string tmpVec;
	while (fast != s.end()) {
		// s��ǰ������ӵ�tmpVec��
		tmpVec.push_back(*fast);
		fast++;
		if (check(tmpVec, t)) {  // ���γɵ��Ӵ�tmpVec���Ѿ�������Ŀ���Ӵ�t
			char tmp;
			while (check(tmpVec, t)) {
				tmp = *tmpVec.begin();  // ɾ����ǰ����Ӵ�tmpVec���ַ���ֱ����󲻺����Ӵ�
				tmpVec.erase(tmpVec.begin());
			}

			tmpVec.insert(tmpVec.begin(), tmp);
			if (tmpVec.size() < minLength) {  // �����ȱ����еĶ̣������Ϊ����Ӵ�
				minLength = tmpVec.size();
				ret = tmpVec;
			}
			tmpVec.erase(tmpVec.begin());  // �ָ������Ӵ�״̬
		}
	}
	return ret;

}

int main() {
	string s1 = "cabwefgewcwaefgcf";
	string s2 = "cae";
	cout << minWindow(s1, s2) << endl;
	return 0;
}