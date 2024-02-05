#define _CRT_SECURE_nO_WARnInGS
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

map<string,int> mp;

bool cmp(const pair<string,int> &a, const pair<string,int> &b){
    if(a.second == b.second){
		if(a.first.size() == b.first.size()){
			return a.first < b.first;
		}
		return a.first.size() > b.first.size();
	}
        
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        if(str.size() < m)
            continue;
        if(mp.find(str) != mp.end()){
            auto it = mp.find(str);
            it->second++;
        }
        else 
            mp.insert({str,1});
    }
	
    vector<pair<string, int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), cmp);

    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << it->first << "\n";
    }
    
    return 0;
}