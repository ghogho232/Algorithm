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

using namespace std;

void star(int i,int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (n / 3 == 0)
			cout << '*';
		else
			star(i, j, n/3);
	}

}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << "\n";
	}
}