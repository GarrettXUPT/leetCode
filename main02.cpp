#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
	vector<vector<int> > resVec;
	if (nums.size() < 3) {
		return resVec;
	}
	// ������С����
	sort(nums.begin(), nums.end());
	int begin = 0;
	int len = nums.size();
	// �̶�һ������ʣ��������ʹ��˫ָ�����Ѱ��
	for (int i = 0; i < len; ++i) {
		// ����ǰ���ִ���0�����������ֲ�����С��0�����Բ����ܳ��ֺ��ʵĽ�
		if (nums[i] > 0) {
			return resVec;
		}
		// �����ظ���
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		// ˫ָ������
		begin = i + 1;
		int end = len - 1;
		// �������еĿ�����
		while (begin < end) {
			// ����������
			if (nums[i] + nums[begin] + nums[end] == 0) {
				resVec.push_back(vector<int>{nums[i], nums[begin], nums[end]});
				// ��ʼָ�����ظ�����
				while ((begin < end) && (nums[begin] == nums[begin + 1]))
				{
					begin++;
				}
				// ��βָ�����ظ�����
				while ((begin < end) && (nums[end] == nums[end - 1])) {
					end--;
				}
				// ��ʼָ����ƣ���βָ�����
				begin++;
				end--;
			}
			// ������0����ĩβָ��ǰ�ƣ�Ѱ��һ���ȵ�ǰ��С������
			else if (nums[i] + nums[begin] + nums[end] > 0) {
				end--;
			}
			// ��С��0����ʼָ����ƣ�Ѱ��һ���ȵ�ǰ��������� 
			else if (nums[i] + nums[begin] + nums[end] < 0) {
				begin++;
			}
		}

	}
	return resVec;
}

int main() {
	vector<int> vec{ -1, 0, 1, 2, -1, -4 };
	auto res = threeSum(vec);
	for (auto& ele : res) {
		for (auto& elem : ele) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}