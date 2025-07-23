#include <iostream>
using namespace std;

// Functions for each operation
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    float num1, num2, result;
    char op;

    cout << "Simple Calculator Program" << endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    if (op == '+') {
        result = add(num1, num2);
        cout << "Result: " << result << endl;
    } else if (op == '-') {
        result = subtract(num1, num2);
        cout << "Result: " << result << endl;
    } else if (op == '*') {
        result = multiply(num1, num2);
        cout << "Result: " << result << endl;
    } else if (op == '/') {
        result = divide(num1, num2);
        if (num2 != 0) {
            cout << "Result: " << result << endl;
        }
    } else {
        cout << "Invalid operator!" << endl;
    }

    return 0;
}
