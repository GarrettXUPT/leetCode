#include<iostream>
#include<vector>

using namespace std;

vector<int> t;
vector<vector<int>> ans;

void dfs(int cur, vector<int>& nums) {
    if (cur == nums.size()) {
        ans.push_back(t);
        return;
    }
    t.push_back(nums[cur]);
    dfs(cur + 1, nums);
    t.pop_back();
    dfs(cur + 1, nums);
}

vector<vector<int>> subsets(vector<int>& nums) {
    dfs(0, nums);
    return ans;
}

int main() {
    vector<int> vec{ 1,2,3 };
    subsets(vec);
}