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

using namespace std;

int n, m;
vector<pair<int,int>>chicken, home;
vector<int> closed;
int mincitydist = 987654321;
void solve(){
    int citydist = 0;
    for(int i = 0; i < home.size(); i++){
        int mindist = 2501;
        for(int j = 0; j < chicken.size(); j++){
            if(closed[j] == 1){
                int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
                mindist = min(dist, mindist);
            }
        }
        citydist += mindist;
    }
    mincitydist = min(citydist, mincitydist);
    
}

void select(){
    for(int i = 0; i < chicken.size()-m; i++){
        closed.push_back(0);
    }
    for(int i = 0; i < m; i++){
        closed.push_back(1);
    }
    do{
        solve();
    }while(next_permutation(closed.begin(), closed.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            if(a == 2)
                chicken.push_back({i,j});
            else if(a == 1)
                home.push_back({i,j});
        }
    }
    select();
    cout << mincitydist;
    return 0;
}