//  Copyright 2021 Dmitry Vargin
#include "MyStack.h"
#include "postfix.h"
#include <string>

std::string infix2postfix(std::string infix) {
    std::string result;
    MyStack<char> stack;
    for (int i = 0; i < infix.length(); ++i) {
        switch (infix[i]) {
            case ' ':
                break;
            case '(':
                stack.push('(');
                break;
            case ')':
                while (stack.get() != '('){
                    result += stack.pop();
                    result += ' ';
                }
                stack.pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (stack.isEmpty() || (priority(infix[i])) > priority(stack.get())) {
                    stack.push(infix[i]);
                } else {
                    while (priority(infix[i]) <= priority(stack.get())) {
                        result += stack.pop();
                        result += ' ';
                    }
                    stack.push(infix[i]);
                }
                break;
            default:
                if (isNumber(infix[i])) {
                    result += infix[i];
                }
                if (i + 1 < infix.length() && !isNumber(infix[i+1])) {
                    result += ' ';
                }
                break;
        }
    }
    if (!stack.isEmpty())
        result += ' ';
    while (!stack.isEmpty()) {
        result += stack.pop();
        result += ' ';
    }
    return result.substr(0, result.length()-1);
}

bool isNumber(char c) {
    if (48 <= c && c <= 57 || c == '.')
        return true;
    return false;
}

int priority(char op) {
    switch (op) {
        case '(':
            return 0;
        case ')':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        default:
            return -1;
    }
}
