#include <stdio.h>

int multiply(int num1, int num2) {
    int sum = 0;
    for (int i = 0; i < num1; i++) {
        sum += num2;
    }
    return sum;
}

int main() {
    int num1 = 4;

    int num2 = 8;
    int product = multiply(num1, num2);
    printf("%d\n", product);
    return 1;
}
