/* 2246. Longest Path With Different Adjacent Characters */


class Solution {
public:
  vector<int> child[100001];
int ans;
 int dfs(string &s, int curr_node){
    
    if(child[curr_node].empty()) return 1;
    int max_sol=0;
    int sol=0;
    // traversing over all the child nodes of the curr_node
    for(auto &child_node:child[curr_node]){
        // recursively trying to find child nodes
      int len=dfs(s,child_node);
       ans=max(ans,len);
       // ignoring curr node if it has a same character
       if(s[curr_node]==s[child_node]) continue;

       if(len>max_sol){
        sol=max_sol;
        max_sol=len;
       }
       else
       sol=max(sol,len);
    }
    // solution is sum of longest valid path going through this node is the 
    //sub tree rooted at this 
    ans=max(ans,1+max_sol+sol);
    // +1 for current node
    return 1+max_sol;
 }

    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
      for(int i=1;i<n;i++){
         child[parent[i]].push_back(i);
      }
      ans=1;
      dfs(s,0);
      return ans;

    }
};