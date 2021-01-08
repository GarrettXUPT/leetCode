#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

bool isPossible(vector<int>& nums) {
    // ������У�С����
    //priority_queue<int, vector<int>, greater<int>> v();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (auto& x : nums) {
        if (mp.find(x) == mp.end()) {  // mp��û����xΪ���ļ�ֵ�ԣ�������С��
            mp[x] = priority_queue<int, vector<int>, greater<int>>();
        }
        if (mp.find(x - 1) != mp.end()) { // ������x-1Ϊ��β��������
            int prevLength = mp[x - 1].top();  // ����x֮ǰ�Ķѵó��ȣ���Ϊ��̶��еĳ���
            mp[x - 1].pop();
            if (mp[x - 1].empty()) {
                mp.erase(x - 1);
            }
            mp[x].push(prevLength + 1);
        }
        else {
            mp[x].push(1);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        priority_queue<int, vector<int>, greater<int>> queue = it->second;
        if (queue.top() < 3) {
            return false;
        }
    }
    return true;

}



int main() {
	vector<int> vec{ 1,2,3,3,4,4,5,5};
	cout << isPossible(vec) << endl;
	return 0;

}