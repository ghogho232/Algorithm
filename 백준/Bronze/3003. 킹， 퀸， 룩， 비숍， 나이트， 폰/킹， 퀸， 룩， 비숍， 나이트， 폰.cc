#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

int main() {
    int arr[6] = { 1,1,2,2,2,8 };
    
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n;
        if (n == arr[i])
            arr[i] = 0;
        else 
            arr[i] = arr[i] - n;
    }
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}