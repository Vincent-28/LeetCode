#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
    int count = 0; //set count to 0
    bool space = false; //create a false boolean
    for(int i = s.length() -1; i >= 0; i--) { //loop through every character in the string s starting from the end 
        if (s[i] != ' ') { 
            space = true;
        } //if a character is found at the end, set space to true
        if (space == true) {
            if (s[i] == ' ') {
                return count;
            }
        } //when space is true (a character is found) check for a space. When that space is found, that means a character is found and then a space meaning that the word has been completely found since it is seperated by a space
        if (space == true) {
            count++; //when space is true, iterate count by one since we are trying to count the number of characters of the last word
        }
    }
    return count; //return count in the end
    }
};

int main() {
    std::string s;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, s);

    Solution solution;

    std::cout << solution.lengthOfLastWord(s) << std::endl;
}