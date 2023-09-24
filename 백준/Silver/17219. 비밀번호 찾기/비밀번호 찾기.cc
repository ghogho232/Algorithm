#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
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
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, string> pwd;
    for(int i = 0; i < n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        pwd.insert({str1, str2});
    }
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        cout << pwd[str] <<"\n";
    }
    return 0;
}