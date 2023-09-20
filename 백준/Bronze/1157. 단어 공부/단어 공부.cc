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
    string str;
    int arr[27] = {0};
    int m = 0;
    string ans;
    int check = 0;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 'a' + 'A';
        arr[str[i] - 'A']++;
    }

    for(int i = 0; i <= 26; i++){
        if(m < arr[i]){
        m = arr[i];
        ans = 'A' + i;            
        }

    }
    for(int i = 0; i <= 26; i++){

        if(m == arr[i]) 
            check++;
    }
    if(check == 1)
        cout << ans <<"\n";        
    else    
        cout << "?";

    return 0;
}