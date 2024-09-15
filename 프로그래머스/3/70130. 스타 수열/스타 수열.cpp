#include <string>
#include <vector>
using namespace std;
    
int solution(std::vector<int> a) {
    int answer = -1;
    vector<int> cnt(a.size()+1, 0);
    for(int i = 0; i < a.size(); i++){
        cnt[a[i]]++;
    }
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] == 0 || cnt[i] <= answer) continue;
        
        int tmp = 0;
        for(int j = 0; j < a.size()-1; j++){
            if(a[j] != i && a[j+1] != i) continue;
            if(a[j] == a[j+1]) continue;
            
            tmp++;
            j++;
        }
        answer = max(answer, tmp);
    }
    return 2*answer;
}