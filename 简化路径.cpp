#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string simplifyPath(string path) {
    stringstream is(path);
    vector<string> strs;
    string res = "", tmp = "";
    while (getline(is, tmp, '/')) { // ʹ��/��־��is stringstream�ָtmp
        if (tmp == "" || tmp == ".")
            continue;
        else if (tmp == ".." && !strs.empty())
            strs.pop_back();
        else if (tmp != "..")
            strs.push_back(tmp);
    }
    for (string str : strs)
        res += "/" + str;
    if (res.empty())
        return "/";
    return res;
}

