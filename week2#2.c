#include <stdio.h>

struct Distance {
    int feet;
    float inch;
};

int main() {
    struct Distance d1, d2, sum;

    printf("Enter 1st distance (feet and inch): ");
    scanf("%d %f", &d1.feet, &d1.inch);

    printf("Enter 2nd distance (feet and inch): ");
    scanf("%d %f", &d2.feet, &d2.inch);

    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;

    /* Normalize inches to less than 12 */
    if (sum.inch >= 12.0) {
        int extra_feet = (int)(sum.inch / 12);   /* whole feet from inches */
        sum.feet += extra_feet;
        sum.inch -= extra_feet * 12;             /* keep remainder inches */
    }

    printf("\nTotal Distance: %d feet, %.1f inches\n", sum.feet, sum.inch);
    return 0;
}

