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
        int n, ans = 1;
        string name, kind;
        map<string, int> m;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> name >> kind;
            if(m.find(kind) == m.end()){
                m.insert({kind, 1});
            }
            else
                m[kind]++;
        }
        for(auto it : m){
            ans *= (it.second + 1);
        }
        cout << ans -1 <<"\n";
    }
    return 0;
}