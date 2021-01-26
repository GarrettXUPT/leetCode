#include<iostream>
#include<vector>

using namespace std;

/*
	给定一个排序数组nums，和一个正整数n，在[1,n]区间内任意个数组补充道nums中，使得[1,n]中任何数字都可以由
	数组中数字的和来表示
*/

/*
	贪心算法：
	对于整数x，若是区间[1, x - 1]内所有的数字已经被覆盖，那么在x的数组中, [1, 2x - 1]内所有的数字也就被覆盖
	假如x缺失，则至少在数组中补充一个小于或者是等于x的数字，才能覆盖到x

	若是[1,x-1]的数字都已经被覆盖,那么直接补充x是补充数字最少的情况，在补充x之后[1, 2x - 1]的所有数字都已经被覆盖
	所以下一个补充的数字将不小于2x
	
	由此可得到一个贪心方案：
	每次寻找未被覆盖的最小整数x，补充x，再寻找下一个未被覆盖的最小整数，直至所有的[1, n]都被覆盖

	若index在数组nums的下标范围内且nums[index] <= x, 则将nums[index]的值加给x，并将index加一
		被覆盖的区间从[1, x - 1]扩招到了[1, x + nums[index] - 1], 被覆盖的x更新以后，被覆盖的区间就是[1, x - 1]
	若x没有被覆盖，因此需要补充x，然后将x乘以二
		补充x以后，将原本的[1, x - 1]区间扩展为[1, 2x - 1]区间, 对x进行更新以后，也就是[1, x - 1]

*/
int minPatches(vector<int>& nums, int n) {
	int patches = 0;
	long long x = 1;
	int length = nums.size(), index = 0;
	// 由x = 1 ... n
	while (x <= n) {
		// 若是下标还没到最后，且当前值还在该求和中
		if (index < length && nums[index] <= x) {
			x += nums[index];
			index++;
		}
		else  // 若是当前值不在该求和中，即为需要补充的数字
		{
			x = 2 * x;
			patches++;
		}
	}
	return patches;
}

int main() {
	vector<int> vec{ 1,5,10 };
	cout << minPatches(vec, 20) << endl;
	return 0;
}