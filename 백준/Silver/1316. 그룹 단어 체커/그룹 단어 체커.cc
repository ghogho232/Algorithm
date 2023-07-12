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

	int ans = 0;
	while (n--) {
		string str;
		cin >> str;	
		int arr[26] = { 0 };
		arr[str[0] - 'a'] = 1;
		bool flag = true;

		for (int i = 1; i < str.length(); i++) {
			if (str[i] == str[i - 1])
				continue;
			if (arr[str[i] - 'a'])
				flag = false;
			arr[str[i] - 'a'] = 1;
		}
		if (flag)
			ans++;
	}
	cout << ans;

	return 0;
}