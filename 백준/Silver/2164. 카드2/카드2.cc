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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int>q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size()!=1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}