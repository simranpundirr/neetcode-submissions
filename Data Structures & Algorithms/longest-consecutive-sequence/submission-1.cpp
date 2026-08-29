class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> check;
        for(int i=0;i<n;i++){
            check.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int k=nums[i];
            if(!check.count(k-1)){
                int l=1;
                while(check.count(k+l)){
                    l++;
                }
                ans=max(ans,l);
            }
        }
        return ans;

    }
};
