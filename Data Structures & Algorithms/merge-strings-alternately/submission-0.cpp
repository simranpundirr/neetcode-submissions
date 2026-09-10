class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string c="";
        while(i<word1.size()&& j<word2.size()){
            c+=word1[i];
            i++;
            c+=word2[j];
            j++;
        }
        while(i<word1.size()){
            c+=word1[i];
            i++;
        }
        while(j<word2[j]){
            c+=word2[j];
            j++;
        }
        return c;
    }
};