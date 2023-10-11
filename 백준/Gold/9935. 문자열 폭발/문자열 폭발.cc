#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, bomb;
    cin >> str >> bomb;
    int str_len = str.length();
    int bomb_len = bomb.length();
    int len = 0;
    stack<pair<char, int>> S;

    for (int i = 0; i < str_len; i++) {
        if (str[i] == bomb[len])
            len++;
        else if (str[i] == bomb[0])
            len = 1;
        else
            len = 0;

        S.push({str[i], len});

        if (len == bomb_len) {
            for (int j = 0; j < bomb_len; j++)
                S.pop();

            if (!S.empty())
                len = S.top().second;
            else
                len = 0;
        }
    }

    int stack_sz = S.size();
    if (stack_sz == 0) {
        cout << "FRULA";
        return 0;
    }

    string result(stack_sz, ' ');
    for (int i = stack_sz - 1; i >= 0; i--) {
        result[i] = S.top().first;
        S.pop();
    }

    cout << result;
    return 0;
}