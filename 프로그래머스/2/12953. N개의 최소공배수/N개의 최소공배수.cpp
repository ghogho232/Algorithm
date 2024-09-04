#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int c = a%b;
    if(c == 0)
        return b;
    return gcd(b,c);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
int solution(vector<int> arr) {
    int answer = 0;
    int tmpgcd;
    for(int i = 1; i < arr.size(); i++){
      tmpgcd = gcd(arr[i-1],arr[i]);
    }
    for(int i = 0; i < arr.size(); i++){
        tmpgcd = lcm(tmpgcd, arr[i]);
    }
    answer = tmpgcd;
    return answer;
}