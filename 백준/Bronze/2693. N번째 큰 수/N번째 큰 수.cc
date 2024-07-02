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
#define INF 987654321

using namespace std;



int main() {
    int t;
    cin >> t;
    
    while(t--){
        int arr[10];
        for(int i=0;i<10;i++){
            cin>>arr[i];
        }
        sort(arr,arr+10);
        cout << arr[7] <<"\n";
    }

    return 0;
}

