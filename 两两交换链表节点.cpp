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

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* pos = head;
	vector<int> vec;
	while (pos != nullptr) {
		vec.push_back(pos->val);
		pos = pos->next;
	}
	for (auto& ele : vec) {
		cout << ele << " ";
	}
	cout << endl;
	for (int i = 1; i < vec.size(); i += 2) {
		int tmp = vec[i];
		vec[i] = vec[i - 1];
		vec[i - 1] = tmp;
	}
	ListNode* newList = new ListNode(vec[0]);
	ListNode* tmpNode = newList;
	for (int i = 1; i < vec.size(); ++i) {
		ListNode* newNode = new ListNode(vec[i]);
		tmpNode->next = newNode;
		tmpNode = tmpNode->next;
	}
	return newList;
}

int main() {

	return 0;
}