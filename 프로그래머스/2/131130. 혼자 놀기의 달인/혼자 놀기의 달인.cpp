#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int size = cards.size();
    vector<int>visited(size+1,0);
    vector<int>group;
    int answer = 0;
    
    for(int i = 0; i < size; i++){
        int cur = cards[i];
        int cnt = 0;
        while(!visited[cur]){
            visited[cur] = 1;
            cur = cards[cur-1];
            cnt++;
        }
        if(cnt > 0){
            group.push_back(cnt);
        }
    }
    sort(group.begin(),group.end(),greater<int>());
    if(group.size() > 1){
        answer = group[0]*group[1];
    }
    return answer;
}