class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res =false;
        for(auto row:matrix){
            res |=binary_search(row.begin(),row.end(),target);
        }
        
        return res;
        // return std::binary_search(matrix.begin(),matrix.end(),target);
    }
};
