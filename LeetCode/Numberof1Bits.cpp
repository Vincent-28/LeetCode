#include <iostream>
#include <cmath>

class Solution {
public:
    int hammingWeight(int n) {
        std::string binary = ""; //create empty string calledd binary

        while (n != 0) { //while loop that occurs as long as n isn't equal to 0
            if (n % 2 != 0) { //checks if n is odd using modulus by checking if it will have a remainder that isn't 0 when divided by 2
                binary += "1"; //if true, add "1" binary
            }
            n = n /2; //divide n by 2 because in order to convert an integer decimal number into binary, you always want to divide by 2 and check if the remaindeer is either 1 or 0
        }
        return binary.length(); //when the while loop finishes, return the amount of 1s that end up in binary
    }
};

int main() {
    int x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    Solution solution;

    std::cout << solution.hammingWeight(x) << std::endl;

    return 0;
    }