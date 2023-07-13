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
	int a1, a2, c, n;
	cin >> a1 >> a2 >> c >> n;
	if (a1 * n + a2 <= c * n && a1 <= c)
		cout << 1;
	else cout << 0;
}