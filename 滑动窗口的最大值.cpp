#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

	auto begin = nums.begin();
	vector<int> retVec;
	int maxValue = *max_element(begin, begin + k);  // �ô�����ֵʱ����Ե�������ҿ�����
	retVec.push_back(maxValue);
	while (1) {
		auto endPos = begin + k;
		if (endPos == nums.end()) {
			break;
		}
		if (maxValue == *begin) {
			begin++; endPos++;
			maxValue = *max_element(begin, endPos);   // �ô�����ֵʱ����Ե�������ҿ�����
		}
		else if(maxValue < *endPos)
		{
			maxValue = *endPos;
			begin++;
		}
		else
		{
			begin++;
		}
		retVec.push_back(maxValue);
	}
	return retVec;
}

vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
	if (nums.empty() || k > nums.size() || k <= 0) {
		return {};
	}

	vector<int> res;
	deque<int> findMax;

	for (int i = 0; i < nums.size(); ++i) {
		// i ÿ��һ�Σ�����������������һ����λ��
		// i ָ�����ÿ���������ڵ�β��Ԫ�أ��� i = k - 1 ��ʼ����

		if (i >= k && !findMax.empty()) {
			// i >= k ��Ϊ��ȷ�� findMax.front() ����Ϊ��һ�������Ļ������ڵ����ֵ������
			// �������γ���һ�������Ļ������ڡ�
			res.push_back(nums[findMax.front()]);
		}

		while (!findMax.empty() && nums[i] >= nums[findMax.back()]) {
			// ����½����� nums[i] ���ڵ��ڻ������ڵ�β��Ԫ�أ�
			// ˵����β��Ԫ�ؿ϶��������κλ������ڵ����Ԫ�ء�
			// ������˾������һ���ȱ��������ֱ����ܸɣ����ڵ����㣩���ˣ������ֻ�ܱ���̭�ˣ�
			// ������ѭ����̭�����в�����Ա������Ա����
			findMax.pop_back();
		}

		if (!findMax.empty() && i - findMax.front() >= k) {
			// ��Ȼ findMax ��ͷ��������Ԫ�ص����������������ǰ���������Ѳ�������������
			// ��ô��Ҫ������������
			// ������ʹ�ǹ�˾�ĹǸɳ�Ա�����ǹ���35��ҲҪ����̭��
			findMax.pop_front();
		}

		findMax.push_back(i);
	}

	res.push_back(nums[findMax.front()]); // ���һ���������ڻ�û������˳��� for ѭ�����貹�ϡ�

	return res;
}


int main() {
	vector<int> vec{ 1,3,-1,-3,5,3,6,7 };
	auto res = maxSlidingWindow1(vec, 3);
	for (auto& ele : res){
		cout << ele << "	";
	}
	cout << endl;
	return 0;
}