class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        bool flag=false;
        int n=word.size();

        for(int i=0;i<word.size();i++){
           if(i==0 && isupper(word[0])){
               flag=true;
               count++;
           }
           if(i!=0 && isupper(word[i]))
           {
               count++;
           }
           
        }
       if(count==word.size() || count==0)
       return true;
       else if( flag==true && count==1)
       return true;
       else
       return false;

    }
};
