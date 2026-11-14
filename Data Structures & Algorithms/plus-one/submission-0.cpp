class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        reverse(digits.begin(),digits.end());

        int carry = 1;
        int n = digits.size();
        int i = 0;

        while(i<n || carry){
            int sum = 0;
            if(i<n) sum += digits[i];
            // cout<<sum<<endl;
            sum += carry;
            if(i<n)
            digits[i] = sum%10;
            else digits.push_back(sum%10);

            carry = sum / 10;
            i++;
        }

        reverse(digits.begin(),digits.end());
        return digits;
        
    }
};
