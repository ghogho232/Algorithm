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

vector<char>v;

bool check(int a){
    string s = to_string(a);
    for(int i = 0; i < s.size(); i++){
        if(find(v.begin(), v.end(), s[i]) != v.end())
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        char a;
        cin >> a;
        v.push_back(a);
    }
    if(n == 100){
        cout << 0;
        return 0;    
    }
    int Min = abs(n - 100);
    string str = to_string(n);

    for(int i = 0; i < 1000001; i++){
        if(check(i)){
            int cur = to_string(i).length() + abs(i - n);
            if(Min > cur) 
                Min = cur;
        }
    }
    cout << Min;
    return 0;
}