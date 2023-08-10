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
    queue<int>q;
    stack<int>st;
    vector<int>v;
    int n, cur = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    while (!q.empty()) {
        if (q.front() == cur) {
            v.push_back(q.front());
            cur++;
            q.pop();
        }
        else if (!st.empty() && st.top() == cur) {
            v.push_back(st.top());
            st.pop();
            cur++;
        }
        else {
            st.push(q.front());
            q.pop();
        }
    }
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < v.size() - 1;i++) {
        if (v[i] > v[i + 1]) {
            cout << "Sad" << "\n";
            return 0;
        }
    }
    cout << "Nice" << "\n";
    return 0;
}