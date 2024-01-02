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
#define MAX INT_MAX
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>>v;
    for(int i = 0; i < n; i++){
        int begin, end;
        cin >> begin >> end;
        v.push_back({begin,end});
    }
    sort(v.begin(),v.end());
    int begin = v[0].first;
    int end = v[0].second;
    int len = 0;
    for(int i = 1; i < n; i++){
        int from = v[i].first;
        int to = v[i].second;
        if(from < end){
            if(to > end)
                end = to;
        }
        else{
            len += end - begin;
            begin = from;
            end = to;
        }
    }
    len += end - begin;
    cout << len;
    return 0;
}