#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
    �Ƿ�����ظ�Ԫ�أ��ǵ����ֶ���Ҫʹ�ù�ϣ������������ͻᳬʱ
*/

bool containDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int x : nums) {
        if (s.find(x) != s.end()) {
            return true;
        }
        s.insert(x);
    }
    return false;
}