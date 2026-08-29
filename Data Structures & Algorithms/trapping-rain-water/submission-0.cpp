class Solution {
public:
    int trap(vector<int>& height) {
        int units=0;
        int n=height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        if(n==0){
            return 0;
        }
        int maxo=0;
       
        prefix[0]=0;
        suffix[n-1]=0;
        for(int i=1;i<n;i++){
            if(height[i-1]>maxo){
                maxo=height[i-1];
            }
            prefix[i]=maxo;
        }
        maxo=0;
        for(int i=n-2;i>=0;i--){
            if(height[i+1]>maxo){
                maxo=height[i+1];
            }
            suffix[i]=maxo;
        }
        int ts=0;

        for(int i=0;i<n;i++){
            if(height[i]>min(suffix[i],prefix[i])){
                continue;
            }
            ts+=min(suffix[i],prefix[i])-height[i];
            
        }
        return ts;

    }
};
