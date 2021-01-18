//  Copyright 2021 Dmitry Vargin
#include "MyStack.h"
#include "postfix.h"
#include <string>

std::string infix2postfix(std::string infix) {
    MyStack<std::string> out_stack;
    MyStack<std::string> oper_stack;
    int tmp_num = -1;
    for (int i = 0; i < infix.length(); ++i) {
        if (infix[i] == ' ')
            continue;
        if (48 <= infix[i] && infix[i] <= 57) {
            if (tmp_num == -1) {
                tmp_num = infix[i] - 48;
            } else {
                tmp_num = tmp_num * 10 + infix[i] - 48;
            }
        } else {
            if (tmp_num != -1) {
                out_stack.push(std::to_string(tmp_num));
                tmp_num = -1;
            }
            if (infix[i] == '*' || infix[i] == '/') {
                oper_stack.push(std::string(1, infix[i]));
            } else if (infix[i] == '+' || infix[i] == '-') {
                if (!oper_stack.isEmpty() && oper_stack.get()[0] != '(') {
                    out_stack.push(oper_stack.pop());
                    oper_stack.push(std::string(1, infix[i]));
                } else {
                    oper_stack.push(std::string(1, infix[i]));
                }
            } else if (infix[i] == '(') {
                oper_stack.push("(");
            } else if (infix[i] == ')') {
                char tmp = oper_stack.pop()[0];
                while (tmp != '(') {
                    out_stack.push(std::string(1, tmp));
                    tmp = oper_stack.pop()[0];
                }
            }
        }
        // std::cout << "Stage " << i << std::endl;
        // std::cout << "Out_stack:\n" << out_stack.to_string() << std::endl;
        // std::cout << "Oper_stack:\n" << oper_stack.to_string() << "\n\n";
    }
    if (tmp_num != -1) {
        out_stack.push(std::to_string(tmp_num));
    }
    tmp_num = oper_stack.getLength();
    for (int i = 0; i < tmp_num; ++i) {
        out_stack.push(oper_stack.pop());
    }
    return out_stack.to_string();
}
