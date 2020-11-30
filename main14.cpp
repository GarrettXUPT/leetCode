#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {};
	ListNode(int x) :val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int len = lists.size();
	if (len == 0) {
		return nullptr;
	}
	vector<int> allVec;
	for (int i = 0; i < len; ++i) {
		while (lists[i] != nullptr) {
			allVec.push_back(lists[i]->val);
			lists[i] = lists[i]->next;
		}
	}
	if (allVec.empty()) {
		return nullptr;
	}
	sort(allVec.begin(), allVec.end());
	ListNode* newList = new ListNode(allVec[0]);
	ListNode* tmpList = new ListNode();
	tmpList = newList;
	for (int i = 1; i < allVec.size(); i++) {
		ListNode* newNode = new ListNode(allVec[i]);
		newList->next = newNode;
		newList = newList->next;
	}
	return tmpList;

}

int main() {

	return 0;
}