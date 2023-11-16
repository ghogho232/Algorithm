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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true){
        int n, cnt = 0;
        bool flag=true;
        cin >> n;
        if(n == 0)
            break;
        string str = to_string(n);
        for(int i = 0; i < str.size()/2; i++){
            if(str[i] != str[str.size()-i-1]){
                cout << "no" <<"\n";
                flag = false;
                break;
            }
        }
        if(flag)
            cout <<"yes" <<"\n";

    }
    return 0;
}