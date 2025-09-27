#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0; //setting ans to 0
        for (int x : nums) {
            ans ^= x; //ans = ans ^ x
        } 
        return ans;
    }
}; //this uses XOR in which a ^ a = 0 and a ^ b = b ... all duplicates will cancel each other out (to 0) and the last one remaining wont cancel out since there's only one of itself



int main() {
    std::vector<int> numbers = {1,1,2,2,4};

    Solution solution;

    std::cout << solution.singleNumber(numbers) << std::endl;

    return 0;
}