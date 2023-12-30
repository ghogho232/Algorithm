#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	int zero = 0, one = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[i + 1]) {
			if (str[i] == '0') {
				zero++;
			}
			else
				one++;
		}
	}
	cout << min(zero, one);

	return 0;
}