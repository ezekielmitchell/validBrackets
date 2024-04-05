/**
Ezekiel Mitchell
ECEGR 2030 01
Homework #1
April 04, 2024
**/

#include <iostream>
#include <cassert>
#include <stack>

#define NDEBUG

using namespace std;

bool hasValidBrackets( string expr );
void testValidBrackets();

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
    return true;
    
}

void testValidBrackets() {
    assert(hasValidBrackets("[()]{}{[()()]()}") == true);
    assert(hasValidBrackets("[()(}") == false);
    assert(hasValidBrackets("[()]{}{[]()}") == true);
    assert(hasValidBrackets("[{((}") == false);
    assert(hasValidBrackets("[]{}{[()()]}") == true);
    assert(hasValidBrackets("()(}") == false);
}