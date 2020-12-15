#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
	ƴ�������
*/

/*
	���ȱȽ����������еĵ�ǰԪ�أ����������ǰԪ�ز�ͬ����ѡ���нϴ��Ԫ����Ϊ��һ���ϲ���Ԫ�أ�
	������Ҫ�ȽϺ��������Ԫ�ز��ܾ���ѡ�ĸ�Ԫ����Ϊ��һ���ϲ���Ԫ�ء�
*/
int numsCompare(vector<int>& vec1, int index1, vector<int>& vec2, int index2) {
	int len1 = vec1.size();  int len2 = vec2.size();
	while (index1 < len1 && index2 < len2) {
		int diff = vec1[index1] - vec2[index2];
		if (diff != 0) {
			return diff;;
		}
		index1++;
		index2++;
	}
	return (len1 - index1) - (len2 - index2);  // nums1�ĳ��ȴ���nums2
}

vector<int> merge(vector<int>& vec1, vector<int>& vec2) {
	int len1 = vec1.size();  int len2 = vec2.size();
	if (len1 == 0) {
		return vec2;
	}
	else if(len2 == 0) {
		return vec1;
	}
	int mergedLen = len1 + len2;
	int index1 = 0; int index2 = 0;
	vector<int> mergedVec(mergedLen, 0);
	for (int i = 0; i < mergedLen; ++i) {
		if (numsCompare(vec1, index1, vec2, index2) > 0) {
			mergedVec[i] = vec1[index1++];
		}
		else {
			mergedVec[i] = vec2[index2++];
		}
	}
	return mergedVec;
}

/*
	��ȡ��Ϊk������Ӵ�
*/
vector<int> maxSubNums(vector<int> vec, int k) {
	int len = vec.size();
	vector<int> stk(k, 0);
	int remain = len - k;  // ������ʣ���Ԫ��
	int top = -1;
	for (int i = 0; i < len; ++i) {
		int num = vec[i];
		while ((top >= 0) && stk[top] < num && remain > 0) {  // ������ʣ��Ԫ�ظ������������£�ʹstk�е��Ӵ����
			top--;
			remain--;
		}
		if (k - 1 > top) {
			stk[++top] = num;
		}
		else {
			remain--;
		}
	}
	return stk;
}


vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	int len1 = nums1.size(); int len2 = nums2.size();
	vector<int> maxVec(k, 0);
	int start = max(0, k - len2);
	int end = min(k, len1);
	for (int i = start; i <= end; ++i) {
		vector<int> subVec1(maxSubNums(nums1, i));
		vector<int> subVec2(maxSubNums(nums2, k - i));
		vector<int> curVec = merge(subVec1, subVec2);
		if (numsCompare(curVec, 0, maxVec, 0) > 0) {
			maxVec.swap(curVec);
		}
	}
	return maxVec;
}

int main() {
	vector<int> vec1{ 3,4,6,5 };
	vector<int> vec2{ 9,1,2,5,8,3 };
	maxNumber(vec1, vec2, 5);
	return 0;
}