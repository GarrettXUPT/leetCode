#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
	int len = nums.size();
	if (len <= 1) {
		return;
	}
	// �Ӻ���ǰ��,�ҵ��ǽ���������һ��Ԫ�� 5
	int i = len - 1;
	while (i > 0 && nums[i - 1] >= nums[i]) {
		i--;
	}
	// �������Ѿ�������ֵ���
	if (i == 0) {
		reverse(nums.begin(), nums.end());
		return;
	}
	// �Ӻ���ǰ�ң��ҵ������ϲ��ҵ�λ�õ�Ԫ�� 4
	int j = len - 1;
	while (j > 0 && nums[i - 1] >= nums[j]) {
		j--;
	}
	// ����������Ԫ��
	swap(nums[i - 1], nums[j]);
	// ��i - 1�����Ԫ�ؽ��з�ת
	reverse(nums.begin() + i, nums.end());
}

int main() {
	vector<int> vec{ 1, 5, 1};
	vector<int> vec1{ 3,2,1 };
	nextPermutation(vec);
	for (auto& ele : vec) {
		cout << ele << endl;
	}
}