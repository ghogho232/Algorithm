#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int students, rooms, ans = 0;
	cin >> students >> rooms;
	int arr[2][7] = { 0 };
	for (int i = 0; i < students; i++) {
		int sex, grade;
		cin >> sex >> grade;
		arr[sex][grade]++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			if (arr[i][j] != 0) {
				ans += arr[i][j] / rooms;
				if (arr[i][j] % rooms != 0)
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}