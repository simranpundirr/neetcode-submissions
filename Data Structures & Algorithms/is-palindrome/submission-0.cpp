class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char c:s){
            if(isalnum(c)){
                temp+=tolower(c);
            }
        }
        int n=temp.length();
        int i=0;
        int j=n-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
