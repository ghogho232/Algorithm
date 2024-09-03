#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> arr(n+1, vector<int>(n+1,INF));
    for(int i = 0; i < fares.size(); i++){
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] == INF | arr[k][j] == INF) continue;
                else{
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(arr[s][i] == INF || arr[i][a] == INF || arr[i][b] == INF) continue;
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }
    return answer;
}