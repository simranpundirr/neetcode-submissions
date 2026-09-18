class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> lol(nums.size());
        int n=nums.size();
        int m=0;
        k=k%n;
        for(int i=n-k;i<n;i++){
            lol[m]=nums[i];
            m++;
        }
        for(int i=0;i<n-k;i++){
            lol[m]=nums[i];
            m++;
        }
        for(int i=0;i<n;i++){
            nums[i]=lol[i];
        }
    }
};