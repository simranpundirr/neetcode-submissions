class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chec;
        int maxo=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            while(chec.contains(s[j])){
                chec.erase(s[i]);
                i++;
            }
            chec.insert(s[j]);
            maxo=max(maxo,j-i+1);
        }
        return maxo;
        
    }
};
