#include <iostream>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int count = 0; //set count to 0
        for (int i = 0; i < nums.size(); i++) { //loop through each element in nums
            if (nums[i] != 0) { 
                std::swap(nums[count], nums[i]);
                count++;
            } 
            /*
            if the element isn't equal to 0, swap it with whatever position count is at. 
            Basically count starts at 0 and the moment we find a number that isn't 0, we move it to nums[count] or num[0] which is the first element. 
            And since we do this for all elements that are not 0, in the end, all the 0s will be at the back of the array.
            */
        }
    }
};

int main() {
    std::vector<int> nums = {0,0,1};

    Solution solution;

    solution.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    
    std::cout << "\n";
}