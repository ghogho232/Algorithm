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

    int n;
    int arr[21] = { 0 };
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "add"){
            int x;
            cin >> x;
            arr[x] = 1;
        }
        else if(str == "remove"){
            int x;
            cin >> x;
            arr[x] = 0;
        }
        else if(str == "check"){
            int x; 
            cin >> x;
            if(arr[x] == 1)
                cout << 1 <<"\n";
            else
                cout << 0 <<"\n";
        }
        else if(str == "toggle"){
            int x;
            cin >> x;
            if(arr[x] == 1)
                arr[x] = 0;
            else
                arr[x] = 1;
        }
        else if(str == "all"){
            for(int i = 1; i <= 20; i++){
                arr[i] = 1;
            }
        }
        else if(str == "empty"){
            for(int i = 1; i <= 20; i++){
                arr[i] = 0;
            }       
        }
    }
    return 0;
}