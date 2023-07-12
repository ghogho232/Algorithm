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
	string n;
	int b;
	int ans = 0;
	
	cin >> n >> b;

	for (int i = 0; i < n.length(); i++) {
		if ('0' <= n[i] && n[i] <= '9')
			ans = ans * b + (n[i] - '0');
		else
			ans = ans * b + (n[i] - 'A' + 10);
	}

	cout << ans;
	return 0;
}