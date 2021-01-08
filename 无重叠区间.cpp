#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
	̰���㷨
	
*/


int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int len = intervals.size();
	if (len < 2) {
		return 0;
	}
	// �ɸ������������С��������
	sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {return u[1] < v[1]; });

	// Ŀǰ�������ޣ�ȷ���� ���䲻�غϵ�����ͱ��������
	int right = intervals[0][1];
	int ret = 1;  // �����غϵ��������
	for (int i = 1; i < len; ++i) {
		if (intervals[i][0] >= right) {  // ���������䲻�غ�
			ret++;
			right = intervals[i][1];
		}
	}
	return len - ret;
}