class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        if(n==0){
            return 0;
        }
        while(i<j){
            if(nums[i]==val){
                if(nums[j]!=val){
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                    i++;
                    j--;
                }
                else{
                    while(j>=i && nums[j]==val){
                        j--;
                    }
                    if(j>=i){
                        int temp=nums[i];
                        nums[i]=nums[j];
                        nums[j]=temp;
                        i++;
                        j--;    
                    }
                }
            }
            else{
                i++;

            }
        }
        if(i<n && nums[i]==val){
            return i;
        }
        return i+1;
    }
};