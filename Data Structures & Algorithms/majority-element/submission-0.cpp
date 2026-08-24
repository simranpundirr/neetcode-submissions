
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=1;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int f=0;
        int idx=0;
        for(auto x:mp){
            if(x.second>f){
                f=x.second;
                idx=x.first;
            }
        }
        return idx;

    }
};