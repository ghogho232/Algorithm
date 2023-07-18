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

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    set<string>s;
    string ans = "";
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            ans += str[j];
            s.insert(ans);
        }
        ans = "";
    }
    cout << s.size();
    return 0;
}