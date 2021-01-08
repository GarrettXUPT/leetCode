#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
/*
	1���Ӹߵ��ͽ��п��ǣ�����һ���ؼ��ֽ��򣬵ڶ����ؼ��������������
	2������߶ȵ͵��˲����ǰ��������Ӱ�죬���Խ�����룬���θ�ÿ�����ڵ�ǰ�����У�ǰ��������k���˾ͺ�
*/
vector<vector<int> > reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end(), [](vector<int> v1, vector<int> v2) {
		return (v1[0] > v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
		});
	vector<vector<int>> ret;
	for (auto& ele : people) {
		ret.insert(ret.begin() + ele[1], ele);
	}
	return ret;

}