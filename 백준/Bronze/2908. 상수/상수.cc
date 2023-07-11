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
	string a, b;
	string aa, bb;
	cin >> a >> b;

	for (int i = 2; i >=0 ; i--) {
		aa += a[i];
		bb += b[i];
	}
	cout << max(aa, bb);

	return 0;
}