#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

vector<string> lst;
vector<string> generateParenthesis(int n) {
	backtrack(0, 0, n, "");
	return lst;
}

void backtrack(int left, int right, int n, string path) {
	if (left > n || left > right) return;
	if (left + right == 2 * n) {
		lst.push_back(path);
		return;
	}
	backtrack(left + 1, right, n, path + '(');
	backtrack(left, right + 1, n, path + ')');
}


int main() {

	return 0;

}