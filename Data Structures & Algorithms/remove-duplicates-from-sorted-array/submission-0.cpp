class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]==nums[i]){
                i++;
                continue;
            }
            else{
                k++;
                nums[k]=nums[i+1];
                i++;
            }
        }
        return k+1;
    }
};