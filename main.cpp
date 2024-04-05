/**
Ezekiel Mitchell
ECEGR 2030 01
Homework #1
April 05, 2024
**/

#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

bool hasValidBrackets( string expr );
int testValidBrackets();

int main() {
    testValidBrackets();
    return 0;
}

bool hasValidBrackets( string expr ) { // check for balanced brackets in an expression
    
    stack<char> st; // declare char stack
    
    for ( char c : expr ) { // add opening brackets to stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c); // push opening brackets to strack
        } else if  ( (c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[') ) {
            st.pop(); // pop if stack top bracket opens current closing bracket
        } else {
            return false;
        }
    }

    if (!st.empty()) { // if there are any remaining entries, algo fails
        return false;
    }

    return true;
}

int testValidBrackets() { // test for hasValidBrackets() function

    assert(hasValidBrackets("[()]{}{[]()}") == true);
    assert(hasValidBrackets("[]{}{[()()]}") == true);
    assert(hasValidBrackets("{[{}]([]{}())}") == true);
    assert(hasValidBrackets("[[]{}{[([]){}([[{{}}]])]}]") == true);
    assert(hasValidBrackets("((") == false);
    assert(hasValidBrackets("[()(}") == false);
    assert(hasValidBrackets("((()(}") == false);
    assert(hasValidBrackets("[()]{}{[()()]()") == false);
//    assert(hasValidBrackets("[{((}}}") == true); // purposely failed test

    cout << "All tests pass successfully!\n";
    return 0;
}