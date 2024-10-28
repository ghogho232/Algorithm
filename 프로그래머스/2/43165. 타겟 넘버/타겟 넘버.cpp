#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int target, int depth, int res){
    if(depth == numbers.size()){
        if(res == target){
            answer++;
        }
        return;
    }
    else{
        dfs(numbers, target, depth+1, res+numbers[depth]);
        dfs(numbers, target, depth+1, res-numbers[depth]);
    }
    
}
int solution(vector<int> numbers, int target) {

    dfs(numbers, target, 0, 0);
    return answer;
}

