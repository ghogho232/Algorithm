#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int a, b;
	int cnt = 0;
	cin >> a >> b;
	if (b < 45) {
		if (a == 0) {
			a = 23;
		}
		else 
			a = a - 1;
		
		int nb = b + 15;

		
		cout << a << " " << nb;
	}
	else if(b>=45)
		cout << a << " " << b - 45;
}
