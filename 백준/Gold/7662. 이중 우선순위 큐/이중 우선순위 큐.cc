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
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        priority_queue<int> xq;
        priority_queue<int, vector<int>, greater<int>> nq;
        map<int, int> m;
        for(int i = 0; i < k; i++){
            string str;
            cin >> str;
            if(str == "I"){
                int a;
                cin >> a;
                xq.push(a);
                nq.push(a);
                if(m.find(a) != m.end()){
                    m[a]++;
                }
                else
                    m[a] = 1;
            }

            else if(str == "D"){
                int a;
                cin >>a;
                if(a == 1){
                    while(!xq.empty() && m[xq.top()] == 0)
                        xq.pop();
                    if(!xq.empty()){
                        m[xq.top()]--;
                        xq.pop();
                    }
                }
                else if(a == -1){
                    while(!nq.empty() && m[nq.top()] == 0)
                        nq.pop();
                    if(!nq.empty()){
                        m[nq.top()]--;
                        nq.pop();
                    }
                }
            }
        }
        while(!xq.empty() && m[xq.top()] == 0) xq.pop();
        while(!nq.empty() && m[nq.top()] == 0) nq.pop();

        if(xq.empty()||nq.empty())
            cout << "EMPTY\n";
        else
            cout << xq.top() <<" "<< nq.top() <<"\n";
        
    }
    return 0;
}