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

int T;
int arr[15][15];

int main() {
    cin >> T;

    //초기화
    for(int i=0;i<15;i++) 
        arr[0][i]=i;

    //바로 아래층 계산
    for(int i=1;i<15;i++)
        for(int j=1;j<15;j++)
            for(int k=1;k<=j;k++)
                arr[i][j]+=arr[i-1][k]; 

    while(T--) {
        int K, N;
        cin >> K >> N;
        cout <<arr[K][N]<< "\n"; //결과 출력
    }
}