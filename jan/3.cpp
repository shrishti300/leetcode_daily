/* PROBLEM TITLE :- DELETE COLUMNS TO MAKE SORTED */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       int n=strs[0].size();
       bool flag=false; //initializing flag to check if the col is not sorted
       int count=0;     // to count number of deleted columns

    for(int i=0;i<n;i++){ // for loop to traverse each element of a string
        flag=false;
        for(int j=1;j<strs.size();j++){
            // for loop for traversing each string of strs
            if(strs[j][i]<strs[j-1][i]){ // check if the string is not sorted
                flag=true;
             }
        }
        if(flag==true)
            count++; }

       return count;
    }
};