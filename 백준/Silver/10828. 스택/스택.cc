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

    int n;
    cin >> n;
    stack<int>s;
    while (n--) {
        string str;
        cin >> str;
        if (str == "push") {
            int a;
            cin >> a;
            s.push(a);
        }
        else if (str == "pop") {
            if (!s.size()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (str == "size") {
            cout << s.size()<<"\n";
        }
        else if (str == "empty") {
            if (s.empty())
                cout << 1<<"\n";
            else
                cout << 0<<"\n";
        }
        else if (str == "top") {
            if (!s.size()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
            }
        }
    }
    return 0;
}

