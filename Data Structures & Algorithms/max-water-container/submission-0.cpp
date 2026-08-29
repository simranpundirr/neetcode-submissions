class Solution {
public:
    int maxArea(vector<int>& heights) {
        int vol=0;
        int n=heights.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int temp=(j-i)*min(heights[i],heights[j]);
            vol=max(vol,temp);
            if(heights[i]<=heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return vol;
    }
};
