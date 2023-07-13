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
	int n;
	cin >> n;
	int maxx = -10000, minx = 10000;
	int maxy = -10000, miny = 10000;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		maxx = max(maxx, a);
		minx = min(minx, a);
		maxy = max(maxy, b);
		miny = min(miny, b);
	}

	int area = (maxx - minx) * (maxy - miny);
	cout << area;
}