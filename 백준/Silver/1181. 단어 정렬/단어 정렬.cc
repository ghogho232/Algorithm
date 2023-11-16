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
bool sort_dic(string& str1, string& str2){
    if(str1.length() != str2.length())
        return str1.length() < str2.length();
    return str1 < str2;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<string>s;
    vector<string> v;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    for(auto it = s.begin(); it != s.end(); it++){
        v.push_back(*it);
    }
    sort(v.begin(), v.end(), sort_dic);
    for(int i = 0; i < v.size(); i++){
        cout << v[i]<<"\n";
    }
}