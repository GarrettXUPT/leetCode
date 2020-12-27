#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<list>
#include<map>

using namespace std;

string intToRoman(int x) {
    if (x < 1 || x >3999) return "";
    int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    string key[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
    int len = sizeof(values) / sizeof(values[0]);
    string str;
    for (int i = 0; i < len; i++) {
        while (x >= values[i]) {
            x -= values[i];
            str.append(key[i]);
        }
    }
    return str;
}

int romanToInt(string s) {

    int len = s.length();
    int number = 0;
        for (int i = 0; i < len; i++) {
            switch(s[i]){
                case 'M': 
                    number += 1000;
                    break;
                case 'D':
                    number += 500;
                    break;
                case 'C': 
                    if (i + 1 < len && (s[i + 1] == 'M' || s[i + 1] == 'D'))
                        number -= 100;
                    else
                        number += 100;
                    break;
                case 'L':
                    number += 50; 
                    break;
                case 'X': 
                    if (i + 1 < len && (s[i + 1] == 'C' || s[i + 1] == 'L'))
                        number -= 10;
                    else
                        number += 10;
                    break;
                case 'V':
                    number += 5; 
                    break;
                case 'I': 
                    if (i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                        number -= 1;
                    else
                        number += 1;
                    break;
            }
        }
        return number;
}



int main() {
	cout << intToRoman(1994) << endl;
    cout << romanToInt("MCMXCIV") << endl;
	return 0;
}
