class Solution {
public:

    void maxProfitFinder(vector<int>& prices, int i,
                         int& minPrice, int& maxProfit) {

        // Base case
        if (i == prices.size())
            return;

        // Find minimum buying price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Profit if we sell today
        int todayProfit = prices[i] - minPrice;

        // Update maximum profit
        if (todayProfit > maxProfit) {
            maxProfit = todayProfit;
        }

        // Move to next day
        maxProfitFinder(prices, i + 1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        maxProfitFinder(prices, 0, minPrice, maxProfit);

        return maxProfit;
    }
};