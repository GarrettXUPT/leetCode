#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* p1 = before, * p2 = after;
        //遍历链表，<x的值连在before后面，>=x的值连在after后面
        while (head != nullptr)
        {
            if (head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        //将before和after连起来
        p2->next = NULL;
        p1->next = after->next;
        return before->next;
    }
};

ListNode* partition(ListNode* head, int x) {
    ListNode* betterhead = new ListNode(0);
    ListNode* lesserhead = new ListNode(0);
    ListNode* ret = lesserhead;
    ListNode* secondTerm = betterhead;
    while (head != nullptr) {
        if (head->val < x) {
            lesserhead->next = head;
            lesserhead = lesserhead->next;
        }
        else {
            betterhead->next = head;
            betterhead = betterhead->next;
        }
        head = head->next;
    }
    betterhead->next = nullptr;
    secondTerm = secondTerm->next;
    // while(secondTerm != nullptr){
    //     cout << "better val " << secondTerm->val << endl;
    //     secondTerm = secondTerm->next;
    // }
    while (secondTerm != nullptr) {
        lesserhead->next = new ListNode(secondTerm->val);
        lesserhead = lesserhead->next;
        secondTerm = secondTerm->next;
    }
    return ret;
}
