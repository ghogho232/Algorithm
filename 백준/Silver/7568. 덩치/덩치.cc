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

    vector<pair<int, int>>v;
    int n, rank = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                rank++;
            }            
        }
        cout << rank <<" ";
        rank = 1;
    }
    return 0;
}