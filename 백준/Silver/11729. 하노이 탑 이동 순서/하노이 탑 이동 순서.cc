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

void hanoi(int n, int from, int to) {
	if (n == 0)
		return;
	hanoi(n - 1, from, 6 - from - to);
	cout << from << " " << to<<"\n";
	hanoi(n - 1, 6 - from - to, to);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	cin >> n;
	int cnt = pow(2,n) - 1;
	cout << cnt << "\n";
	hanoi(n, 1, 3);

	return 0;
}