#include <iostream>

//INITIAL ATTEMPT
class Solution_attempt {
public:
    int findMaxConsecutiveOnes_attempt(std::vector<int>& nums) {
        int count = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            }
            if (nums[i] != 1) { //can just change this to an else statement since we already are checking if num[i] is 1. We can already assume that whatever we are checking here isn't 1
                if (count >= max ) {
                    max = count;
                }
                count = 0;
            }
        }
        if (count > max) {
            return count; //instead of returning count, we can just set the current count to max if it greater than max. This rduced the runtime from 4ms to 1ms
        }
        return max;
    }
};

//MORE EFFICIENT SOLUTION
class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int count = 0; //set count to 0
        int max = 0; //max starts at 0. Will keep track of the highest consecutive 1s
        for (int i = 0; i < nums.size(); i++) { //loops through every element in nums
            if (nums[i] == 1) { 
                count++;
            } //if an element is equal to 1, iterate count by 1
            else {
                if (count >= max ) {//if the element is not equal to 1, check if count is greater then or equal to max (to keep track of the maximum consecutive ones)
                    max = count; //set max to current count if count is greater than max
                }
                count = 0; //if count is not greater than max (the collected consecutive ones isnt the maximum) reset count back to 0 and continue looping through nums
            }
        }
        if (count > max) {
            max = count;
        } //after the loop check if the last row of 1s is greater than the current max found and if it is, set the new max accordingly
        return max; //return whatever max is
    }
};

int main() {
    std::vector<int> nums = {1,1,0,1,1,1};

    Solution solution;

    std::cout << solution.findMaxConsecutiveOnes(nums) << std::endl;
}