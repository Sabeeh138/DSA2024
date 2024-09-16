#include <iostream>
using namespace std;

// Non-tail recursive function
int factorialNonTail(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialNonTail(n - 1);
}

// Tail recursive function
int factorialTailHelper(int n, int accumulator) {
    if (n <= 1) {
        return accumulator;
    }
    return factorialTailHelper(n - 1, n * accumulator);
}

int factorialTail(int n) {
    return factorialTailHelper(n, 1);
}

int main() {
    int number = 6;
    cout << "Factorial of " << number << " (non-tail recursion) is: " << factorialNonTail(number) << endl;
    cout << "Factorial of " << number << " (tail recursion) is: " << factorialTail(number) << endl;
    return 0;
}
