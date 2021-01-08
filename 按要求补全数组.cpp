#include<iostream>
#include<vector>

using namespace std;

int minPatches(vector<int>& nums, int n) {
	int patches = 0;
	long long x = 1;
	int length = nums.size(), index = 0;
	// ��x = 1 ... n
	while (x <= n) {
		// �����±껹û������ҵ�ǰֵ���ڸ������
		if (index < length && nums[index] <= x) {
			x += nums[index];
			index++;
		}
		else  // ���ǵ�ǰֵ���ڸ������
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