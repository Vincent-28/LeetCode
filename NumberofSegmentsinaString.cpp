#include <iostream>
#include <cctype>

class Solution {
public:
    int countSegments(std::string s) {
        if (s.empty()) { //check if the string is empty then we just return 0 segments
            return 0;
        }
        bool character = false; //false by default (no characters) will be true when there is a character
        int count = 0; //this is our count for the number of segments
        for(char c : s) { //we loop through every characetr value in s
            if(c != ' ' && !character) { //if we find a character then we set character to true meaning that we are currently in a single segement
                character = true;        //then we iterate the count since we found a segment
                count ++;
            }
            else if(c == ' ') { //once we find a ' ' we set character back to false and we are now looking for the next segment
                character = false;
            } //now we go to the next element in s and continue our search for the next segment
        }

        return count; //return count which represents the number of segments
    }
};

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    Solution solution;

    std::cout << "Your string has " << solution.countSegments(s) << " segments." << std::endl;
}