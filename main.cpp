/**
Ezekiel Mitchell
ECEGR 2030 01
Homework #1
April 04, 2024
**/

#include <iostream>
#include <cassert>
#include <stack>
#include <cstdlib>

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

    if (!st.empty()) {
        return false;
    }


    return true;
}

int testValidBrackets() {
    
#ifdef NDEBUG
    std::cerr << "Tests run with NDEBUG defined (asserts compiled out)";
    std::abort();
#endif

    assert(hasValidBrackets("[()]{}{[]()}") == true);
    assert(hasValidBrackets("[]{}{[()()]}") == true);
    assert(hasValidBrackets("{[{}]([]{}())}") == true);
    assert(hasValidBrackets("[[]{}{[([]){}([[{{}}]])]}]") == true);
    assert(hasValidBrackets("((") == false);
    assert(hasValidBrackets("[()(}") == false);
    assert(hasValidBrackets("((()(}") == false);
//    assert(hasValidBrackets("[{((}}}") == true); // purposely failed test
    assert(hasValidBrackets("[()]{}{[()()]()") == false);

    return 0;
}