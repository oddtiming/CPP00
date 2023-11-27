#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::runtime_error;
using std::stack;
using std::string;
using std::vector;

string&
str_remove_all(string& str, const string& pattern) {
    string::size_type i = str.find(pattern, 0);
    string::size_type pattern_length = pattern.length();

    while (i != string::npos) {
        str.erase(i, pattern_length);
        i = str.find(pattern, i);
    }
    return str;
}

void
str_remove_all(string& str, char c) {
    // std::remove() moves all the elements that are to be kept to the front of
    // the container, and returns an iterator to this new logical end.
    str.erase(std::remove(str.begin(), str.end(), c), str.end());
}

template <typename T>
vector<T>
reverse_stack(stack<T>& stk) {
    vector<T> reversed;
    reversed.reserve(stk.size());

    while (!stk.empty()) {
        reversed.push_back(stk.top());
        stk.pop();
    }
    return reversed;
}

template <typename T>
void
print_stack_rev(stack<T> stk) {
    if (stk.empty()) return;

    // Convert to a vector to hold the reversed stack
    vector<T> reversed = reverse_stack(stk);
    typename vector<T>::iterator it = reversed.begin();
    typename vector<T>::iterator ite = reversed.end();

    cout << "[";
    // Print first of array without preceding by separator
    cout << *(it++);
    while (it != ite) {
        cout << ", " << *it++;
    }
    cout << "]" << endl;
}

template <typename T>
void
print_stack(stack<T> stk) {
    if (stk.empty()) return;

    cout << "[";
    T& val = stk.top();
    stk.pop();
    // Print first of array without preceding by separator
    cout << (val);
    while (!stk.empty()) {
        val = stk.top();
        stk.pop();
        cout << ", " << val;
    }
    cout << "]" << endl;
}

float
convertCharToDigit(char c) {
    int value = c;
    return float(value - '0');
}

/*
 *  @throws runtime_error if op is not a valid operator
 */
float
operation(float a, float b, char op) {
    switch (op) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            if (a == 0) throw runtime_error("Error. Division by zero.");
            return b / a;
        default:
            throw runtime_error(string("Error. Invalid operator '") + op + "'");
    }
}

/*
 *  @throws runtime_error if:
 *      - invalid characters in the RPN expression
 *      - operands left in stack after evaluation
 */
float
postfixEval(string postfix) {
    float a, b;
    stack<float> stk;
    string::iterator it;

    for (it = postfix.begin(); it != postfix.end(); it++) {
        if (isdigit(*it)) {
            stk.push(convertCharToDigit(*it));
        } else {
            if (stk.size() < 2) {
                throw runtime_error(string("Error. Not enough operands for operator: '") + *it + "'");
            }

            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            float res = operation(a, b, *it);
            stk.push(res);
        }

        // Print current evaluation state
        cout << *it << " ";
        print_stack(stk);
    }

    if (stk.size() != 1) {
        throw runtime_error("Error. Operands left in stack after evaluation.");
    }

    return stk.top();
}

/*
 *  @brief Validates the postfix notation, warns user if digits are not space separated.
 *
 *  @throws runtime_error if notation contains invalid chars or is empty
 */
string
parsePostFixNotation(string notation) {
    static char const* allowed_chars = "0123456789+-/* ";

    // Check for invalid chars
    if (notation.find_first_not_of(allowed_chars) != string::npos) {
        throw runtime_error("Error. Invalid character found in postfix notation.");
    }

    // Issue a warning if two digits are together
    for (size_t i = 0; i + 1 < notation.length(); i++) {
        // Check if consecutive digits, increment otherwise
        if (isdigit(notation[i]) && isdigit(notation[++i])) {
            cerr << "Warning: adjacent digits at position " << i << ". Each digit is evaluated separately in RPN."
                 << endl;
            break;
        }
    }

    str_remove_all(notation, ' ');

    if (notation.empty()) {
        throw runtime_error("Error. Empty argument.");
    }

    return notation;
}

int
main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Error. " << argv[0] << " requires a single reverse polish mathematical expression as argument."
             << endl;
        return (EXIT_FAILURE);
    }

    try {
        string post = parsePostFixNotation(argv[1]);
        float res = postfixEval(post);
        cout << "The final result is: " << res << endl;
    } catch (runtime_error& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
