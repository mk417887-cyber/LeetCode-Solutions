class Solution {
public:

    void solve(vector<int>& nums, int index,
               vector<int>& current,
               vector<vector<int>>& ans)
    {
        // Base case
        if (index == nums.size())
        {
            ans.push_back(current);
            return;
        }

        // INCLUDE current element
        current.push_back(nums[index]);
        solve(nums, index + 1, current, ans);

        // BACKTRACK
        current.pop_back();

        // EXCLUDE current element
        solve(nums, index + 1, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(nums, 0, current, ans);

        return ans;
    }
};