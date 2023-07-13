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
    int a, b, v;
    cin >> a >> b >> v;
    cout << (v - b - 1) / (a - b) + 1;
    return 0;
}
