class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
               ans.push_back(nums[i]-1);
        }
        sort(ans.begin(),ans.end());
        return ans[n-1]*ans[n-2];
    }
};