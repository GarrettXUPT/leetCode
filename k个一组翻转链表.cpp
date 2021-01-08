#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {};
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

ListNode* reverseKGroup(ListNode* head, int k) {
	vector<int> vec;
	while (head != nullptr) {
		vec.push_back(head->val);
		head = head->next;
	}
	int vecLen = vec.size();

	int divNum = vecLen / k;
	int j = 0, i = 0;
	vector<int> tmpVec;
	for (i = 0; i < divNum; ++i) {
		for (j = k - 1; j >= 0; j--) {
			tmpVec.push_back(vec[j + i * k]);
		}
	}

	for (auto& ele : tmpVec) {
		cout << ele << " ";
	}
	cout << endl;
	
	ListNode* newList = new ListNode(tmpVec[0]);
	ListNode* tmpList = newList;
	int m = 0;
	for (m = 1; m < tmpVec.size(); ++m) {
		ListNode* tmpNode = new ListNode(tmpVec[m]);
		tmpList->next = tmpNode;
		tmpList = tmpList->next;
	}

	if (m == vecLen) {
		return newList;
	}
	else {
		for (; m < vecLen; ++m) {
			ListNode* tmpNode = new ListNode(vec[m]);
			tmpList->next = tmpNode;
			tmpList = tmpList->next;
		}
	}

	
	return newList;
}