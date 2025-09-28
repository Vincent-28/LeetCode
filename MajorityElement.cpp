#include <iostream>

//INITIAL ATTEMPT
class Solution_attempt {
public:
    int majorityElement_attempt(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (std::count(nums.begin(), nums.end(), nums[i]) > n /2) {
                return nums[i];
            }
        }
        return 0;
    }
};
/*
In my initial attempt, I am looping through each element in nums and checking if the number of times an element appears in the vector is greater than the size of nums divided by 2. 
This case was explicitly mentioned in the problem description. 
I'll return 0 in the end to eliminate the "non-void function does not return a value in all control paths" message. In this speific problem, we are assuming the majority element always exists. 
This would be a O(n^2) time complexity due to the fact that the worst case would be to count each element in the vector for every element we loop through in nums. 
*/

//MORE EFFICIENT SOLUTION
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int current = 0;
        for (int i : nums) { //loop through each value in nums
            if (count == 0) { 
                current = i;
            } //if our count is at 0 we set whatever value we are checking (as current) to the current value we are at in nums
            count += (i == current) ? 1 : -1; //if the value we are at i nums is equal to the current, we increment count by 1, if not, we subtract 1 from count
        }
        return current;
    }
}; //we are basically keeping count of everytuime we see the current we have and down when we see something else. When count hits 0, we reset since that would be the value does not appear more than n /2. 
//the time complexity is O(n) since we are looping through the size of nums. The space complxity is O(1) since we are only keeping the 2 variables current and count no matter how big the vector is.


int main() {
    std::vector<int> nums = {3,2,3};

    Solution solution;

    std::cout << solution.majorityElement(nums) << std::endl;
}