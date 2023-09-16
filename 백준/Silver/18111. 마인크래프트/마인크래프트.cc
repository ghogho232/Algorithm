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
    int n, m, b;
    int time = 1e9, height = 0;
    int maxh = -1, minh = 257;  
    int arr[501][501];
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] > maxh)
                maxh = arr[i][j];
            if(arr[i][j] < minh)
                minh = arr[i][j];
        }
    }
    for(int k = minh; k <= maxh; k++){
        int add = 0, minus = 0;
        int temp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int blck = k-arr[i][j];
                if(blck < 0)
                    minus -= blck;
                else
                    add += blck;
            }
        }
        if(add <= minus + b){
            temp = add + 2*minus;
            if(temp <= time){
                time = temp;
                height = k;
            }
        }
    }
    cout << time <<" "<< height;

    return 0;
}