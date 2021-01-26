#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
    是否存在重复元素，记得这种东西要使用哈希表来做，否则就会超时
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