#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int distance(int dst, int src) {
	return abs(dst - src);
}


int threeSum(vector<int>& nums, int target) {
	if (nums.size() < 3) {
		return EXIT_FAILURE;
	}
	// ������С����
	sort(nums.begin(), nums.end());
	int minDistan = 9999;
	int begin = 0;
	int len = nums.size();
	int res = 0;
	// �̶�һ������ʣ��������ʹ��˫ָ�����Ѱ��
	for (int i = 0; i < len; ++i) {
		// ˫ָ������
		begin = i + 1;
		int end = len - 1;
		// �������еĿ�����
		while (begin < end) {
			// ����������
			int tmp = nums[i] + nums[begin] + nums[end];
			if (tmp == target) {
				return target;
			}
			// ������target����ĩβָ��ǰ�ƣ�Ѱ��һ���ȵ�ǰ��С������
			else if (tmp > target) {
				int dis = distance(target, tmp);
				if (dis < minDistan) {
					minDistan = dis;
					res = tmp;
				}
				end--;
			}
			// ��С��target����ʼָ����ƣ�Ѱ��һ���ȵ�ǰ��������� 
			else if (tmp < target) {
				int dis = distance(target, tmp);
				if (dis < minDistan) {
					minDistan = dis;
					res = tmp;
				}
				begin++;
			}
		}
	}
	return res;
}

int main() {
	vector<int> vec{-1,0,1,1,55 };
	auto res = threeSum(vec, 3);
	cout << res << endl;
	cout << distance(-100, 2) << endl;
	cout << distance(-100, 3) << endl;

	return 0;
}