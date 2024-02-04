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

int r,c,k;
int arr[101][101];
int cnt[101] = {0}; //나오는 숫자 비트마스킹

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> k;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	int row = 3; //초기값
	int col = 3;

	while(1){
		if(arr[r][c] == k){ //종료조건
			cout << ans;
			break;
		}
		if(ans > 100){
			cout << -1;
			break;
		}
		vector<int>sizeCheck; //행,열의 최대 사이즈 구하기

		if(row >= col){ //r연산
			for(int i = 1; i <= row; i++){
				vector<pair<int,int>>tmp;
				memset(cnt,0,sizeof(cnt));
				for(int j = 1; j <= col; j++){ //행에 존재하는 숫자와 그 갯수 세기
					cnt[arr[i][j]]++;
				}
				for(int j = 1; j < 101; j++){ //배열 돌면서 숫자, 갯수 임시 벡터에 저장
					if(cnt[j] == 0)
						continue;
					tmp.push_back({cnt[j],j});
				}
				sort(tmp.begin(),tmp.end()); //임시벡터 정렬 
				for(int j = 1; j <= col; j++){ //입력할 행의 값 초기화
					arr[i][j] = 0;
				}
				int idx = 1; //1부터 시작했으니 인덱스 설정
				for(int j = 0; j < tmp.size(); j++){
					arr[i][idx++] = tmp[j].second;
					arr[i][idx++] = tmp[j].first;
				}
				idx--; //1부터 시작했으니 사이즈 저장위해 1--
				sizeCheck.push_back(idx); //사이즈 저장
			}
			sort(sizeCheck.begin(),sizeCheck.end()); //정렬
			col = sizeCheck.back(); //가장 큰게 열 사이즈
		}
		else{ //c연산 = 행 열 반대로 연산
			for(int i = 1; i <= col; i++){
				vector<pair<int,int>>tmp;
				memset(cnt,0,sizeof(cnt));
				for(int j = 1; j <= row; j++){
					cnt[arr[j][i]]++;
				}
				for(int j = 1; j < 101; j++){
					if(cnt[j] == 0)
						continue;
					tmp.push_back({cnt[j],j});
				}
				sort(tmp.begin(),tmp.end());
				for(int j = 1; j <= row; j++){
					arr[j][i] = 0;
				}
				int idx = 1;
				for(int j = 0; j < tmp.size(); j++){
					arr[idx++][i] = tmp[j].second;
					arr[idx++][i] = tmp[j].first;
				}
				idx--;
				sizeCheck.push_back(idx);
			}
			sort(sizeCheck.begin(),sizeCheck.end());
			row = sizeCheck.back();
		}
		ans++;
	}
	return 0;
}