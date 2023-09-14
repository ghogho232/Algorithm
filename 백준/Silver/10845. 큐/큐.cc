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
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    queue<int>q;
    while(n--){
        string str;
        cin >> str;
        if(str == "push"){
            int a;
            cin >> a;
            q.push(a);
        }
        else if(str == "pop"){
            if(q.empty())
                cout << "-1\n";
            else{
                cout << q.front() <<"\n";
                q.pop();
            }
        }
        else if(str == "size"){
            cout << q.size()<<"\n";
        }
        else if(str == "empty"){
            if(q.empty())
                cout << 1 <<"\n";
            else
                cout << 0 <<"\n";
        }
        else if(str == "front"){
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.front()<<"\n";
        }
        else if(str == "back"){
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.back()<<"\n";
        }
    }
    return 0;
}