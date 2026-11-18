
class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,
              int i, vector<int>& dp) {

        // Base case
        if (i >= days.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // Option 1: Buy 1-day pass
        int oneDay = costs[0] + solve(days, costs, i + 1, dp);

        // Option 2: Buy 7-day pass
        int j = i;

        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }

        int sevenDay = costs[1] + solve(days, costs, j, dp);

        // Option 3: Buy 30-day pass
        j = i;

        while (j < days.size() && days[j] < days[i] + 30) {
            j++;
        }

        int thirtyDay = costs[2] + solve(days, costs, j, dp);

        return dp[i] = min({oneDay, sevenDay, thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(days.size(), -1);

        return solve(days, costs, 0, dp);
    }
};
