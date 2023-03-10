/* 131. Palindrome Partitioning*/
class Solution {
public:

bool ispalindrome(string s,int start,int end){
int i=start,j=end;
while(i<=end){
    if(s[i++]!=s[j--]){
    return false;
    }
  
}
  return true;
}
void solve(int idx,string s,vector<string>&path,vector<vector<string>>&res){
    if(idx==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(ispalindrome(s,idx,i)){
         path.push_back(s.substr(idx,i-idx+1));
         solve(i+1,s,path,res);
         path.pop_back();   
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        solve(0,s,path,res);
        return res;
    }
};