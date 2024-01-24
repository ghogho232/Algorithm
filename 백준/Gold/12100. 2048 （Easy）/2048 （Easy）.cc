#define _CRT_SECURE_nO_WARnInGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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

int n, ans=0;

struct Board {
	int board[20][20];

	void rotate() {
		int tmp[20][20];
		memset(tmp, 0, sizeof(tmp));

		for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
			    tmp[i][j] = board[n - 1 - j][i];

		memcpy(board, tmp, sizeof(board));
	}

	void move() {

		queue<int> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0) 
                    q.push(board[i][j]);
				board[i][j] = 0;
			}

			int j = 0;

			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (board[i][j] == 0) 
                    board[i][j] = cur;
				else if (board[i][j] == cur) 
                    board[i][j++] *= 2;
				else board[i][++j] = cur;
			}
		}
	}

	void getMax() {
		for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
			    if (ans < board[i][j]) ans = board[i][j];
	}
};

void dfs(Board b,int cnt){
    if(cnt == 5){
        b.getMax();
        return;
    }
    for(int i = 0; i < 4; i++){
        Board nb = b;
        nb.move();
        dfs(nb, cnt+1);
        b.rotate();
    }
}

Board b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> b.board[i][j];
        }
    }
    dfs(b,0);
    cout << ans;
    return 0;
}