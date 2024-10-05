#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
    vector<char> elements;

public:
    void push(char ch) {
        elements.push_back(ch);
    }

    char pop() {
        if (!elements.empty()) {
            char topElement = elements.back();
            elements.pop_back();
            return topElement;
        }
        return '\0';
    }

    char top() {
        if (!elements.empty()) {
            return elements.back();
        }
        return '\0';
    }

    bool empty() {
        return elements.empty();
    }
};

// Precedence function for operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Helper function to reverse a string (manually)
string reverse_string(const string& str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

// Convert infix expression to postfix
string infix_to_postfix(const string& expression) {
    Stack stack;
    string result;

    for (char ch : expression) {
        if (isalpha(ch)) {
            result += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                result += stack.pop();
            }
            stack.pop();
        } else if (isOperator(ch)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) {
                result += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        result += stack.pop();
    }

    return result;
}

// Convert infix to prefix by modifying the infix_to_postfix algorithm
string infix_to_prefix(string expression) {
    // Step 1: Reverse the infix expression manually
    expression = reverse_string(expression);

    // Step 2: Swap '(' with ')' and vice versa
    for (char& ch : expression) {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    // Step 3: Apply the modified infix_to_postfix algorithm (no changes in logic)
    string postfix = infix_to_postfix(expression);

    // Step 4: Reverse the postfix result to get the prefix notation
    return reverse_string(postfix);
}

int main() {
    string expression = "K+L-M*N+(O^P)*W/U/V*T+Q";

    string postfix = infix_to_postfix(expression);
    cout << "Postfix Expression: " << postfix << endl;

    string prefix = infix_to_prefix(expression);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
