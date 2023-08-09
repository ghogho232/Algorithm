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
    string str;
    getline(cin, str);
    int ans = 0;
    string tmp = "";
    bool flag = 0;
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || i == str.length()) {
            if (flag) {
                ans -= stoi(tmp);
                tmp = "";
            }
            else {
                ans += stoi(tmp);
                tmp = "";
            }
        }
        else
            tmp += str[i];
        if (str[i] == '-')
            flag = 1;
    }
    cout << ans;
    return 0;
}