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

map<string, int>m;

void infest(string str1,string str2) {
    if (str1 == "ChongChong" || m[str1] == 1)
        m[str2] = 1;
    if (str2 == "ChongChong" || m[str2] == 1)
        m[str1] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str1, str2;
        cin >> str1 >> str2;
        m.insert({ str1, 0 });
        m.insert({ str2, 0 });
        if (m.find(str1) != m.end()) {
            infest(str1, str2);
        }    
        if (m.find(str2) != m.end()) {
            infest(str1, str2);
        }        
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}