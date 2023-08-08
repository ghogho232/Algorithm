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

using namespace std;

const int INF = 1e9;

int minimal_board(vector<string>& board, char color, int N, int M, int K) {
    vector<vector<int>> prefix_sum(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int value;
            if ((i + j) % 2 == 0) {
                value = (board[i][j] != color);
            }
            else {
                value = (board[i][j] == color);
            }
            prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + value;
        }
    }

    int count = INF;
    for (int i = 1; i <= N - K + 1; i++) {
        for (int j = 1; j <= M - K + 1; j++) {
            count = min(count, prefix_sum[i + K - 1][j + K - 1] - prefix_sum[i + K - 1][j - 1] - prefix_sum[i - 1][j + K - 1] + prefix_sum[i - 1][j - 1]);
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    cout << min(minimal_board(board, 'B', N, M, K), minimal_board(board, 'W', N, M, K));

    return 0;
}