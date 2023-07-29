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

int n; //수 개수
int arr[11]; //입력된 수를 저장할 배열
int op[4]; // 연산자 개수 저장할 배열

int Min = 1000000000; //초기 최소값
int Max = -1000000000; //초기 최대값

//백트래킹
void dfs(int ans, int indx) {
    if (indx == n) { //모든 수를 다 사용했을 때(수식이 완성됐을 때)
        if (ans < Min) //답이 MIN보다 작다면 교체
            Min = ans;
        if (ans > Max) //답이 MAX보다 크다면 교체
            Max = ans;
        return; //탈출
    }
    for (int i = 0; i < 4; i++) { //연산자 네개에 대해
        if(op[i]>0) { //연산자가 남아있다면
            op[i]--; //하나 사용하므로 --
            if (i == 0) //더하기연산
                dfs(ans + arr[indx], indx + 1);
            else if (i == 1) //빼기
                dfs(ans - arr[indx], indx + 1);
            else if (i == 2) //곱
                dfs(ans * arr[indx], indx + 1);
            else //나누기
                dfs(ans / arr[indx], indx + 1);
            op[i]++; //다른 연산자 사용을 위해 백트래킹
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    dfs(arr[0], 1);
    cout << Max << "\n" << Min;
    return 0;
}