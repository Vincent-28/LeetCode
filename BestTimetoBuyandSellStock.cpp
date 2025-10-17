#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min = prices[0]; //the minimum value is set to the first element
        int profit = 0; //the profit is set at 0
        //time to iterate through each element in prices
        for (int i : prices) {
            if (i <= min) { //first check if the element is less than the current minimum value we have to set that to the new minimum value (best time to buy)
                min = i;
            }
            else if (i - min > profit) { //else check if the element minus whatever the minimum value we have is greater than the current profit. we set that as our current best profit(best time to sell)
                profit = i - min;
            }
        }
        return profit; //once we go through prices and  have our min value and profit, we return the profit we have
    }
};

int main() {
    std::vector<int> prices = {7,1,5,3,6,4};

    Solution solution;

    std::cout << solution.maxProfit(prices) << std::endl;
}