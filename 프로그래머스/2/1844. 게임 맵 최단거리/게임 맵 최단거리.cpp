#include<vector>
#include<queue>

using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int visited[101][101];
int cnt = 1;
bool flag = false;

int bfs(int x, int y, int n, int m, vector<vector<int>>& maps) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        if (curx == n - 1 && cury == m - 1) {
            return visited[curx][cury]; 
        }

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maps[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = visited[curx][cury] + 1;  // 거리 누적
            }
        }
    }
    return -1;  
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int m = maps[0].size();
    int n = maps.size();
    
    answer = bfs(0,0,n,m,maps);
    return answer;
}