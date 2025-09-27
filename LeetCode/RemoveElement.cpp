#include <iostream>

//INITIAL ATTEMPT
class Solution_attempt {
public:
    int removeElement_attempt(std::vector<int>& nums, int val) {
        int k = nums.size(); //set k to be the size of nums
        std::vector<int> newNums = {}; //create a new empty vector
        for (int i = 0; i < nums.size(); i++) { //this for loop goes through all elements in nums
            if (nums[i] == val) { //check if the emement is equal to the value we want to remove
                k = k -1; //subtract 1 from k
            }
            else {
                newNums.push_back(nums[i]); //if the element is not equal to the value we want to remove, we add that value to the new empty vector newNums
            }
        }
        nums = newNums; //we set nums as the new vector without val
        return k; //return k which is the number of elements that aren't val in nums
    }
}; //this initial attempt works, but it creates a new array. Extra space O(n).

//MORE EFFICIENT SOLUTION
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
    int k = 0; //creates integer variable k as 0
    for (int i = 0; i < nums.size(); i++) { //loops through each element in nums
        if (nums[i] != val) { //if an element in nums isn't the val to remove, 
            nums[k++] = nums[i]; //set the next element to be the current element
        }
    }
    return k; //return the value of k
    }
};

int main() {
    std::vector<int> nums = {0,1,2,2,3,0,4,2}; // Input array
    int val = 2; // Value to remove

    Solution solution;

    std::cout << solution.removeElement(nums, val) << std::endl;
}

