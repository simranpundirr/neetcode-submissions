class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            int min=nums[i];
            int idx=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<min){
                    min=nums[j];
                    idx=j;
                }
            }
            if(idx!=i){
                int temp=nums[i];
                nums[i]=nums[idx];
                nums[idx]=temp;
            }

        }
        
    }
};