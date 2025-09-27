#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        } // if n is equal to 1, return true since 2^0 is 1
        double count = 2; //sets count as a double (to avoid runtime errors) as 2 since we already checked for 1
        while (count <= n) { 
            if (count == n) { 
                return true;
            }
            count = count *2;
        } //this while loop keeps multiplying count by 2 to simulate powers of 2 all the way up until it reaches n. If it ends up being equal to n, then n is a power of 2
        return false; //if count ends up being grader than n without every being equal to it, n is not a power of 2
    }
};

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    Solution solution;

    if (solution.isPowerOfTwo(num) == 1) {
        std::cout << num << " is a power of two." << std::endl;;
    }
    else {
        std::cout << num << " is not a power of two" << std::endl;
    }
}