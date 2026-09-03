class NumMatrix {
public:
vector<vector<int>> prefixsum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        prefixsum=vector<vector<int>>(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefixsum[i][j]=prefixsum[i-1][j]+prefixsum[i][j-1]+matrix[i-1][j-1]-prefixsum[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s=prefixsum[row2+1][col2+1]-prefixsum[row1][col2+1]-prefixsum[row2+1][col1]+prefixsum[row1][col1];
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */