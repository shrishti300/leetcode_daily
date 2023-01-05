/* 2244. Minimum Rounds to Complete All Tasks */
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int count=0;
        for(auto it:mp){
           if(it.second==1)
           return -1;
            count+=(it.second+2)/3;
             }
        return count;
    }

};