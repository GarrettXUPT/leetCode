#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
/*
	1、从高到低进行考虑，按第一个关键字降序，第二个关键字升序进行排列
	2、后面高度低的人不会对前面的人造成影响，所以将其插入，依次给每个人在当前队列中，前面正好有k个人就好
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