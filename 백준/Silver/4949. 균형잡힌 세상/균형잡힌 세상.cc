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

bool vps(string str) {
    stack<char> st;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        else if (str[i] == ')') {
            if (st.empty() || st.top() == '[') {
                return false;
            }
            else if(st.top() == '(')
                st.pop();
        }
        else if (str[i] == ']') {
            if (st.empty() || st.top() == '(') {
                return false;
            }
            else if(st.top() == '[')
                st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string str;
        getline(cin, str);
        if (str == ".")
            break;
        if (vps(str))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
