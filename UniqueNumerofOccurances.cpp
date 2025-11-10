#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        /*create unordered map where the key represents a number in arr and 
        the value represents how many times that value appears*/
        std::unordered_map<int,int> occ;
        for(int x : arr) { //loop through every element in arr
            occ[x]++; //occ[x] looks for the key x in the unordered map and if it's not already there, it creates it with a value of 0 and then increments 1
        }

        std::unordered_set<int> numOcc; //we create a set because sets only store unique values (no duplicates)
        for(auto[x,y] : occ) { //structured binding loop. Since occ is a map, each element is a pair where x is the key and y is the value
            if(numOcc.count(y)) { //.count(y) check is the value y (how many times an element appears) is already in the set numOcc
                return false; //if y has been seen before, we return false (two numbers have the same number of occurances)
            }
            numOcc.insert(y); //if we have not seen the occurance count yet, then we add it to the set numOcc
        }
        return true; //if we never returned false, that would mean every element has a unique numnber of occurences and we return true
    }
};

int main() {
    std::vector<int> arr = {1,2,2,3,3,3};

    Solution solution;

    if(solution.uniqueOccurrences(arr) == 1) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
}