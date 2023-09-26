#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
    cin.tie(0);
    cout.tie(0);
    stack<char> s;
    string str;
    string ans = "";
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(isalpha(str[i]))
            ans += str[i];
        else if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == '*' || str[i] == '/'){
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if(str[i] == '+' || str[i] == '-'){
            while(!s.empty() && s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans;
    return 0;
}
