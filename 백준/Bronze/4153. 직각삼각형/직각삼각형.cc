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
    int a,b,c;
    int arr[4];
    while(1){
    cin >> arr[0] >> arr[1] >> arr[2];
    if(arr[0] ==0 && arr[1] == 0 && arr[2] == 0)
        break;
    sort(arr, arr+3);
    if(pow(arr[2],2) == pow(arr[1],2)+pow(arr[0],2))
        cout << "right\n";
    else
        cout << "wrong\n";
    }
    return 0;
}