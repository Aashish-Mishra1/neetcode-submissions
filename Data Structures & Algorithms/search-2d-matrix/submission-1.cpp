class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bool res =false;
        // for(auto row:matrix){
        //     res |=binary_search(row.begin(),row.end(),target);
        // }
        
        // return res;
        // return std::binary_search(matrix.begin(),matrix.end(),target);

        int noRows = matrix.size();
        int noCols = matrix[0].size();

        int low = 0,high = noRows-1;

        int potRow=-1;
        while(low<=high){
            int mid = (high-low)/2+low;
            
            if(matrix[mid][0]<=target){
                potRow = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        if(potRow==-1) return false;
        return  binary_search(matrix[potRow].begin(),matrix[potRow].end(),target);
    
    }
};
