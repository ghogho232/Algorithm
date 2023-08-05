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
    int n;
    int sum[2001][27] = { 0 };
    cin >> str >> n;
    for (int i = 0; i < str.length(); i++) {
        if (i != 0) {
            for (int j = 0; j < 26; j++) {
                sum[i][j] = sum[i-1][j];
            }
        }            
        sum[i][str[i] - 'a']++;
    }
    while (n--) {
        char ch;
        int from, to;
        cin >> ch >> from >> to;
        int num = ch - 'a';
        int from2 = from > 0 ? sum[from - 1][num] : 0;
        cout << sum[to][num] - from2<<"\n";
    }
    return 0;
}