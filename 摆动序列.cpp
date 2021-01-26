#include<iostream>
#include<vector>

using namespace std;

/*
    摆动序列：
    若连续数字之间的差严格地在整数和负数之间进行交替，则数字序列就是摆动序列。少于两个元素的序列也是摆动序列
    [1, 7, 4, 9, 2, 5]是一个摆动序列，因为差值[6, -3, 5, -7, 3]是正负交替出现的

    给定一个整数序列，安徽作为摆动序列的最长子序列的长度，通过从原始序列中删除或者是不删除元素来获得子序列，剩下的
    元素保持原始顺序。
*/

int wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    // 若序列长度为1，则直接返回该长度
    if (len <= 1) {
        return len;
    }
    // 若序列中只有一种元素，那么就返回1即可
    if (count(nums.begin(), nums.end(), nums[0]) == len) {
        return 1;
    }
    int count = 0;
    // 在过程中的差值正负记录，2表示无状态
    int ResFlag = 2;
    // 差值正负的判断
    int Flag = 2;

    /*
        确定第一个差值的正负
    */
    if (nums[1] - nums[0] == 0) {  // 若是前两个元素相同
        count = 1;
    }
    else {
        ResFlag = nums[1] - nums[0] > 0 ? true : false;
        Flag = nums[1] - nums[0] > 0 ? true : false;
        count = 2;
    }

    /*
        开始对剩下的元素进行差值分析
    */
    for (int i = 2; i < nums.size(); ++i) {
        // 两个元素相同
        if (nums[i] - nums[i - 1] == 0) {
            continue;
        }
        nums[i] - nums[i - 1] > 0 ? Flag = 1: Flag = 0;
        // 若是没有摆动且没有
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