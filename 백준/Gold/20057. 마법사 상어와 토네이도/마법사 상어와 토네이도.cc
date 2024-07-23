#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 506
#define INF 2e9

using namespace std;
int N;
int MAP[MAX][MAX];
pair<int, int> Start;
int moveY[4] = { 0,1,0,-1 };
int moveX[4] = { -1,0,1,0 };

int spreadY[4][10] = { { -1,1,-1,1,-1,1,-2,2,0,0 }, 
					   { 0,0,1,1,2,2,1,1,3,2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 },
					   { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 } };
int spreadX[4][10] = { { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 },
					   { 0,0,1,1,2,2,1,1,3,2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 } };
int Sand_Percent[9] = { 1,1,7,7,10,10,2,2,5 };
int moveLen = 1;
int Direction = 0;
int Dir_Change = 0; 
int answer = 0;

void Sand_Spread(int Y, int X, int YY, int XX, int Sand, int Dir) {
	int tmp = Sand;
	for (int i = 0; i < 9; i++) { 
		int nextY = Y + spreadY[Dir][i];
		int nextX = X + spreadX[Dir][i];
		int Per = Sand_Percent[i];
		int Sand_Part = (tmp * Per) / 100;

		if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
			answer += Sand_Part;
		}
		else {
			MAP[nextY][nextX] += Sand_Part;
		}
		Sand -= Sand_Part;

	}
	int nextY = Y + spreadY[Dir][9];
	int nextX = X + spreadX[Dir][9];
	if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
		answer += Sand;
	}
	else {
		MAP[nextY][nextX] += Sand;
	}
	MAP[YY][XX] = 0; 
}

void Tornado(int Y, int X, int Dir, int Len) {
	int CurY = Y;
	int CurX = X;
	for (int l = 0; l < Len; l++) {

		int nextY = CurY + moveY[Dir];
		int nextX = CurX + moveX[Dir];
		if (MAP[nextY][nextX] > 0) { 
			int Sand = MAP[nextY][nextX];
			Sand_Spread(CurY, CurX, nextY, nextX, Sand, Dir);
		}
		CurY = nextY;
		CurX = nextX;
	}

	Start = make_pair(CurY, CurX);
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	Start = make_pair(N / 2, N / 2);
	while (1) {

		Tornado(Start.first, Start.second, Direction, moveLen);

		Direction++; 
		if (Direction == 4) {
			Direction = 0;
		}

		Dir_Change++;
		if (Dir_Change == 2) {
			Dir_Change = 0;
			moveLen++;
		}

		if (moveLen == N) {
			Tornado(Start.first, Start.second, Direction, moveLen);
			break;
		}
	};

	cout << answer << "\n";

	return 0;
}