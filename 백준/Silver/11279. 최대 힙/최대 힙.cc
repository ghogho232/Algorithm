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
    priority_queue<int> pq;
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        if (a == 0) {
            if (pq.empty())
                cout << 0 << "\n";
            else { 
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(a);
    }
    return 0;
}