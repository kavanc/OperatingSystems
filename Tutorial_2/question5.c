#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euclid_dist(int x1, int y1, int x2, int y2);

int main() {
    for(int i = 0; i < 10; i++) {
        int x1 = rand() % 100;
        int x2 = rand() % 100;
        int y1 = rand() % 100;
        int y2 = rand() % 100;
        double dist = euclid_dist(x1, y1, x2, y2);
        printf("x = (%d, %d), y = (%d, %d), distance = %f\n", x1, x2, y1, y2, dist);
    }

    return 0;
}

double euclid_dist(int x1, int y1, int x2, int y2) {
    double square1 = pow(y1-x1, 2);
    double square2 = pow(y2-x2, 2);
    return sqrt(square1 + square2);
}
