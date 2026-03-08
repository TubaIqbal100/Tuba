#include <stdio.h>

/* Struct definition */
struct Complex {
    float real;
    float imag;
};

/* Function prototype */
struct Complex addComplex(struct Complex n1, struct Complex n2);

int main() {
    struct Complex c1, c2, result;  /* Declarations at top */

    printf("Enter real and imaginary part of 1st complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter real and imaginary part of 2nd complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);

    result = addComplex(c1, c2);

    if (result.imag >= 0) {
        printf("Sum = %.1f + %.1fi\n", result.real, result.imag);
    } else {
        printf("Sum = %.1f - %.1fi\n", result.real, -result.imag);
    }

    return 0;
}

/* Function definition */
struct Complex addComplex(struct Complex n1, struct Complex n2) {
    struct Complex temp;  /* Declare at top */
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return temp;
}

