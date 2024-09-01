#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, vector<vector<int>>& ans){
    if(n == 1){
        ans.push_back({from, to});
        return;
    }
    hanoi(n-1, from, 6-from-to, ans);
    hanoi(1, from, to, ans);
    hanoi(n-1, 6-from-to, to, ans);
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);
    return answer;
}