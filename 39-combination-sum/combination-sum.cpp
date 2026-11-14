
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int target,
               int index, vector<int>& temp) {

        // Target achieved
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        // No more candidates
        if (index >= candidates.size()) {
            return;
        }

        // Choice 1: Include current element
        if (candidates[index] <= target) {

            temp.push_back(candidates[index]);

            // Same index because repetition is allowed
            solve(candidates, target - candidates[index],
                  index, temp);

            // Backtracking: remove the selected element
            temp.pop_back();
        }

        // Choice 2: Exclude current element
        solve(candidates, target, index + 1, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<int> temp;

        solve(candidates, target, 0, temp);

        return result;
    }
};
