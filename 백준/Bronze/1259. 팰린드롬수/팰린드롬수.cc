#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    while (true) {
        string str;
        cin >> str;
        bool flag = false;
        if (str == "0")
            break;
        for (int i = 0; i < (str.length() / 2); i++) {
            if (str[i] != str[str.length() - 1 - i]) {
                cout << "no" << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "yes" << "\n";
        }
    } 
    return 0;
}