#include <stdio.h>

struct Time {
    int h, m, s;
};

int main() {
    struct Time t1, t2, diff;
    int sec1, sec2, total_diff_secs; /* Declarations at top */

    printf("Enter start time (HH MM SS): ");
    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    printf("Enter end time (HH MM SS): ");
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    /* Convert everything to seconds to find difference */
    sec1 = t1.h * 3600 + t1.m * 60 + t1.s;
    sec2 = t2.h * 3600 + t2.m * 60 + t2.s;

    total_diff_secs = (sec1 > sec2) ? (sec1 - sec2) : (sec2 - sec1);

    diff.h = total_diff_secs / 3600;
    diff.m = (total_diff_secs % 3600) / 60;
    diff.s = total_diff_secs % 60;

    printf("\nTime Difference: %02d:%02d:%02d\n", diff.h, diff.m, diff.s);
    return 0;
}

