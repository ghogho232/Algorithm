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
    vector<int>v;
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < k-1; i++) {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for (auto it = v.begin(); it != v.end()-1; it++) {
        cout << * it << ", " ;
    }
    cout << v.back() << ">";

    return 0;
}
