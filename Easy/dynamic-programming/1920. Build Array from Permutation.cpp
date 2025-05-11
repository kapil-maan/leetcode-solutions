//Easy

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans;
    
            for(int i:nums){
                ans.push_back(nums[i]);
            }
    
            return ans;
        }
    };