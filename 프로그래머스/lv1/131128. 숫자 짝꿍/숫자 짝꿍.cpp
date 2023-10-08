#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int Xarr[10] = {0}; 
    int Yarr[10] = {0};
    int arr[10] = {0};

    for(int i = 0; i < X.size(); i++){
        int num = X[i] - '0';
        Xarr[num]++;
    }
    for(int i = 0; i < Y.size(); i++){
        int num = Y[i] - '0';
        Yarr[num]++;
    }
    for(int i = 0; i < 10; i++){
        if(Xarr[i] > 0 && Yarr[i] > 0){
            arr[i] = min(Xarr[i], Yarr[i]);
        }
    }

    for (int i = 9; i >= 0; i--) { 
        if (arr[i] > 0) {
            for (int j = 0; j < arr[i]; j++) {
            answer += to_string(i); 
            } 
        }
    }

    if (answer.length() == 0) {
        answer = "-1";
    }
    if(answer[0] == '0')
        answer = '0';
    return answer;
}


