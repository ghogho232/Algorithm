#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> pairing;
    vector<pair<string,string>> tmp;
    
    for(int i = 0; i < record.size(); i++){
        string state, id, name;
        stringstream sstream;
        sstream.str(record[i]);
        sstream >> state >> id >> name;
        
        if(state == "Enter"){
            tmp.push_back({id,"님이 들어왔습니다."});
            pairing[id] = name;
        }
        else if(state == "Leave"){
            tmp.push_back({id, "님이 나갔습니다."});
        }
        else{
            pairing[id] = name;
        }
    }
    
    for(int i = 0; i < tmp.size(); i++){
        answer.push_back(pairing[tmp[i].first]+tmp[i].second);
    }

        
    
    return answer;
}