class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> pq;
        int n=nums.size();
        int k=n/3;
        int max=nums[0];
        vector<int> mj;
        for(int i=0;i<n;i++){
    
            pq[nums[i]]++;
            if((pq[nums[i]]>k) && (find(mj.begin(),mj.end(),nums[i])==mj.end())){
                mj.push_back(nums[i]);
            }
        }
        return mj;
        

    }
};