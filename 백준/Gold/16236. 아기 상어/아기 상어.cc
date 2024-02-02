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

int n;
int arr[21][21];
int dist[21][21];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int ans = 0;

struct Shark{
	int x,y,size,cnt;
};
Shark shark;

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

void trip(){
	while(true){
		int minX = 20;
		int minY = 20;
		int minDist = 400;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){ //해당 위치까지 거리 초기화
				dist[i][j] = -1;
			}
		}
		dist[shark.x][shark.y] = 0;

		queue<pair<int,int>> q;
		q.push({shark.x,shark.y});

		while(!q.empty()){ //bfs
			vector<pair<int,int>>edible;
			int qsize = q.size(); //현재 사이즈만큼만 탐색
			for(int i = 0; i < qsize; i++){
				auto cur = q.front();
				q.pop();
				
				for(int i = 0; i < 4; i++){
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] > shark.size || dist[nx][ny] != -1) //dist로 방문여부 체크
						continue;
					dist[nx][ny] = dist[cur.first][cur.second] + 1; //거리 증가
					q.push({nx,ny});

					if(arr[nx][ny] != 0 && arr[nx][ny] < shark.size){ //현재보다 크기 작으면 먹을 수 있는 걸로 저장
						edible.push_back({nx,ny});
					}
				}
			}
			if(edible.size() != 0){//먹을 게 있으면
				if(edible.size() != 1){//같은 거리의 먹을 게 여러개면
					sort(edible.begin(), edible.end(), cmp); //정렬
				}
				minX = edible[0].first; //먹을 거 정하기
				minY = edible[0].second;
				minDist = dist[minX][minY];
				break;
			}
		}
		if(minDist == 400) //더 먹을게 없다면 종료
			break;
		//먹기
		shark.x = minX; //상어 해당 위치로 이동
		shark.y = minY;
		arr[minX][minY] = 0;		
		shark.cnt++; //먹은 물고기++

		if(shark.cnt == shark.size){ //먹은 물고기와 사이즈 같으면
			shark.cnt = 0; //먹은 물고기 초기화
			shark.size++; //사이즈++
		}
		
		ans += minDist; //이동한 거리만큼 시간 추가
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 9){ //상어 초기 설정
				shark.x = i;
				shark.y = j;
				shark.size = 2;
				shark.cnt = 0;
				arr[i][j] = 0;
			}
		}
	}
	trip();
	cout << ans;

	return 0;
}