class Solution {
public:
    void sort(vector<int>& arr, int low, int high){
        if(low>=high){
            return;
        }
        int mid= low+(high-low)/2;
        sort(arr,low,mid);
        sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    void merge(vector<int>& arr, int low, int mid, int high){
        int i=low;
        int j=mid+1;
        vector<int> temp;
        while(i<=mid &&j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
         while(i<=mid ){
            temp.push_back(arr[i]);
            i++;
            
        }
         while(j<=high){
    
            temp.push_back(arr[j]);
            j++;
            
        }
        for(int k=0;k<temp.size();k++){
            arr[low+k]=temp[k];
        }
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums,0,nums.size()-1);
        int n=nums.size();
        vector<vector<int>> sol;
        for(int i=0;i<n-2;i++){
            if(i>0 &&nums[i]==nums[i-1]){
                continue;
            }
            int f= (-1)*(nums[i]);
            int j=i+1;
            int k=n-1;
            

            while(j<k){
                int s=nums[j]+nums[k];
                
                if(s==f){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sol.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }

                }
                else if(s<f){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return sol;
    }
};
