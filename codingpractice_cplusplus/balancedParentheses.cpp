#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {

        stack<char> myStack;



        for (char c : s) {

            if (c == '(' || c == '[' || c == '{') {
                myStack.push(c);
            }
            else {
                if (myStack.empty()) {
                    //if no opening parentheses, then immediately false
                    return false;
                }
                else if (c == ')' && myStack.top() == '(') {
                    myStack.pop();
                }
                else if (c == '}' && myStack.top() == '{') {
                    myStack.pop();
                }
                else if (c == ']' && myStack.top() == '[') {
                    myStack.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (myStack.empty()) {
            //if all elements have been used up then ture
            return true;
        }
        else {
            //if there are any remaining parentheses, then false
            return false;
        }

    }
};
int main() {

    Solution sol;


    string test = "{[()]}";
    string test2 = "{[()}";


    cout << "Test 1: " << sol.isValid(test) << endl
        << "Test 2: " << sol.isValid(test2) << endl
        ;








}

