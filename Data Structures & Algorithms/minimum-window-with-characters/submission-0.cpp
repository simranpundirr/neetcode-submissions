class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(126,0);
        vector<int> window(126,0);
        for(char c:t){
            need[c]++;
        }
        int left=0;
        int start=0;
        int have=0;
        int required=t.size();
        int mlen=INT_MAX;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;
            if(need[c]>0 && window[c]<=need[c]){
                have++;
            }
            while(have==required){
                if(right-left+1<mlen){
                    mlen=right-left+1;
                    start=left;
                }
                char c =s[left];
                window[c]--;
                if(need[c]>0 && window[c]<need[c]){
                    have--;
                }
                left++;
            }
        }
        if(mlen==INT_MAX){
            return "";
        }
        return s.substr(start,mlen);
    }
};
