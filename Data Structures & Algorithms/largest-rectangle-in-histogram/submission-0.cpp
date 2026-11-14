class Solution {
public:
    vector<int> findnse(vector<int>nums){
        int n = nums.size();
        vector<int>nse(n,n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            if(st.empty()) st.push(i);
            else{
                nse[i] = st.top();
                st.push(i);
            }
        }

        return nse;
    }

    vector<int> findpse(vector<int>nums){
        int n = nums.size();
        vector<int>pse(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
            }
            else{
                pse[i] = st.top();
                st.push(i);
            }
        }
        return pse;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        

        vector<int> pse = findpse(heights);
        vector<int> nse = findnse(heights);

        // cout<<"pse: ";
        // for(auto it:pse){
        //     cout<<it<<" ";
        // }
        // cout<<"nse: ";

        // for(auto it:nse){
        //     cout<<it<<" ";
        // }

        int maxArea = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int area = heights[i] * (nse[i]-pse[i]-1);
            maxArea = max(maxArea,area);
        }


        return maxArea;
    }
};
