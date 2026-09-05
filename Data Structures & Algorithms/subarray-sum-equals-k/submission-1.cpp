class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixsum(n);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            int need=prefixsum[i]-k;
            if(mp.contains(need)){
                count+=mp[need];
            }
            mp[prefixsum[i]]++;
        }
        return count;
    }
};