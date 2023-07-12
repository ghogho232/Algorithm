#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < str.length()-1 / 2; i++) {
        if (str[i] == str[str.length() - 1 - i])
            cnt++;
    }
    if (cnt == str.length() - 1 / 2)
        cout << 1;
    else
        cout << 0;
}