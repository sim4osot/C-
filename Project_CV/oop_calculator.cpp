#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0) {
            cout << "ERROR!" << endl;
            return NAN;
        }
        return a / b;
    }

    double power(double base, double exponent) { return pow(base, exponent); }

    double squareRoot(double value) {
        if (value < 0) {
            cout << "ERROR!" << endl;
            return NAN;
        }
        return sqrt(value);
    }

    int mod(int a, int b) {
        if (b == 0) {
            cout << "ERROR!" << endl;
            return 0;
        }
        return a % b;
    }

    double factorial(int n) {
        if (n < 0) return NAN;
        double result = 1;
        for (int i = 2; i <= n; ++i)
            result *= i;
        return result;
    }

    double logarithm(double x) {
        if (x <= 0) {
            cout << "ERROR!" << endl;
            return NAN;
        }
        return log10(x);
    }

    double ln(double x) {
        if (x <= 0) {
            cout << "ERROR!" << endl;
            return NAN;
        }
        return log(x);
    }

    double sine(double x) { return sin(x); }
    double cosine(double x) { return cos(x); }
    double tangent(double x) { return tan(x); }
};

int main() {
    Calculator calc;
    double num1 = 0, num2 = 0;
    string op;
    while(op != "end"){
    cout << "== OOP CALCULATOR ==" << endl;
    bool i = false;
    bool i2 = false;
    do{
    i = false;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter first number: ";
    cin >> num1;
    i = cin.fail();
    }while(i);

    cout << "Choose operation (+, -, *, /, ^, r, %, !, log, ln, sin, cos, tan, end): ";
    cin >> op;
    if(op == "end"){
        break;
    }else if (op == "r") {
        cout << "Result: " << calc.squareRoot(num1) << endl;
    }
    else if (op == "!") {
        if (num1 < 0 || floor(num1) != num1) {
            cout << "ERROR!" << endl;
        } else {
            cout << "Result: " << calc.factorial((int)num1) << endl;
        }
    }
    else if (op == "log") {
        cout << "Result: " << calc.logarithm(num1) << endl;
    }
    else if (op == "ln") {
        cout << "Result: " << calc.ln(num1) << endl;
    }
    else if (op == "sin") {
        cout << "Result: " << calc.sine(num1) << endl;
    }
    else if (op == "cos") {
        cout << "Rasult: " << calc.cosine(num1) << endl;
    }
    else if (op == "tan") {
        cout << "Result: " << calc.tangent(num1) << endl;
    }
    else {
        cout << "Enter second number: ";
        do{
            i2 = false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter second number: ";
            cin >> num2;
            i2 = cin.fail();
            }while(i2);

        double result;

        if (op == "+") result = calc.add(num1, num2);
        else if (op == "-") result = calc.subtract(num1, num2);
        else if (op == "*") result = calc.multiply(num1, num2);
        else if (op == "/") result = calc.divide(num1, num2);
        else if (op == "^") result = calc.power(num1, num2);
        else if (op == "%") result = calc.mod((int)num1, (int)num2);
        else {
            cout << "Invalid operation!" << endl;
            return 1;
        }

        cout << "Result: " << result << endl;
    }
    }
    return 0;
}
