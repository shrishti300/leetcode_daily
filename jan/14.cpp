

/* 1061. Lexicographically Smallest Equivalent String */
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        char values[26];
        for(int i=0;i<26;i++)
        values[i]='a'+i;
        for(int i=0;i<s1.size();i++){
            char replace=max(values[s1[i]-'a'], values[s2[i]-'a']);
            char replacewith=min(values[s1[i]-'a'],values[s2[i]-'a']);
            for(int i=0;i<26;i++){
                if(values[i]==replace)
                values[i]=replacewith;
            }
            for(int i=0;i<baseStr.size();i++)
            baseStr[i]=values[baseStr[i]-'a'];
        }
        return baseStr;
    }
};