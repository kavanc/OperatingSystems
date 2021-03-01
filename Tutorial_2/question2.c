#include <stdio.h>
#include <stdlib.h>

int main() {
    double nums[5] = { 1.2, 5.5, 2.1, 3.3, 3.3 };
    double prev = 0;
    for(int i = 0; i < 5; i++) {
        if (nums[i] > prev) {
            printf("%.1f is greater than %.1f\n", nums[i], prev);
        } else if (nums[i] < prev) {
            printf("%.1f is less than %.1f\n", nums[i], prev);
        } else {
            printf("%.1f is equal to %.1f\n", nums[i], prev);
        }

        prev = nums[i];
    }
    return 0;
}
