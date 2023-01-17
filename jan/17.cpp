/* 926. Flip String to Monotone Increasing */


class Solution {
public:
    int minFlipsMonoIncr(string s) {

    int res=0,count=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='1')
        count++;
        else{
            int tmp1=count;
            int tmp2=res+1;
            res=min(tmp1,tmp2);
        }
    }
return res;
    }
};