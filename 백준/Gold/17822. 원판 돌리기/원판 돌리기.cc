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
#define MAX 51

using namespace std;


int N, M, T;
int MAP[MAX][MAX];
bool Will_Erase[MAX][MAX];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Will_Erase[i][j] = false;
		}
	}
}

void Rotation(int X, int D, int K) {
	for (int i = X; i <= N; i += X) {
		if (D == 0) {
			int tmp[MAX];
			for (int j = 1; j <= M; j++) {
				tmp[j] = MAP[i][j];
			}
			for (int j = 1; j <= (M - K); j++) {
				MAP[i][j + K] = tmp[j];
			}
			for (int j = (M - K + 1); j <= M; j++) {
				MAP[i][j - (M - K)] = tmp[j];
			}
		}
		else if (D == 1) {
			int tmp[MAX];
			for (int j = 1; j <= M; j++) {
				tmp[j] = MAP[i][j];
			}
			for (int j = 1; j <= K; j++) {
				MAP[i][j + (M - K)] = tmp[j];
			}
			for (int j = K + 1; j <= M; j++) {
				MAP[i][j - K] = tmp[j];
			}
		}
	}
}

void Erase_Number() {
	init();
	bool Same_Number = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 0) {
				continue;
			}
			int Left = j - 1;
			int Right = j + 1;
			int Top = i + 1;
			int Bottom = i - 1;
			if (Left == 0) {
				Left = M;
			}
			if (Right == M + 1) {
				Right = 1;
			}
			bool Flag = false;
			if (MAP[i][j] == MAP[i][Left]) {
				Flag = true;
				Will_Erase[i][Left] = true; 
			}
			if (MAP[i][j] == MAP[i][Right]) {
				Flag = true;
				Will_Erase[i][Right] = true;
			}
			if (MAP[i][j] == MAP[Top][j]) {
				if (i < N) {
					Flag = true;
					Will_Erase[Top][j] = true;
				}
			}
			if (MAP[i][j] == MAP[Bottom][j]) {
				if (i > 1) {
					Flag = true;
					Will_Erase[Bottom][j] = true;
				}
			}
			if (Flag) {
				Will_Erase[i][j] = true;
				Same_Number = true;
			}
		}
	}
	if (Same_Number) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (Will_Erase[i][j]) {
					MAP[i][j] = 0;
				}
			}
		}
	}
	else {
		int sum = 0;
		int size = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (MAP[i][j] > 0) {
					sum += MAP[i][j];
					size++;
				}
			}
		}

		double avg = (double)sum / (double)size;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (MAP[i][j] > 0) {
					if (avg > (double)MAP[i][j]) {
						MAP[i][j]++;
					}
					else if (avg < (double)MAP[i][j]) {
						MAP[i][j]--;
					}
				}
			}
		}
	}
}

int Calc_Sum() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res += MAP[i][j];
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL); 
	ios::sync_with_stdio(false);
		cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int X, D, K;
		cin >> X >> D >> K;
		Rotation(X, D, K);
		Erase_Number();
	}
	cout << Calc_Sum() << "\n";

	return 0;
}