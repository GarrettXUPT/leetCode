#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    最大扰动距离
*/

int wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
        return len;
    }
    if (count(nums.begin(), nums.end(), nums[0]) == len) {
        return 1;
    }
    int count = 0;
    int ResFlag = 2;
    int Flag = 2;
    if (nums[1] - nums[0] == 0) {
        count = 1;
    }
    else {
        ResFlag = nums[1] - nums[0] > 0 ? true : false;
        Flag = nums[1] - nums[0] > 0 ? true : false;
        count = 2;
    }
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] - nums[i - 1] == 0) {
            continue;
        }
        nums[i] - nums[i - 1] > 0 ? Flag = 1: Flag = 0;
        
        if (ResFlag == Flag) {
            continue;
        }
        ResFlag = Flag;
        count++;
    }
    return count;
}

int main() {
	vector<int> vec{ 3,3,3,2,5};
	cout << wiggleMaxLength(vec) << endl;

}