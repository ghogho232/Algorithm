#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> binary;

bool check(int begin, int end){
    if (begin == end) return true;

    int mid = (begin + end) / 2;
    int left = (begin + mid - 1) / 2;
    int right = (mid + 1 + end) / 2;
    if (!binary[mid] && (binary[left] || binary[right]))
        return false;

    return check(begin, mid - 1) && check(mid + 1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        binary.clear();
        while (numbers[i] > 0) {
            binary.push_back(numbers[i] % 2);
            numbers[i] /= 2;
        }
        int Size = binary.size();
        int height = ceil(log2(Size + 1));
        int dummySize = pow(2, height) - 1;

        
        while (binary.size() < dummySize) {
            binary.push_back(0);
        }

        
        answer.push_back(check(0, dummySize - 1) ? 1 : 0);
    }

    return answer;
}