class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        
        for(auto x:count){
            bucket[x.second].push_back(x.first);
        }
        vector<int>ans;
        for(int i=bucket.size()-1;i>=0 &&ans.size()<k;i--){
            for(auto x:bucket[i]){
                ans.push_back(x);
            
                if(ans.size()==k){
                    break;
                }
            }
        }
        return ans;
    }
};