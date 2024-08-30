#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
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
#define INF 987654321

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<int, vector<int>, less<int>> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    cin >> n;
    int a;
    cin >> a;
    maxpq.push(a);
    cout << a <<"\n";
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        if(maxpq.size() > minpq.size()){
            minpq.push(a);
        }
        else{
            maxpq.push(a);
        }

        if(minpq.top() < maxpq.top()){
            int maxtop = maxpq.top();
            int mintop = minpq.top();
            maxpq.pop();
            minpq.pop();
            maxpq.push(mintop);
            minpq.push(maxtop);
        }
        cout << maxpq.top()<<"\n";
    }
    return 0;
}