#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        digits[digits.size() - 1] += 1; //first we want to add 1 to the end of the array 
        for (int i = digits.size() - 1; i >= 0; i--) { //we loop through each element in array in reverse
            if (digits[i] == 10) { //we want to check if the digit we added 1 to is 10 in the case that it was 9
                digits[i] = 0; //we make that 0 due to basic rules of addition
                if (digits[0] != 0) { //as long as the first position is not 0 we add 1 to the next digit because we can't have digits[-1]
                    digits[i - 1] += 1;
                } 
            }
        }
        if (digits[0] == 0) { //if the first digit is 0 (meaning the second digit was 9 and 1 was added 1 to it ie. 99), we insert a 1 to the front ie. 00->100
            digits.insert(digits.begin(), 1); 
        }
        return digits; 
    }
};

int main() {
    std::vector<int> digits = {9,9,9,9};

    Solution solution;

    std::vector<int> result = solution.plusOne(digits);

    for (int i : result) {
        std::cout << i;
    }
    std::cout << std::endl;
}
