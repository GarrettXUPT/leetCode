#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<list>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> vis(26), num(26);
    for (char ch : s) {
        num[ch - 'a']++;
    }

    string stk;
    for (char ch : s) {
        if (!vis[ch - 'a']) {
            while (!stk.empty() && stk.back() > ch) {
                if (num[stk.back() - 'a'] > 0) {
                    vis[stk.back() - 'a'] = 0;  // 并将其标记为不在栈中
                    stk.pop_back();  // 弹出栈顶元素
                }
                else {
                    break;
                }
            }  // 将当前字符标记为在栈中
            vis[ch - 'a'] = 1;
            stk.push_back(ch);
        }
        num[ch - 'a'] -= 1;
    }
    return stk;
}


int main() {
    cout << removeDuplicateLetters("cbcdcbca") << endl;
	return 0;
}