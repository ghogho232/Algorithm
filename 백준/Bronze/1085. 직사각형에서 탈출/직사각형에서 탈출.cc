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
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int ty = h - y;
	int by = y;
	int rx = w - x;
	int bx = x;
	int temp1 = min(ty, by);
	int temp2 = min(rx, bx);
	cout << min(temp1, temp2);
}