// Car Fleet Problem
#include <stdio.h>
#include <stdlib.h>

// Structure for each car
typedef struct {
    int position;
    int speed;
} Car;

// Compare cars by position in descending order
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int main() {
    int target, n, i;

    // Input target
    printf("Enter target distance: ");
    scanf("%d", &target);

    // Input number of cars
    printf("Enter number of cars: ");
    scanf("%d", &n);

    Car cars[n];

    // Input positions
    printf("Enter positions of cars:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    // Input speeds
    printf("Enter speeds of cars:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // Step 1: Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    // Step 2: Process from nearest to target
    for(i = 0; i < n; i++) {

        // Time for current car to reach target
        double currentTime = (double)(target - cars[i].position) / cars[i].speed;

        /*
           If current car takes more time than fleet ahead,
           it forms a new fleet.
           Otherwise, it joins the fleet ahead.
        */
        if(currentTime > lastTime) {
            fleets++;
            lastTime = currentTime;
        }
    }

    // Output
    printf("Number of car fleets = %d\n", fleets);

    return 0;
}