#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int count = -1; //set count to -1 since the first thing we will do when going through nums is iterate count by 1 which will make count 0 and we want to start at the 0 position
        for (int i = 0; i < nums.size(); i++) { //loop through each element in nums
            count++; //iterate count by 1 to keep track of position
            if (nums[i] == target) { 
                return count;
            } //check if the target is found then we return count (count represents the current position)
            if (nums[i] > target) {
                return count;
            } //check if the element is greater then the target, in other words we passed the position where target would be if it was there so we just return that position
        }
        return count +1; //if target is greater than the last element in nums, then return the position +1
    }
};

int main() {
    std::vector<int> nums = {1,3,5,6};
    int target = 7;

    Solution solution;

    std::cout << solution.searchInsert(nums, target) << std::endl;
}