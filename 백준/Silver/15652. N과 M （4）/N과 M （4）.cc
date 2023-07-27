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

const int MAX = 9;

int n, m;
int arr[MAX] = { 0 };
int visited[MAX] = { 0 };

void dfs(int v,int idx) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
        return;
	}
	for (int i = idx; i <= n; i++) {
		arr[v] = i;
		dfs(v + 1, i); 
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> n >> m;
	dfs(0,1);

	return 0;
}