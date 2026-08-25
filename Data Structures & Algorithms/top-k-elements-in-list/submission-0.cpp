class Solution {
public:
void mergesort(vector<pair<int,int>>& nums, int low, int high){
    if(low>=high){
        return;
    }
    int mid=low+(high-low)/2;
    mergesort(nums, low, mid);
    mergesort(nums,mid+1,high);
    merge(nums,low,mid,high);
}
void merge(vector<pair<int,int>>& nums, int low, int mid, int high){
    int i=low;
    int j=mid+1;
    vector<pair<int,int>> temp;
    while(i<=mid && j<=high){
        if(nums[i].second<=nums[j].second){
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid ){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=high){
       
        temp.push_back(nums[j]);
        j++;
        
    }
    for(int k=0;k<temp.size();k++){
        nums[low+k]=temp[k];
    }

}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        vector<pair<int,int>> p;
        for(auto x: count){
            p.push_back({x.first,x.second});
        }
        mergesort(p,0,p.size()-1);
        vector<int> ans;
        int j=p.size()-1;
        while(k--!=0){
            ans.push_back(p[j].first);
            j--;
        }
        return ans;
        
    }
};
