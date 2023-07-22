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
    stack<int>st;
    int n;
    cin >> n;
    vector<int>v(n);
    vector<char> ch;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int idx = 0;

    for (int i = 1; i <= n; i++) {
        st.push(i);
        ch.push_back('+');
        while (!st.empty() && st.top() == v[idx]) {
            st.pop();
            ch.push_back('-');
            idx++;
        } 
    }        
    if (!st.empty())
        cout << "NO" << "\n";
    else {
        for (auto it = ch.begin(); it < ch.end(); it++) {
            cout << *it << "\n";
        }
    }
    return 0;
}
