#include <iostream>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        if(s.empty()) { //if the vector is empty we're just gonna return
            return;
        }
        std::stack<char> r; //for this solution we will use a stack
        for(char c : s) {
            r.push(c); //push every character to the stack
        }
        int i = 0;
        while(!r.empty()) {
            s[i] = r.top(); //overwrite each character from the original string with the values in the stack which are LIFO (last in first out) reversed
            r.pop(); 
            i++;
        }
    }
};

int main() {
    std::vector<char> s = {'h','e','l','l','o'};

    Solution solution;

    solution.reverseString(s);

    for(int i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
}