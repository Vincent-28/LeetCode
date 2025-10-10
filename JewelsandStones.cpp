#include <iostream>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        int count = 0; //set count to
        for (int i = 0; i < jewels.length(); i++) { //loop through jewels string
            for (int j = 0; j < stones.length(); j++) { //for each character in jewels, loop through each character in stones
                if (stones[j] == jewels[i]) {
                    count ++;
                } //iterate count by 1 if a character in stones is equal to a character in jewels
            }
        }
        return count; //return count as an integer
    }
};

int main() {
    std::string jewels; //aA
    std::string stones; //aAAbbbb

    std::cout << "Enter jewel types: ";
    std::getline(std::cin, jewels);

    std::cout << "Enter stone types: ";
    std::getline(std::cin, stones);

    Solution solution;

    std::cout << solution.numJewelsInStones(jewels, stones);
}

